#include <stdio.h>
int main() {
    int totalCustomers;
    float totalRevenue = 0;
    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);
    for (int i = 1; i <= totalCustomers; i++) {
        int itemsCount;
        float customerTotal = 0;
        printf("\n-- Customer %d --\n", i);
        printf("Enter number of items: ");
        scanf("%d", &itemsCount);
        int j = 1;
        while (j <= itemsCount) {
            int code, qty;
            float price = 0;
            printf("Enter item code: ");
            scanf("%d", &code);
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if (code == 1)
                price = 80;
            else if (code == 2)
                price = 120;
            else if (code == 3)
                price = 150;
            else if (code == 4)
                price = 60;
            else if (code == 5)
                price = 50;
            else {
                printf("Invalid item code! Skipped.\n");
                j++;
                continue;
            }
            customerTotal += price * qty;
            j++;
        }
        printf("\n Customer %d Bill \n", i);
        printf("Item Menu (for reference):\n");
        printf("1. Sandwich - ₹80\n2. Burger - ₹120\n3. Pizza Slice - ₹150\n4. Coffee - ₹60\n5. Juice - ₹50\n");
        printf("\nTotal before discount = ₹%.2f\n", customerTotal);
        if (customerTotal > 250) {
            float discount = customerTotal * 0.10;
            customerTotal -= discount;
            printf("Discount (10%%) = ₹%.2f\n", discount);
        }
        printf("Final Bill = ₹%.2f\n", customerTotal);
        totalRevenue += customerTotal;
    }
    printf("\n Canteen Summary \n");
    printf("Total Customers Served: %d\n", totalCustomers);
    printf("Total Revenue: ₹%.2f\n", totalRevenue);
    return 0;
}