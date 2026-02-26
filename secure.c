#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for Encryption & Decryption using XOR
void encryptDecrypt(char *input) {
    char key = 'K';  
    int i;
    for(i = 0; i < strlen(input); i++) {
        input[i] = input[i] ^ key;
    }
}

// Function to Register User
void registerUser() {
    char username[50], password[50];
    FILE *file;

    printf("Create Username: ");
    scanf("%s", username);

    printf("Create Password: ");
    scanf("%s", password);

    encryptDecrypt(password);

    file = fopen(username, "w");
    if(file == NULL) {
        printf("Error creating file!\n");
        return;
    }

    fprintf(file, "%s", password);
    fclose(file);

    printf("Registration Successful!\n");
}

// Function to Login User
void loginUser() {
    char username[50], password[50], storedPassword[50];
    FILE *file;
    int attempts = 3;

    printf("Enter Username: ");
    scanf("%s", username);

    file = fopen(username, "r");
    if(file == NULL) {
        printf("User not found!\n");
        return;
    }

    fscanf(file, "%s", storedPassword);
    fclose(file);

    while(attempts > 0) {
        printf("Enter Password: ");
        scanf("%s", password);

        encryptDecrypt(password);

        if(strcmp(password, storedPassword) == 0) {
            printf("Login Successful!\n");
            return;
        } else {
            attempts--;
            printf("Wrong Password! Attempts left: %d\n", attempts);
        }
    }

    printf("Account Locked!\n");
}

// Main Function
int main() {
    int choice;

    while(1) {
        printf("\n===== SecureVault =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}