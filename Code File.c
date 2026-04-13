#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float balance = 1000.0;
    float amount;

    // Security Variables
    int userId;
    int correctUserId = 1618;
    int pin;
    int correctPin = 1234;
    int authenticated = 0;

    printf("=== MIT Bank Security Login ===\n");
    
    // Login Verification Loop
    while (!authenticated) {
        printf("Enter User ID: ");
        scanf("%d", &userId);
        printf("Enter 4-digit PIN: ");
        scanf("%d", &pin);

        if (userId == correctUserId && pin == correctPin) {
            printf("\nLogin Successful!\n");
            authenticated = 1;
        } else {
            printf("\nInvalid User ID or PIN. Please try again.\n\n");
        }
    }

    // Main Menu
    while (1) {
        printf("\n*** MIT Bank - User ID: %d ***\n", userId);
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCurrent balance: ₹%.2f\n", balance);
                break;
            case 2:
                printf("\nEnter amount to deposit: ₹");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Balance after deposit: ₹%.2f\n", balance);
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 3:
                printf("\nEnter amount to withdraw: ₹");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("New balance is: ₹%.2f\n", balance);
                } else if (amount > balance) {
                    printf("Not enough funds.\n");
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 4:
                printf("\nThank you for using MIT Bank. Exiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}