#pragma once
#include "ui_QTApplication.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

class QTApplication : public QMainWindow
{
    Q_OBJECT
private:
    Ui_QTApplication *ui;

public:
    explicit QTApplication(QWidget *parent = nullptr);
    ~QTApplication();

private:
private:
};