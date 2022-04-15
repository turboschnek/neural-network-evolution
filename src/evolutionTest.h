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

void sortByFitness(Tfcnn** population, int populationCount, FILE* file);

void evolutionTest(void);

#endif
