#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lenet5.h"

void conv1_3(int input [nb_layer][outputH_2p][outputW_2p], int kernel [nb_filter_conv_2][kernel_H][kernel_W], 
	int output [nb_filter_conv_3]){
	
	int nb_filtre, nb_l, i, j, k, l, res = 0;
	int index = 0 ;
	// Each of the 64 units in kernal is connected to all the 400 nodes (16x5x5) of the input  
	for (nb_l = 0 ; nb_l < nb_layer ; nb_l++){
		for (nb_filtre = 0 ; nb_filtre < nb_filter_conv_2 ; nb_filtre++ ){
			for (i = 0 ; i < outputH_2p ; i+=stride){ // index I of input 
				for(j = 0; j < outputW_2p ;j+=stride) { // index Y of input
				 // index of the feature map 
 					for ( k = 0 ; k < kernel_pH ; k++){ 
						for ( l = 0 ; l < kernel_pW; l++) {
							res = res + input[nb_l][k+i][l+j] * kernel[nb_filtre][k][l] ;;
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