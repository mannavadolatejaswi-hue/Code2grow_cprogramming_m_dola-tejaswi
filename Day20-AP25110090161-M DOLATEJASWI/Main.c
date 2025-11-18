#include <stdio.h>
#define MAX 20
int productID[MAX];
int quantity[MAX];
int price[MAX];
int count = 0;
void addProduct();
void searchProduct();
void updateQuantity();
void rackReport();
void calculateStockValue();
void displayAll();
int rack[3][3];
int main() {
    int choice;
    int temp[3][3] = { {5, 3, 7},
                       {2, 9, 1},
                       {6, 4, 8} };
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            rack[i][j] = temp[i][j];
    while (1) {
        printf("\n===== SMART WAREHOUSE MENU =====\n");
        printf("1. Add Product\n");
        printf("2. Search Product (By ID)\n");
        printf("3. Update Quantity\n");
        printf("4. Generate Rack Report (2D Array)\n");
        printf("5. Calculate Stock Value\n");
        printf("6. Display All Products\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addProduct(); break;
            case 2: searchProduct(); break;
            case 3: updateQuantity(); break;
            case 4: rackReport(); break;
            case 5: calculateStockValue(); break;
            case 6: displayAll(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
void addProduct() {
    if (count >= MAX) {
        printf("Storage full!\n");
        return;
    }
    int id, qty, pr;
    printf("Enter Product ID: ");
    scanf("%d", &id);  
          for (int i = 0; i < count; i++) {
        if (productID[i] == id) {
            printf("Duplicate ID not allowed!\n");
            return;
        }
    }
    printf("Enter Quantity: ");
    scanf("%d", &qty);
    printf("Enter Price: ");
    scanf("%d", &pr);
    if (qty <= 0 || pr <= 0) {
        printf("Quantity & Price must be positive!\n");
        return;
    }
    productID[count] = id;
    quantity[count] = qty;
    price[count] = pr;
    count++;
    printf("Product added successfully!\n");
}
void searchProduct() {
    int id, found = 0;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (productID[i] == id) {
            printf("Product Found!\n");
            printf("ID: %d  Quantity: %d  Price: %d\n",
                productID[i], quantity[i], price[i]);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Not Found!\n");
}
void updateQuantity() {
    int id, opt, val;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (productID[i] == id) {
            printf("1. Increase stock\n2. Decrease stock\n");
            scanf("%d", &opt);
            printf("Enter amount: ");
            scanf("%d", &val);
            if (opt == 1) {
                quantity[i] += val;
            }
            else if (opt == 2) {
                if (quantity[i] - val >= 0)
                    quantity[i] -= val;
                else
                    printf("Error! Quantity cannot go negative.\n");
            }
            printf("Updated quantity: %d\n", quantity[i]);
            return;
        }
    }
    printf("Product not found!\n");
}
void rackReport() {
    int max = rack[0][0], min = rack[0][0];
    int maxR = 0, maxC = 0, minR = 0, minC = 0;
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = rack[i][j];
            total += val;
            if (val > max) {
                max = val;
                maxR = i;
                maxC = j;
            }
            if (val < min) {
                min = val;
                minR = i;
                minC = j;
            }
        }
    }
    printf("\nRack Report:\n");
    printf("Max Stock: %d at (%d, %d)\n", max, maxR, maxC);
    printf("Min Stock: %d at (%d, %d)\n", min, minR, minC);
    printf("Total Items in Racks: %d\n", total);
}
void calculateStockValue() {
    if (count == 0) {
        printf("No products available!\n");
        return;
    }
    int maxVal = 0, minVal = 999999;
    int maxIndex = 0, minIndex = 0;
    int totalValue = 0;
    for (int i = 0; i < count; i++) {
        int value = quantity[i] * price[i];
        printf("ID: %d  Value: %d\n", productID[i], value);
        if (value > maxVal) {
            maxVal = value;
            maxIndex = i;
        }
        if (value < minVal) {
            minVal = value;
            minIndex = i;
        }
        totalValue += value;
    }
    printf("\nHighest Value Product: ID %d (Value %d)\n",
           productID[maxIndex], maxVal);
    printf("Lowest Value Product: ID %d (Value %d)\n",
           productID[minIndex], minVal);
    printf("Total Warehouse Value: %d\n", totalValue);
}
void displayAll() {
    if (count == 0) {
        printf("No products to display!\n");
        return;
    }
    printf("\nID\tQuantity\tPrice\tStockValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t\t%d\t%d\n",
            productID[i],
            quantity[i],
            price[i],
            quantity[i] * price[i]);
    }
}
