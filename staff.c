#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAFF 100

typedef struct {
    int id;
    char name[50];
    char role[30];
    char shift[30];
} Staff;

Staff staffList[MAX_STAFF];
int staffCount = 0;

void addStaff() {
    if (staffCount >= MAX_STAFF) {
        printf("Staff limit reached.\n");
        return;
    }

    Staff s;
    s.id = staffCount + 1;

    printf("Enter staff name: ");
    scanf(" %[^\n]s", s.name);
    printf("Enter staff role (e.g., Nurse, Technician): ");
    scanf(" %[^\n]s", s.role);
    strcpy(s.shift, "Not Assigned");

    staffList[staffCount++] = s;
    printf("Staff added with ID: %d\n", s.id);
}

void assignShift() {
    int id;
    printf("Enter staff ID to assign shift: ");
    scanf("%d", &id);

    if (id <= 0 || id > staffCount) {
        printf("Invalid staff ID.\n");
        return;
    }

    char shift[30];
    printf("Enter shift (e.g., Morning, Evening, Night): ");
    scanf(" %[^\n]s", shift);
    strcpy(staffList[id - 1].shift, shift);

    printf("Shift assigned to %s (%s)\n", staffList[id - 1].name, staffList[id - 1].role);
}

void viewStaff() {
    if (staffCount == 0) {
        printf("No staff available.\n");
        return;
    }

    printf("\nStaff List:\n");
    for (int i = 0; i < staffCount; i++) {
        printf("ID: %d | Name: %s | Role: %s | Shift: %s\n",
               staffList[i].id,
               staffList[i].name,
               staffList[i].role,
               staffList[i].shift);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=========================\n");
        printf("1. Add Staff\n");
        printf("2. Assign Shift\n");
        printf("3. View Staff\n");
        printf("4. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStaff();
                break;
            case 2:
                assignShift();
                break;
            case 3:
                viewStaff();
                break;
            case 4:
                printf("Exiting staff system.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

