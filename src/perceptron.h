/**
 * Project:  perceptron
 * Author:   Jakub Urbanek
 * Year:     2022
 */

#ifndef __MODULE_PERCEPTRON_H
#define __MODULE_PERCEPTRON_H

#include <stdio.h>

typedef struct {
  int inputCount;

  float* weights;

  float bias;

} Tneuron;

/**
 * returns pointer to Tneuron initialized with
 * weights and bias in parameters
 */
Tneuron* initNeuron(int inputCount, float* weights, float bias);

void freeNeuron(Tneuron* n);

void printNeuron(const Tneuron* n);

void fprintNeuron(FILE* out, const Tneuron* n);

Tneuron* scanNeuron(void);

Tneuron* fscanNeuron(FILE* in);

/**
 * y = 1/(1+e^(-x))
 * https://en.wikipedia.org/wiki/Logistic_function
 */
float sigmoid(float x);

float calcNeuronOutput(const Tneuron* n, float* inputs);

#endif
