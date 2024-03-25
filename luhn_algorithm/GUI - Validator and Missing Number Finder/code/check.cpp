#include "check.h"
#include "validation.h"
#include "ui_check.h"

check::check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::check)
{
    ui->setupUi(this);
}

check::~check()
{
    delete ui;
}

void check::on_pushButton_clicked()
{
    QString number = ui->lineEditNum->text();
    QString numberType = ui->comboBoxType->currentText();

    string errorMessage;
    Validation validator;

    if (numberType == "Local Visa/MasterCard")
        errorMessage = validator.validateCard(number.toStdString(), false);
    else if (numberType == "International Visa/MasterCard")
        errorMessage = validator.validateCard(number.toStdString(), true);
    else if (numberType == "ISBN - 10")
        errorMessage = validator.validateISBN10(number.toStdString());
    else if (numberType == "ISBN - 13")
        errorMessage = validator.validateISBN13(number.toStdString());
    else if (numberType == "Universal Product Code")
        errorMessage = validator.validateUPC(number.toStdString());

    if (errorMessage.empty())
        ui->info_label->setText("Card Number is valid.");
    else{
        QString qErrorMessage = QString::fromStdString(errorMessage);
        ui->info_label->setText(qErrorMessage);
    }

}

