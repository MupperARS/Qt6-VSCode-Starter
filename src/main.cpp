#include "QTApplication.h"

#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTApplication w;
    w.show();
    return a.exec();
}