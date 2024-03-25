#ifndef MISSING_H
#define MISSING_H

#include <QDialog>

namespace Ui {
class missing;
}

class missing : public QDialog
{
    Q_OBJECT

public:
    explicit missing(QWidget *parent = nullptr);
    ~missing();

private slots:
    void on_pushButton_2_clicked();

    void on_missingDigit_clicked();

private:
    Ui::missing *ui;
};

#endif // MISSING_H
