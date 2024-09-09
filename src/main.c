#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "emaths.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void displayOptions();
void handleInput(char input);

int programShouldEnd = 0;
int isInputValid = 1;

int main()
{
    do{
        displayOptions();
        char input;

        do{
            input = getchar();
            handleInput(input);
        }while(isInputValid == 1);

        printf("\nEnter x to exit or anything else to restart.\n");
        getchar(); 
        input = getchar();
        if(input == 'x') programShouldEnd = 1;
            else system(CLEAR);
        
    }while(programShouldEnd == 0);
}

void handleInput(char input){
    isInputValid = 0;
    float output = 0;
    char buffer[64];
    double current = 0;
    float r = 0;
    float v = 0;
    float l = 0;
    float f = 0;
    char* o;

    switch(input){
        case '0':
            printf("\nSolve for \'V\', \'R\', or \'I\':\n");
            getchar();
            char option = (char)tolower(getchar());
            switch(option){
                case 'v':
                    printf("\nEnter current:\n");
                    scanf("%s", buffer);
                    current = getCurrentInAmps(buffer);
                    printf("\nEnter resistance:\n");
                    scanf("%s", buffer);
                    r = getResValueInOhms(buffer);
                    float num = VfromRI(r, current);
                    o = getValFromVolts(VfromRI(r, current));
                    printf("\nVoltage: %s\n",o);
                    free(o);
                    break;
                case 'r':
                    printf("\nEnter voltage:\n");
                    scanf("%s", buffer);
                    v = getVoltageInVolts(buffer);
                    printf("\nEnter current:\n");
                    scanf("%s", buffer);
                    current = getCurrentInAmps(buffer);
                    o = getValFromOhms(RfromVI(v, current));
                    printf("\nResistance: %s",o);
                    free(o);
                    break;
                case 'i':
                    printf("\nEnter voltage:\n");
                    scanf("%s", buffer);
                    v = getVoltageInVolts(buffer);
                    printf("\nEnter resistance:\n");
                    scanf("%s", buffer);
                    r = getResValueInOhms(buffer);
                    o = getValFromAmps(IfromVR(v, r));
                    printf("\nCurrent: %s",o);
                    free(o);
                    break;
            }
            break;
        case '1':
            printf("\nEnter voltage gain:\n");
            float gain;
            scanf("%f", &gain);
            output = gainTodB(gain);
            printf("\n%.2f dB.\n", output);
            break;
        case '2':
            printf("\nEnter first resistor value:\n");
            float r1;
            scanf("%s", buffer);
            r1 = getResValueInOhms(buffer);
            printf("\nEnter second resistor value:\n");
            float r2;
            scanf("%s", buffer);
            r2 = getResValueInOhms(buffer);
            output = parallelR(r1,r2);
            char* rP = getValFromOhms(output);
            printf("\nR1 and R2 in parallel are equivalent to %s\n", rP);
            free(rP);
            break;
        case '3':
            printf("\nEnter first capacitor value:\n");
            scanf("%s", buffer);
            float c1 = getCapValueInFarads(buffer);
            printf("\nEnter second capacitor value:\n");
            scanf("%s", buffer);
            float c2 = getCapValueInFarads(buffer);
            output = seriesC(c1, c2);
            char* cP = getValFromFarads(output);
            printf("\nC1 and C2 in series are equivalent to %s\n", cP);
            free(cP);
            break;
        case '4':
            printf("\nEnter \'L\' for LC filter, \'C\' for RC filter, or \'R\' for RL filter:\n");
            getchar();
            option = (char)tolower(getchar());
            switch(option){
                case 'l':
                    printf("\nEnter inductor value:\n");
                    scanf("%s", buffer);
                    l = getIndValueInHenries(buffer);
                    printf("\nEnter capacitor value:\n");
                    scanf("%s", buffer);
                    c1 = getCapValueInFarads(buffer);
                    output = LCpassFilterCutoff(l,c1);
                    break;
                case 'c':
                    printf("\nEnter resistor value:\n");
                    scanf("%s", buffer);
                    r1 = getResValueInOhms(buffer);
                    printf("\nEnter capacitor value:\n");
                    scanf("%s", buffer);
                    c1 = getCapValueInFarads(buffer);
                    output = RCpassFilterCutoff(r1,c1);
                    break;
                case 'r':
                    printf("\nEnter resistor value:\n");
                    scanf("%s", buffer);
                    r1 = getResValueInOhms(buffer);
                    printf("\nEnter inductor value:\n");
                    scanf("%s", buffer);
                    l = getIndValueInHenries(buffer);
                    output = RLpassFilterCutoff(r1,l);
                    break;
                default:
                    l = 0;
                    r1 = 0;
                    break;
            }
            o = getValFromFreq(output);
            printf("\nCutoff frequency is %s\n", o);
            free(o);
            break;
        case '5':
            printf("\nEnter capacitor value:\n");
            scanf("%s", buffer);
            c1 = getCapValueInFarads(buffer);
            printf("\nEnter resistance:\n");
            scanf("%s", buffer);
            r1 = getResValueInOhms(buffer);
            output = totalChargeTime(c1,r1);
            float timeConstant = c1 * r1;
            char* tc = getValFromSeconds(timeConstant);
            o = getValFromSeconds(output);
            printf("\nTime constant is: %s\nTotal charge time is %s\n", tc, o);
            free(o);
            free(tc);
            break;
        case '6':
            printf("\nTo calculate from V and I, enter \'1\'. To calculate from I and R, enter \'2\'.\n");
            getchar();
            option = (char)tolower(getchar());
            switch(option){
                case '1':
                    printf("\nEnter voltage:\n");
                    scanf("%s", buffer);
                    v = getVoltageInVolts(buffer);
                    printf("\nEnter current:\n");
                    scanf("%s", buffer);
                    current = getCurrentInAmps(buffer);
                    output = powerDissipation(v, current);
                    o = getValFromWatts(output);
                    printf("\nTotal power is: %s", o);
                    free(o);
                    break;
                case '2':
                    printf("\nEnter current:\n");
                    scanf("%s", buffer);
                    current = getCurrentInAmps(buffer);
                    printf("\nEnter resistance:\n");
                    scanf("%s", buffer);
                    r = getResValueInOhms(buffer);
                    output = powerDissipationTwo(r, current);
                    o = getValFromWatts(output);
                    printf("\nPower dissipation is: %s", o);
                    free(o);
                    break;
            }
            break;
        case '7':
            printf("\nEnter input voltage:\n");
            scanf("%s", buffer);
            v = getVoltageInVolts(buffer);
            printf("\nEnter value of R1 (the series resistor):\n");
            scanf("%s", buffer);
            r1 = getResValueInOhms(buffer);
            printf("\nEnter value of R2 (the shunt resistor):\n");
            scanf("%s", buffer);
            r2 = getResValueInOhms(buffer);
            output = voltageDivider(r1 ,r2, v);
            o = getValFromVolts(output);
            printf("\nOutput voltage is %s\n", o);
            free(o);
            break;
        case '8':
            printf("\nEnter \'A\' to solve for AC rms or \'D\' for DC equivalent:\n");
            getchar();
            option = (char)tolower(getchar());
            switch(option){
                case 'd':
                    printf("\nEnter AC rms voltage:\n");
                    scanf("%s", buffer);
                    v = getVoltageInVolts(buffer);
                    output = ACrmstoDC(v);
                    o = getValFromVolts(output);
                    printf("\nEquivalent DC voltage is %s\n", o);
                    free(o);
                    break;
                case 'a':
                    printf("\nEnter DC voltage:\n");
                    scanf("%s", buffer);
                    v = getVoltageInVolts(buffer);
                    output = DCtoACrms(v);
                    o = getValFromVolts(output);
                    printf("\nEquivalent AC voltage is %s rms\n", o);
                    free(o);
                    break;
            }
            break;
        case '9':
            printf("\nEnter \'C\' for capacitive or \'L\' for inductive:\n");
            getchar();
            option = (char)tolower(getchar());
            switch(option){
                case 'c':
                    printf("\nEnter frequency:\n");
                    scanf("%s", buffer);
                    f = getFreqInHz(buffer);
                    printf("\nEnter capacitance:\n");
                    scanf("%s", buffer);
                    c1 = getCapValueInFarads(buffer);
                    output = capacitiveReactance(f, c1);
                    o = getValFromOhms(output);
                    printf("\nCapacitive reactance: %s", o);
                    free(o);
                    break;
                case 'l':
                    printf("\nEnter frequency:\n");
                    scanf("%s", buffer);
                    f = getFreqInHz(buffer);
                    printf("\nEnter inductance:\n");
                    scanf("%s", buffer);
                    l = getIndValueInHenries(buffer);
                    output = inductiveReactance(f, l);
                    o = getValFromOhms(output);
                    printf("\nInductive reactance: %s", o);
                    free(o);
                    break;
            }
            break;
        case 'x':
            programShouldEnd = 1;
            break;
        default:
            isInputValid = 1;
            break;
    }
}

void displayOptions()
{
    printf("\nElectronics Cheatsheet. Enter a number:\n");
    printf("0. ohm's law calculations\n");
    printf("1. dB from voltage gain.\n");
    printf("2. parallel resistance.\n");
    printf("3. series capacitance.\n");
    printf("4. cutoff frequency for hi/lo pass filter.\n");
    printf("5. total charge/discharge time\n");
    printf("6. power consumption/dissipation\n");
    printf("7. voltage divider\n");
    printf("8. AC/DC conversion\n");
    printf("9. reactance\n");
    printf("Enter x to Quit/Restart.\n");
}