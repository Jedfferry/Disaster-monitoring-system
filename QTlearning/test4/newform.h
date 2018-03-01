#ifndef NEWFORM_H
#define NEWFORM_H

#include <QMainWindow>

namespace Ui {
class newForm;
}

class newForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit newForm(QWidget *parent = 0);
    ~newForm();
signals:

    void back();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newForm *ui;
};

#endif // NEWFORM_H
