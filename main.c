#include <stdio.h>
#include <stdlib.h>
#include "account.h"

int main() {
    int choice;

    while (1) {
        printf("\n=== Banking System ===\n");
        printf("1. Open New Account\n2. Deposit\n3. Withdraw\n4. Show Balance\n5. Transaction History\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: showBalance(); break;
            case 5: showHistory(); break;
            case 6: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
}