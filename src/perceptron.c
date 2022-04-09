/**
 * Project:  perceptron
 * Author:   Jakub Urbanek
 * Year:     2022
 */

#include "perceptron.h"


#include <stdio.h>
#include <stdlib.h>


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
