#include "new2form.h"
#include "ui_new2form.h"

new2form::new2form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::new2form)
{
    ui->setupUi(this);
}

new2form::~new2form()
{
    delete ui;
}

void new2form::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet(QStringLiteral("border-image: url(:/images/5_down.JPG);"));
    ui->lineEdit->setText( ui->lineEdit->text()+"5");
}

void new2form::on_pushButton_released()
{
      ui->pushButton->setStyleSheet(QStringLiteral("border-image: url(:/images/5_up.JPG);"));
}
