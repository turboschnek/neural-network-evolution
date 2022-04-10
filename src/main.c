/**
 * Project:  perceptron
 * Author:   Jakub Urbanek
 * Year:     2022
 */


#include "perceptron.h"

#include <stdio.h>
#include <stdlib.h>

void neuronTest()
{
  Tneuron* n = initRandNeuron(2, -1, 1);
  printNeuron(n);

  float* inputs = malloc(n->inputCount * sizeof(float));
  
  printf("inputs:\n");
  for(int i = 0; i < n->inputCount; i++){
    if(scanf("%f", &inputs[i]) != 1){
      fprintf(stderr,"error while reading input");
      return;
    }
  }

  printf("output: %f\n\n", calcNeuronOutput(n, inputs));

  free(inputs);

  freeNeuron(n);
}

void sigmoidTest()
{
  printf("Sigmoid test:\n");
  printf("0    -> %f\n", sigmoid(0));
  printf("-0.5 -> %f\n", sigmoid(-0.5));
  printf("-1   -> %f\n", sigmoid(-1));
  printf("1    -> %f\n", sigmoid(1));
  printf("50   -> %f\n", sigmoid(50));
  printf("-50  -> %f\n", sigmoid(-50));
}


int main(){
  neuronTest();

  sigmoidTest();
}