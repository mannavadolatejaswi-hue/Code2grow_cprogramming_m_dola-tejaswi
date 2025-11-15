#include <stdio.h>
int main() 
{
    int attendance[5][5];
    int marks[5][5];
    char names[5][20];
    int i, j, choice;
    printf("Enter names of 5 students:\n");
    for(i = 0; i < 5; i++) {
        scanf("%s", names[i]);
    }
    printf("\nEnter Attendance (1=Present, 0=Absent) for 5 students (5 classes each):\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &attendance[i][j]);
        }
    }
    printf("\nEnter Marks (0-100) of 5 students in 5 subjects:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &marks[i][j]);
        }
    }
    do {
        printf("\n===== MENU =====\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("=================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("\n--- Attendance Matrix ---\n");
            for(i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for(j = 0; j < 5; j++) {
                    printf("%d ", attendance[i][j]);
                }
                printf("\n");
            }
        }
        else if(choice == 2) {
            printf("\n--- Marks Matrix ---\n");
            for(i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for(j = 0; j < 5; j++) {
                    printf("%d ", marks[i][j]);
                }
                printf("\n");
            }
        }
        else if(choice == 3) {
            printf("\n--- Attendance Report ---\n");
            for(i = 0; i < 5; i++) {
                int present = 0;
                for(j = 0; j < 5; j++) present += attendance[i][j];
                printf("%s - Present: %d  Absent: %d\n", names[i], present, 5 - present);
            }
        }
        else if(choice == 4) {
            printf("\n--- Performance Report ---\n");
            for(i = 0; i < 5; i++) {
                int total = 0;
                for(j = 0; j < 5; j++) total += marks[i][j];
                printf("%s - Total: %d  Average: %.2f\n", names[i], total, total/5.0);
            }
        }
        else if(choice == 5) {
            printf("\n--- Grade Report ---\n");
            for(i = 0; i < 5; i++) {
                int sum = 0;
                for(j = 0; j < 5; j++) sum += marks[i][j];
                float avg = sum / 5.0;
                char grade;
                if(avg >= 90) grade = 'A';
                else if(avg >= 80) grade = 'B';
                else if(avg >= 70) grade = 'C';
                else if(avg >= 60) grade = 'D';
                else if(avg >= 50) grade = 'E';
                else grade = 'F';
                printf("%s - Average: %.2f Grade: %c\n", names[i], avg, grade);
            }
        }
    } while(choice != 6);
    return 0;
}
