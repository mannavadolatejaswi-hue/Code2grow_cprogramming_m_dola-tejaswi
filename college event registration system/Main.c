#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_EVENTS 50

int main() {
    int student_id[MAX_STUDENTS];
    char student_name[MAX_STUDENTS][50];
    int student_count = 0;

    int event_id[MAX_EVENTS];
    char event_name[MAX_EVENTS][50];
    int event_count = 0;

    int reg_student[200];
    int reg_event[200];
    int reg_count = 0;

    int choice, sid, eid;
    int i, foundS, foundE;

    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Add Event\n");
        printf("3. Register Student to Event\n");
        printf("4. View Registrations\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter student ID: ");
            scanf("%d", &student_id[student_count]);
            printf("Enter student name: ");
            scanf("%s", student_name[student_count]);
            student_count++;
        }

        else if (choice == 2) {
            printf("Enter event ID: ");
            scanf("%d", &event_id[event_count]);
            printf("Enter event name: ");
            scanf("%s", event_name[event_count]);
            event_count++;
        }

        else if (choice == 3) {
            printf("Enter student ID: ");
            scanf("%d", &sid);
            foundS = 0;
            for (i = 0; i < student_count; i++) {
                if (student_id[i] == sid) {
                    foundS = 1;
                    break;
                }
            }

            printf("Enter event ID: ");
            scanf("%d", &eid);
            foundE = 0;
            for (i = 0; i < event_count; i++) {
                if (event_id[i] == eid) {
                    foundE = 1;
                    break;
                }
            }

            if (foundS && foundE) {
                reg_student[reg_count] = sid;
                reg_event[reg_count] = eid;
                reg_count++;
                printf("Registered.\n");
            } else {
                printf("Invalid ID.\n");
            }
        }

        else if (choice == 4) {
            if (reg_count == 0) {
                printf("No registrations.\n");
            } else {
                for (i = 0; i < reg_count; i++) {
                    printf("Student %d -> Event %d\n",
                           reg_student[i], reg_event[i]);
                }
            }
        }

        else if (choice == 5) {
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
