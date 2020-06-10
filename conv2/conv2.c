#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lenet5.h"


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