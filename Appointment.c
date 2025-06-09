#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 100
#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    char name[50];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialization[50];
} Doctor;

typedef struct {
    int id;
    Patient *patient;
    Doctor *doctor;
    char date[20];
    char time[10];
    int status;
} Appointment;

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];
int patientCount = 0, doctorCount = 0, appointmentCount = 0;

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient list is full.\n");
        return;
    }

    Patient newPatient;
    newPatient.id = patientCount + 1;
    printf("Enter patient name: ");
    scanf(" %[^\n]s", newPatient.name);
    patients[patientCount] = newPatient;
    patientCount++;
    printf("Patient added successfully with ID: %d\n", newPatient.id);
}

void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor list is full.\n");
        return;
    }

    Doctor newDoctor;
    newDoctor.id = doctorCount + 1;
    printf("Enter doctor name: ");
    scanf(" %[^\n]s", newDoctor.name);
    printf("Enter doctor specialization: ");
    scanf(" %[^\n]s", newDoctor.specialization);
    doctors[doctorCount] = newDoctor;
    doctorCount++;
    printf("Doctor added successfully with ID: %d\n", newDoctor.id);
}

void bookAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full.\n");
        return;
    }

    int patientId, doctorId;
    printf("Enter patient ID: ");
    scanf("%d", &patientId);
    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    printf("Enter doctor ID: ");
    scanf("%d", &doctorId);
    if (doctorId <= 0 || doctorId > doctorCount) {
        printf("Invalid doctor ID.\n");
        return;
    }

    Appointment newAppointment;
    newAppointment.id = appointmentCount + 1;
    newAppointment.patient = &patients[patientId - 1];
    newAppointment.doctor = &doctors[doctorId - 1];

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", newAppointment.date);
    printf("Enter appointment time (HH:MM AM/PM): ");
    scanf(" %[^\n]s", newAppointment.time);

    newAppointment.status = 0;

    appointments[appointmentCount] = newAppointment;
    appointmentCount++;
    printf("Appointment booked successfully for patient '%s' with doctor '%s' on %s at %s.\n", newAppointment.patient->name, newAppointment.doctor->name, newAppointment.date, newAppointment.time);
}

void viewUpcomingAppointmentsByDoctor() {
    int doctorId;
    printf("Enter doctor ID to view upcoming appointments: ");
    scanf("%d", &doctorId);
    if (doctorId <= 0 || doctorId > doctorCount) {
        printf("Invalid doctor ID.\n");
        return;
    }

    printf("Upcoming appointments for doctor '%s':\n", doctors[doctorId - 1].name);
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].doctor->id == doctorId && appointments[i].status != 2) {
            printf("Appointment ID: %d | Patient: %s | Date: %s | Time: %s | Status: %s\n",
                   appointments[i].id, appointments[i].patient->name, appointments[i].date, appointments[i].time,
                   appointments[i].status == 0 ? "Pending" : (appointments[i].status == 1 ? "Confirmed" : "Cancelled"));
        }
    }
}

void viewUpcomingAppointmentsByPatient() {
    int patientId;
    printf("Enter patient ID to view upcoming appointments: ");
    scanf("%d", &patientId);
    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    printf("Upcoming appointments for patient '%s':\n", patients[patientId - 1].name);
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].patient->id == patientId && appointments[i].status != 2) {
            printf("Appointment ID: %d | Doctor: %s | Date: %s | Time: %s | Status: %s\n",
                   appointments[i].id, appointments[i].doctor->name, appointments[i].date, appointments[i].time,
                   appointments[i].status == 0 ? "Pending" : (appointments[i].status == 1 ? "Confirmed" : "Cancelled"));
        }
    }
}

void updateOrCancelAppointment() {
    int appointmentId;
    printf("Enter appointment ID to update or cancel: ");
    scanf("%d", &appointmentId);
    if (appointmentId <= 0 || appointmentId > appointmentCount) {
        printf("Invalid appointment ID.\n");
        return;
    }

    Appointment *appointment = &appointments[appointmentId - 1];
    int choice;
    printf("1. Confirm Appointment\n");
    printf("2. Cancel Appointment\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        appointment->status = 1;
        printf("Appointment confirmed successfully.\n");
    } else if (choice == 2) {
        appointment->status = 2;
        printf("Appointment cancelled successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n============================\n");
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Book Appointment\n");
        printf("4. View Upcoming Appointments (by Doctor)\n");
        printf("5. View Upcoming Appointments (by Patient)\n");
        printf("6. Update/Cancel Appointment\n");
        printf("7. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                addDoctor();
                break;
            case 3:
                bookAppointment();
                break;
            case 4:
                viewUpcomingAppointmentsByDoctor();
                break;
            case 5:
                viewUpcomingAppointmentsByPatient();
                break;
            case 6:
                updateOrCancelAppointment();
                break;
            case 7:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

