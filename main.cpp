#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile style(":/Styles/Diffnes.qss");
    style.open(QIODevice::ReadOnly);
    auto currentStyle = style.readAll();
    a.setStyleSheet(currentStyle);
    a.setWindowIcon(QIcon(":/Icons/kometaicon.png"));
    style.close();
    return a.exec();
}
