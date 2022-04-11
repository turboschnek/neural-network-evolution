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
  Tneuron*** neuron;

} Tfcnn;

/**
 * intits random fully connected neural network of given size
 */
Tfcnn* initRandNeuralNet(int layerCount, int* neuronsInLayersCount);


#endif