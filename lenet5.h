
#ifndef LENET5_H_
#define LENET5_H_

/*** number of filters   ***/
#define nb_filter_conv_1 1
#define nb_filter_pool_1 1
#define nb_filter_conv_2 16
#define nb_filter_pool_2 16
/*** dimension of image input   ***/
#define input_H 8
#define input_W 8
/*** dimension of filters (convolution)   ***/
#define kernel_H 3
#define kernel_W 3
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

// function of activation 
int relu_func(int x);
int sigmoid(int x) ;

// print function 
void affiche_input ( int  tab[input_H][input_W]);

// 1st layer of convolution 

void conv1_1(int input [input_H][input_W], int kernel [nb_filter_conv_1][kernel_H][kernel_W], int output [nb_filter_conv_1][outputH_1c][outputH_1c]);

// 1 st layer of pooling (average) / subsampling 

void avg_pool_1(int input[outputH_1c][outputW_1c],int output_P[nb_filter_pool_1][outputH_1p][outputW_1p]);





#endif