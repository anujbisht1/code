#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOCTORS 100
#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[50];
    char specialization[50];
    char timing[50];
} Doctor;

typedef struct {
    int id;
    char name[50];
    Doctor *assignedDoctor;
} Patient;

Doctor doctors[MAX_DOCTORS];
Patient patients[MAX_PATIENTS];
int doctorCount = 0;
int patientCount = 0;

void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Unable to add more doctors. Doctor list is full.\n");
        return;
    }

    Doctor newDoctor;
    printf("Enter doctor details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", newDoctor.name);
    printf("Specialization: ");
    scanf(" %[^\n]s", newDoctor.specialization);
    printf("Timing (e.g., 9 AM - 5 PM): ");
    scanf(" %[^\n]s", newDoctor.timing);

    newDoctor.id = doctorCount + 1;
    doctors[doctorCount] = newDoctor;
    doctorCount++;

    printf("Doctor '%s' added successfully with ID %d.\n", newDoctor.name, newDoctor.id);
}

void displayDoctor(Doctor d) {
    printf("ID: %d\n", d.id);
    printf("Name: %s\n", d.name);
    printf("Specialization: %s\n", d.specialization);
    printf("Timing: %s\n", d.timing);
}

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Unable to add more patients. Patient list is full.\n");
        return;
    }

    Patient newPatient;
    printf("Enter patient details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", newPatient.name);

    newPatient.id = patientCount + 1;
    newPatient.assignedDoctor = NULL;

    patients[patientCount] = newPatient;
    patientCount++;

    printf("Patient '%s' added successfully with ID %d.\n", newPatient.name, newPatient.id);
}

void assignDoctorToPatient() {
    int patientId, doctorId;
    printf("Enter patient ID to assign a doctor: ");
    scanf("%d", &patientId);

    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    Patient *patient = &patients[patientId - 1];

    printf("Enter doctor ID to assign: ");
    scanf("%d", &doctorId);

    if (doctorId <= 0 || doctorId > doctorCount) {
        printf("Invalid doctor ID.\n");
        return;
    }

    Doctor *doctor = &doctors[doctorId - 1];
    patient->assignedDoctor = doctor;

    printf("Doctor '%s' has been assigned to patient '%s'.\n", doctor->name, patient->name);
}

void displayPatient(Patient p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    if (p.assignedDoctor != NULL) {
        printf("Assigned Doctor: %s\n", p.assignedDoctor->name);
        printf("Doctor Specialization: %s\n", p.assignedDoctor->specialization);
        printf("Doctor Timing: %s\n", p.assignedDoctor->timing);
    } else {
        printf("No doctor assigned.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n============================\n");
        printf("1. Add New Doctor\n");
        printf("2. Add New Patient\n");
        printf("3. Assign Doctor to Patient\n");
        printf("4. Display Doctor Details\n");
        printf("5. Display Patient Details\n");
        printf("6. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDoctor();
                break;
            case 2:
                addPatient();
                break;
            case 3:
                assignDoctorToPatient();
                break;
            case 4:
                {
                    int doctorId;
                    printf("Enter doctor ID to view details: ");
                    scanf("%d", &doctorId);
                    if (doctorId <= 0 || doctorId > doctorCount) {
                        printf("Invalid doctor ID.\n");
                    } else {
                        displayDoctor(doctors[doctorId - 1]);
                    }
                }
                break;
            case 5:
                {
                    int patientId;
                    printf("Enter patient ID to view details: ");
                    scanf("%d", &patientId);
                    if (patientId <= 0 || patientId > patientCount) {
                        printf("Invalid patient ID.\n");
                    } else {
                        displayPatient(patients[patientId - 1]);
                    }
                }
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

