/**
 * Project:  neural network
 * Author:   Jakub Urbanek
 * Year:     2022
 */


#ifndef __MODULE_FULLY_CONNECTED_NEURAL_NET_H
#define __MODULE_FULLY_CONNECTED_NEURAL_NET_H


#include "neuron.h"


//fully connected neural network
typedef struct
{
  //nuber of layers including input and output layer
  int layerCount;

  //number of neurons for each layer
  int* neuronsInLayersCount;

  //pointers to all neurons in network
  Tneuron*** neurons;

} Tfcnn;

/**
 * intits random fully connected neural network of given size
 */
Tfcnn* initRandfcnn(int layerCount, int* neuronsInLayersCount);

/**
 * frees fully connected neural network
 */
void freefcnn(Tfcnn* net);

void printfcnn(const Tfcnn* n);

void fprintfcnn(FILE* out, const Tfcnn* n);

Tfcnn* scanfcnn(void);

Tfcnn* fscanfcnn(FILE* in);

float* propagateLayer(Tfcnn* net, float* inputs, int layerIndex);

float* predict(Tfcnn* net, float* inputs);

#endif