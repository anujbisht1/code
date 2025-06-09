#include <stdio.h>
#include <string.h>

struct Patient {
    int id;
    char name[100];
    int age;
    char history[500];
};

struct Doctor {
    int id;
    char name[100];
    char specialization[100];
    char availability[50];
};

struct Appointment {
    int id;
    int patientId;
    int doctorId;
    char date[20];
};

struct Bill {
    int id;
    int patientId;
    float amount;
};

struct Inventory {
    int id;
    char medicineName[100];
    int quantity;
    char expiryDate[20];
};

struct LabReport {
    int id;
    int patientId;
    char result[500];
};

struct User {
    char username[50];
    char password[50];
    char role[20];
};

struct Record {
    int id;
    int patientId;
    char description[500];
};

struct Room {
    int roomNumber;
    int patientId;
    char roomType[50];
    char status[50];
};

void registerPatient(struct Patient *p) {
    printf("Enter Patient ID: ");
    scanf("%d", &p->id);
    printf("Enter Name: ");
    scanf("%s", p->name);
    printf("Enter Age: ");
    scanf("%d", &p->age);
    printf("Enter History: ");
    scanf("%s", p->history);
}

void addDoctor(struct Doctor *d) {
    printf("Enter Doctor ID: ");
    scanf("%d", &d->id);
    printf("Enter Name: ");
    scanf("%s", d->name);
    printf("Enter Specialization: ");
    scanf("%s", d->specialization);
    printf("Enter Availability: ");
    scanf("%s", d->availability);
}

void scheduleAppointment(struct Appointment *a) {
    printf("Enter Appointment ID: ");
    scanf("%d", &a->id);
    printf("Enter Patient ID: ");
    scanf("%d", &a->patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &a->doctorId);
    printf("Enter Date: ");
    scanf("%s", a->date);
}

void generateBill(struct Bill *b) {
    printf("Enter Bill ID: ");
    scanf("%d", &b->id);
    printf("Enter Patient ID: ");
    scanf("%d", &b->patientId);
    printf("Enter Amount: ");
    scanf("%f", &b->amount);
}

void updateInventory(struct Inventory *inv) {
    printf("Enter Inventory ID: ");
    scanf("%d", &inv->id);
    printf("Enter Medicine Name: ");
    scanf("%s", inv->medicineName);
    printf("Enter Quantity: ");
    scanf("%d", &inv->quantity);
    printf("Enter Expiry Date: ");
    scanf("%s", inv->expiryDate);
}

void enterLabReport(struct LabReport *lr) {
    printf("Enter Report ID: ");
    scanf("%d", &lr->id);
    printf("Enter Patient ID: ");
    scanf("%d", &lr->patientId);
    printf("Enter Result: ");
    scanf("%s", lr->result);
}

void createUser(struct User *u) {
    printf("Enter Username: ");
    scanf("%s", u->username);
    printf("Enter Password: ");
    scanf("%s", u->password);
    printf("Enter Role (Admin/Doctor/Receptionist/Patient/LabTech): ");
    scanf("%s", u->role);
}

void manageRecord(struct Record *r) {
    printf("Enter Record ID: ");
    scanf("%d", &r->id);
    printf("Enter Patient ID: ");
    scanf("%d", &r->patientId);
    printf("Enter Record Description: ");
    scanf("%s", r->description);
}

void manageRoom(struct Room *rm) {
    printf("Enter Room Number: ");
    scanf("%d", &rm->roomNumber);
    printf("Enter Patient ID: ");
    scanf("%d", &rm->patientId);
    printf("Enter Room Type (General/ICU/Private): ");
    scanf("%s", rm->roomType);
    printf("Enter Status (Occupied/Vacant): ");
    scanf("%s", rm->status);
}

void fullAccessMenu() {
    struct Patient p;
    struct Doctor d;
    struct Appointment a;
    struct Bill b;
    struct Inventory inv;
    struct LabReport lr;
    struct User u;
    struct Record r;
    struct Room rm;

    int choice;

    while (1) {
        printf("\n--- Full Access Dashboard ---\n");
        printf("1. Register Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Schedule Appointment\n");
        printf("4. Generate Bill\n");
        printf("5. Update Inventory\n");
        printf("6. Enter Lab Report\n");
        printf("7. Create User\n");
        printf("8. Manage Records\n");
        printf("9. Manage Rooms\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerPatient(&p);
                break;
            case 2:
                addDoctor(&d);
                break;
            case 3:
                scheduleAppointment(&a);
                break;
            case 4:
                generateBill(&b);
                break;
            case 5:
                updateInventory(&inv);
                break;
            case 6:
                enterLabReport(&lr);
                break;
            case 7:
                createUser(&u);
                break;
            case 8:
                manageRecord(&r);
                break;
            case 9:
                manageRoom(&rm);
                break;
            case 0:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    char role[20];
    printf("Enter role to login (Admin/Doctor/Receptionist/Patient/LabTech): ");
    scanf("%s", role);
    fullAccessMenu();
    return 0;
}
