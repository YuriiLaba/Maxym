#include "data_processing.h"
#include <stdio.h>

int processData(int dataTest[], int size){
    int TDS = 0;
    int BDS = 1;
    int UP_M = 2;
    int DOWN_M = 3;


    int BottomStates[1000];
    int BottomStatesCount = 0;

    int TopStates[1000];
    int TopStatesCount= 0;


    int cur_state = TDS;

    int prev_dist = dataTest[0];


    for(int i = 1; i < size; i++) {
        if (cur_state == TDS){
            if (prev_dist < dataTest[i]) {
                cur_state = DOWN_M;
            }
        }
        else if(cur_state == BDS) {
            if (prev_dist > dataTest[i]) {
                cur_state = UP_M;
            }
        }
        else if (cur_state == UP_M) {
            if (prev_dist == dataTest[i]) {
                cur_state = TDS;
                TopStates[TopStatesCount] = prev_dist;
                TopStatesCount +=1;
            }
            else if(prev_dist < dataTest[i]) {
                cur_state = DOWN_M;
                TopStates[TopStatesCount] = prev_dist;
                TopStatesCount +=1;
            }
        }
        else if(cur_state == DOWN_M){
            if (prev_dist == dataTest[i]){
                cur_state = BDS;

                BottomStates[BottomStatesCount] = prev_dist;
                BottomStatesCount +=1;


            } else if(prev_dist > dataTest[i]){

                BottomStates[BottomStatesCount] = prev_dist;
                BottomStatesCount +=1;

                cur_state = UP_M;

            }

        }

        prev_dist = dataTest[i];


    }

    for(int i = 0; i<BottomStatesCount; i++){
        printf("Bottom States: %d \n", BottomStates[i]);
    }


    for(int i = 0; i<TopStatesCount; i++){
        printf("Top States: %d \n", TopStates[i]);
    }

    int max = -1000;
    for(int c = 0; c < BottomStatesCount; c+=1) {
        if(BottomStates[c] > max) {
            max=BottomStates[c];
        }
    }



//    printf("MAX: ");
//    printf("%d\n", max);

//    int number = 0;
//    int delta = 3;
//    for(int c = 0; c < count; c+=1) {
//        if(c%2 != 0){
//            if((states[c][1] >= max-delta)||(states[c][1] >= max+delta)) {
//                number++;
//            }
//        }
//    }
//    printf("Strikes: %d\n", number);
    return max;

}

