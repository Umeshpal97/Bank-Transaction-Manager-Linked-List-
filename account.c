#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

struct Account* head = NULL;
int accCounter = 1000;

struct Account* findAccount(int accNo) {
    struct Account* temp = head;
    while (temp != NULL) {
        if (temp->accNumber == accNo)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void createAccount() {
    struct Account* newAcc = (struct Account*)malloc(sizeof(struct Account));

    newAcc->accNumber = ++accCounter;
    newAcc->balance = 0;
    newAcc->tHead = NULL;
    newAcc->next = NULL;

    printf("Enter Name: ");
    scanf(" %[^\n]", newAcc->name);

    if (head == NULL) {
        head = newAcc;
    } else {
        struct Account* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newAcc;
    }

    printf("Account Created! Acc No: %d\n", newAcc->accNumber);
}

void deposit() {
    int accNo;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    struct Account* acc = findAccount(accNo);

    if (!acc) {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Amount: ");
    scanf("%f", &amount);

    acc->balance += amount;
    addTransaction(acc, "Deposit", amount);

    printf("Deposited Successfully!\n");
}

void withdraw() {
    int accNo;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    struct Account* acc = findAccount(accNo);

    if (!acc) {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Amount: ");
    scanf("%f", &amount);

    if (amount > acc->balance) {
        printf("Insufficient Balance!\n");
        return;
    }

    acc->balance -= amount;
    addTransaction(acc, "Withdraw", amount);

    printf("Withdraw Successful!\n");
}

void showBalance() {
    int accNo;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    struct Account* acc = findAccount(accNo);

    if (!acc) {
        printf("Account Not Found!\n");
        return;
    }

    printf("Name: %s\nBalance: %.2f\n", acc->name, acc->balance);
}

void showHistory() {
    int accNo;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    struct Account* acc = findAccount(accNo);

    if (!acc) {
        printf("Account Not Found!\n");
        return;
    }

    struct Transaction* temp = acc->tHead;

    if (!temp) {
        printf("No Transactions!\n");
        return;
    }

    printf("\n--- Transaction History ---\n");
    while (temp != NULL) {
        printf("%s : %.2f | %s\n", temp->type, temp->amount, temp->datetime);
        temp = temp->next;
    }
}