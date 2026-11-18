/*
 * Project Title : AI-Assisted Student Record and Result Management System
 * Course        : Programming in C (PRC1001) - B.Tech CSE, Semester I
 * University    : University of Petroleum and Energy Studies (UPES)
 * SAP ID        : 590042233
 * Commit 2      : Student record functions (add, search, display all, delete)
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

/* Function Declarations */
int addStudent(struct Student s[], int count);
void searchStudent(struct Student s[], int count);
void displayAllStudents(struct Student s[], int count);
int deleteStudent(struct Student s[], int count);

int main(void) {
    /* Pre-load 5 sample students so all features work immediately */
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
        printf("1. Add Student Details\n");
        printf("2. Search Student Record\n");
        printf("3. Calculate CGPA of Each Student (Coming soon)\n");
        printf("4. Calculate Year-Wise Average CGPA (Coming soon)\n");
        printf("5. Display All Students\n");
        printf("6. Delete a Student Record\n");
        printf("7. Display Sorted by SAP ID (Coming soon)\n");
        printf("8. Display Sorted by Name (Coming soon)\n");
        printf("9. AI-Assisted Academic Advisor (Coming soon)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: count = addStudent(s, count); break;
            case 2: searchStudent(s, count); break;
            case 5: displayAllStudents(s, count); break;
            case 6: count = deleteStudent(s, count); break;
            case 3:
            case 4:
            case 7:
            case 8:
            case 9:
                printf("Feature %d will be added in Commit 3 or 4.\n", choice);
                break;
            case 0: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

/* 1. Add a new student record and return updated count */
int addStudent(struct Student s[], int count) {
    if (count >= MAX) {
        printf("List is full!\n");
        return count;
    }

    struct Student st;
    printf("Enter SAP ID: ");
    scanf("%ld", &st.sap_id);
    printf("Enter Roll No: ");
    scanf("%s", st.roll_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", st.name);
    printf("Enter Phone No: ");
    scanf("%s", st.phone);
    printf("Enter Email ID: ");
    scanf("%s", st.email);
    printf("Enter Year (1-4): ");
    scanf("%d", &st.year);
    printf("Enter Current Semester (1-8): ");
    scanf("%d", &st.semester);

    for (int i = 0; i < 8; i++) {
        if (i < st.semester) {
            printf("Enter Semester %d SGPA: ", i + 1);
            scanf("%f", &st.sgpa[i]);
        } else {
            st.sgpa[i] = -1;
        }
    }

    s[count] = st;
    printf("Student added successfully!\n");
    return count + 1;
}

/* 2. Search for a student by SAP ID and display details */
void searchStudent(struct Student s[], int count) {
    long id;
    printf("Enter SAP ID to search: ");
    scanf("%ld", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].sap_id == id) {
            printf("\nSAP ID: %ld | Roll No: %s | Name: %s\n", s[i].sap_id, s[i].roll_no, s[i].name);
            printf("Phone: %s | Email: %s | Year: %d | Sem: %d\n", s[i].phone, s[i].email, s[i].year, s[i].semester);
            return;
        }
    }
    printf("Student not found.\n");
}

/* 5. Display all student records */
void displayAllStudents(struct Student s[], int count) {
    printf("\n%-10s %-11s %-16s %-11s %-19s %-4s %-4s\n",
           "SAP ID", "Roll No", "Name", "Phone", "Email", "Yr", "Sem");
    for (int i = 0; i < count; i++) {
        printf("%-10ld %-11s %-16s %-11s %-19s %-4d %-4d\n",
               s[i].sap_id, s[i].roll_no, s[i].name, s[i].phone,
               s[i].email, s[i].year, s[i].semester);
    }
}

/* 6. Delete a student record by SAP ID and return updated count */
int deleteStudent(struct Student s[], int count) {
    long id;
    printf("Enter SAP ID to delete: ");
    scanf("%ld", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].sap_id == id) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            printf("Student record deleted.\n");
            return count - 1;
        }
    }
    printf("Student not found.\n");
    return count;
}