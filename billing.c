#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_PATIENTS 100
#define MAX_INVOICES 100

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

typedef struct {
    int id;
    char name[50];
    char address[100];
    char phone[15];
} Patient;

typedef struct {
    int id;
    Patient *patient;
    Item items[MAX_ITEMS];
    int itemCount;
    float totalAmount;
    int paymentStatus;
} Invoice;

Item items[] = {
    {1, "Consultation", 100.0},
    {2, "Test - X-Ray", 50.0},
    {3, "Test - Blood Work", 30.0},
    {4, "Medicine - Paracetamol", 10.0},
    {5, "Medicine - Antibiotics", 20.0}
};

int patientCount = 0, invoiceCount = 0;

Patient patients[MAX_PATIENTS];
Invoice invoices[MAX_INVOICES];

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

void generateInvoice() {
    if (invoiceCount >= MAX_INVOICES) {
        printf("Invoice list is full.\n");
        return;
    }

    int patientId;
    printf("Enter patient ID for invoice: ");
    scanf("%d", &patientId);
    if (patientId <= 0 || patientId > patientCount) {
        printf("Invalid patient ID.\n");
        return;
    }

    Invoice newInvoice;
    newInvoice.id = invoiceCount + 1;
    newInvoice.patient = &patients[patientId - 1];
    newInvoice.itemCount = 0;
    newInvoice.totalAmount = 0;
    newInvoice.paymentStatus = 0;

    int itemChoice;
    while (1) {
        printf("Available items:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s - %.2f\n", items[i].id, items[i].name, items[i].price);
        }
        printf("Enter item ID to add to the invoice (0 to finish): ");
        scanf("%d", &itemChoice);
        if (itemChoice == 0) {
            break;
        }
        if (itemChoice < 1 || itemChoice > 5) {
            printf("Invalid item choice.\n");
            continue;
        }

        newInvoice.items[newInvoice.itemCount] = items[itemChoice - 1];
        newInvoice.totalAmount += items[itemChoice - 1].price;
        newInvoice.itemCount++;
    }

    invoices[invoiceCount] = newInvoice;
    invoiceCount++;
    printf("Invoice generated successfully with ID: %d\n", newInvoice.id);
}

void printBill() {
    int invoiceId;
    printf("Enter invoice ID to print the bill: ");
    scanf("%d", &invoiceId);
    if (invoiceId <= 0 || invoiceId > invoiceCount) {
        printf("Invalid invoice ID.\n");
        return;
    }

    Invoice *invoice = &invoices[invoiceId - 1];
    printf("\n==== Bill ====\n");
    printf("Patient: %s\n", invoice->patient->name);
    printf("Address: %s\n", invoice->patient->address);
    printf("Phone: %s\n", invoice->patient->phone);
    printf("Items:\n");
    for (int i = 0; i < invoice->itemCount; i++) {
        printf("%s - %.2f\n", invoice->items[i].name, invoice->items[i].price);
    }
    printf("Total Amount: %.2f\n", invoice->totalAmount);
    printf("Payment Status: %s\n", invoice->paymentStatus == 0 ? "Unpaid" : "Paid");
    printf("================\n");
}

void updatePaymentStatus() {
    int invoiceId;
    printf("Enter invoice ID to update payment status: ");
    scanf("%d", &invoiceId);
    if (invoiceId <= 0 || invoiceId > invoiceCount) {
        printf("Invalid invoice ID.\n");
        return;
    }

    Invoice *invoice = &invoices[invoiceId - 1];
    int choice;
    printf("Current payment status: %s\n", invoice->paymentStatus == 0 ? "Unpaid" : "Paid");
    printf("1. Mark as Paid\n");
    printf("2. Mark as Unpaid\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        invoice->paymentStatus = 1;
        printf("Invoice marked as Paid.\n");
    } else if (choice == 2) {
        invoice->paymentStatus = 0;
        printf("Invoice marked as Unpaid.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=====================\n");
        printf("1. Add Patient\n");
        printf("2. Generate Invoice\n");
        printf("3. Print Bill\n");
        printf("4. Update Payment Status\n");
        printf("5. Exit\n");
        printf("=====================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                generateInvoice();
                break;
            case 3:
                printBill();
                break;
            case 4:
                updatePaymentStatus();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

