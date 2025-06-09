#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char contact[15];
} Patient;

Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Unable to add more patients. Patient list is full.\n");
        return;
    }

    Patient newPatient;
    printf("Enter patient details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", newPatient.name);
    printf("Age: ");
    scanf("%d", &newPatient.age);
    printf("Gender: ");
    scanf(" %[^\n]s", newPatient.gender);
    printf("Contact: ");
    scanf(" %[^\n]s", newPatient.contact);

    newPatient.id = patientCount + 1;
    patients[patientCount] = newPatient;
    patientCount++;

    printf("Patient '%s' added successfully with ID %d.\n", newPatient.name, newPatient.id);
}

void displayPatient(Patient p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %s\n", p.gender);
    printf("Contact: %s\n", p.contact);
}

void searchPatient() {
    int choice;
    printf("Search by: 1. Name  2. ID\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char searchName[50];
        printf("Enter patient name to search: ");
        scanf(" %[^\n]s", searchName);

        for (int i = 0; i < patientCount; i++) {
            if (strstr(patients[i].name, searchName) != NULL) {
                printf("\nPatient Found:\n");
                displayPatient(patients[i]);
                return;
            }
        }
        printf("No patient found with that name.\n");
    } else if (choice == 2) {
        int searchId;
        printf("Enter patient ID to search: ");
        scanf("%d", &searchId);

        for (int i = 0; i < patientCount; i++) {
            if (patients[i].id == searchId) {
                printf("\nPatient Found:\n");
                displayPatient(patients[i]);
                return;
            }
        }
        printf("No patient found with that ID.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

void editPatient() {
    int searchId;
    printf("Enter patient ID to edit: ");
    scanf("%d", &searchId);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == searchId) {
            printf("\nEditing Patient ID: %d\n", patients[i].id);
            printf("Enter new name (current: %s): ", patients[i].name);
            scanf(" %[^\n]s", patients[i].name);
            printf("Enter new age (current: %d): ", patients[i].age);
            scanf("%d", &patients[i].age);
            printf("Enter new gender (current: %s): ", patients[i].gender);
            scanf(" %[^\n]s", patients[i].gender);
            printf("Enter new contact (current: %s): ", patients[i].contact);
            scanf(" %[^\n]s", patients[i].contact);
            printf("Patient details updated successfully.\n");
            return;
        }
    }
    printf("No patient found with that ID.\n");
}

void deletePatient() {
    int searchId;
    printf("Enter patient ID to delete: ");
    scanf("%d", &searchId);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == searchId) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient with ID %d deleted successfully.\n", searchId);
            return;
        }
    }
    printf("No patient found with that ID.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n============================\n");
        printf("1. Add New Patient\n");
        printf("2. View/Search Patient\n");
        printf("3. Edit Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                searchPatient();
                break;
            case 3:
                editPatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
