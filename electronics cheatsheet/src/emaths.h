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

char* getRKMfromFarads(long double c){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    int scale = 1;
    double temp = c;

    while(temp < .1){
        temp *= 10;
        scale++;
        if(scale > 20)
            return "ERROR";
    }
    if(scale < 2){
        suffix = 'F';
    }
    else if(scale < 8){
        c *= (pow(10,scale));
        suffix = 'u';
    }
    else if(scale < 11){
        c *= (pow(10,scale));
        suffix = 'n';
    }
    else{
        c *= (pow(10,scale));
        suffix = 'p';
    }

    sprintf(output, "%.1Lf%cf\n", c,suffix);
    return output;  
}

char* getRKMfromOhms(float r){
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

char* getRKMfromHenries(long double l){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    int scale = 1;
    double temp = l;

    while(temp < .1){
        temp *= 10;
        scale++;
        if(scale > 20)
            return "ERROR";
    }
    if(scale < 2){
        sprintf(output, "%.1LfH\n", l);
        return output;
    }
    else if(scale < 5){
        l *= (pow(10, scale));
        suffix = 'm';
    }
    else if(scale < 8){
        l *= (pow(10,scale));
        suffix = 'u';
    }
    else if(scale < 11){
        l *= (pow(10,scale));
        suffix = 'n';
    }
    else{
        l *= (pow(10,scale));
        suffix = 'p';
    }

    sprintf(output, "%.1Lf%cH\n", l,suffix);
    return output;  
}

char* getRKMfromAmps(long double i){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    int scale = 1;
    double temp = i;

    while(temp < .1){
        temp *= 10;
        scale++;
        if(scale > 20)
            return "ERROR";
    }
    if(scale < 2){
        sprintf(output, "%.1LfA\n", i);
        return output;  
    }
    else if(scale < 5){
        i *= (pow(10, scale));
        suffix = 'm';
    }
    else if(scale < 8){
        i *= (pow(10,scale));
        suffix = 'u';
    }
    else{
        i *= (pow(10,scale));
        suffix = 'n';
    }

    sprintf(output, "%.1Lf%cA\n", i,suffix);
    return output;  
}

char* getRKMfromVolts(float v){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    int scale = 1;
    double temp = v;

    while(temp < .1){
        temp *= 10;
        scale++;
        if(scale > 20)
            return "ERROR";
    }
    if(scale < 2)
    {
        sprintf(output, "%.2fV", v);
        return output;
    }
    else if(scale < 5){
        v *= (pow(10, scale));
        suffix = 'm';
    }
    else if(scale < 8){
        v *= (pow(10,scale));
        suffix = 'u';
    }

    sprintf(output, "%.2f%cV", v,suffix);
    return output;  
}

char* getRKMfromFreq(float f){
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

char* getRKMfromSeconds(float s){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    int scale = 1;
    double temp = s;

    while(temp < .1){
        temp *= 10;
        scale++;
        if(scale > 20)
            return "ERROR";
    }
    if(scale < 2)
    {
        sprintf(output, "%.2fs\n", s);
        return output;
    }
    else if(scale < 5){
        s *= (pow(10, scale));
        suffix = 'm';
    }
    else if(scale < 8){
        s *= (pow(10,scale));
        suffix = 'u';
    }
    else if(scale < 11){
        s *= (pow(10,scale));
        suffix = 'n';
    }

    sprintf(output, "%.2f%cs\n", s,suffix);
    return output;  
}

char* getRKMfromWatts(float w){
    char* output = (char*)malloc(20 * sizeof(char));
    if(output == NULL)
        return NULL;

    char suffix = ' ';
    int scale = 1;
    double temp = w;

    while(temp < .1){
        temp *= 10;
        scale++;
        if(scale > 20)
            return "ERROR";
    }
    if(scale < 2)
    {
        sprintf(output, "%.2fW\n", w);
        return output;
    }
    else if(scale < 5){
        w *= (pow(10, scale));
        suffix = 'm';
    }
    else if(scale < 8){
        w *= (pow(10,scale));
        suffix = 'u';
    }

    sprintf(output, "%.2f%cW\n", w,suffix);
    return output;  
}

#endif