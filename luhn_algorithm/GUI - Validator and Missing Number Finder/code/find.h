#ifndef FIND_H
#define FIND_H

#include <QWidget>

namespace Ui {
class find;
}

class find : public QWidget
{
    Q_OBJECT

public:
    explicit find(QWidget *parent = nullptr);
    ~find();

private:
    Ui::find *ui;
};

#endif // FIND_H
