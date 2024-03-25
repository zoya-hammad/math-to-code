#include "missing.h"
#include "ui_missing.h"
#include "MissingNum.h"

missing::missing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::missing)
{
    ui->setupUi(this);
}

missing::~missing()
{
    delete ui;
}


void missing::on_missingDigit_clicked() {
//    QString number = ui->lineEditNum->text();
//    QString numberType = ui->comboBoxType->currentText();

//    MissingNum missingNum;
//    string errorMessage;

//    if (!number.back().isDigit()) {
//        if (numberType == "Local Visa/MasterCard")
//            errorMessage = missingNum.missingCardcd(number.toStdString(), false);
//        else if (numberType == "International Visa/MasterCard")
//            errorMessage = missingNum.missingCardcd(number.toStdString(), true);
//        else if (numberType == "ISBN - 10")
//            errorMessage = missingNum.missingISBN10cd(number.toStdString());
//        else if (numberType == "ISBN - 13")
//            errorMessage = missingNum.missingISBN13cd(number.toStdString());
//        else if (numberType == "Universal Product Code")
//            errorMessage = missingNum.missingUPCcd(number.toStdString());
//    } else {
//        if (numberType == "Local Visa/MasterCard")
//            errorMessage = missingNum.missingCard(number.toStdString(), false);
//        else if (numberType == "International Visa/MasterCard")
//            errorMessage = missingNum.missingCard(number.toStdString(), true);
//        else if (numberType == "ISBN - 10")
//            errorMessage = missingNum.missingISBN10(number.toStdString());
//        else if (numberType == "ISBN - 13")
//            errorMessage = missingNum.missingISBN13(number.toStdString());
//        else if (numberType == "Universal Product Code")
//            errorMessage = missingNum.missingUPC(number.toStdString());
//    }

//    QString qErrorMessage = QString::fromStdString(errorMessage);
//    ui->info_label->setText(qErrorMessage);
    ui->info_label->setText("Hello");
}




