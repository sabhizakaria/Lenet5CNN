#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lenet5.h"

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