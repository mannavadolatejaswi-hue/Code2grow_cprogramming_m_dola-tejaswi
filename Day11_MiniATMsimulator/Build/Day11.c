#include<stdio.h>
int main()
{
    int choice, transactions = 0;
    float balance = 10000, amount;
    printf("===== Mini ATM Simulator =====\n");
    printf("Initial Balance: ₹%.2f\n", balance);
    while (transactions < 5) {
        printf("\n1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Your Current Balance: %.2f\n", balance);
            transactions++;
        } 
        else if (choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Amount Deposited Successfully!\n");
            } else {
                printf("Invalid amount. Try again.\n");
            }
            transactions++;
        } 
        else if (choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && balance - amount >= 500) {
                balance -= amount;
                printf("Withdrawal Successful! Remaining Balance: ₹%.2f\n", balance);
            } else if (amount <= 0) {
                printf("Invalid amount. Try again.\n");
            } else {
                printf("Insufficient Balance! Minimum ₹500 must remain.\n");
            }
            transactions++;
        } 
        else if (choice == 4) {
            printf("Thank you for banking with us!\n");
            break;
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }
        if (transactions >= 5) {
            printf("\nMaximum 5 transactions reached!\n");
            break;
        }
    }
    printf("\n===== Transaction Summary =====\n");
    printf("Total Transactions: %d\n", transactions);
    printf("Final Balance: ₹%.2f\n", balance);
    printf("Session Ended.\n");
    return 0;
}
