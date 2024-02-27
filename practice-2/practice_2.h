//
// Created by MSI on 27.02.2024.
//

#ifndef PROGRAMMING_PRACTICE_2_H
#define PROGRAMMING_PRACTICE_2_H

typedef struct Laptop;

Laptop* InitDynamic(char* firmName, char* CPUModel, int hasGamingGPU, char* tag);

int isDataCorrect(Laptop*& laptop);

Laptop* InitFromSource(Laptop*& sourceLaptop, char* sourceTag, char* targetTag);

int initLaptop(Laptop*& laptop, char firmName[], char CPUModel[], int hasGamingGPU, char* tag);

void printData(Laptop*& laptop, char tag[]);

int updateLaptopCPUModelValue(Laptop* laptop, char* CPUModel, char* tag, char* oldVersion);
int updateLaptopFirmNameValue(Laptop* laptop, char* firmName);
int updateLaptopHasGamingGPUValue(Laptop* laptop, int hasGamingGPU);


int updateLaptopHasGamingGPU(Laptop*& laptop, int hasGamingGPU);

int test();

#endif //PROGRAMMING_PRACTICE_2_H
