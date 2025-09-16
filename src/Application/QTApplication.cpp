#include "QTApplication.h"
#include <QApplication>

/**
 * @brief 构造函数
 * @param parent 父级指针
 * @return this
 */
QTApplication::QTApplication(QWidget *parent) : QMainWindow(parent), ui(new Ui_QTApplication)
{
    ui->setupUi(this);

    QVBoxLayout *vboxLayout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Wellcome Use", this);
    QLabel *img = new QLabel(this);
    QPixmap pixMap("../static/icon.png");

    this->setWindowIcon(QIcon("../static/icon.ico"));
    this->setWindowTitle("Qt6-VSCode-Starter"); // 设置
    QPixmap scaledPixmap = pixMap.scaled(
        150,
        pixMap.height() * 150 / pixMap.width(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation);

    img->setMaximumSize(150, 150);
    img->setPixmap(pixMap);
    img->setPixmap(scaledPixmap);
    vboxLayout->setSpacing(0);
    vboxLayout->addWidget(label, 1, Qt::AlignHCenter | Qt::AlignBaseline);
    vboxLayout->addWidget(img, 1, Qt::AlignCenter | Qt::AlignTop);

    ui->centralwidget->setLayout(vboxLayout);
}
/**
 * @brief 析构函数
 */
QTApplication::~QTApplication()
{
    delete ui;
}
