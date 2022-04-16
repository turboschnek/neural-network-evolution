/**
 * Project:  evolution algorithm
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

  /**
   * array of arrays of pointers to all neurons in network
   * 
   * there is one less layer than above layers state,
   * because input neurons are not neurons
   */
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

/**
 * prints fully connected neural network to stdout
 */
void printfcnn(const Tfcnn* n);

/**
 * prints fully connected neural network to file
 */
void fprintfcnn(FILE* out, const Tfcnn* n);

/**
 * scans fully connected neural network from stdin
 * 
 * @return initialized fcnn or NULL for error
 */
Tfcnn* scanfcnn(void);

/**
 * scans fully connected neural network from file
 * 
 * @return initialized fcnn or NULL for error
 */
Tfcnn* fscanfcnn(FILE* in);

/**
 * returns array of outputs of neurons in layer (layerIndex) based on inputs
 * to this layer
 */
float* propagateLayer(const Tfcnn* net, const float* inputs, int layerIndex);

/**
 * returns array of outputs of neural network
 * 
 * @param inputs inputs of neural network
 */
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