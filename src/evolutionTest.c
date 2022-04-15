/**
 * Project:  evolution algorithm
 * Author:   Jakub Urbanek
 * Year:     2022
 */

#include "fcnn.h"
#include "neuron.h"
#include "evolutionTest.h"

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>



#define NET_STRUCT_LAYER_COUNT 3

void insertSort(Tfcnn** population, int populationCount, float* keys, bool increasing)
{
  if(increasing){
    for(int i = 1; i < populationCount; i++){
      int j;
      float tempKey = keys[i];
      Tfcnn* tempNet = population[i];

      for(j = i-1; (j >= 0 && keys[j] > tempKey); j--){
        population[j+1] = population[j];
        keys[j+1] = keys[j];
      }
      population[j+1] = tempNet;
      keys[j+1] = tempKey;
    }
  } else {
    for(int i = 1; i < populationCount; i++){
      int j;
      float tempKey = keys[i];
      Tfcnn* tempNet = population[i];

      //keys[j] <= tempKey   would be stable, but slower
      for(j = i-1; (j >= 0 && keys[j] < tempKey); j--){
        population[j+1] = population[j];
        keys[j+1] = keys[j];
      }
      population[j+1] = tempNet;
      keys[j+1] = tempKey;
    }
  }
}

float calculateErrorRate(const Tfcnn* net, float* testIn, float* testOut)
{
  float* prediction = predict(net, testIn);
      
  float errorRate = 0;
  for(int i = 0;
      i < net->neuronsInLayersCount[net->layerCount - 1];
      ++i){
  
    //printf("P:%f\n", prediction[k]);
    errorRate += fabs(prediction[i] - testOut[i]);
  }

  free(prediction);

  return errorRate;
}

int lineToTestInOut(char* line, Tfcnn** population,
                    float* testIn, float* testOut)
{
  int i = 0;
  char *delim = " ";
  char *token = NULL;
  for (token = strtok(line, delim);
        token != NULL;
        token = strtok(NULL, delim))
  {
    char *unconverted;
    float value = strtof(token, &unconverted);
    if (!isspace(*unconverted) && *unconverted != 0)
    {
      fprintf(stderr, "ERROR: incorrect data in file");
      return -1;
    }
    
    if(i < population[0]->neuronsInLayersCount[0]){
      testIn[i++] = value;
    } else {
      testOut[(i++) - population[0]->neuronsInLayersCount[0]] = value;
    }
  }

  return 0;
}

void sortByFitness(Tfcnn** population, int populationCount, FILE* file)
{
  float* errorRates = calloc(populationCount, sizeof(float));


  const int maxLen = 100;
  char line[maxLen];
  float* testIn = malloc(population[0]->neuronsInLayersCount[0] *
                         sizeof(float));
  float* testOut = malloc(population[0]->neuronsInLayersCount[population[0]->layerCount - 1] *
                          sizeof(float));
  while (fgets(line, maxLen, file))
  {
    // Remove trailing newline
    line[strcspn(line, "\n")] = '\0';
    
    if(lineToTestInOut(line, population, testIn, testOut) == -1){
      free(errorRates);
      free(testIn);
      free(testOut);
      return;
    }
    
    
    for(int j = 0; j < populationCount; ++j){
      errorRates[j] = calculateErrorRate(population[j], testIn, testOut);
    }
  }

  insertSort(population, populationCount, errorRates, true);

  for(int i = 0; i < populationCount; ++i){
    printf("E:%f %d\n", errorRates[i], i);
  }

  free(errorRates);
  free(testIn);
  free(testOut);
}

void evolutionTest()
{
   
  const int netStructure[NET_STRUCT_LAYER_COUNT] = {2, 2, 1};

  const int populationCount = 100;  //number of networks in population
  
  const int maxGenerationCount = 100;  //number of generations in simulation
  
  const int matingFraction = 2;  // 1/matingFraction of nets has a baby

  const int mutationRareness = 2;  // 1 in mutationRareness neurons gets randomized

  //intit random population
  Tfcnn** population = malloc(populationCount * sizeof(Tfcnn*));
  for(int i = 0; i < populationCount; ++i){
    population[i] = initRandfcnn(NET_STRUCT_LAYER_COUNT, netStructure);
  }
  
  

  for(int generation = 0; generation < maxGenerationCount; ++generation){

    
    FILE* file = fopen("../src/test_dataset.txt", "r");
    if(file == NULL){
      fprintf(stderr, "ERROR: unable to open file");
      for(int i = 0; i < populationCount; ++i){
        freefcnn(population[i]);
      }
      free(population);
      return;
    }

    sortByFitness(population, populationCount, file);
    
    fclose(file);

    
    
    int elderyCount = populationCount/matingFraction;
    for(int i = elderyCount; i < populationCount; ++i){
      freefcnn(population[i]);

      population[i] = sex(population[(i - elderyCount) % elderyCount],
                                     population[(i+1) % elderyCount],
                                     mutationRareness);
    }
    printf("\nalphamale:\n");
    printfcnn(population[0]);
  }

  
  for(int i = 0; i < populationCount; ++i){
    freefcnn(population[i]);
  }
  free(population);
}