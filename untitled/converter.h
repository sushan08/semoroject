#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string,double>parseString(string response);
double giveConversion(string firCountry,string secCountry,double amount,map<string,double>);

#endif // CONVERTER_H
