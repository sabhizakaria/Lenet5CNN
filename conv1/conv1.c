#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lenet5.h"



int relu_func(int x){
	
	int return_value;
	/*** Final Relu value ***/
	return_value = (x > 0) ? x : 0;
	return return_value;


}

int sigmoid(int x)
{
     int return_value;

     /*** Final sigmoid value ***/
     return_value = 1 / (1 + exp(-x));

     return return_value;
}

void affiche_input ( int  tab[input_H][input_W]) {
	int i, j ;

	printf("Input image : \n{ \n");
	for (i = 0 ; i < input_H ; i++ ){
	 	printf(" { ");
	 	for ( j = 0 ; j < input_W ; j++){
	 		if (j != input_H-1)
	 			printf("%d, ", tab[i][j] );
	 		else 
	 			printf("%d ", tab[i][j] );
	 	}
	 	if (i != input_H-1)
	 		printf("}, \n");
	 	else 
	 		printf("} \n");
	 	
	}
	
	printf("}\n");
	printf("\n");
}

/*** 

The input for LeNet-5 is a 32×32 ( 8 × 8 in in the example below ) grayscale image which passes through 
the first convolutional layer with 6 ( 1 in in the example below ) feature maps or filters having size 5×5 
and a stride of one. The image dimensions changes from 32x32x1 to 28x28x6 ( from 8×8×1 to 6×6×1 in the example below ).

***/

void conv1_1(int input [input_H][input_W], int kernel [nb_filter_conv_1][kernel_H][kernel_W], 
	int output [nb_filter_conv_1][outputH_1c][outputH_1c]){
	
	int nb_filtre,i, j, k, l, res = 0;
	
	for (nb_filtre = 0 ; nb_filtre < nb_filter_conv_1; nb_filtre++) { // Choose the first filter 
		for (i = 0 ; i < outputH_1c ; i+=stride){ // Choose index I of input 
			for(j = 0; j < outputW_1c ; j+=stride) { // Choose index Y of input
				
				for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
					for ( l = 0 ; l < kernel_W; l++) {

						res = res + input[k+i][l+j] * kernel[nb_filtre][k][l] ;
					}
				}
				// applying relu function (as activation function)
				output[nb_filtre][i][j] = relu_func(res) ;	
				res = 0 ;	
			}
					
		}			
	}
}