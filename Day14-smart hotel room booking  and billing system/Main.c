#include <stdio.h>
int main() {
    int totalCustomers, i = 1;
    float totalRevenue = 0, highestBill = 0, lowestBill = 0;
    int totalRooms = 0;
    printf("===== Smart Hotel Room Booking System =====\n");
    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);
    while (i <= totalCustomers) 
    {
        char name[50];
        int roomType, days;
        char bf, wifi, gym;
        float rate = 0, baseFare, addService = 0, discount = 0, gst, finalBill;
        printf("\n-- Customer %d --\n", i);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite): ");
        scanf("%d", &roomType);
        printf("Enter number of days: ");
        scanf("%d", &days);
        printf("Breakfast (Y/N): ");
        scanf(" %c", &bf);
        printf("Wi-Fi (Y/N): ");
        scanf(" %c", &wifi);
        printf("Gym Access (Y/N): ");
        scanf(" %c", &gym);
        if (roomType == 1) rate = 2500;
        else if (roomType == 2) rate = 4000;
        else if (roomType == 3) rate = 6000;
        else rate = 0;
        baseFare = rate * days;
        if (bf == 'Y' || bf == 'y') addService += 300 * days;
        if (wifi == 'Y' || wifi == 'y') addService += 100 * days;
        if (gym == 'Y' || gym == 'y') addService += 200 * days;
        float subtotal = baseFare + addService;
        if (subtotal > 10000) discount = subtotal * 0.10;
        float totalBeforeGST = subtotal - discount;
        gst = totalBeforeGST * 0.12;
        finalBill = totalBeforeGST + gst;
        printf(" customer: %s", name);
        printf("\nBase Fare: ₹%f", baseFare);
        printf("\nAdditional Services: ₹%f", addService);
        printf("\nsubtotal: ₹%.2f\n",subtotal);
        printf("\nDiscount (10%%): ₹%f", discount);
        printf("\nGST (12%%): ₹%f", gst);
        printf("\nFinal Bill: ₹%f\n", finalBill);
        totalRevenue += finalBill;
        totalRooms++;
        if (i == 1 || finalBill > highestBill) highestBill = finalBill;
        if (i == 1 || finalBill < lowestBill) lowestBill = finalBill;
        i++;
    }
    printf("\n===== Hotel Summary =====\n");
    printf("Total Rooms Booked: %d\n", totalRooms);
    printf("Total Revenue: ₹%f\n", totalRevenue);
    printf("Highest Bill: ₹%f\n", highestBill);
    printf("Lowest Bill: ₹%f\n", lowestBill);
    return 0;
}
