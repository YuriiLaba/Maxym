#include <iostream>
#include "data_processing.h"

using namespace std;



int main() {
    int distancesUltrasonic[100];
    int data[20] = {
            8,8,8,9,8,7,6,4,10,12,14,16,18,18,18,12,10,8,8,8
    };

    int TDS = data[0];
    int count = 0;
    int countTDS = 0;

    for(int i = 1; i < 20; i+=1){
        if(data[i] == TDS){
            countTDS += 1;
        }


        if(data[i] < TDS){
            TDS = data[i];
        }
        else if(data[i] != TDS){
            distancesUltrasonic[count] = data[i];
            count+=1;
        }




        if((countTDS == 5)&&(count!=0)){
            //send
            countTDS = 0;
            count = 0;
        }
        else if (count == 0) {
            countTDS=0;
        }


    }


    for(int y = 0; y< count; y+=1){
        cout<<distancesUltrasonic[y]<<endl;
    }

    int x = processData(distancesUltrasonic, count);
    cout<<x<<endl;
    return 0;
}