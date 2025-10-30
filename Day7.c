#include <stdio.h>
int main() {
    int choice;
    float balance = 10000, amount, bonus;
    do {
        printf("\n1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                bonus = (amount > 25000) ? amount * 0.01 : 0;
                if (bonus > 0) printf("Bonus of ₹%.2f added!\n", bonus);
                balance += amount + bonus - 5;
                printf("Service charge ₹5 applied.\nUpdated Balance: ₹%.2f\n", balance);
            } else printf("Invalid amount!\n");
        }
        else if (choice == 2) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0) printf("Invalid amount!\n");
            else if (amount > balance) printf("Insufficient balance!\n");
            else {
                balance -= amount + 5;
                printf("Service charge ₹5 applied.\nUpdated Balance: ₹%.2f\n", balance);
            }
        }
        else if (choice == 3)
            printf("Current Balance: ₹%.2f\n", balance);
        else if (choice == 4)
            printf("Thank you for banking with us!\n");
        else
            printf("Invalid choice!\n");

    } while (choice != 4);

    return 0;
}