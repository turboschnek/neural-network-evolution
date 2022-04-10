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

/**
 * returns pointer to Tneuron initialized with
 * random weights and bias between min and max values
 */
Tneuron* initRandNeuron(int inputCount, float min, float max);

/**
 * frees neuron
 */
void freeNeuron(Tneuron* n);

/**
 * prints neuron in format:  
 * inputCount  
 * weights  
 * bias
 */
void printNeuron(const Tneuron* n);

/**
 * prints neuron to file in format:  
 * inputCount  
 * weights  
 * bias
 */
void fprintNeuron(FILE* out, const Tneuron* n);

/**
 * scans neuron in format:  
 * inputCount  
 * weights  
 * bias
 */
Tneuron* scanNeuron(void);

/**
 * scans neuron from file in format:  
 * inputCount  
 * weights  
 * bias
 */
Tneuron* fscanNeuron(FILE* in);

/**
 * y = 1/(1+e^(-x))
 * https://en.wikipedia.org/wiki/Logistic_function
 */
float sigmoid(float x);

float calcNeuronOutput(const Tneuron* n, float* inputs);

#endif
