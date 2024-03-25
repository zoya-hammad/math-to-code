#ifndef CHECK_H
#define CHECK_H

#include <QDialog>

namespace Ui {
class check;
}

class check : public QDialog
{
    Q_OBJECT

public:
    explicit check(QWidget *parent = nullptr);
    ~check();

private slots:
    void on_pushButton_clicked();

private:
    Ui::check *ui;
};

#endif // CHECK_H
