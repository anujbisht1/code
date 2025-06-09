#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_ROOMS 50

typedef struct {
    int id;
    char name[50];
    int roomAssigned;
    int isDischarged;
} Patient;

typedef struct {
    int roomNumber;
    int isOccupied;
} Room;

Patient patients[MAX_PATIENTS];
Room rooms[MAX_ROOMS];
int patientCount = 0;

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isOccupied = 0;
    }
}

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient limit reached.\n");
        return;
    }

    Patient newPatient;
    newPatient.id = patientCount + 1;
    newPatient.roomAssigned = -1;
    newPatient.isDischarged = 0;

    printf("Enter patient name: ");
    scanf(" %[^\n]s", newPatient.name);

    patients[patientCount] = newPatient;
    patientCount++;

    printf("Patient added successfully with ID: %d\n", newPatient.id);
}

void viewRoomAvailability() {
    printf("\nRoom Availability:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d - %s\n", rooms[i].roomNumber, rooms[i].isOccupied ? "Occupied" : "Available");
    }
}

void assignBed() {
    int patientId;
    printf("Enter patient ID to assign bed: ");
    scanf("%d", &patientId);

    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    if (patients[patientId - 1].roomAssigned != -1) {
        printf("Patient already assigned to Room %d\n", patients[patientId - 1].roomAssigned);
        return;
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!rooms[i].isOccupied) {
            rooms[i].isOccupied = 1;
            patients[patientId - 1].roomAssigned = rooms[i].roomNumber;
            printf("Patient %s assigned to Room %d\n", patients[patientId - 1].name, rooms[i].roomNumber);
            return;
        }
    }

    printf("No available rooms.\n");
}

void dischargePatient() {
    int patientId;
    printf("Enter patient ID to discharge: ");
    scanf("%d", &patientId);

    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    Patient *p = &patients[patientId - 1];

    if (p->isDischarged) {
        printf("Patient already discharged.\n");
        return;
    }

    if (p->roomAssigned != -1) {
        int roomIndex = p->roomAssigned - 1;
        rooms[roomIndex].isOccupied = 0;
    }

    p->isDischarged = 1;

    printf("\n--- Discharge Summary ---\n");
    printf("Patient ID: %d\n", p->id);
    printf("Name: %s\n", p->name);
    if (p->roomAssigned != -1)
        printf("Room: %d\n", p->roomAssigned);
    printf("Status: Discharged\n");
}

int main() {
    int choice;
    initializeRooms();

    while (1) {
        printf("\n==========================\n");
        printf("1. Add Patient\n");
        printf("2. View Room Availability\n");
        printf("3. Assign Bed to Patient\n");
        printf("4. Discharge Patient\n");
        printf("5. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewRoomAvailability();
                break;
            case 3:
                assignBed();
                break;
            case 4:
                dischargePatient();
                break;
            case 5:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

