#ifndef ADDFORM_H
#define ADDFORM_H

#include <QDialog>

namespace Ui {
class AddForm;
}

class AddForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = 0);
    ~AddForm();

private:
    Ui::AddForm *ui;
};

#endif // ADDFORM_H
