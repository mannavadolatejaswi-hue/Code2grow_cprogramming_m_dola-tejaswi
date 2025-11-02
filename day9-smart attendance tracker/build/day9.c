#include <stdio.h>
int main() {
    int n, i, present;
    float percentage, totalPercentage ;
    int eligible = 0, notEligible = 0;
    const int totalDays = 30;
    printf("Enter total number of students: ");
    scanf("%d", &n);
    i = 1;
    while (i <= n) {
        printf("Enter attendance for student %d : ", i);
        scanf("%d", &present);
        percentage = (present / 30) * 100;
        totalPercentage += percentage;
        if (percentage >= 75) {
            printf("Student %d: " , i, percentage);
           printf("percentage %.2f%%-eligible",percentage);
            eligible++;
        } else {
            printf("Student %d: %.2f%% - Not Eligible\n", i, percentage);
            notEligible++;
        }
        i++;
    }
    printf("\nClass Summary:\n");
    printf("Total Students: %d\n", n);
    printf("Eligible Students: %d\n", eligible);
    printf("Not Eligible: %d\n", notEligible);
    printf("Average Attendance: %.2f%%\n", totalPercentage / n);
    return 0;
}
