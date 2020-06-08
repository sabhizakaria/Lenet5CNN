#ifndef LENET5_H_
#define LENET5_H_

/*** number of filters   ***/
#define nb_filter_conv_1 4
#define nb_filter_pool_1 4
#define nb_filter_conv_2 16
#define nb_filter_pool_2 16
#define nb_filter_conv_3 64
#define nb_layer 4
/*** dimension of image input   ***/
#define input_H 32
#define input_W 32
/*** dimension of filters (convolution)   ***/
#define kernel_H 5
#define kernel_W 5
/*** dimension of filters (pooling)   ***/
#define kernel_pH 2
#define kernel_pW 2
/*** convolution stride  ***/
#define stride 1
/*** pooling stride ***/
#define stride_P 2

#define bias 0
/*** output of 1st convolution layer  ***/
// for kernel of n*m in size, the input image loses (n-1)x(m-1) in size
#define outputH_1c input_H-(kernel_H-1)
#define outputW_1c input_W-(kernel_W-1)
/*** output of subsampling or average pooling layer  ***/
// for kernel of n*m in size, the input  loses half of his size( wihth stride 2)
#define outputH_1p (outputH_1c) / 2
#define outputW_1p (outputW_1c) / 2
/*** output of 2nt convolution layer  ***/
#define outputH_2c 10
#define outputW_2c 10
/*** output of subsampling 2 or second average pooling layer  ***/
// for kernel of n*m in size, the input  loses half of his size( wihth stride 2)
#define outputH_2p (outputH_2c) / 2
#define outputW_2p (outputW_2c) / 2
/*** output of 3rd convolution layer  ***/
#define output_3c 1

/*** size of the final output ***/


/** function of activation **/
int relu_func(int x);
int sigmoid(int x) ;

/** print function **/ 
void affiche_input ( int  tab[input_H][input_W]);

/** 1st layer of convolution **/
void conv1_1(int input [input_H][input_W], int kernel [nb_filter_conv_1][kernel_H][kernel_W], int output [nb_filter_conv_1][outputH_1c][outputW_1c]);

/** 1st layer of pooling (average) / subsampling **/
void avg_pool_1(int input[outputH_1c][outputW_1c],int output_P[nb_filter_pool_1][outputH_1p][outputW_1p]);

/** 2nd layer of convolution **/ 
void conv1_2(int input [nb_layer][outputH_1p][outputW_1p], int kernel [nb_filter_conv_2][kernel_H][kernel_W], int output [nb_filter_conv_2][outputH_2c][outputW_2c]);

/** 2st layer of pooling (average) / subsampling**/ 
void avg_pool_2(int input[nb_layer][outputH_2c][outputW_2c],int output_P[nb_filter_pool_2][outputH_2p][outputW_2p]);

/** 3rd convolution layer **/ 
void conv1_3(int input [nb_layer][outputH_2p][outputW_2p], int kernel [nb_filter_conv_2][kernel_H][kernel_W], int output [nb_filter_conv_3][output_3c][output_3c]);
/** fully connected layer **/
void fully_C(int output [output_3c][output_3c][output_3c]);





#endif