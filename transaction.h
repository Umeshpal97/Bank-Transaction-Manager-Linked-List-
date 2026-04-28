#ifndef TRANSACTION_H
#define TRANSACTION_H

struct Transaction {
    char type[10];
    float amount;
    char datetime[50];
    struct Transaction* next;
};

void addTransaction(struct Account* acc, char type[], float amount);
void getDateTime(char* buffer);

#endif