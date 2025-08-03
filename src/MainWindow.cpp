#include "MainWindow.h"
#include "../build/ui_MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->ClickOnMeButton, &QPushButton::clicked, this, &MainWindow::clickedBut);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_ClickOnMeButton_clicked() {
    QPushButton *btn = ui->ClickOnMeButton;

    btn->setStyleSheet("background-color: red;");

    QSize sz = btn->size();

    btn->setFixedSize(sz.width() * 2, sz.height() * 2);
}