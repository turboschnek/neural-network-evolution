/**
 * Project:  evolution algorithm
 * Author:   Jakub Urbanek
 * Year:     2022
 */


#ifndef __MODULE_EVOLUTION_TEST_H
#define __MODULE_EVOLUTION_TEST_H

#include "fcnn.h"

#include <stdbool.h>

/**
 * population is sorted based on values of corresponding keys
 * 
 * @param increasing sorts in increasing order if true
 */
void insertSort(Tfcnn** population,
                int populationCount,
                float* keys,
                bool increasing);

/**
 * takes two arrays: testInputs and testOutputs
 * 
 * 
 * returns absolute value of (sum of differences in predicted
 * output and correct output (testOut) 
 */
float calculateErrorRate(const Tfcnn* net, float* testIn, float* testOut);


/**
 * takes string and fills testIn adn testOut based on input and output count of
 * firts member of population
 * 
 * @return 0 if OK else -1
 */
int lineToTestInOut(char* line, Tfcnn** population,
                    float* testIn, float* testOut);

/**
 * reads tests from file and sorts population based on
 * how well they do those tests
 * 
 * @return error rate of best net
 */
float sortByFitness(Tfcnn** population, int populationCount, FILE* file);


/**
 * tests evolution of network by forcing it to learn to do XOR
 */
void evolutionTest(void);

#endif
