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
Tfcnn* initRandfcnn(int layerCount, const int* neuronsInLayersCount);

/**
 * frees fully connected neural network
 */
void freefcnn(Tfcnn* net);

void printfcnn(const Tfcnn* n);

void fprintfcnn(FILE* out, const Tfcnn* n);

Tfcnn* scanfcnn(void);

Tfcnn* fscanfcnn(FILE* in);

float* propagateLayer(const Tfcnn* net, const float* inputs, int layerIndex);

float* predict(const Tfcnn* net, const float* inputs);

/**
 * returns baby of mum and dad in parameters
 * 
 * @param mutationRareness 1 in $(mutationRareness) neurons gets randomized
 *  
 * @note mum and dad must have the number of layers and neurons in them
 */
Tfcnn* sex(const Tfcnn* dad, const Tfcnn* mum, int mutationRareness);

#endif