#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"

struct Account {
    int accNumber;
    char name[50];
    float balance;
    struct Transaction* tHead;
    struct Account* next;
};

void createAccount();
void deposit();
void withdraw();
void showBalance();
void showHistory();
struct Account* findAccount(int accNo);

#endif