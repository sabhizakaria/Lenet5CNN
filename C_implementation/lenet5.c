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

void conv1_1(int input [input_H][input_W], int kernel [nb_filter_conv_1][kernel_H][kernel_W], int output [nb_filter_conv_1][outputH_1c][outputH_1c]){
	
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

/*** 
	Then the LeNet-5 applies average pooling layer or 
	sub-sampling layer with a filter size 2×2 and a stride of two. 
	The resulting image dimensions will be reduced to 3x3x1.

***/

void avg_pool_1(int input[outputH_1c][outputW_1c],int output_P[nb_filter_pool_1][outputH_1p][outputW_1p]) {
	int nb_filtre,i, j, k, l, res = 0;
	int m = 0 , n =0;
	for (nb_filtre = 0 ; nb_filtre < nb_filter_conv_1; nb_filtre++) { // Choose the first filter 
		for (i = 0 ; i < outputH_1c ; i+=stride_P, m++){ // index I of input 
			for(j = 0; j < outputW_1c ;j+=stride_P,n++) { // index Y of input
				
				for ( k = 0 ; k < kernel_pH ; k++){ // pooling filter dimention 
					for ( l = 0 ; l < kernel_pW; l++) {
						
						res = res + input[k+i][l+j];
					}
				}
				// applying aferage pooling function 
				output_P[nb_filtre][m][n] = res/(kernel_pH*kernel_pW) ;	
				res = 0 ;	
			}
			n = 0 ;

			
		}

	}

}

/*** 

The input for LeNet-5 is a 14×14x6 which passes through 
the second convolutional layer with 16 feature maps or filters having size 5×5 
and a stride of one. The image dimensions changes from 14x14x6 to 10x10x16 ( from 8×8×1 to 6×6×1 in the example below ).

***/
void conv1_2(int input [nb_layer][outputH_1p][outputW_1p], int kernel [nb_filter_conv_2][kernel_H][kernel_W], 
	int output [nb_filter_conv_2][outputH_2c][outputW_2c]){

	int nb_filtre,nb_l,i, j, k, l, res = 0;
	for (nb_l = 0 ; nb_l < nb_layer ; nb_l++){
		for (nb_filtre = 0 ; nb_filtre < nb_filter_conv_2; nb_filtre++){
			for (i = 0 ; i < outputH_2c ; i+=stride){
				for (j = 0 ; j < outputW_2c ; j+=stride){				 
					if (nb_filtre == 0) { // (featur map)
						if (nb_l == 0 || nb_l == 1 ||nb_l == 2 ){ // (nb of Layer)
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre = 1) { // (featur map)
						if (nb_l == 1 || nb_l == 2 ||nb_l == 3){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
							output[nb_filtre][i][j] = relu_func(res) ;	
							res = 0 ;

						}
					}

					if (nb_filtre == 2) { // (featur map)
						if (nb_l== 2 || nb_l == 3 ||nb_l == 4){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 3) { // (featur map)
						if (nb_l == 3 || nb_l == 4 ||nb_l == 5){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}
					if (nb_filtre == 4) { // (featur map)
						if (nb_l == 4 || nb_l == 5 ||nb_l == 0){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}
					if (nb_filtre == 5) { //(featur map)
						if (nb_l == 5 || nb_l == 0 ||nb_l == 1){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}
					if (nb_filtre == 6) { // (featur map)
						if (nb_l == 0 || nb_l == 1 ||nb_l == 2 || nb_l == 3){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 6) { // (featur map)
						if (nb_l == 0 || nb_l == 1 ||nb_l == 2 || nb_l == 3){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}

						}
					}

					if (nb_filtre == 7) { // (featur map)
						if (nb_l == 1 || nb_l == 2 ||nb_l == 3 || nb_l == 4){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 8) { // (featur map)
						if (nb_l == 2 || nb_l == 3 ||nb_l == 4 || nb_l == 5){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 9) { // (featur map)
						if (nb_l == 3 || nb_l == 4 ||nb_l == 5 || nb_l == 0){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 10) { // (featur map)
						if (nb_l == 4 || nb_l == 5 ||nb_l == 0 || nb_l == 1){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 11) { // (featur map)
						if (nb_l == 5 || nb_l == 0 ||nb_l == 1 || nb_l == 2){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 12) { // (featur map)
						if (nb_l == 0 || nb_l == 1 ||nb_l == 2 || nb_l == 4){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 13) { // (featur map)
						if (nb_l == 1 || nb_l == 2 ||nb_l == 4 || nb_l == 5){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}

					if (nb_filtre == 14) { // (featur map)
						if (nb_l == 0 || nb_l == 2 ||nb_l == 3 || nb_l == 5){
							// Get the conv result 
							for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
								for ( l = 0 ; l < kernel_W; l++) {
									res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
								}
							}
						}
					}
					if (nb_filtre = 15) { // (featur map)
						// Get the conv result 
						for ( k = 0 ; k < kernel_H ; k++){ // kernel dimention 
							for ( l = 0 ; l < kernel_W; l++) {
								res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l];
							}
						}					
					}

					output[nb_filtre][i][j] = relu_func(res) ;	
					res = 0 ;

				}

			}
		}	
	}

}

void avg_pool_2(int input[nb_filter_conv_2][outputH_2c][outputW_2c],int output_P[nb_filter_pool_2][outputH_2p][outputW_2p]){

	int nb_filtre,i, j, k, l, res = 0;
	int m = 0 , n =0;
	for (nb_filtre = 0 ; nb_filtre < nb_filter_pool_2; nb_filtre++) { // Choose the first filter 
		for (i = 0 ; i < outputH_1c ; i+=stride_P, m++){ // index I of input 
			for(j = 0; j < outputW_1c ;j+=stride_P,n++) { // index Y of input
				
				for ( k = 0 ; k < kernel_pH ; k++){ // pooling filter dimention 
					for ( l = 0 ; l < kernel_pW; l++) {
						
						res = res + input[nb_filtre][k+i][l+j];
					}
				}
				// applying aferage pooling function 
				output_P[nb_filtre][m][n] = res/(kernel_pH*kernel_pW) ;	
				res = 0 ;	
			}
			n = 0 ;

			
		}

	}
}

void conv1_3(int input [nb_layer][outputH_2p][outputW_2p], int kernel [nb_filter_conv_2][kernel_H][kernel_W], 
	int output [nb_filter_conv_3]){
	
	int nb_filtre, nb_l, i, j, k, l, f, res = 0;
	int index = 0 ;
	// Each of the 64 units in kernal is connected to all the 400 nodes (16x5x5) of the input  
	for (nb_l = 0 ; nb_l < nb_layer ; nb_l++){
		for (nb_filtre = 0 ; nb_filtre < nb_filter_conv_2 ; nb_filtre++ ){
			for (i = 0 ; i < outputH_2p ; i+=stride){ // index I of input 
				for(j = 0; j < outputW_2p ;j+=stride) { // index Y of input
				 // index of the feature map 
 					for ( k = 0 ; k < kernel_pH ; k++){ 
						for ( l = 0 ; l < kernel_pW; l++) {
							res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l] ;
						}
					}
				}
				// applying relu function (as activation function)
				output[index] = relu_func(res) ;
				index ++ ;
				res = 0 ;	
			}
				
		}

	}


}



/**  Finally, there is a fully connected softmax output layer  
 	 with 10 possible values corresponding to the digits from 0 to 9.
 	 N.B ( TODO : Check if the function works correctly (doubts), should it be implemented ? )
**/
void softmax(int input [nb_filter_conv_3], int output[final_size]) {
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
        output[i] = exp(input[i] - max - log(sum));

    }    
}