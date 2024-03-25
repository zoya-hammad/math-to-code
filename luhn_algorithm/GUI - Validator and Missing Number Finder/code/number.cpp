#include "number.h"
#include "ui_number.h"
#include "MissingNum.h"

number::number(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::number)
{
    ui->setupUi(this);
}

number::~number()
{
    delete ui;
}

void number::on_missingDigit_clicked(bool checked)
{
    QString number = ui->lineEditNum->text();
    QString numberType = ui->comboBoxType->currentText();

    MissingNum missingNum;
    string errorMessage;

    if (numberType == "Local Visa/MasterCard")
        errorMessage = missingNum.missingCard(number.toStdString(), false);
    else if (numberType == "International Visa/MasterCard")
        errorMessage = missingNum.missingCard(number.toStdString(), true);
    else if (numberType == "ISBN - 10")
        errorMessage = missingNum.missingISBN10(number.toStdString());
    else if (numberType == "ISBN - 13")
        errorMessage = missingNum.missingISBN13(number.toStdString());
    else if (numberType == "Universal Product Code")
        errorMessage = missingNum.missingUPC(number.toStdString());

    //QString qErrorMessage = QString::fromStdString(errorMessage);
    QString qErrorMessage= QString::fromStdString(errorMessage);

    if (errorMessage.size() == 1 && std::isdigit(errorMessage.at(0))) {
        qErrorMessage = "Missing digit - " + QString::fromStdString(errorMessage);
    } else {
        qErrorMessage = QString::fromStdString(errorMessage);
    }
    ui->info_label->setText(qErrorMessage);

}

