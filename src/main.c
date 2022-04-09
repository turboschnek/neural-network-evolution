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
  Tneuron* n = scanNeuron();
  printNeuron(n);
  freeNeuron(n);
}

int main(){
  neuronTest();
}