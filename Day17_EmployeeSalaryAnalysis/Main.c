#include <stdio.h>
int main() {
    char name[50], reg[20], section[10];
    float salary[10], total = 0, avg, temp, high, low;
    int n, i, j, choice, above, below;
    printf("Enter Student Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Registration Number: ");
    scanf("%s", reg);
    printf("Enter Section: ");
    scanf("%s", section);
    printf("Enter number of employees: ");
    scanf("%d", &n);
    printf("Enter salaries:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &salary[i]);
        total += salary[i];
    }
    avg = total / n;
    do {
        printf("\n1.All Salaries\n2.Total & Average\n3.Highest & Lowest\n4.Above/Below Avg\n5.Sorted Salaries\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            for (i = 0; i < n; i++)
                printf("%.2f\n", salary[i]);
        }
        else if (choice == 2) {
            printf("Total = %.2f\nAverage = %.2f\n", total, avg);
        }
        else if (choice == 3) {
            high = low = salary[0];
            for (i = 1; i < n; i++) {
                if (salary[i] > high) high = salary[i];
                if (salary[i] < low) low = salary[i];
            }
            printf("Highest = %.2f\nLowest = %.2f\n", high, low);
        }
        else if (choice == 4) {
            above = below = 0;
            for (i = 0; i < n; i++) {
                if (salary[i] > avg) above++;
                else if (salary[i] < avg) below++;
            }
            printf("Above Avg = %d\nBelow Avg = %d\n", above, below);
        }
        else if (choice == 5) {
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (salary[j] > salary[j + 1]) {
                        temp = salary[j];
                        salary[j] = salary[j + 1];
                        salary[j + 1] = temp;
                    }
                }
            }
            printf("Sorted Salaries:\n");
            for (i = 0; i < n; i++)
                printf("%.2f\n", salary[i]);
        }
        else if (choice == 6) {
            printf("\nSubmitted by: %s | Reg No: %s | Section: %s\n", name, reg, section);
            printf("Challenge Day 17 - Code2Grow Program\n");
        }
    } while (choice != 6);
    return 0;
}
