#include <stdio.h>
int main() {
    int prices[5] = {50, 30, 80, 120, 60};  // Fixed menu prices
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int totalQty[5] = {0};  // To track how many of each item sold
    int numCustomers;
    int totalRevenue = 0, totalItemsSold = 0;
    printf("========== Café Order Management System ==========\n");
    printf("\nMenu:\n");
    printf("Item No\tItem Name\tPrice (₹)\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%-10s\t%d\n", i + 1, items[i], prices[i]);
    }
    printf("\nEnter total number of customers (max 10): ");
    scanf("%d", &numCustomers);
    for (int c = 1; c <= numCustomers; c++) {
        int numItems;
        int customerTotal = 0;
        printf("\n--- Customer %d ---\n", c);
        printf("Enter number of items: ");
        scanf("%d", &numItems);
        for (int j = 0; j < numItems; j++) {
            int itemNo, qty;
            printf("Enter item number and quantity: ");
            scanf("%d %d", &itemNo, &qty);
            customerTotal += prices[itemNo - 1] * qty;
            totalQty[itemNo - 1] += qty;
            totalItemsSold += qty;
        }
        printf("Total Bill for Customer %d: ₹%d\n", c, customerTotal);
        totalRevenue += customerTotal;
    }
    int mostOrdered = 0, leastOrdered = 0;
    for (int i = 1; i < 5; i++) {
        if (totalQty[i] > totalQty[mostOrdered])
            mostOrdered = i;
        if (totalQty[i] < totalQty[leastOrdered])
            leastOrdered = i;
    }
    printf("\n========== Café Summary ==========\n");
    printf("Total Revenue: ₹%d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItemsSold);
    printf("Most Ordered Item: %s\n", items[mostOrdered]);
    printf("Least Ordered Item: %s\n", items[leastOrdered]);
    printf("==================================\n");
    return 0;
}
