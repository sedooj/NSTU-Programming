#include <iostream>
#include <random>
#include <ctime>
#include "lab_1.h"

typedef struct Item
{
    int value;
    struct Item *nextItem;
};

Item* getItemDataByPosition(int position, struct Item*& head) {
    if (position < 0) {
        printf("\nSend a correct position.");
        return NULL;
    }
    if (position == 0)
    {
        return head;
    }
    Item *item = head;
    int currentPos = 0;
    while (item != NULL && currentPos < position)
    {
        item = item->nextItem;
        currentPos++;
    }

    if (item == NULL)
    {
        return NULL;
    } else
    {
        return item;
    }
}

void insertDigitToPosition(int digit, int position, struct Item *&head)
{
    if (position < 0) {
        printf("\nSend a correct position.");
        return;
    }
    struct Item *newItem = (struct Item *) malloc(sizeof(struct Item));
    newItem->value = digit;
    newItem->nextItem = NULL;

    if (position == 0)
    {
        newItem->nextItem = head;
        head = newItem;
        return;
    }

    Item *current = head;
    for (int i = 0; i < position - 1 && current != NULL; ++i)
    {
        if (current->nextItem != NULL) {
            current = current->nextItem;
        }
    }

    if (current != NULL)
    {
        newItem->nextItem = current->nextItem;
        current->nextItem = newItem;
    } else
    {
        printf("\nPosition index of bound.");
    }
}

void displayList(Item *head)
{
    printf("\n");
    Item *tempItem = head;
    while (tempItem != NULL)
    {
        printf("%d ", tempItem->value);
        tempItem = tempItem->nextItem;
    }
}

Item *generateItems(int count)
{
    Item *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        int randDigit = rand() % 90 + 10;
        insertDigitToPosition(randDigit, i, head);
    }
    return head;
}

int deleteItemByPosition(int position, struct Item *&head)
{
    if (position < 0) {
        printf("\nSend a correct position.");
        return -3;
    }
    if (head == NULL)
    {
        printf("List is empty.");
        return -1;
    }
    if (position == 0)
    {
        Item *tempItem = head;
        head = head->nextItem;
        delete tempItem;
        return 0;
    }

    Item *previousItem = NULL;
    Item *currentItem = head;
    int currentPosition = 0;

    while (currentItem != NULL && currentPosition < position)
    {
        previousItem = currentItem;
        currentItem = currentItem->nextItem;
        currentPosition++;
    }
    if (currentItem == NULL)
    {
        printf("\nIndex of bounds.");
        return -2;
    }
    if (previousItem)
        previousItem->nextItem = currentItem->nextItem;
    delete currentItem;
    return 0;
}

Item *replaceItems(int targetValue, int newValue, struct Item *&head)
{
    Item *lastReplacement = NULL;
    bool isReplaced = false;
    do
    {
        isReplaced = false;
        Item *currentItem = head;
        while (currentItem != nullptr)
        {
            if (currentItem->value == targetValue)
            {
                currentItem->value = newValue;
                lastReplacement = currentItem;
                isReplaced = true;
            }
            currentItem = currentItem->nextItem;
        }
    } while (isReplaced);
    return lastReplacement;
}

int getItemsCount(Item *head)
{
    int count = 0;
    Item *currentItem = head;
    while (currentItem != NULL)
    {
        currentItem = currentItem->nextItem;
        count++;
    }
    return count;
}

void copyReversedIntoAList(struct Item* sourceListHead, struct Item*& targetListHead) {
    if (sourceListHead == NULL)
        return;

    copyReversedIntoAList(sourceListHead->nextItem, targetListHead);

    Item* newItem = new Item();
    newItem->value = sourceListHead->value;
    newItem->nextItem = NULL;

    if (targetListHead == NULL) {
        targetListHead = newItem;
    } else {
        Item* current = targetListHead;
        while (current->nextItem != NULL) {
            current = current->nextItem;
        }
        current->nextItem = newItem;
    }
}

int show()
{
    /**
     * Generation a new list with random digits
     * */
    int itemsCountForGenerate = 1;
    printf("Send items count to generate: ");
    scanf("%d", &itemsCountForGenerate);
    Item *list_1 = generateItems(itemsCountForGenerate);
    displayList(list_1);

    /**
     * Input a targetValue and newValue for replacement
     * */
    int target;
    int newValue;
    printf("\nSend a target digit to replace in the list: ");
    scanf("%d", &target);
    printf("Send a new value for a target %d: ", target);
    scanf("%d", &newValue);

    /**
     * Replacement
     * */
    printf("\nLast replacement address: %p", replaceItems(target, newValue, list_1));
    printf("\nList with replacements:");
    displayList(list_1);

    /**
     * Generation a second list with ramdom digits
     * */
    printf("\nGenerating second list...");
    Item *list_2 = generateItems(itemsCountForGenerate);
    displayList(list_2);
    printf("\nReversing...");

    /**
     * Copy list_2 with reverse to list_1
     * */
    copyReversedIntoAList(list_2, list_1);
    displayList(list_1);
    delete list_1;
    delete list_2;

    return 0;
}
