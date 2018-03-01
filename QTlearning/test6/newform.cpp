#include "newform.h"

#include "ui_newform.h"

newForm::newForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newForm)
{
    ui->setupUi(this);
}

newForm::~newForm()
{
    delete ui;
}

void newForm::on_pushButton_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

void newForm::on_pushButton_2_clicked()
{
    w = new new2form(this);
    this->hide();
    w->show();

}
