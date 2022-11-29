#include "converter.h"
#include <string>

vector<string> countryCodes = {"AUD","INR","NPR","CAD","CNY","KWD","SGD","QAR","CZK","MYR","RUB","RAD","NZD","JPY","STG","EGP","IRR","HKD","BZD","BHD","SAR"};

double stringToDouble(string val){
    double d_val = stod(val.c_str());
    return d_val;
}

map<string,double> parseString(string response){
    map<string,double> currRate;
    currRate["USD"] = 1.00;
    for(int i=0;i<countryCodes.size();i++){
        int ind = response.find(countryCodes[i]);
        if(ind == string::npos)continue;
        ind+=6;
        string val="";
        for(int j=ind;j<ind+4;j++)
            val+=response[j];
        double rate = stringToDouble(val);
        currRate.insert({countryCodes[i],rate});
    }
    return currRate;
}

double giveConversion(string firCountry,string secCountry,double amount,map<string,double> currRate){
    double to_usd = amount/currRate[firCountry];
    return to_usd*currRate[secCountry];
}

