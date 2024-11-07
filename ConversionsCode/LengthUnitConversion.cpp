#include <iostream>
#include <map>
#include <string>
#include <math.h>

using namespace std;

//Metric Conversion used only for metric to metric
//Unit inputs can only be mm, cm, m, or km
float metricConversion(float val, string unitIn, string unitOut){
    //Metric Dictionary
    map<string, float> metricDictionary;
    metricDictionary["mm"] = 0.001;
    metricDictionary["cm"] = 0.01;
    metricDictionary["m"] = 1;
    metricDictionary["km"] = 1000;

    //Calculation
    float convertedUnit = val * metricDictionary[unitIn] / metricDictionary[unitOut];
    return convertedUnit;
}

//Imperial Conversion used only for imperial to imperial
//Unit inputs can only be in, ft, yd, or mi
float imperialConversion(float val, string unitIn, string unitOut){
    //Imperial Dictionary
    map<string, float> imperialDictionary;
    imperialDictionary["in"] = 1;
    imperialDictionary["ft"] = 12;
    imperialDictionary["yd"] = 36;
    imperialDictionary["mi"] = 63360;

    //Calculation
    float convertedUnit = val * imperialDictionary[unitIn] / imperialDictionary[unitOut];
    return convertedUnit;
}

//Cross system conversion used to go between imperial and metric
//Inputs can only be mm, cm, m, km, in, ft, yd, or mi
//ONLY HAS CASES FOR CONVERTING TO OPPOSITE SYSTEM OF MEASUREMENT
float impMetConv(float val, string unitIn, string unitOut){
    float convertedUnit = val;
    //Metric Start
    if (unitIn == "mm") {
        //Millimeter Dictionary
        map<string, float> mmToImpDict;
        mmToImpDict["in"] = 0.0393701;
        mmToImpDict["ft"] = 0.00328084;
        mmToImpDict["yd"] = 0.00109361;
        mmToImpDict["mi"] = 0.00000062137;

        //Calculation
        convertedUnit = val * mmToImpDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "cm") {
        //Centimeter Dictionary
        map<string, float> cmToImpDict;
        cmToImpDict["in"] = 0.393701;
        cmToImpDict["ft"] = 0.0328084;
        cmToImpDict["yd"] = 0.0109361;
        cmToImpDict["mi"] = 0.0000062137;

        //Calculation
        convertedUnit = val * cmToImpDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "m") {
        //Meter Dictionary
        map<string, float> mToImpDict;
        mToImpDict["in"] = 39.3701;
        mToImpDict["ft"] = 3.28084;
        mToImpDict["yd"] = 1.09361;
        mToImpDict["mi"] = 0.000621371;

        //Calculation
        convertedUnit = val * mToImpDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "km") {
        //Kilometer Dictionary
        map<string, float> kmToImpDict;
        kmToImpDict["in"] = 39370.1;
        kmToImpDict["ft"] = 3280.84;
        kmToImpDict["yd"] = 1093.61;
        kmToImpDict["mi"] = 0.621371;

        //Calculation
        convertedUnit = val * kmToImpDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "in") {
        //Inches Dictionary
        map<string, float> inToMetDict;
        inToMetDict["mm"] = 25.4;
        inToMetDict["cm"] = 2.54;
        inToMetDict["m"] = 0.0254;
        inToMetDict["km"] = 0.0000254;

        //Calculation
        convertedUnit = val * inToMetDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "ft") {
        //Feet Dictionary
        map<string, float> ftToMetDict;
        ftToMetDict["mm"] = 304.8;
        ftToMetDict["cm"] = 30.48;
        ftToMetDict["m"] = 0.3048;
        ftToMetDict["km"] = 0.0003048;

        //Calculation
        convertedUnit = val * ftToMetDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "yd") {
        //Yards Dictionary
        map<string, float> ydToMetDict;
        ydToMetDict["mm"] = 914.4;
        ydToMetDict["cm"] = 91.44;
        ydToMetDict["m"] = 0.9144;
        ydToMetDict["km"] = 0.0009144;

        //Calculation
        convertedUnit = val * ydToMetDict[unitOut];
        return convertedUnit;
    } else if (unitIn == "mi") {
        //Miles Dictionary
        map<string, float> miToMetDict;
        miToMetDict["mm"] = 1609000;
        miToMetDict["cm"] = 160934;
        miToMetDict["m"] = 1609.34;
        miToMetDict["km"] = 1.60934;

        //Calculation
        convertedUnit = val * miToMetDict[unitOut];
        return convertedUnit;
    } else {
        //Catch all if invalid inputs
        //cout << "Invalid Inputs" << endl;
        return convertedUnit;
    }
}


