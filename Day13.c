#include <stdio.h>
int main() {
    int n, i = 1;
    float totalRevenue = 0, highest = 0, lowest = 99999;
    printf("===== SRM Smart Bus Fare Calculator =====\n");
    printf("Enter number of passengers: ");
    scanf("%d", &n);
    while (i <= n) {
        char name[50];
        int age, time;
        float distance, baseFare, finalFare;
        printf("\n--- Passenger %d ---\n", i);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter distance (in km): ");
        scanf("%f", &distance);
        printf("Enter travel time (24-hour format): ");
        scanf("%d", &time);
        baseFare = distance * 10; 
        finalFare = baseFare;
        if (age < 12)
            finalFare *= 0.5;
        else if (age >= 60)
            finalFare *= 0.7;
        if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20))
            finalFare *= 1.2;
        if (finalFare < 20)
            finalFare = 20;
        printf("Passenger: %s | Base Fare: ₹%.0f", name, baseFare);
        if (age < 12)
            printf(" | Child Discount Applied");
        else if (age >= 60)
            printf(" | Senior Citizen Discount Applied");
        if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20))
            printf(" | Peak Hour Surcharge Applied");
        printf(" | Final Fare: ₹%.0f\n", finalFare);
        totalRevenue += finalFare;
        if (finalFare > highest) highest = finalFare;
        if (finalFare < lowest) lowest = finalFare;
        i++;
    }
    printf("\n========== Daily Summary ==========\n");
    printf("Total Passengers: %d\n", n);
    printf("Total Revenue Collected: ₹%.0f\n", totalRevenue);
    printf("Highest Fare: ₹%.0f\n", highest);
    printf("Lowest Fare: ₹%.0f\n", lowest);
    printf("===================================\n");
    return 0;
}