#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int choice;
    FILE *file;
    char username[50], password[50], role[20];
    char inputUsername[50], inputPassword[50], fileUsername[50], filePassword[50], fileRole[20];
    int found = 0;

    while (1) {
        // Main Menu
        printf("\n============================\n");
        printf("1  Register a new user\n");
        printf("2  Login\n");
        printf("3  Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Register User
            file = fopen("users.txt", "a");
            if (!file) {
                printf("Unable to open user file for writing.\n");
                return 0;
            }

            printf("\nCreate a new account\n");
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);

            // Ask for valid role
            while (1) {
                printf("Role (Admin / Doctor / Receptionist / Patient): ");
                scanf("%s", role);
                if (strcmp(role, "admin") == 0 || strcmp(role, "doctor") == 0 ||
                    strcmp(role, "receptionist") == 0 || strcmp(role, "patient") == 0) {
                    break;
                } else {
                    printf("Invalid role. Please try again.\n");
                }
            }

            fprintf(file, "%s %s %s\n", username, password, role);
            fclose(file);
            printf("User '%s' registered successfully as '%s'.\n", username, role);

        } else if (choice == 2) {
            // Login User
            file = fopen("users.txt", "r");
            if (!file) {
                printf("Unable to open user file for reading.\n");
                return 0;
            }

            printf("\nLogin to your account\n");
            printf("Username: ");
            scanf("%s", inputUsername);
            printf("Password: ");
            scanf("%s", inputPassword);

            found = 0;
            while (fscanf(file, "%s %s %s", fileUsername, filePassword, fileRole) != EOF) {
                if (strcmp(fileUsername, inputUsername) == 0 && strcmp(filePassword, inputPassword) == 0) {
                    found = 1;
                    printf("Login successful. Your role: %s\n", fileRole);

                    // Show Role-based Access
                    if (strcmp(fileRole, "admin") == 0) {
                        printf("Hello Admin! You have full system access.\n");
                    } else if (strcmp(fileRole, "doctor") == 0) {
                        printf("Welcome Doctor! You can view and manage patient records.\n");
                    } else if (strcmp(fileRole, "receptionist") == 0) {
                        printf("Hi Receptionist! You can manage appointments and schedules.\n");
                    } else if (strcmp(fileRole, "patient") == 0) {
                        printf("Hello Patient! You can view your medical records.\n");
                    }
                    break;
                }
            }
            fclose(file);

            if (!found) {
                printf("Login failed. Incorrect username or password.\n");
            }

        } else if (choice == 3) {
            // Exit
            printf("Exiting. Have a great day!\n");
            break;

        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
