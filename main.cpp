#include <iostream>
#include <random>

typedef struct Item
{
    int value;
    struct Item *nextItem;
};

Item *getItemAddressByPosition(int position, struct Item *&head)
{
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

int getItemValueByPosition(int position, struct Item *&head)
{
    if (position == 0)
    {
        return head->value;
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
        return item->value;
    }
}

Item *getNextItemValueByPosition(int position, struct Item *&head)
{
    if (position == 0)
    {
        return head->nextItem;
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
        return item->nextItem;
    }
}

void insertDigitToPosition(int digit, int position, struct Item *&head)
{
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
        current = current->nextItem;
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

int deleteItemByPosition(int position, Item *&head)
{
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

void displayList(Item *head)
{
    Item *tempItem = head;
    while (tempItem != NULL)
    {
        printf("%d ", tempItem->value);
        tempItem = tempItem->nextItem;
    }
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

void generateItems(int count, Item*& head) {
    for (int i = 0; i < count; i++) {
        int randDigit = rand() % 90 + 10;
        insertDigitToPosition(randDigit, i, head);
    }
    displayList(head);
}

int main()
{
    Item *head = NULL;

    return 0;
}
