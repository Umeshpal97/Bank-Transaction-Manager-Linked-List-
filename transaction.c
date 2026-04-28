#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "account.h"

void getDateTime(char* buffer) {
    time_t t;
    time(&t);
    struct tm* tm_info = localtime(&t);
    strftime(buffer, 50, "%d-%m-%Y %H:%M:%S", tm_info);
}

void addTransaction(struct Account* acc, char type[], float amount) {
    struct Transaction* newNode = (struct Transaction*)malloc(sizeof(struct Transaction));

    strcpy(newNode->type, type);
    newNode->amount = amount;
    getDateTime(newNode->datetime);
    newNode->next = NULL;

    if (acc->tHead == NULL) {
        acc->tHead = newNode;
    } else {
        struct Transaction* temp = acc->tHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}