#ifndef EMATHS
#define EMATHS

#include <math.h>
#include <stdlib.h>
#include <string.h>

float gainTodB(float gain){
    return 20 * log10(gain);
}

float dBtoGain(float dB){
    return pow(10, dB/20);
}

float parallelR(float r1, float r2){
    return (r1 * r2)/(r1 + r2);
}

long double seriesC(long double c1, long double c2){
    return(c1 * c2)/(c1 + c2);
}

long double RCpassFilterCutoff(float r, long double c){
    return 1/(6.28 * r * c);
}

long double LCpassFilterCutoff(double l, long double c){
    return 1/(6.28 * (sqrt(c * l)));
}

double RLpassFilterCutoff(float r, double l){
    return r/(6.26 * l);
}

float totalChargeTime(long double c, float r){
    return 5 * r * c;
}

float timeConstant(float c, float r){
    return r * c;
}

float powerDissipation(float v, float i){
    return v * i;
}

float powerDissipationTwo(float r, float i){
    return r * pow(i, 2);
}

float voltageDivider(float r1, float r2, float v){
    return v * r2 / (r1 + r2);
}

float parallelToEqual(int currentr, int targetr){
    return (currentr * targetr)/(currentr - targetr);
}

double RfromVI(float v, double i){
    return v/i;
} 

double VfromRI(float r, double i){
    return r * i;
}

double IfromVR(float v, float r){
    return v/r;
}

float ACrmstoDC(float ac){
    return ac * 1.414;
}

float DCtoACrms(float dc){
    return dc / 1.414;
}

float getFreqInHz(char* c){
    int size = strlen(c);
    float multiplier = 1;

    for(int i = 0; i < size; i++){
        switch(c[i]){
            case 'k':
                multiplier = 1000;
                c[i] = '\0';
                break;
            default:
                break;
        }
    }
    float val = atof(c);
    return val * multiplier;
}

float capacitiveReactance(float f, float c){
    return 1/(6.28 * f * c);
}

float inductiveReactance(float f, float l){
    return 6.28 * f * l;
}

long double getCapValueInFarads(char* c){
    int size = strlen(c);
    float multiplier = 1;

    for(int i = 0; i < size; i++){
        switch(c[i]){
            case 'u':
                multiplier = .000001;
                c[i] = '\0';
                break;
            case 'n':
                multiplier = .000000001;
                c[i] = '\0';
                break;
            case 'p':
                multiplier = .000000000001;
                c[i] = '\0';
                break;
            default:
                break;
        }
    }
    long double val = atof(c);
    return val * multiplier;
}

long double getCurrentInAmps(char* c){
    int size = strlen(c);
    float multiplier = 1;

    for(int i = 0; i < size; i++){
        if(c[i] > 'A'){
            switch(c[i]){
                case 'm':
                    multiplier = .001;
                    c[i] = '\0';
                    break;
                case 'u':
                    multiplier = .000001;
                    c[i] = '\0';
                    break;
                case 'n':
                    multiplier = .000000001;
                    c[i] = '\0';
                    break;
                default:
                    break;
            }
            break;
        }
    }
    long double val = atof(c);
    return val * multiplier;
}

long double getIndValueInHenries(char* l){
    int size = strlen(l);
    float multiplier = 1;

    for(int i = 0; i < size; i++){
        switch(l[i]){
            case 'm':
                multiplier = .001;
                l[i] = '\0';
                break;
            case 'u':
                multiplier = .000001;
                l[i] = '\0';
                break;
            case 'n':
                multiplier = .000000001;
                l[i] = '\0';
                break;
            case 'p':
                multiplier = .000000000001;
                l[i] = '\0';
                break;
            default:
                break;
        }
    }
    long double val = atof(l);
    return val * multiplier;
}

long double getVoltageInVolts(char* v){
    int size = strlen(v);
    float multiplier = 1;

    for(int i = 0; i < size; i++){
        if(v[i] > 'A'){
            switch(v[i]){
                case 'm':
                    multiplier = .001;
                    v[i] = '\0';
                    break;
                case 'u':
                    multiplier = .000001;
                    v[i] = '\0';
                    break;
                case 'n':
                    multiplier = .000000001;
                    v[i] = '\0';
                    break;
                default:
                    break;
            }
            break;
        }
    }
    long double val = atof(v);
    return val * multiplier;
}

float getResValueInOhms(char* c){
    int size = strlen(c);
    float multiplier = 1;
    int index = 0;
    char beforeBuffer[size];
    char afterBuffer[size];
    int afterChar = 1;
    int overK = 0;

    for(int i = 0; i < size; i++){
        if(c[i] > 'A'){
            overK = 1;
            switch(c[i]){
                case 'k':
                    multiplier = 1000;
                    break;
                case 'K':
                    multiplier = 1000;
                    break;
                case 'M':
                    multiplier = 1000000;
                    break;
                case 'm':
                    multiplier = .001;
                    break;
                case 'G':
                    multiplier = 1000000000;
                    break;
                default:
                    break;
            }
            index = i + 1;
            break;  
        }
        else{ 
            overK = 0;  
            beforeBuffer[i] = c[i];
        }
    }
    
    if(overK == 1){
        for(int j = 0; j < size - index + 1; j++){

            afterChar *= 10;
            afterBuffer[j] = c[index];
            index++;
        }
    }
    return atof(beforeBuffer) * multiplier + (atof(afterBuffer) * multiplier/afterChar); 
}

char* getValFromFarads(long double c) {
    char* output = (char*)malloc(20 * sizeof(char));
    if (output == NULL)
        return NULL;

    char suffix = ' ';
    long double scaled = c;

    if (c < 1) {
        if (c >= 0.000001) {  // Values between 1µF and 1F
            suffix = 'u';
            scaled = c * 1000000;
        }
        else if (c >= 0.000000001) {  // Values between 1nF and 1µF
            suffix = 'n';
            scaled = c * 1000000000;
        }
        else if (c >= 0.000000000001) {  // Values between 1pF and 1nF
            suffix = 'p';
            scaled = c * 1000000000000;
        }
        else {
            sprintf(output, "ERROR");
            return output;
        }
    }

    if (suffix == ' ') {
        sprintf(output, "%.1LfF", scaled);
    } else {
        sprintf(output, "%.1Lf%cF", scaled, suffix);
    }

    return output;
}

char* getValFromOhms(float r){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char rstring[20];
    sprintf(rstring, "%.0f", r);
    int size = strlen(rstring);
    char suffix = '\0';
    
    if(size < 4){
        sprintf(output, "%.1f ohms.\n", r);
        return output;
    }
    else if(size < 7){
        r /= 1000;
        suffix = 'k';
    }
    else if(size < 10){
        r /= 1000000;
        suffix = 'M';
    }
    else{
        r /= 1000000000;
        suffix = 'G';
    }

    sprintf(output, "%.1f%c ohms.\n", r,suffix);
    return output;
}

char* getValFromHenries(long double l) {
    char* output = (char*)malloc(20 * sizeof(char));
    if (output == NULL)
        return NULL;

    char suffix = ' ';
    long double scaled = l;

    if (l < 1) {
        if (l >= 0.001) {  // Values between 1mH and 1H
            suffix = 'm';
            scaled = l * 1000;
        }
        else if (l >= 0.000001) {  // Values between 1µH and 1mH
            suffix = 'u';
            scaled = l * 1000000;
        }
        else if (l >= 0.000000001) {  // Values between 1nH and 1µH
            suffix = 'n';
            scaled = l * 1000000000;
        }
        else if (l >= 0.000000000001) {  // Values between 1pH and 1nH
            suffix = 'p';
            scaled = l * 1000000000000;
        }
        else {
            sprintf(output, "ERROR");
            return output;
        }
    }

    if (suffix == ' ') {
        sprintf(output, "%.1LfH", scaled);
    } else {
        sprintf(output, "%.1Lf%cH", scaled, suffix);
    }

    return output;
}

char* getValFromAmps(long double i) {
    char* output = (char*)malloc(20 * sizeof(char));
    if (output == NULL)
        return NULL;

    char suffix = ' ';
    long double scaled = i;

    if (i < 1) {
        if (i >= 0.001) {  // Values between 1mA and 1A
            suffix = 'm';
            scaled = i * 1000;
        }
        else if (i >= 0.000001) {  // Values between 1µA and 1mA
            suffix = 'u';
            scaled = i * 1000000;
        }
        else if (i >= 0.000000001) {  // Values between 1nA and 1µA
            suffix = 'n';
            scaled = i * 1000000000;
        }
        else {
            sprintf(output, "ERROR");
            return output;
        }
    }

    if (suffix == ' ') {
        sprintf(output, "%.1LfA", scaled);
    } else {
        sprintf(output, "%.1Lf%cA", scaled, suffix);
    }

    return output;
}

char* getValFromVolts(float v){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;
char suffix = ' ';
    double scaled = v;

    if (v < 1) {
        if (v >= 0.001) {  // Values between 1mV and 1V
            suffix = 'm';
            scaled = v * 1000;
        }
        else if (v >= 0.000001) {  // Values between 1µV and 1mV
            suffix = 'u';
            scaled = v * 1000000;
        }
        else if (v >= 0.000000001) {  // Values between 1nV and 1µV
            suffix = 'n';
            scaled = v * 1000000000;
        }
        else {
            sprintf(output, "ERROR");
            return output;
        }
    } else if (v >= 1000) {  // Values in kilovolts (kV)
        suffix = 'k';
        scaled = v / 1000;
    }

    if (suffix == ' ') {
        sprintf(output, "%.2fV", scaled);
    } else {
        sprintf(output, "%.2f%cV", scaled, suffix);
    }

    return output;
}

char* getValFromFreq(float f){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char fstring[20];
    sprintf(fstring, "%.0f", f);
    int size = strlen(fstring);
    char suffix = '\0';
    
    if(size < 4){
        sprintf(output, "%.1f Hz.\n", f);
        return output;
    }
    else if(size < 7){
        f /= 1000;
        suffix = 'k';
    }
    else if(size < 10){
        f /= 1000000;
        suffix = 'M';
    }
    else{
        f /= 1000000000;
        suffix = 'G';
    }

    sprintf(output, "%.1f %cHz.\n", f,suffix);
    return output;
}

char* getValFromSeconds(float s){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    double scaled = s;

    if(s < 1){
        if(s >= 0.001){
            suffix = 'm';
            scaled = s * 1000;
        }
        else if(s >= 0.000001){
            suffix = 'u';
            scaled = s * 1000000;
        }
        else if(s >= .000000001){
            suffix = 'n';
            scaled = s * 1000000000;
        }   
        else{
            sprintf(output, "ERROR\n");
            return output;
        }
    }

    if(suffix == ' '){
        sprintf(output, "%.2fs", scaled);
    }
    else{
        sprintf(output, "%.2f%cs\n", scaled, suffix);
    }
    
    return output;  
}

char* getValFromWatts(float w){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    double scaled = w;

    if(w < 1){
        if(w >= 0.001){
            suffix = 'm';
            scaled = w * 1000;
        }
        else if(w >= 0.000001){
            suffix = 'u';
            scaled = w * 1000000;
        }
        else if(w >= .000000001){
            suffix = 'n';
            scaled = w * 1000000000;
        }   
        else{
            sprintf(output, "ERROR\n");
            return output;
        }
    }

    if(suffix == ' '){
        sprintf(output, "%.2fW", scaled);
    }
    else{
        sprintf(output, "%.2f%cW\n", scaled, suffix);
    }

    return output;  
}

#endif