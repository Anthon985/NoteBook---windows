#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QString>
#include <QDebug>
#include <QShortcut>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    // void on_btnClose_clicked();
    // void on_btnSave_clicked();
    // void on_btnOpen_clicked();
    void on_textEdit_selectionChanged();
    void on_actionClose_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionTime_triggered();
    void on_actionFont_triggered();
    void on_comboBox_currentIndexChanged(int index);
    void undo();  //撤销
    void selAll(); //全选
    void zoomIn(); //放大
    void zoomOut(); //缩小

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    QSettings settings{"简易记事本", "Notepad", this} ;
    int defaultFontSize = 12; //默认字体大小
    int minFontSize = 6;      // 最小字体限制
    int maxFontSize = 72;     // 最大字体限制
    bool isFileModified = false;
    bool isUserCanceled = false;
    QString currentFilePath = "";

    QString currEncoding = "UTF-8";
    QStringList surpportEncoding = {
        "UTF-8",
        "UTF-16",
        "GBK",
        "ANSI"
    };

    void updateCursorPosition();
    void updateWindowTitle();
    void initEncoding();
    void updateZoomLabel();
    bool openFile(const QString &filePath);
    bool saveFile(bool askForPath);
    bool confirmSaveIfModified(const QString &context);
};

#endif // MAINWINDOW_H
