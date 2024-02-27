//
// Created by MSI on 27.02.2024.
//

#ifndef PROGRAMMING_PRACTICE_2_H
#define PROGRAMMING_PRACTICE_2_H

#define MAX_FIRM_NAME_LENGTH 20
#define MAX_CPU_NAME_LENGTH 30

typedef struct Laptop
{

    char firmName[MAX_FIRM_NAME_LENGTH];
    char CPUModel[MAX_CPU_NAME_LENGTH];
    int hasGamingGPU;

} Laptop;

Laptop *InitStatic(char *firmName, char *CPUModel, int hasGamingGPU);

Laptop *InitDynamic(char *firmName, char *CPUModel, int hasGamingGPU);

int isDataCorrect(Laptop *&laptop);

Laptop *InitFromSource(Laptop *&sourceLaptop);

int initLaptop(Laptop *&laptop, char firmName[], char CPUModel[], int hasGamingGPU, char *tag);

void printData(Laptop *&laptop, char tag[]);

int updateLaptopCPUModelValue(Laptop *laptop, char *CPUModel, char *tag, char *oldVersion);

int updateLaptopFirmNameValue(Laptop *laptop, char *firmName);

int updateLaptopHasGamingGPUValue(Laptop *laptop, int hasGamingGPU);

int updateLaptopHasGamingGPU(Laptop *&laptop, int hasGamingGPU);

int test();

#endif //PROGRAMMING_PRACTICE_2_H
