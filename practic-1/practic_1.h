//
// Created by MSI on 25.02.2024.
//

#ifndef PROGRAMMING_LAB_1_H
#define PROGRAMMING_LAB_1_H

typedef struct Laptop;

Laptop* Init(char firmName[], char CPUModel[], int hasGamingGPU);

int isDataCorrect(Laptop*& laptop);

Laptop* initFromSource(Laptop*& sourceLaptop);

int initLaptop(Laptop*& laptop, char firmName[], char CPUModel[], int hasGamingGPU);

void printData(Laptop*& laptop);

int updateLaptopData(Laptop*& laptop, char* CPUModel, char* firmName, int hasGamingGPU);

int updateLaptopHasGamingGPU(Laptop*& laptop, int hasGamingGPU);

int test();

#endif //PROGRAMMING_LAB_1_H
