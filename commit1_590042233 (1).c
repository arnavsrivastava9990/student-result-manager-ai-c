/*
 * Project Title : AI-Assisted Student Record and Result Management System
 * Course        : Programming in C (PRC1001) - B.Tech CSE, Semester I
 * University    : University of Petroleum and Energy Studies (UPES)
 * SAP ID        : 590042233
 * Commit 1      : Initial C program (struct Student, 5 sample students, menu)
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

/* Structure to store one student's complete details */
struct Student {
    long sap_id;
    char roll_no[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;        /* 1, 2, 3, or 4 */
    int semester;    /* 1 to 8 */
    float sgpa[8];   /* -1 means semester not yet completed */
};

int main(void) {
    /* Pre-load 5 sample students */
    struct Student s[MAX] = {
        {500010101, "R214226001", "Aarav Sharma", "9876543210", "aarav@upes.ac.in",
         2, 3, {9.2, 9.1, 9.15, -1, -1, -1, -1, -1}},
        {500010105, "R214226005", "Diya Verma", "9876543211", "diya@upes.ac.in",
         1, 2, {7.8, 7.4, -1, -1, -1, -1, -1, -1}},
        {500010102, "R214226002", "Kabir Mehta", "9876543212", "kabir@upes.ac.in",
         3, 5, {6.1, 5.9, 5.7, 5.8, 5.5, -1, -1, -1}},
        {500010104, "R214226004", "Rohan Nair", "9876543213", "rohan@upes.ac.in",
         4, 7, {4.5, 4.2, 4.8, 4.0, 4.3, 4.1, 4.4, -1}},
        {500010103, "R214226003", "Ananya Singh", "9876543214", "ananya@upes.ac.in",
         2, 4, {8.4, 8.6, 8.2, 8.5, -1, -1, -1, -1}}
    };
    int count = 5;
    int choice;

    do {
        printf("\n=== Student Record & Result Management System ===\n");
        printf("Loaded %d student records.\n", count);
        printf("1. Add Student Details (Coming soon)\n");
        printf("2. Search Student Record (Coming soon)\n");
        printf("3. Calculate CGPA of Each Student (Coming soon)\n");
        printf("4. Calculate Year-Wise Average CGPA (Coming soon)\n");
        printf("5. Display All Students (Coming soon)\n");
        printf("6. Delete a Student Record (Coming soon)\n");
        printf("7. Display Sorted by SAP ID (Coming soon)\n");
        printf("8. Display Sorted by Name (Coming soon)\n");
        printf("9. AI-Assisted Academic Advisor (Coming soon)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting program. Goodbye!\n");
        } else if (choice >= 1 && choice <= 9) {
            printf("Feature %d will be added in upcoming commits.\n", choice);
        } else {
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    (void)s; /* Suppresses unused variable warning in Commit 1 */
    return 0;
}