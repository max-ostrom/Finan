#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "currencyprovider.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CurrencyProvider* provider = new CurrencyProvider();
    connect(provider, SIGNAL(testFinish(QString)),
            this, SLOT(responseFromNetwork(QString)));
    connect(provider, SIGNAL(started()),
            this, SLOT(startHandler()));
    provider->start();
}
void MainWindow::startHandler()
{
    QMessageBox::information(0, "START", "START");
}
void MainWindow::responseFromNetwork(QString reply)
{
    ui->textBrowser->setSource(reply);
}
MainWindow::~MainWindow()
{
    delete ui;
}
