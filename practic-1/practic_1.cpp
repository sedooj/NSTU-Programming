#include <iostream>
#include "practic_1.h"

#define MAX_FIRM_NAME_LENGTH 20
#define MAX_CPU_NAME_LENGTH 30

typedef struct Laptop {

    char firmName[MAX_FIRM_NAME_LENGTH];
    char CPUModel[MAX_CPU_NAME_LENGTH];
    int hasGamingGPU;

} Laptop;

Laptop *Init(char* firmName, char* CPUModel, int hasGamingGPU) {
    Laptop *newLaptop = (Laptop *) malloc(sizeof(Laptop));
    if (newLaptop == NULL)
        return NULL;

    newLaptop->hasGamingGPU = 0;
    strncpy(newLaptop->CPUModel, "Intel Pentium", MAX_CPU_NAME_LENGTH);
    strncpy(newLaptop->firmName, "MSI", MAX_FIRM_NAME_LENGTH);
    return newLaptop;
}

Laptop* initFromSource(Laptop *&sourceLaptop) {
    Laptop* targetLaptop = new Laptop();
    strncpy(targetLaptop->firmName, sourceLaptop->firmName, MAX_FIRM_NAME_LENGTH);
    strncpy(targetLaptop->CPUModel, sourceLaptop->CPUModel, MAX_CPU_NAME_LENGTH);
    targetLaptop->hasGamingGPU = sourceLaptop->hasGamingGPU;
    return targetLaptop;
}

int isDataCorrect(Laptop *&laptop) {
    if (strlen(laptop->CPUModel) > MAX_CPU_NAME_LENGTH)
        return 1;
    if (strlen(laptop->firmName) > MAX_FIRM_NAME_LENGTH)
        return 2;
    if (laptop->hasGamingGPU < 0 || laptop->hasGamingGPU > 1)
        return 3;
    return 0;
}

void printData(Laptop *&laptop) {
    printf("\nLaptop's firmName: %s", laptop->firmName);
    printf("\nLaptop's CPU model: %s", laptop->CPUModel);
    printf("\nIs Laptop has gaming GPU: %d", laptop->hasGamingGPU);
}

int updateLaptopData(Laptop *&laptop, char *CPUModel, char *firmName, int hasGamingGPU) {
    strncpy(laptop->CPUModel, CPUModel, MAX_CPU_NAME_LENGTH);
    strncpy(laptop->firmName, firmName, MAX_FIRM_NAME_LENGTH);
    laptop->hasGamingGPU = hasGamingGPU;
    return isDataCorrect(laptop);
}

int initLaptop(Laptop *&laptop, char firmName[], char CPUModel[], int hasGamingGPU) {
    strncpy(laptop->CPUModel, CPUModel, MAX_CPU_NAME_LENGTH);
    strncpy(laptop->firmName, firmName, MAX_FIRM_NAME_LENGTH);
    laptop->hasGamingGPU = hasGamingGPU;
    return isDataCorrect(laptop);
}

int test() {
    Laptop *stackLaptop_1 = new Laptop();
    Laptop *stackLaptop_2 = new Laptop();

    char cpuName_laptop_1[] = "APPLE M1";
    char firmName_laptop_1[] = "Apple";
    char cpuName_laptop_2[] = "Ryzen 5";
    char firmName_laptop_2[] = "Lenovo";

    initLaptop(stackLaptop_1, firmName_laptop_1, cpuName_laptop_1, 0);
    initLaptop(stackLaptop_2, firmName_laptop_2, cpuName_laptop_2, 1);

    printData(stackLaptop_1);
    printData(stackLaptop_2);

    stackLaptop_2 = (stackLaptop_1);

    char _firmName_laptop_1[] = "Msi";
    // Todo: снова разбить функцию на несколько
    updateLaptopData(stackLaptop_1, _firmName_laptop_1, 1);

    printData(stackLaptop_1);
    printData(stackLaptop_2);




    return 0;
}