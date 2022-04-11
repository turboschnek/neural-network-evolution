/**
 * Project:  neural network
 * Author:   Jakub Urbanek
 * Year:     2022
 */

#include "fcnn.h"
#include "neuron.h"

#include <stdlib.h>

#define MIN_RAND_WEIGHT -1.0
#define MAX_RAND_WEIGHT 1.0


Tfcnn* initRandfcnn(int layerCount, int* neuronsInLayersCount)
{
  //there are no neurons in first layer

  Tfcnn* n = malloc(sizeof(Tfcnn));
  n->layerCount = layerCount;
  n->neuronsInLayersCount = malloc(n->layerCount * sizeof(int));
  n->neurons = malloc((n->layerCount-1) * sizeof(Tneuron**));

  n->neuronsInLayersCount[0] = neuronsInLayersCount[0];
  for(int i = 1; i < n->layerCount; ++i){
    n->neuronsInLayersCount[i] = neuronsInLayersCount[i];

    n->neurons[i-1] = malloc(n->neuronsInLayersCount[i] * sizeof(Tneuron*));
    for(int j = 0; j < n->neuronsInLayersCount[i]; ++j){
      n->neurons[i-1][j] = initRandNeuron(n->neuronsInLayersCount[i-1],
                                          MIN_RAND_WEIGHT,
                                          MAX_RAND_WEIGHT);
    }
  }

  return n;
}


void freefcnn(Tfcnn* n)
{
  for(int i = 1; i < n->layerCount; ++i){
    for(int j = 0; j < n->neuronsInLayersCount[i]; ++j){
      freeNeuron(n->neurons[i-1][j]);
    }
    free(n->neurons[i-1]);
  }
  free(n->neuronsInLayersCount);
  free(n->neurons);
}

void printfcnn(const Tfcnn* n)
{
  fprintfcnn(stdout, n);
}


void fprintfcnn(FILE* out, const Tfcnn* n)
{
  for(int i = 1; i < n->layerCount; ++i){
    for(int j = 0; j < n->neuronsInLayersCount[i]; ++j){
      fprintNeuron(out, n->neurons[i-1][j]);
    }
  }
}
