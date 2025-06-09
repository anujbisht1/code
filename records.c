#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_RECORDS 100
#define MAX_DOCUMENTS 10

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[15];
} Patient;

typedef struct {
    int id;
    Patient *patient;
    char diagnosis[200];
    char prescription[200];
    char testReports[200];
    char documents[MAX_DOCUMENTS][100]; // File names for uploaded documents
    int documentCount;
} MedicalRecord;

Patient patients[MAX_PATIENTS];
MedicalRecord records[MAX_RECORDS];
int patientCount = 0, recordCount = 0;

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient list is full.\n");
        return;
    }

    Patient newPatient;
    newPatient.id = patientCount + 1;
    printf("Enter patient name: ");
    scanf(" %[^\n]s", newPatient.name);
    printf("Enter patient address: ");
    scanf(" %[^\n]s", newPatient.address);
    printf("Enter patient phone number: ");
    scanf(" %[^\n]s", newPatient.phone);
    patients[patientCount] = newPatient;
    patientCount++;
    printf("Patient added successfully with ID: %d\n", newPatient.id);
}

void storeMedicalRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Medical record list is full.\n");
        return;
    }

    int patientId;
    printf("Enter patient ID for medical record: ");
    scanf("%d", &patientId);
    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    MedicalRecord newRecord;
    newRecord.id = recordCount + 1;
    newRecord.patient = &patients[patientId - 1];
    newRecord.documentCount = 0;

    printf("Enter diagnosis: ");
    scanf(" %[^\n]s", newRecord.diagnosis);
    printf("Enter prescription: ");
    scanf(" %[^\n]s", newRecord.prescription);
    printf("Enter test reports: ");
    scanf(" %[^\n]s", newRecord.testReports);

    while (1) {
        char document[100];
        printf("Enter document name to upload (0 to finish): ");
        scanf(" %[^\n]s", document);
        if (strcmp(document, "0") == 0) {
            break;
        }

        if (newRecord.documentCount < MAX_DOCUMENTS) {
            strcpy(newRecord.documents[newRecord.documentCount], document);
            newRecord.documentCount++;
        } else {
            printf("Maximum document limit reached.\n");
            break;
        }
    }

    records[recordCount] = newRecord;
    recordCount++;
    printf("Medical record stored successfully for patient ID: %d\n", newRecord.patient->id);
}

void viewMedicalRecord() {
    int recordId;
    printf("Enter medical record ID to view: ");
    scanf("%d", &recordId);
    if (recordId <= 0 || recordId > recordCount) {
        printf("Invalid record ID.\n");
        return;
    }

    MedicalRecord *record = &records[recordId - 1];
    printf("\n=== Medical Record ===\n");
    printf("Patient: %s\n", record->patient->name);
    printf("Diagnosis: %s\n", record->diagnosis);
    printf("Prescription: %s\n", record->prescription);
    printf("Test Reports: %s\n", record->testReports);

    printf("Uploaded Documents:\n");
    for (int i = 0; i < record->documentCount; i++) {
        printf("%s\n", record->documents[i]);
    }
    printf("=======================\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n=====================\n");
        printf("1. Add Patient\n");
        printf("2. Store Medical Record\n");
        printf("3. View Medical Record\n");
        printf("4. Exit\n");
        printf("=====================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                storeMedicalRecord();
                break;
            case 3:
                viewMedicalRecord();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

