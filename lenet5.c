#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
				//printf("m = %d, n= %d ", m, n);
				output_P[nb_filtre][m][n] = res/(kernel_pH*kernel_pW) ;	
				res = 0 ;	
			}
			n = 0 ;

			
		}

	}

}


int main(int argc, char const *argv[])
{
	
	// Declaration and Initizing inputs / kernals / outputs of each layer 
	int i , j, k, l,num ;
	int input[input_H][input_W] = { { 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0} , 
									{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0} , 
									{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} ,

									{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0} , 
									{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0} , 
									{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} ,

									{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0} , 
									{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0} , 
									{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} ,

									{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0} , 
									{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0} , 
									{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0} ,
									{ 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} ,
									{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0} 
							};

	int kernel[nb_filter_conv_1][kernel_H][kernel_W] =   {
								{ 
								  { 1, 0, 1, 1, 0} , 
								  { 0, 1, 0, 0, 1} , 
						          { 1, 0, 1, 1, 1} ,
						          { 0, 0, 0, 0, 1} , 
						          { 0, 0, 1, 1, 1} 
						      	},
						      	{ 
								  { 0, 0, 0, 0, 1} , 
								  { 0, 0, 1, 0, 1} , 
						          { 1, 0, 1, 1, 1} ,
						          { 0, 1, 0, 0, 1} , 
						          { 1, 0, 1, 1, 1} 
						      	},
						      	{ 
								  { 1, 0, 0, 1, 1} , 
								  { 0, 1, 1, 0, 1} , 
						          { 1, 0, 1, 1, 1} ,
						          { 0, 1, 1, 0, 1} , 
						          { 0, 0, 1, 0, 0}  
						      	},
						      	{ 
								  { 1, 0, 1, 0, 1} , 
								  { 0, 1, 1, 0, 1} , 
						          { 1, 0, 1, 1, 1} ,
						          { 0, 1, 0, 0, 1} , 
						          { 0, 1, 1, 0, 0}  
						      	},

						      } ;

	int output[nb_filter_conv_1][outputH_1c][outputW_1c];
	int output_P[nb_filter_pool_1][outputH_1p][outputW_1p];
	
	
	memset(output,0,sizeof(output));
	memset(output_P,0,sizeof(output_P));
	
	affiche_input(input);

	// First convolutional layer   

	conv1_1(input,kernel,output);
	
	// Print results of 1st conv

	printf("Output conv1 ====> : \n{ \n");
	for (num = 0 ; num < nb_filter_conv_1 ; num++){	
		printf(" { \n");
		for (i = 0 ; i < outputH_1c ; i++ ){
	 		printf("  { ");
	 		for ( j = 0 ; j < outputW_1c ; j++){
	 			if (j != outputW_1c-1)
	 				printf("%d, ", output[num][i][j] );
	 			else 
	 				printf("%d ", output[num][i][j] );
	 		}
	 		if (i != outputW_1c-1)
	 			printf("}, \n");
	 		else 
	 			printf("} \n");
		}
		if (num != nb_filter_conv_1-1)
			printf(" }, \n");
		else 
			printf(" }\n");
	}
	
	printf("}\n");

	// first average pooling layer (subsampling)
	avg_pool_1(output[0],output_P);

	// Print results of 2nd conv 
	

	printf("Output pool1 ====> : \n{ \n");
	for(num = 0 ; num < nb_filter_pool_1 ; num++){
		printf(" { \n");
		for (i = 0 ; i < outputH_1p ; i++ ){
		 	printf("  { ");
		 	for ( j = 0 ; j < outputW_1p ; j++){
		 		if (j != outputH_1p-1)
		 			printf("%d, ", output_P[num][i][j] );
		 		else 
		 			printf("%d ", output_P[num][i][j] );
		 	}
		 	if (i != outputH_1p-1)
		 		printf("}, \n");
		 	else 
		 		printf("} \n");
		}
		if (num != nb_filter_pool_1-1)
		printf(" },\n");
		else 
		printf(" }\n");
		
	}
	printf("}\n");

	return 0;
}



/*



void conv_2()

void pool_2()

void fully_connected()
*/





