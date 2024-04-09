#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    regex = new QRegularExpression("^\\+[0-9]{11}$");
    connect(ui->lineEdit, &QLineEdit::textEdited, this, [this](QString currentNumber)
    {
        if (regex->match(currentNumber).hasMatch())
            isOk();
        else
            notOk();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::isOk()
{
    ui->label->setText("OK!");
    ui->label->setStyleSheet("QLabel {color: darkgreen}");
}

void MainWindow::notOk()
{
    ui->label->setText("Not OK!");
    ui->label->setStyleSheet("QLabel {color: red}");
}
