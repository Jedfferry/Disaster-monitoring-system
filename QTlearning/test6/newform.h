#ifndef NEWFORM_H
#define NEWFORM_H

#include <QMainWindow>
#include "new2form.h"

namespace Ui {
class newForm;
}

class newForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit newForm(QWidget *parent = 0);
    ~newForm();
    new2form *w;

signals:

    void back();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newForm *ui;
};

#endif // NEWFORM_H
