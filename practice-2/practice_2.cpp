#include "practice_2.h"
#include <iostream>
#include <strings.h>

#define MAX_FIRM_NAME_LENGTH 20
#define MAX_CPU_NAME_LENGTH 30


Laptop *InitStatic(char *firmName, char *CPUModel, int hasGamingGPU)
{
    auto *newLaptop = (Laptop *) malloc(sizeof(Laptop));
    if (newLaptop == NULL)
        return NULL;

    newLaptop->hasGamingGPU = hasGamingGPU;
    strncpy(newLaptop->CPUModel, CPUModel, MAX_CPU_NAME_LENGTH);
    strncpy(newLaptop->firmName, firmName, MAX_FIRM_NAME_LENGTH);
    return newLaptop;
}

Laptop *InitDynamic(char *firmName, char *CPUModel, int hasGamingGPU)
{
    auto *newLaptop = (Laptop *) malloc(sizeof(Laptop));
    if (newLaptop == NULL)
        return NULL;

    newLaptop->hasGamingGPU = hasGamingGPU;
    strncpy(newLaptop->CPUModel, CPUModel, MAX_CPU_NAME_LENGTH);
    strncpy(newLaptop->firmName, firmName, MAX_FIRM_NAME_LENGTH);
    return newLaptop;
}

Laptop* InitFromSource(Laptop* sourceLaptop, Laptop* targetLaptop)
{
    strncpy(targetLaptop->firmName, sourceLaptop->firmName, MAX_FIRM_NAME_LENGTH);
    strncpy(targetLaptop->CPUModel, sourceLaptop->CPUModel, MAX_CPU_NAME_LENGTH);
    targetLaptop->hasGamingGPU=sourceLaptop->hasGamingGPU;
    return targetLaptop;
}

int dropStructure(Laptop* laptop) {
    free(laptop);
    return 0;
}

int isDataCorrect(Laptop *&laptop)
{
    if (strlen(laptop->CPUModel) > MAX_CPU_NAME_LENGTH)
        return 1;
    if (strlen(laptop->firmName) > MAX_FIRM_NAME_LENGTH)
        return 2;
    if (laptop->hasGamingGPU < 0 || laptop->hasGamingGPU > 1)
        return 3;
    return 0;
}

void printData(Laptop*& laptop, char tag[])
{
    printf("\n---------- %s ----------", tag);
    printf("\nLaptop's firmName: %s", laptop->firmName);
    printf("\nLaptop's CPU model: %s", laptop->CPUModel);
    printf("\nIs Laptop has gaming GPU: %d", laptop->hasGamingGPU);
    printf("\n==============================");
}

int updateLaptopCPUModelValue(Laptop *laptop, char *CPUModel, char *tag, char *oldVersion)
{
    printf("\nupdating %s \"%s\"->\"%s\"", tag, oldVersion, CPUModel);
    strncpy(laptop->CPUModel, CPUModel, MAX_CPU_NAME_LENGTH);
    return isDataCorrect(laptop);
}

int updateLaptopFirmNameValue(Laptop *laptop, char *firmName)
{
    strncpy(laptop->firmName, firmName, MAX_FIRM_NAME_LENGTH);
    return isDataCorrect(laptop);
}

int updateLaptopHasGamingGPUValue(Laptop *laptop, int hasGamingGPU)
{
    laptop->hasGamingGPU = hasGamingGPU;
    return isDataCorrect(laptop);
}

int testProgram(
        Laptop* laptop1,
        Laptop* laptop2,
        char *laptop1_cpu_update,
        char *laptop1_tag,
        char *laptop2_tag
)
{
    printData(laptop1, laptop1_tag);
    printData(laptop2, laptop2_tag);

    laptop2 = InitFromSource(laptop1, laptop2);
    updateLaptopCPUModelValue(laptop1, laptop1_cpu_update, laptop1_tag, laptop1->CPUModel);

    printData(laptop1, laptop1_tag);
    printData(laptop2, laptop2_tag);

    return 0;
}

int test()
{
    char laptop1_firm[] = "Apple";
    char laptop1_cpu[] = "APPLE M1";
    int laptop1_hasGamingGPU = 0;
    char laptop2_firm[] = "Lenovo";
    char laptop2_cpu[] = "Ryzen 5";
    int laptop2_hasGamingGPU = 1;
    char laptop1_cpu_update[] = "Lenovo";

    char laptop1_tag[] = "Laptop 1";
    char laptop2_tag[] = "Laptop 2";

    printf("Stack part:");
    auto *laptop1 = InitStatic(laptop1_firm, laptop1_cpu, laptop1_hasGamingGPU);
    auto *laptop2 = InitStatic(laptop2_firm, laptop2_cpu, laptop2_hasGamingGPU);
    testProgram(
            laptop1,
            laptop2,
            laptop1_cpu_update,
            laptop1_tag,
            laptop2_tag
    );

    dropStructure(laptop1);
    dropStructure(laptop2);

    printf("\nDynamic part:");
    Laptop *laptopDynamic1 = InitDynamic(laptop1_firm, laptop1_cpu, laptop1_hasGamingGPU);
    Laptop *laptopDynamic2 = InitDynamic(laptop2_firm, laptop2_cpu, laptop2_hasGamingGPU);

    testProgram(
            laptopDynamic1,
            laptopDynamic2,
            laptop1_cpu_update,
            laptop1_tag,
            laptop2_tag
    );

    dropStructure(laptopDynamic1);
    dropStructure(laptopDynamic2);

    return 0;
}