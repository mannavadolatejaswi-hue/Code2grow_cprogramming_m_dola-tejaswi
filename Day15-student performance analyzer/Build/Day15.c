#include <stdio.h>
int main() 
{
    int n, i;
    int marks[10];
    int total = 0, passed = 0, failed = 0;
    int high, low;
    int gradeAplus = 0, gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    printf("======== Student Performance Analyzer ========\n");
    printf("Enter total number of students (max 10): ");
    scanf("%d", &n);
    if (n > 10 || n <= 0) {
        printf("Invalid number of students.\n");
        return 0;
    }
    printf("Enter marks for each student:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
        if (i == 0) {
            high = marks[i];
            low = marks[i];
        }
        if (marks[i] > high)
            high = marks[i];
        if (marks[i] < low)
            low = marks[i];
        if (marks[i] >= 90) {
            gradeAplus++;
            passed++;
        } else if (marks[i] >= 80) {
            gradeA++;
            passed++;
        } else if (marks[i] >= 70) {
            gradeB++;
            passed++;
        } else if (marks[i] >= 60) {
            gradeC++;
            passed++;
        } else if (marks[i] >= 50) {
            gradeD++;
            passed++;
        } else {
            gradeF++;
            failed++;
        }
    }
    float average = (float) total / n;
    printf("\n======== Result Summary ========\n");
    printf("Average Marks: %.2f\n", average);
    printf("Highest Marks: %d\n", high);
    printf("Lowest Marks: %d\n", low);
    printf("\nTotal Passed Students: %d\n", passed);
    printf("Total Failed Students: %d\n", failed);
    printf("\nGrade Distribution:\n");
    printf("A+: %d\n", gradeAplus);
    printf("A : %d\n", gradeA);
    printf("B : %d\n", gradeB);
    printf("C : %d\n", gradeC);
    printf("D : %d\n", gradeD);
    printf("F : %d\n", gradeF);
    printf("================================\n");

    return 0;
}