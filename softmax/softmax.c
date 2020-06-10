#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lenet5.h"


/**  
     Finally, there is a fully connected softmax output layer  
     with 10 possible values corresponding to the digits from 0 to 9.
**/

void softmax(int input [nb_filter_conv_3]) {
    int i;
    int max;
    /*** Find maximum value from input array ***/
    max = input[0];
    for (i = 1; i < nb_filter_conv_3; i++) {
        if (input[i] > max) {
            max = input[i];
        }
    }

    double sum = 0;
    for (i = 0; i < nb_filter_conv_3; i++) {
        sum += exp(input[i]-max);
    }

    for (i = 0; i < nb_filter_conv_3; i++) {
        input[i] = exp(input[i] - max - log(sum));

    }    
}