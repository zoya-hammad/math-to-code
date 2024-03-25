#include "validation.h"

Validation::Validation()
{

}


string Validation::validateUPC(string product_code){
    int weights_pc[11] = {3,1,3,1,3,1,3,1,3,1,3};
    int S=0, code_number[12];
    int num, check_digit,product;
    string errorMessage="";

    // checking for size
    if (product_code.size() !=  12 ){
        return "UPC needs to be exactly 12 digits.";

    }
    //adding upc to an array for processing
    for (int i=0;i<12;i++){
        char c = product_code[i];
        if (!isdigit(c)){
            return "UPC cannot contain a letter.";

        }
        num = c - '0';
        code_number[i] = num;
    }

    check_digit = product_code[10];

    // 0306406152

    for (int i=0;i<11;i++){
        product = weights_pc[i]*code_number[i];
        S+= product;
    }

    S =  S%10;

    if (check_digit != (10 - S))
        errorMessage = "Invalid UPC.";

    return errorMessage;
}

string Validation::validateISBN10(string isbn_no){
    int weights_isbn10[9] = {10,9,8,7,6,5,4,3,2};
    int S=0, isbn_number[10];
    int num, check_digit,product;
    string errorMessage = "";

    // checking for size
    if (isbn_no.size() !=  10 ){
        return "ISBN number needs to be exactly 10 digits.";
    }
    //adding isbn number to an array for processing
    for (int i=0;i<10;i++){
        char c = isbn_no[i];
        if (!isdigit(c)){
            return "ISBN-10 number cannot contain a letter.";
        }
        num = c - '0';
        isbn_number[i] = num;
    }

    check_digit = isbn_number[9];

    // 0306406152

    for (int i=0;i<9;i++){
        product = weights_isbn10[i]*isbn_number[i];
        S+= product;
    }

    S =  S%11;
    if ((check_digit!=(11-S)))
        errorMessage = "Invalid ISBN Number.";

    return errorMessage;
}

string Validation::validateISBN13(string isbn_no){
    int weights_isbn13[12] = {1,3,1,3,1,3,1,3,1,3,1,3};
    int S=0, isbn_number[16];
    int num, check_digit,product;
    string errorMessage="";

    // checking for size
    if (isbn_no.size() !=  13 ){
        return "ISBN number needs to be exactly 13 digits.";
    }
    //adding isbn number to an array for processing
    for (int i=0;i<13;i++){
        char c = isbn_no[i];
        if (!isdigit(c)){
            return "ISBN-13 number cannot contain a letter.";
        }
        num = c - '0';
        isbn_number[i] = num;
    }

    check_digit = isbn_number[12];

    // international card check
    for (int i=0;i<12;i++){
        product = weights_isbn13[i]*isbn_number[i];
        S+= product;
    }
    S = S%10;

    if (check_digit!=(10-S))
        errorMessage = "Invalid ISBN Number.";

    return errorMessage;
}

string Validation::validateCard(string card_no, bool isInternational){
    int weights_international[15] = {2,1,2,1,2,1,2,1,2,1,2,1,2,1,2};
    int weights_local[15] = {1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};
    int S=0, card_number[16];
    int num, check_digit,product;
    string errorMessage="";

    // checking for size
    if (card_no.size() !=  16 ){
        return "Card size needs to be exactly 16 digits.";
    }
    //adding card number to an array for processing
    for (int i=0;i<16;i++){
        char c = card_no[i];
        if (!isdigit(c)){
            return "Card number cannot contain a letter.";
        }
        num = c - '0';
        card_number[i] = num;
    }


    check_digit = card_number[15];
    // international card check
    if (isInternational){
        for (int i=0;i<15;i++){
            product = weights_international[i]*card_number[i];
            if (product >= 10){
                int n1,n2;
                n1 = product/10;
                n2 = product%10;
                product = n1+n2;
            }
            S+= product;
        }

    }
    // local card check
    else{
        for (int i=0;i<15;i++){
            product = weights_local[i]*card_number[i];
            if (product > 10){
                int n1,n2;
                n1 = product/10;
                n2 = product%10;
                product = n1+n2;
            }
            S+= product;
        }
    }

    S = S%10;
    if (check_digit!=(10-S))
        errorMessage="Invalid Card Number";

    return errorMessage;

}

