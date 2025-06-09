#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define LOW_STOCK_THRESHOLD 10

typedef struct {
    int id;
    char name[50];
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Medicine storage full.\n");
        return;
    }

    Medicine m;
    m.id = medicineCount + 1;

    printf("Enter medicine name: ");
    scanf(" %[^\n]s", m.name);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);

    medicines[medicineCount++] = m;
    printf("Medicine added successfully with ID: %d\n", m.id);
}

void deleteMedicine() {
    int id, found = 0;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicineCount--;
            found = 1;
            printf("Medicine with ID %d deleted.\n", id);
            break;
        }
    }

    if (!found)
        printf("Medicine ID not found.\n");
}

void showInventory() {
    if (medicineCount == 0) {
        printf("No medicines in stock.\n");
        return;
    }

    printf("\nMedicine Inventory:\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d", medicines[i].id, medicines[i].name, medicines[i].quantity);
        if (medicines[i].quantity <= LOW_STOCK_THRESHOLD)
            printf("  <-- LOW STOCK");
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===========================\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                showInventory();
                break;
            case 4:
                printf("Exiting inventory system.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

