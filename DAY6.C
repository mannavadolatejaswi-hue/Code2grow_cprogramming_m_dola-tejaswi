 #include <stdio.h>
int main()
{
    float dataUsed, baseCost, extraData, extraCost, totalBeforeDiscount, finalBill ;
    float discount ;
    int studentStatus, corporateStatus;
    char planName;
    printf("Enter total data used (GB)\n : ");
    scanf("%f", &dataUsed);
    printf("Are you a student? (1-Yes / 0-No)\n :");
    scanf("%d", &studentStatus);
    printf("Corporate user? (1-Yes / 0-No)\n : ");
    scanf("%d", &corporateStatus);
    if (dataUsed > 100) 
    {
        printf("Excessive Usage Plan Not Allowed.\n");
    } else {
        if (dataUsed < 30) {
            baseCost = 299;
            extraCost = 50;
            if (dataUsed > 30) {
                extraData = dataUsed - 30;
            }
            printf("planName = Silver");
        } else if (dataUsed >= 30 && dataUsed <= 60) {
            baseCost = 499;
            extraCost = 40;
            if (dataUsed > 60) {
                extraData = dataUsed - 60;
            }
            printf("planName = Gold");
        } else {
            baseCost = 799;
            extraCost = 30;
            if (dataUsed > 90) {
                extraData = dataUsed - 90;
            }
            printf( " planname = Platinum");
        }
                totalBeforeDiscount = baseCost + (extraData * extraCost);
        if (studentStatus == 1 && corporateStatus == 1) {
            discount = 15;
        } else if (studentStatus == 1) {
            discount = 15;
        } else if (corporateStatus == 1) {
            discount = 10;
        } else {
            discount = 0;
        }
        finalBill = totalBeforeDiscount - (totalBeforeDiscount * discount / 100);
        printf("User Plan Summary:\n");
        printf("Data Used: %.0f GB\n", dataUsed);
        printf("Selected Plan: %s\n", planName);
        printf("Base Cost: ₹%.0f\n", baseCost);
        printf("Extra Data: %.0f GB\n", extraData);
        printf("Total (before discount): ₹%.2f\n", totalBeforeDiscount);
        printf("Discount Applied: %.0f%%\n", discount);
        printf("Final Bill: ₹%.2f\n", finalBill);
    }
    return 0;
}