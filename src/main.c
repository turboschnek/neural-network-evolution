/**
 * Project:  neural network
 * Author:   Jakub Urbanek
 * Year:     2022
 */


#include "fcnn.h"
#include "neuron.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void neuronTest()
{
  Tneuron* n = initRandNeuron(2, -1, 1);
  printNeuron(n);

  float inputs[2] = {1, 1};

  printf("output: %f\n\n", calcNeuronOutput(n, inputs));

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


void fcnnTest()
{
  int temp[3] = {10, 2, 1};
  Tfcnn* n = initRandfcnn(3, temp);

  printfcnn(n);

  freefcnn(n);
}


int main(){
  srand(time(NULL));
  //neuronTest();
  //sigmoidTest();
  fcnnTest();
}