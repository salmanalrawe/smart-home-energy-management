#include <stdio.h>
#include <stdlib.h>

int main()
{
//Used Variables:

const char *deviceNames[]={"Fridge","WaterDespender","TV","Lights","WashingMachine","ClothesDryer","HairDryer","Iron","Blender","Kettle","Stove","VacuumCleaner","DishWasher","AirCondition"};
int devicesPower[14] = {200,1200,200,1000,1500,2000,1200,2500,500,1000,1000,500,1200,3000};
int sumw1[24]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sums1[24]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sumw2[24]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sums2[24]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sumw3[24]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sums3[24]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const char *hours []= {"00:00","01:00","02:00","03:00","04:00","05:00","06:00","07:00","08:00","09:00","10:00","11:00","12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00","23:00"};
int m, n , i , j , limit;
float block1, block2, block3, save=0;
float costw1=0, costw2=0, costw3=0, costs1=0, costs2=0, costs3=0;
float batteryCapacity, batteryCharge, dischargeRate;

// Winter Load Profile:
int priorityw[24][14] = {{1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,1,1,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,1,0,0,0},
                         {1,1,0,0,0,0,0,0,0,1,0,0,0,0},
                         {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                         {1,1,1,1,0,0,0,0,0,0,0,0,0,0},
                         {1,1,1,1,2,0,0,0,0,0,0,2,0,0},
                         {1,1,1,1,2,0,2,0,0,0,0,0,0,0},
                         {1,1,1,1,0,2,0,0,0,0,0,2,0,0},
                         {1,1,1,1,0,2,0,2,0,0,1,0,0,0},
                         {1,1,1,1,0,0,2,2,2,1,0,0,2,0},
                         {1,1,1,1,0,0,0,0,2,0,1,0,2,0},
                         {1,1,1,0,0,0,0,0,0,0,0,0,0,0}};

// Summer Load Profile:
int prioritys[24][14] ={{1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,1,1,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,1,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,1,0,0,0,0,0,0,0,0,1,0,0,1},
                        {1,1,0,0,0,0,0,0,0,1,0,0,2,1},
                        {1,1,0,0,0,0,0,0,0,0,0,0,2,1},
                        {1,1,1,1,0,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,2,0,0,0,0,0,0,2,0,1},
                        {1,1,1,1,2,0,2,0,0,0,0,0,0,0},
                        {1,1,1,1,0,2,0,0,0,0,0,2,0,0},
                        {1,1,1,1,0,2,0,2,0,0,1,0,0,0},
                        {1,1,1,1,0,0,2,2,2,1,0,0,2,0},
                        {1,1,1,1,0,0,0,0,2,0,0,0,2,0},
                        {1,1,1,0,0,0,0,0,0,0,0,0,0,0}};


// Setting the variables:
/*
printf("  Please indicate the winter limit:  "); scanf("%d", &limit);puts(" ");
printf("  Please indicate the first pricing block in $/Wh:(between 23:00-06:00)  "); scanf("%f", &block1);puts(" ");
printf("  Please indicate the second pricing block in $/Wh:(between 07:00-16:00)  "); scanf("%f", &block2);puts(" ");
printf("  Please indicate the third pricing block in $/Wh:(between 17:00-22:00)  "); scanf("%f", &block3);puts(" ");
*/
puts(" ");
limit = 6000;  printf("  The treshold is %dW\n", limit);
block1 = 0.03; printf("  The first pricing block is %.2f$/kWh\n", block1);
block2 = 0.05; printf("  The second pricing block is %.2f$/kWh\n", block2);
block3 = 0.5;  printf("  The third pricing block is %.2f$/kWh\n", block3);puts(" "); puts(" ");


// Winter and summer analysis without applying anything
puts("  Winter and summer analysis without applying anything");puts(" "); puts(" ");
//Winter:
puts("  Winter");
//Calculating the total energy consumption
for (i=0; i<24; i++){
        for(j=0; j<14; j++){
            if (priorityw[i][j]>0) {
                    sumw1[i]=sumw1[i] + devicesPower[j]; }}}
//Winter Graphing:
puts("  Winter Energy Profile without Applying Anything");
printf("  %s%15s\n", "Hours", "Devices");
for(i=0; i<24; i++){
    printf("  %s", hours[i]); for(j=0;j<14;j++){if(priorityw[i][j]>0){printf("%15s",deviceNames[j]);} } puts(" ");} puts(" ");
printf("  %s%17s%20s\n", "Hours", "Total Energy", "Histrogram");
for(i=0; i<24; i++){
printf("  %s%13d              ",hours[i], sumw1[i]); for(j=0;j<=(sumw1[i]/100); j++ ){printf("*");} puts(" ");}
puts("  Note: Each star represents a 100W of power consumption"); puts(" ");
// Winter Cost:
for(n= 0; n< 7; n++){costw1 = costw1 + (((float)sumw1[n ]/1000) *block1);}
for(n= 7; n<17; n++){costw1 = costw1 + (((float)sumw1[n ]/1000) *block2);}
for(n=17; n<23; n++){costw1 = costw1 + (((float)sumw1[n ]/1000) *block3);}
                     costw1 = costw1 + (((float)sumw1[23]/1000) *block1); puts(" ");
printf("  The cost without applying anything in winter is $%.3f\n", costw1); puts(" ");puts(" ");puts(" ");


//Summer:
puts("  Summer");
//Calculating the total energy consumption
for (i=0; i<24; i++){
        for(j=0; j<14; j++){
            if (prioritys[i][j]>0) {
                    sums1[i]=sums1[i] + devicesPower[j]; }}}
//Summer Graphing:
puts("  Summer Energy Profile without Applying Anything");
printf("  %s%15s\n", "Hours", "Devices");
for(i=0; i<24; i++){
    printf("  %s", hours[i]); for(j=0;j<14;j++){if(prioritys[i][j]>0){printf("%15s",deviceNames[j]);} } puts(" ");} puts(" ");
printf("  %s%17s%20s\n", "Hours", "Total Energy", "Histrogram");
for(i=0; i<24; i++){
printf("  %s%13d              ",hours[i], sums1[i]); for(j=0;j<=(sums1[i]/100); j++ ){printf("*");} puts(" ");}
puts("  Note: Each star represents a 100W of power consumption"); puts(" ");
// Summer Cost:
for(n= 0; n< 7; n++){costs1 = costs1 + (((float)sums1[n ]/1000) *block1);}
for(n= 7; n<17; n++){costs1 = costs1 + (((float)sums1[n ]/1000) *block2);}
for(n=17; n<23; n++){costs1 = costs1 + (((float)sums1[n ]/1000) *block3);}
                     costs1 = costs1 + (((float)sums1[23]/1000) *block1); puts(" ");
printf("  The cost without applying anything in summer is $%.3f\n", costs1); puts(" ");puts(" ");puts(" ");






// Winter and Summer Analysis After Applying the Wind-Turbine-Battery-System:
puts("  Winter and Summer Analysis After Applying the Wind-Turbine-Battery-System:"); puts(" "); puts(" ");
//Setting the capacity of the battery
batteryCapacity = sumw1[17];
for (i=18; i<23; i++){
    if(sumw1[i]>batteryCapacity){batteryCapacity = sumw1[i]; }}
batteryCapacity = 0.5 * batteryCapacity;
printf("  The capacity of the battery is: %.1fWh\n", batteryCapacity);
batteryCharge = batteryCapacity * 0.8;
dischargeRate = batteryCapacity * 0.3;
printf("  The charge of the battery is: %.1fWh\n", batteryCharge);
printf("  The discharge rate of the battery is: %.1fWh\n",dischargeRate); puts(" "); puts(" ");


//Winter:
puts("  Winter");
//Calculating the total energy consumption
for (i=0; i<24; i++){
        for(j=0; j<14; j++){
            if (priorityw[i][j]>0) {
                    sumw2[i]=sumw2[i] + devicesPower[j]; }}}

//Using the battery during the peak hours for winter
if(batteryCharge > batteryCapacity*0.5){
            sumw2[17] -= dischargeRate;
            batteryCharge-=dischargeRate;
        if (batteryCharge > dischargeRate){
            batteryCharge-=dischargeRate;
            sumw2[18]-=batteryCharge;}}

//Winter Graphing:
puts("  Winter Energy Profile After Applying the Wind-Turbine-Battery System");
printf("  %s%15s\n", "Hours", "Devices");
for(i=0; i<24; i++){
    printf("  %s", hours[i]); for(j=0;j<14;j++){if(priorityw[i][j]>0){printf("%15s",deviceNames[j]);} } puts(" ");} puts(" ");
printf("  %s%17s%20s\n", "Hours", "Total Energy", "Histrogram");
for(i=0; i<24; i++){
printf("  %s%13d              ",hours[i], sumw2[i]); for(j=0;j<=(sumw2[i]/100); j++ ){printf("*");} puts(" ");}
puts("  Note: Each star represents a 100W of power consumption"); puts(" ");
// Winter Cost:
for(n= 0; n< 7; n++){costw2 = costw2 + (((float)sumw2[n ]/1000) *block1);}
for(n= 7; n<17; n++){costw2 = costw2 + (((float)sumw2[n ]/1000) *block2);}
for(n=17; n<23; n++){costw2 = costw2 + (((float)sumw2[n ]/1000) *block3);}
                     costw2 = costw2 + (((float)sumw2[23]/1000) *block1); puts(" ");
printf("  The cost after applying the Wind-Turbine-Battery System in winter is $%.3f\n", costw2);
save= (float) 100*((costw1 -costw2)/costw1);printf("  The percentage of savings is: %.3f", save); puts(" ");puts(" ");puts(" ");


//Summer:
puts("  Summer");
// Setting the battery charge:
batteryCharge = batteryCapacity * 0.8;
//Calculating the total energy consumption
for (i=0; i<24; i++){
        for(j=0; j<14; j++){
            if (prioritys[i][j]>0) {
                    sums2[i]=sums2[i] + devicesPower[j]; }}}

//Using the battery during the peak hours for winter
if(batteryCharge > batteryCapacity*0.5){
            sums2[17] -= dischargeRate;
            batteryCharge-=dischargeRate;
        if (batteryCharge > dischargeRate){
            batteryCharge-=dischargeRate;
            sums2[18]-=batteryCharge;}}

//Summer Graphing:
puts("  Summer Energy Profile After Applying the Wind-Turbine-Battery System");
printf("  %s%15s\n", "Hours", "Devices");
for(i=0; i<24; i++){
    printf("  %s", hours[i]); for(j=0;j<14;j++){if(prioritys[i][j]>0){printf("%15s",deviceNames[j]);} } puts(" ");} puts(" ");
printf("  %s%17s%20s\n", "Hours", "Total Energy", "Histrogram");
for(i=0; i<24; i++){
printf("  %s%13d              ",hours[i], sums2[i]); for(j=0;j<=(sums2[i]/100); j++ ){printf("*");} puts(" ");}
puts("  Note: Each star represents a 100W of power consumption"); puts(" ");
// Summer Cost:
for(n= 0; n< 7; n++){costs2 = costs2 + (((float)sums2[n ]/1000) *block1);}
for(n= 7; n<17; n++){costs2 = costs2 + (((float)sums2[n ]/1000) *block2);}
for(n=17; n<23; n++){costs2 = costs2 + (((float)sums2[n ]/1000) *block3);}
                     costs2 = costs2 + (((float)sums2[23]/1000) *block1); puts(" ");
printf("  The cost after applying the Wind-Turbine-Battery System in summer is $%.3f\n", costs2);
save= (float) 100*((costs1 -costs2)/costs1);printf("  The percentage of savings is: %.3f", save); puts(" ");puts(" ");puts(" ");






// Winter and Summer Analysis After Applying the Wind-Turbine-Battery-System and LSM:
puts("  Winter and Summer Analysis After Applying the Wind-Turbine-Battery-System and LSM:"); puts(" "); puts(" ");
//Winter:
puts("  Winter");
//Setting the battery charge
batteryCharge = batteryCapacity * 0.8;

//Calculating the total energy consumption
for (i=0; i<24; i++){
        for(j=0; j<14; j++){
            if (priorityw[i][j]>0) {
                    sumw3[i]=sumw3[i] + devicesPower[j]; }}}

//Using the battery during the peak hours for winter
if(batteryCharge > batteryCapacity*0.5){
            sumw3[17] -= dischargeRate;
            batteryCharge-=dischargeRate;
        if (batteryCharge > dischargeRate){
            batteryCharge-=dischargeRate;
            sumw3[18]-=batteryCharge;}}

// LSM
for (i=17;i<23;i++){
    for (j=0;j<14;j++){
        if (sumw3[i]<limit){break;}
        if (sumw3[i] > limit ){
        if(priorityw[i][j]>1){
                if (priorityw[23][j]!=2){ priorityw[23][j]=2; priorityw[i][j]=0; sumw3[i]-=devicesPower[j];sumw3[23]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[23]);}
           else if (priorityw[0 ][j]!=2){ priorityw[0 ][j]=2; priorityw[i][j]=0; sumw3[i]-=devicesPower[j];sumw3[0 ]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[0 ]);}
           else if (priorityw[1 ][j]!=2){ priorityw[1 ][j]=2; priorityw[i][j]=0; sumw3[i]-=devicesPower[j];sumw3[1 ]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[1 ]);}
           else                         { priorityw[2 ][j]=2; priorityw[i][j]=0; sumw3[i]-=devicesPower[j];sumw3[2 ]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[2 ]);}}}}}
puts(" ");puts(" ");puts(" ");
//Winter Graphing:
puts("  Winter Energy Profile After Applying the Wind-Turbine-Battery System and LSM");
printf("  %s%15s\n", "Hours", "Devices");
for(i=0; i<24; i++){
    printf("  %s", hours[i]); for(j=0;j<14;j++){if(priorityw[i][j]>0){printf("%15s",deviceNames[j]);} } puts(" ");} puts(" ");
printf("  %s%17s%20s\n", "Hours", "Total Energy", "Histrogram");
for(i=0; i<24; i++){
printf("  %s%13d              ",hours[i], sumw3[i]); for(j=0;j<=(sumw3[i]/100); j++ ){printf("*");} puts(" ");}
puts("  Note: Each star represents a 100W of power consumption"); puts(" ");
// Winter Cost:
for(n= 0; n< 7; n++){costw3 = costw3 + (((float)sumw3[n ]/1000) *block1);}
for(n= 7; n<17; n++){costw3 = costw3 + (((float)sumw3[n ]/1000) *block2);}
for(n=17; n<23; n++){costw3 = costw3 + (((float)sumw3[n ]/1000) *block3);}
                     costw3 = costw3 + (((float)sumw3[23]/1000) *block1); puts(" ");
printf("  The cost after applying the Wind-Turbine-Battery System and LSM in winter is $%.3f\n", costw3);
save= (float) 100*((costw1 -costw3)/costw1);printf("  The percentage of savings is: %.3f", save); puts(" ");puts(" ");puts(" ");


//Summer:
puts("  Summer");
// Setting the battery charge:
batteryCharge = batteryCapacity * 0.8;
//Calculating the total energy consumption
for (i=0; i<24; i++){
        for(j=0; j<14; j++){
            if (prioritys[i][j]>0) {
                    sums3[i]=sums3[i] + devicesPower[j]; }}}

//Using the battery during the peak hours for winter
if(batteryCharge > batteryCapacity*0.5){
            sums3[17] -= dischargeRate;
            batteryCharge-=dischargeRate;
        if (batteryCharge > dischargeRate){
            batteryCharge-=dischargeRate;
            sums3[18]-=batteryCharge;}}

// LSM
for (i=17;i<23;i++){
    for (j=0;j<14;j++){
        if (sums3[i]<limit){break;}
        if (sums3[i] > limit ){
        if(prioritys[i][j]>1){
                if (prioritys[23][j]!=2){ prioritys[23][j]=2; prioritys[i][j]=0; sums3[i]-=devicesPower[j];sums3[23]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[23]);}
           else if (prioritys[0 ][j]!=2){ prioritys[0 ][j]=2; prioritys[i][j]=0; sums3[i]-=devicesPower[j];sums3[0 ]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[0 ]);}
           else if (prioritys[1 ][j]!=2){ prioritys[1 ][j]=2; prioritys[i][j]=0; sums3[i]-=devicesPower[j];sums3[1 ]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[1 ]);}
           else                         { prioritys[2 ][j]=2; prioritys[i][j]=0; sums3[i]-=devicesPower[j];sums3[2 ]+=devicesPower[j]; printf("  %s has been shifted from %s to %s \n", deviceNames[j], hours[i], hours[2 ]);}}}}}
puts(" ");puts(" ");puts(" ");
//Summer Graphing:
puts("  Summer Energy Profile After Applying the Wind-Turbine-Battery System and LSM");
printf("  %s%15s\n", "Hours", "Devices");
for(i=0; i<24; i++){
    printf("  %s", hours[i]); for(j=0;j<14;j++){if(prioritys[i][j]>0){printf("%15s",deviceNames[j]);} } puts(" ");} puts(" ");
printf("  %s%17s%20s\n", "Hours", "Total Energy", "Histrogram");
for(i=0; i<24; i++){
printf("  %s%13d              ",hours[i], sums3[i]); for(j=0;j<=(sums3[i]/100); j++ ){printf("*");} puts(" ");}
puts("  Note: Each star represents a 100W of power consumption"); puts(" ");
// Summer Cost:
for(n= 0; n< 7; n++){costs3 = costs3 + (((float)sums3[n ]/1000) *block1);}
for(n= 7; n<17; n++){costs3 = costs3 + (((float)sums3[n ]/1000) *block2);}
for(n=17; n<23; n++){costs3 = costs3 + (((float)sums3[n ]/1000) *block3);}
                     costs3 = costs3 + (((float)sums3[23]/1000) *block1); puts(" ");
printf("  The cost after applying the Wind-Turbine-Battery System and LSM in summer is $%.3f\n", costs3);
save= (float) 100*((costs1 -costs3)/costs1);printf("  The percentage of savings is: %.3f", save); puts(" ");puts(" ");puts(" ");


}
