#include <stdio.h>
int main() {
    int n, s1, s2, s3, i = 1, passed = 0, failed = 0, choice;
    float avg, totalAvg = 0, high = 0, low = 100;
    printf("Smart Student Result Management\n");
    printf("Enter number of students: ");
    scanf("%d", &n);
    while (i <= n) {
        printf("\nStudent %d:\n", i);
        printf("Enter marks  subjects1 \n: ");
        printf("Enter marks  subjects2 \n: ");
        printf("Enter marks  subjects3 \n:");
        scanf("%d%d%d", &s1, &s2, &s3);
        avg = (s1 + s2 + s3) / 3.0;
        if (avg > high) high = avg;
        if (avg < low) low = avg;
        if (avg >= 50) passed++; else failed++;
        totalAvg += avg;
        i++;
    }
    do {
        printf("\n1.View All Results\n2.View Class Summary\n3.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            i = 1;
            while (i <= n) {
                printf("\nEnter marks for student %d again: ", i);
                scanf("%d%d%d", &s1, &s2, &s3);
                avg = (s1 + s2 + s3) / 3.0;
                printf("Student %d: Avg=%.1f Grade=", i, avg);
                if (avg >= 90) printf("A+\n");
                else if (avg >= 80) printf("A\n");
                else if (avg >= 70) printf("B\n");
                else if (avg >= 60) printf("C\n");
                else if (avg >= 50) printf("D\n");
                else printf("Fail\n");
                i++;
            }
        } 
        else if (choice == 2) {
            printf("\nTotal: %d\nPassed: %d\nFailed: %d\nClass Avg: %.1f\nHigh: %.1f\nLow: %.1f\n",
                   n, passed, failed, totalAvg / n, high, low);
        }
    } while (choice != 3);
    printf("Exiting system...");
    return 0;
}
