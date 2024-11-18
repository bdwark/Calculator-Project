#include <iostream>
#include <map>
#include <string>
#include <math.h>

using namespace std;

float LengthConv(float val, string unitIn, string unitOut){
    float convertedUnit = val;
    //Metric Start
    if (unitIn == "mm") {
        //Millimeter Dictionary
        map<string, float> mmConvDict;
        mmConvDict["in"] = 0.0393701;
        mmConvDict["ft"] = 0.00328084;
        mmConvDict["yd"] = 0.00109361;
        mmConvDict["mi"] = 0.00000062137;
        mmConvDict["mm"] = 1;
        mmConvDict["cm"] = 0.1;
        mmConvDict["m"] = 0.001;
        mmConvDict["km"] = 0.000001;
        

        //Calculation
        convertedUnit = val * mmConvDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "cm") {
        //Centimeter Dictionary
        map<string, float> cmConvDict;
        cmConvDict["in"] = 0.393701;
        cmConvDict["ft"] = 0.0328084;
        cmConvDict["yd"] = 0.0109361;
        cmConvDict["mi"] = 0.0000062137;
        cmConvDict["mm"] = 10;
        cmConvDict["cm"] = 1;
        cmConvDict["m"] = 0.01;
        cmConvDict["km"] = 0.00001;

        //Calculation
        convertedUnit = val * cmConvDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "m") {
        //Meter Dictionary
        map<string, float> mConvDict;
        mConvDict["in"] = 39.3701;
        mConvDict["ft"] = 3.28084;
        mConvDict["yd"] = 1.09361;
        mConvDict["mi"] = 0.000621371;
        mConvDict["mm"] = 1000;
        mConvDict["cm"] = 100;
        mConvDict["m"] = 1;
        mConvDict["km"] = 0.001;

        //Calculation
        convertedUnit = val * mConvDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "km") {
        //Kilometer Dictionary
        map<string, float> kmConvDict;
        kmConvDict["in"] = 39370.1;
        kmConvDict["ft"] = 3280.84;
        kmConvDict["yd"] = 1093.61;
        kmConvDict["mi"] = 0.621371;
        kmConvDict["mm"] = 1000000;
        kmConvDict["cm"] = 100000;
        kmConvDict["m"] = 1000;
        kmConvDict["km"] = 1;

        //Calculation
        convertedUnit = val * kmConvDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "in") {
        //Inches Dictionary
        map<string, float> inConvDict;
        inConvDict["mm"] = 25.4;
        inConvDict["cm"] = 2.54;
        inConvDict["m"] = 0.0254;
        inConvDict["km"] = 0.0000254;
        inConvDict["in"] = 1;
        inConvDict["ft"] = 0.08333;
        inConvDict["yd"] = 0.2777;
        inConvDict["mi"] = 0.000015782;

        //Calculation
        convertedUnit = val * inConvDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "ft") {
        //Feet Dictionary
        map<string, float> ftConvDict;
        ftConvDict["mm"] = 304.8;
        ftConvDict["cm"] = 30.48;
        ftConvDict["m"] = 0.3048;
        ftConvDict["km"] = 0.0003048;
        ftConvDict["in"] = 12;
        ftConvDict["ft"] = 1;
        ftConvDict["yd"] = 0.3333;
        ftConvDict["mi"] = 0.0001893;

        //Calculation
        convertedUnit = val * ftConvDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "yd") {
        //Yards Dictionary
        map<string, float> ydConvDict;
        ydConvDict["mm"] = 914.4;
        ydConvDict["cm"] = 91.44;
        ydConvDict["m"] = 0.9144;
        ydConvDict["km"] = 0.0009144;
        ydConvDict["in"] = 36;
        ydConvDict["ft"] = 3;
        ydConvDict["yd"] = 1;
        ydConvDict["mi"] = 0.0005681;

        //Calculation
        convertedUnit = val * ydConvDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "mi") {
        //Miles Dictionary
        map<string, float> miConvDict;
        miConvDict["mm"] = 1609000;
        miConvDict["cm"] = 160934;
        miConvDict["m"] = 1609.34;
        miConvDict["km"] = 1.60934;
        miConvDict["in"] = 63360;
        miConvDict["ft"] = 5280;
        miConvDict["yd"] = 1760;
        miConvDict["mi"] = 1;

        //Calculation
        convertedUnit = val * miConvDict[unitOut];
        return convertedUnit;
    } else {
        //Catch all if invalid inputs
        //cout << "Invalid Inputs" << endl;
        return convertedUnit;
    }
}