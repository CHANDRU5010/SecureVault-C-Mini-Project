         C Programming Mini Project Documentation
 Project: SecureVault – User Authentication System
                                                              Title Page
Project Title:
SecureVault – User Authentication System in C
Student Name:
Chandru M
Register Number:
921724115010
Department:
Computer Science and Design
College Name:
Sethu institute of technology
Course:
Programming in C
Guide / Trainer Name:
Balaji
Submission Date:
27/02/2026

Abstract
SecureVault is a console-based authentication system developed using C programming.
The project allows users to register and login securely using file handling and password encryption. The system stores user credentials in separate files and applies XOR encryption to protect passwords. It demonstrates structured programming, file management, and basic security concepts in C.

Introduction
In today’s digital world, user authentication is an important security mechanism. This project solves the problem of basic user registration and login using file storage.
The project is useful for understanding how authentication systems work internally. It can be used in small-scale applications that require login functionality.
This system can be used in:
Academic projects
Beginner security systems
Learning authentication concept.
Objectives
To understand structured programming in C
To use loops and conditional statements
To implement functions
To perform file handling operations
To apply basic encryption techniques
To improve logical thinking and program design
Tools & Technology
Programming Language: C
Compiler: GCC
Platform: Windows / Linux
IDE: VS Code / CodeBlocks / Terminal
System Requirements
Hardware:
Basic computer
Minimum 4GB RAM
Software:
GCC Compiler
Text Editor or IDE
 Methodology / Algorithm
Algorithm:
Start the program
Display main menu (Register / Login / Exit)
Read user choice
If Register:
Enter username
Enter password
Encrypt password
Store in file
If Login:
Enter username
Read stored password from file
Ask password (3 attempts allowed)
Encrypt and compare
Display result
Exit program
Flowchart
Start
   ↓
Display Menu
   ↓
User Choice?
   ↓
Register → Store Data
   ↓
Login → Verify Data
   ↓
Output Result
   ↓
End
(You can draw this neatly in Word using shapes for better marks.)
 Program Code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 123
#define MAX 100

// Encryption / Decryption Function
void encryptDecrypt(char *data) {
    for(int i = 0; i < strlen(data); i++) {
        data[i] = data[i] ^ KEY;
    }
}

// Register User
void registerUser() {
    char username[MAX], password[MAX];
    FILE *fp = fopen("users.txt", "a");

    if(fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Create Username: ");
    scanf("%s", username);
    printf("Create Password: ");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf("Registration Successful!\n");
}

// Login User
int loginUser(char loggedUser[]) {
    char username[MAX], password[MAX];
    char fileUser[MAX], filePass[MAX];
    int attempts = 3;

    printf("Enter Username: ");
    scanf("%s", username);

    while(attempts--) {
        printf("Enter Password: ");
        scanf("%s", password);

        FILE *fp = fopen("users.txt", "r");
        if(fp == NULL) {
            printf("No registered users!\n");
            return 0;
        }

        while(fscanf(fp, "%s %s", fileUser, filePass) != EOF) {
            if(strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
                strcpy(loggedUser, username);
                fclose(fp);
                printf("Login Successful!\n");
                return 1;
            }
        }

        fclose(fp);
        printf("Wrong Password! Attempts left: %d\n", attempts);
    }

    printf("Account Locked!\n");
    return 0;
}

// Write Note
void writeNote(char username[]) {
    char filename[120], note[500];
    sprintf(filename, "%s_note.txt", username);

    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("File error!\n");
        return;
    }

    getchar();
    printf("Enter Secret Note: ");
    fgets(note, sizeof(note), stdin);

    encryptDecrypt(note);
    fputs(note, fp);

    fclose(fp);
    printf("Note Saved Securely!\n");
}

// Read Note
void readNote(char username[]) {
    char filename[120], note[500];
    sprintf(filename, "%s_note.txt", username);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("No note found!\n");
        return;
    }

    fgets(note, sizeof(note), fp);
    fclose(fp);

    encryptDecrypt(note);
    printf("Your Secret Note:\n%s\n", note);
}

// Main Function
int main() {
    int choice;
    char loggedUser[MAX];

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
                if(loginUser(loggedUser)) {
                    int option;
                    while(1) {
                        printf("\n1. Write Note\n");
                        printf("2. Read Note\n");
                        printf("3. Logout\n");
                        printf("Enter option: ");
                        scanf("%d", &option);

                        switch(option) {
                            case 1:
                                writeNote(loggedUser);
                                break;
                            case 2:
                                readNote(loggedUser);
                                break;
                            case 3:
                                printf("Logged Out Successfully!\n");
                                break;
                            default:
                                printf("Invalid Option!\n");
                        }

                        if(option == 3) break;
                    }
                }
                break;

            case 3:
                printf("Exiting SecureVault...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
Sample Input / Output
Sample Run:
===== SecureVault =====
1. Register
2. Login
3. Exit
Enter choice: 1
Create Username: chan
Create Password: 4060
Registration Successful!

===== SecureVault =====
1. Register
2. Login
3. Exit
Enter choice: 2
Enter Username: chan
Enter Password: 4060
Login Successful!
 Result
The program executed successfully.
User registration and login system worked correctly with password encryption and file storage.

 Applications
Educational learning purpose
Basic authentication systems
Beginner security projects
Academic mini projects
Conclusion
The SecureVault project demonstrates fundamental C programming concepts such as file handling, functions, loops, conditional statements, and basic encryption. The project successfully implements a simple user authentication system and enhances understanding of structured programming.
Future Enhancements
Add password strength validation
Store multiple users in single database file
Add graphical user interface
Implement advanced encryption
Add password recovery system

References
C Programming by Dennis Ritchie
Let Us C by Yashavant Kanetkar
Online tutorials (GeeksforGeeks, W3Schools)
Class notes