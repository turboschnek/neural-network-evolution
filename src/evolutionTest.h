/**
 * Project:  evolution algorithm
 * Author:   Jakub Urbanek
 * Year:     2022
 */

#ifndef __MODULE_EVOLUTION_TEST_H
#define __MODULE_EVOLUTION_TEST_H

#include "fcnn.h"

#include <stdbool.h>


void insertSort(Tfcnn** population,
                int populationCount,
                float* keys,
                bool increasing);

float calculateErrorRate(const Tfcnn* net, float* testIn, float* testOut);

int lineToTestInOut(char* line, Tfcnn** population,
                    float* testIn, float* testOut);

/**
 * returns error rate of best net
 */
float sortByFitness(Tfcnn** population, int populationCount, FILE* file);

void evolutionTest(void);

#endif
