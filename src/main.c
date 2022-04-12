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
  int temp[4] = {4, 2560, 1000, 10};
  Tfcnn* n = initRandfcnn(4, temp);

  FILE* log;
  log = fopen("log.txt", "w");
  fprintfcnn(log, n);
  fclose(log);

  log = fopen("log.txt", "r");
  Tfcnn* n2 =fscanfcnn(log);
  fclose(log);

  log = fopen("log2.txt", "w");
  fprintfcnn(log, n2);
  fclose(log);

  float inp[4] = {1, 0, 0.5, 0.1};
  float* output = predict(n, inp);

  for(int i = 0; i < temp[3]; ++i){
    printf("%d -> %f\n", i, output[i]);
  }

  free(output);

  freefcnn(n2);
  freefcnn(n);
}


int main(){
  srand(time(NULL));
  //neuronTest();
  //sigmoidTest();
  fcnnTest();
}