include <stdio.h>
int main() {
    int id[10], qty[10];
    float price[10];
    char name[10][20];
    int n, i, choice;
    printf("Enter number of products (max 10): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id[i]);
        printf("Name: ");
        scanf("%s", name[i]);
        printf("Quantity: ");
        scanf("%d", &qty[i]);
        printf("Price: ");
        scanf("%f", &price[i]);
    }
    do {
        printf("\n----- MENU -----\n");
        printf("1. Display all products\n");
        printf("2. Total inventory value\n");
        printf("3. Highest & lowest value product\n");
        printf("4. Search product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\n--- PRODUCT LIST ---\n");
            for (i = 0; i < n; i++) {
                printf("\nID: %d", id[i]);
                printf("\nName: %s", name[i]);
                printf("\nQuantity: %d", qty[i]);
                printf("\nPrice: %.2f\n", price[i]);
            }
        }
        else if (choice == 2) {
            float total = 0;
            for (i = 0; i < n; i++) {
                total += qty[i] * price[i];
            }
            printf("\nTotal Inventory Value = %.2f\n", total);
        }
        else if (choice == 3) {
            int hi = 0, lo = 0;
            for (i = 1; i < n; i++) {
                float val = qty[i] * price[i];
                float val_hi = qty[hi] * price[hi];
                float val_lo = qty[lo] * price[lo];
                if (val > val_hi)
                    hi = i;
                if (val < val_lo)
                    lo = i;
            }
            printf("\nHighest Value Product:\n");
            printf("ID: %d, Name: %s, Value: %.2f\n",
                   id[hi], name[hi], qty[hi] * price[hi]);
            printf("\nLowest Value Product:\n");
            printf("ID: %d, Name: %s, Value: %.2f\n",
                   id[lo], name[lo], qty[lo] * price[lo]);
            }
        else if (choice == 4) {
            int sid, found = 0;
            printf("Enter ID to search: ");
            scanf("%d", &sid);
            for (i = 0; i < n; i++) {
                if (id[i] == sid) {
                    printf("\nProduct Found!");
                    printf("\nID: %d", id[i]);
                    printf("\nName: %s", name[i]);
                    printf("\nQuantity: %d", qty[i]);
                    printf("\nPrice: %.2f\n", price[i]);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("\nProduct not found.\n");
        }
    } while (choice != 5);
    return 0;
}
