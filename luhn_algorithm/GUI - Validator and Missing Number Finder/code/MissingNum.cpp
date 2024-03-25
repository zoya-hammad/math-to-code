#include "MissingNum.h"

MissingNum::MissingNum()
{

}

string MissingNum::missingCard(string card_no, bool isInternational){
    int weights_international[16] = {2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};
    int weights_local[16] = {1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2};
    int S=0, card_number[16];
    int num, product;
    string errorMessage="";

    int missing_count=0, missing_weight;

    // checking for size
    if (card_no.size() !=  16 ){
        return "Card size needs to be exactly 16 digits.";
    }
    //adding card number to an array for processing
    if (isInternational){
        for (int i=0;i<16;i++){
            char c = card_no[i];
            if (!isdigit(c)){
                missing_count+=1;
                if (missing_count>1)
                    return "Too many characters.";
                missing_weight = weights_international[i];
                card_number[i]=0;
            }
            else{
                num = c - '0';
                card_number[i] = num;
            }
        }
    }
    else{
        for (int i=0;i<16;i++){
            char c = card_no[i];
            if (!isdigit(c)){
                missing_count+=1;
                if (missing_count>1)
                    return "Too many characters.";
                missing_weight = weights_local[i];
                card_number[i]=0;
            }
            else{
                num = c - '0';
                card_number[i] = num;
            }
        }
    }//-----------------------

    // international card check
    if (isInternational){
        for (int i=0;i<16;i++){
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
        for (int i=0;i<16;i++){
            product = weights_local[i]*card_number[i];
            if (product >= 10){
                int n1,n2;
                n1 = product/10;
                n2 = product%10;
                product = n1+n2;
            }
            S+= product;
        }
    }

    int missing_num,y;

    if (missing_weight==1){
        for (int i=0;i<10;i++){
            if ((S+i)%10 == 0)
                missing_num=i;
        }
    }
    else{
        for (int i=0;i<10;i++){
            if ((S+i)%10 == 0)
                y=i;
        }
        switch(y){
        case 0: missing_num=0; break;
        case 1: missing_num=5; break;
        case 2: missing_num=1; break;
        case 3: missing_num=6; break;
        case 4: missing_num=2; break;
        case 5: missing_num=7; break;
        case 6: missing_num=3; break;
        case 7: missing_num=8; break;
        case 8: missing_num=4; break;
        case 9: missing_num=9; break;
        }
    }

    if (missing_count!=0)
        return (to_string(missing_num));
    return "Number complete, no missing digits";

}

string MissingNum::missingISBN10(string isbn_no){
    int weights_isbn10[10] = {10,9,8,7,6,5,4,3,2,1};
    int S=0, isbn_number[10];
    int num,product;
    string errorMessage = "";

    int missing_count=0, missing_weight;

    // checking for size
    if (isbn_no.size() !=  10 ){
        return "ISBN number needs to be exactly 10 digits.";
    }
    //adding isbn number to an array for processing
    for (int i=0;i<10;i++){
        char c = isbn_no[i];
        if (!isdigit(c)){
            missing_count+=1;
            if (missing_count>1)
                return "Too many characters.";
            missing_weight = weights_isbn10[i];
            isbn_number[i]=0;
        }
        else{
            num = c - '0';
            isbn_number[i] = num;
        }
    }

    for (int i=0;i<10;i++){
        product = weights_isbn10[i]*isbn_number[i];
        S+= product;
    }

    int missing_num;

    for (int x=0;x<=9;x++){
        if ( ((S+ missing_weight*x) % 11) == 0)
            missing_num=x;
    }
    if (missing_count!=0)
        return (to_string(missing_num));
    return "Number complete, no missing digits";
}

string MissingNum::missingISBN13(string isbn_no){
    int weights_isbn13[13] = {1,3,1,3,1,3,1,3,1,3,1,3,1};
    int S=0, isbn_number[16];
    int num,product;
    string errorMessage="";
    int missing_count=0, missing_weight;

    // checking for size
    if (isbn_no.size() !=  13 ){
        return "ISBN number needs to be exactly 13 digits.";
    }
    //adding isbn number to an array for processing
    for (int i=0;i<13;i++){
        char c = isbn_no[i];
        if (!isdigit(c)){
            missing_count+=1;
            if (missing_count>1)
                return "Too many characters.";
            missing_weight = weights_isbn13[i];
            isbn_number[i]=0;
        }
        else{
            num = c - '0';
            isbn_number[i] = num;
        }
    }

    // international card check
    for (int i=0;i<13;i++){
        product = weights_isbn13[i]*isbn_number[i];
        S+= product;
    }
    int missing_num;

    for (int x=0;x<10;x++){
        if ( ((S+ missing_weight*x) % 10) == 0)
            missing_num=x;
    }
    if (missing_count!=0)
        return (to_string(missing_num));
    return "Number complete, no missing digits";
}

string MissingNum::missingUPC(string product_code){
    int weights_pc[12] = {3,1,3,1,3,1,3,1,3,1,3,1};
    int S=0, code_number[12];
    int num,product;
    string errorMessage="";

    int missing_count=0, missing_weight;

    // checking for size
    if (product_code.size() !=  12 ){
        return "UPC needs to be exactly 12 digits.";

    }
    //adding upc to an array for processing
    for (int i=0;i<12;i++){
        char c = product_code[i];
        if (!isdigit(c)){
            missing_count+=1;
            if (missing_count>1)
                return "Too many characters.";
            missing_weight = weights_pc[i];
            code_number[i]=0;
        }
        else{
            num = c - '0';
            code_number[i] = num;
        }

    }

    for (int i=0;i<12;i++){
        product = weights_pc[i]*code_number[i];
        S+= product;
    }

    int missing_num;

    for (int x=0;x<10;x++){
        if ( ((S+ missing_weight*x) % 10) == 0)
            missing_num=x;
    }
    if (missing_count!=0)
        return (to_string(missing_num));
    return "Number complete, no missing digits";
}

