#ifndef NEW2FORM_H
#define NEW2FORM_H

#include <QMainWindow>

namespace Ui {
class new2form;
}

class new2form : public QMainWindow
{
    Q_OBJECT

public:
    explicit new2form(QWidget *parent = 0);
    ~new2form();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::new2form *ui;
};

#endif // NEW2FORM_H
