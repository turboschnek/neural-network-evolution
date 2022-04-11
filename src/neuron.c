/**
 * Project:  neural network
 * Author:   Jakub Urbanek
 * Year:     2022
 */

#include "neuron.h"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


Tneuron* initNeuron(int inputCount, float* weights, float bias)
{
  Tneuron *n = malloc(sizeof(Tneuron));
  n->inputCount = inputCount;
  n->weights = malloc(n->inputCount * sizeof(float));
  for(int i = 0; i < n->inputCount; ++i){
    n->weights[i] = weights[i];
  }
  n->bias = bias;
  return n;
}


Tneuron* initRandNeuron(int inputCount, float min, float max)
{
  srand(time(NULL));
  Tneuron *n = malloc(sizeof(Tneuron));
  n->inputCount = inputCount;
  n->weights = malloc(n->inputCount * sizeof(float));
  for(int i = 0; i < n->inputCount; ++i){
    n->weights[i] = (((float)rand()/(float)(RAND_MAX)) * (max-min)) + min;
  }
  n->bias = (((float)rand()/(float)(RAND_MAX)) * (max-min)) + min;
  return n;
}


void freeNeuron(Tneuron* n)
{
  free(n->weights);
  free(n);
}


void printNeuron(const Tneuron* n)
{
  fprintNeuron(stdout, n);
}


void fprintNeuron(FILE* out, const Tneuron* n)
{
  fprintf(out, "%d\n", n->inputCount);
  for(int i = 0; i < n->inputCount; ++i){
    fprintf(out, "%f ", n->weights[i]);
  }
  fprintf(out, "\n%f\n", n->bias);
}


Tneuron* scanNeuron(void)
{
  return fscanNeuron(stdin);
}


Tneuron* fscanNeuron(FILE* in)
{
  Tneuron *n = malloc(sizeof(Tneuron));
  if(fscanf(in, "%d", &n->inputCount) != 1){
    free(n);
    return NULL;
  }
  n->weights = malloc(n->inputCount * sizeof(float));
  for(int i = 0; i < n->inputCount; ++i){
    if(fscanf(in, "%f", &n->weights[i]) != 1){
      freeNeuron(n);
      return NULL;
    }
  }
  if(fscanf(in, "%f", &n->bias) != 1){
    freeNeuron(n);
    return NULL;
  }

  return n;
}


float sigmoid(float x)
{
  return 1 / (1 + exp(-x));
}


float calcNeuronOutput(const Tneuron* n, float* inputs)
{
  float sum = 0;
  for(int i = 0; i < n->inputCount; i++){
    sum += inputs[i] * n->weights[i];
  }
  return sigmoid(sum * n->bias);
}
