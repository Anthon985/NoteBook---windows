#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QFontDialog>
#include <QTextStream>
#include <QFileInfo>
#include <QTextCursor>
#include <QScrollBar>
#include <QTextLayout>
#include <QTextBlock>
#include <QTextDocument>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initEncoding();

    ui->textEdit->installEventFilter(this); // MainWindow作为过滤器
    //初始化字体
    QFont defaultFont = ui->textEdit->font();
    defaultFont.setPointSize(defaultFontSize);
    ui->textEdit->setFont(defaultFont);
    updateZoomLabel();
    // 读取设置
    QString fs;
    if (!(fs = settings.value("font").toString()).isEmpty())
    {
        QFont f;
        f.fromString(fs); // 将保存的字符串解析为 QFont 对象
        ui->textEdit->setFont(f); // 应用到文本框
        updateZoomLabel();
    }

    new QShortcut(QKeySequence("Ctrl+="),this,SLOT(zoomIn())); //放大字体
    new QShortcut(QKeySequence("Ctrl+-"),this,SLOT(zoomOut())); //缩小字体


    connect(ui->textEdit, &QTextEdit::textChanged, this, [this]() {
        if (!ui->textEdit->signalsBlocked()) {
            isFileModified = true;
            updateWindowTitle();
        }
    });

    connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this, &MainWindow::updateCursorPosition);
    updateWindowTitle();
    updateCursorPosition();

    // this->setLayout(ui->verticalLayout);
     ui->widget_2->setLayout(ui->horizontalLayout_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------- 关闭窗口 ----------------
void MainWindow::on_actionClose_triggered()
{
    qDebug()<<"执行了";
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (confirmSaveIfModified("关闭窗口")) {
        event->accept();
    } else {
        event->ignore();
    }
}

// ---------------- 保存文件 ----------------
bool MainWindow::saveFile(bool askForPath)
{
    isUserCanceled = false;

    if (currentFilePath.isEmpty() && askForPath) {
        QString path = QFileDialog::getSaveFileName(
            this, "保存文件", "无标题.txt", "文本文件 (*.txt);;所有文件 (*.*)"
            );
        if (path.isEmpty()) {
            isUserCanceled = true;
            return false;
        }
        currentFilePath = path;
    }
    if (currentFilePath.isEmpty() && !askForPath) {
        return false;
    }

    QFile file(currentFilePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return false;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();

    isFileModified = false;
    updateWindowTitle();
    return true;
}

void MainWindow::on_actionSave_triggered()
{
    if (saveFile(true)) {
        QMessageBox::information(this, "保存成功", "文件已成功保存！");
    } else if (!isUserCanceled) {
        QMessageBox::warning(this, "保存失败", "文件保存失败！");
    }
}
// ---------------- 打开文件 ----------------
void MainWindow::on_actionOpen_triggered()
{
    if (!confirmSaveIfModified("打开新文件"))
        return; // 用户取消，直接返回

    QString filePath = QFileDialog::getOpenFileName(
        this, "打开文件", "", "文本文件 (*.txt);;所有文件 (*.*)"
        );

    if (filePath.isEmpty())
        return;

    if (openFile(filePath)) {
        currentFilePath = filePath;
        isFileModified = false;
        updateWindowTitle();
    } else {
        QMessageBox::warning(this, "打开失败", "无法打开文件，请检查文件是否存在或有读取权限！");
    }
}

bool MainWindow::openFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return false;

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();


    ui->textEdit->blockSignals(true);
    ui->textEdit->clear();
    ui->textEdit->setText(content);
    ui->textEdit->blockSignals(false);

    isFileModified = false;
    updateWindowTitle();
    return true;
}

// ---------------- 状态更新 ----------------
void MainWindow::updateWindowTitle()
{
    QString fileName = currentFilePath.isEmpty()
    ? "无标题"
    : QFileInfo(currentFilePath).fileName();

    setWindowTitle(fileName + (isFileModified ? "*" : "") + " - 简易记事本");

    if (ui->lblFileName)
        ui->lblFileName->setText("当前文件：" + fileName + (isFileModified ? "*" : ""));
}
//---------------更新光标所在行列号-----------------
void MainWindow::updateCursorPosition()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextDocument *doc = ui->textEdit->document();
    QTextBlock block = cursor.block();
    if (!block.isValid() || !doc) return;

    int posInBlock = cursor.position() - block.position();
    if (posInBlock < 0) posInBlock = 0;

    QTextLayout *layout = block.layout();
    int lineIndex = 0;

    if (layout) {
        int safePos = qBound(0, posInBlock, block.length());
        QTextLine line = layout->lineForTextPosition(safePos);
        if (line.isValid())
            lineIndex = line.lineNumber();
        else
            lineIndex = 0;
    } else {
        lineIndex = 0;
    }

    // 计算从文档开始到当前块之前的可视行数，遍历时检查有效性
    int visualLine = 0;
    for (QTextBlock b = doc->begin(); b.isValid() && b != block; b = b.next()) {
        QTextLayout *l = b.layout();
        visualLine += (l ? l->lineCount() : 1);
    }
    visualLine += lineIndex + 1;

    int lineStart = 0;
    if (layout && layout->lineCount() > lineIndex) {
        QTextLine curLine = layout->lineAt(lineIndex);
        if (curLine.isValid()) lineStart = curLine.textStart();
    }

    int visualCol = posInBlock - lineStart + 1; // 基于字符位置计数
    if (visualCol < 1) visualCol = 1;

    if (ui->lblCursorPos)
        ui->lblCursorPos->setText(QString("行 %1，列 %2").arg(visualLine).arg(visualCol));
}
//---------------菜单烂状态更新--------------------
void MainWindow::on_textEdit_selectionChanged()
{
    bool selected = ui->textEdit->textCursor().hasSelection(); // 判断是否有选中文本
    ui->actionCopy->setEnabled(selected); // 无选中则禁用（灰色），有选中则启用（黑色）
    ui->actionCut->setEnabled(selected);  // 同理：剪切
}
//-----------------重写事件过滤器-----------------------
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    // 1. 判断事件源：仅处理textEdit的事件
    if (watched == ui->textEdit)
    {
        // 2. 判断事件类型：是否为鼠标滚轮事件
        if (event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);
            // 3. 判断是否按住Ctrl键（核心：组合键判断）
            if (wheelEvent->modifiers() & Qt::ControlModifier)
            {
                // 4. 根据滚轮方向触发放大/缩小
                if (wheelEvent->angleDelta().y() > 0)
                {
                    // 滚轮向上
                    zoomIn();
                }
                else
                {
                    // 滚轮向下
                    zoomOut();
                }
                // 5. 拦截事件，阻止传递（避免同时滚动页面）
                return true;
            }
        }
    }

    // 其他事件：按原有逻辑传递（不影响正常功能）
    return QMainWindow::eventFilter(watched, event);
}
//--------------提示窗口--------------------
bool MainWindow::confirmSaveIfModified(const QString &context)
{
    if (!isFileModified)
        return true;

    QMessageBox::StandardButton result = QMessageBox::question(
        this,
        "提示",
        currentFilePath.isEmpty()
            ? QString("无标题 - 未保存，是否保存更改后再%1？").arg(context)
            : QString("“%1” 已修改，是否保存更改后再%2？")
                  .arg(QFileInfo(currentFilePath).fileName()).arg(context),
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
        QMessageBox::Save
        );

    switch (result) {
    case QMessageBox::Save:
        if (!saveFile(false)) {      // 尝试静默保存
            if (!saveFile(true))     // 弹出另存为
                return false;        // 用户取消
        }
        return true;
    case QMessageBox::Discard:
        return true;
    case QMessageBox::Cancel:
        return false;
    default:
        return false;
    }
}
//---------------字符编码转换------------------------
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    //TODO 编码切换
}

void MainWindow::initEncoding()
{
    int defaultIndex = surpportEncoding.indexOf("UTF-8");
    if(defaultIndex>=0)
    {
        ui->comboBox->setCurrentIndex(defaultIndex);
        currEncoding="UTF-8";
    }
}
//-----------------------字体大小的更新-----------------
void MainWindow::updateZoomLabel()
{
    QFont currentFont = ui->textEdit->font();
    int currentSize = currentFont.pointSize();
    int zoomPercent = qRound((double)currentSize / defaultFontSize * 100);
    ui->zoomSize->setText(QString("%1%").arg(zoomPercent));
}
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont selectedFont = QFontDialog::getFont(
        &ok,                  // 用于判断用户是否点击“确定”
        ui->textEdit->font(), // 默认字体（文本框当前字体）
        this,                 // 父窗口
        "字体"                // 对话框标题
    );
    if (ok)
    {
        ui->textEdit->setFont(selectedFont); // 应用到文本编辑区
        settings.setValue("font", selectedFont.toString()); // 保存到配置（下次启动恢复）
    }
}
//---------------------快捷键------------------------------
void MainWindow::undo() //撤销
{
    ui->textEdit->undo();
}

void MainWindow::selAll() //全选
{
    ui->textEdit->selectAll();
}

void MainWindow::zoomIn() //放大
{
    QFont font = ui->textEdit->font();
    int currentSize = font.pointSize();

    if (currentSize >= maxFontSize) {
        QMessageBox::information(this, "提示", "已达到最大字体大小！");
        return;
    }
    // 放大1磅（或2磅）
    int step = 1;
    font.setPointSize(currentSize + step);
    ui->textEdit->setFont(font);
    // 更新缩放标签
    updateZoomLabel();
}

void MainWindow::zoomOut() //缩小
{
    QFont font = ui->textEdit->font();
    int currentSize = font.pointSize();

    if (currentSize <= minFontSize) {
        QMessageBox::information(this, "提示", "已达到最小字体大小！");
        return;
    }

    int step = 1;
    font.setPointSize(currentSize - step);
    ui->textEdit->setFont(font);
    // 缩放标签
    updateZoomLabel();
}
//复制
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}
//粘贴
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
//---------------------时间戳---------------------------
void MainWindow::on_actionTime_triggered()
{
    ui->textEdit->insertPlainText(QDateTime::currentDateTime().toString("hh:mm yyyy/MM/dd"));
}
