/*
 * Project Title : AI-Assisted Student Record and Result Management System
 * Course        : Programming in C (PRC1001) - B.Tech CSE, Semester I
 * University    : University of Petroleum and Energy Studies (UPES)
 * SAP ID        : 590042233
 * Commit 3      : Sorting and CGPA functions (CGPA, year average, sort by SAP ID/Name)
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
float calculateCGPA(struct Student st);
void displayAllCGPAs(struct Student s[], int count);
void yearAverageCGPA(struct Student s[], int count);
void displayAllStudents(struct Student s[], int count);
int deleteStudent(struct Student s[], int count);
void sortBySapId(struct Student s[], int count);
void sortByName(struct Student s[], int count);

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
        printf("3. Calculate CGPA of Each Student\n");
        printf("4. Calculate Year-Wise Average CGPA\n");
        printf("5. Display All Students\n");
        printf("6. Delete a Student Record\n");
        printf("7. Display Sorted by SAP ID\n");
        printf("8. Display Sorted by Name\n");
        printf("9. AI-Assisted Academic Advisor (Coming soon)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: count = addStudent(s, count); break;
            case 2: searchStudent(s, count); break;
            case 3: displayAllCGPAs(s, count); break;
            case 4: yearAverageCGPA(s, count); break;
            case 5: displayAllStudents(s, count); break;
            case 6: count = deleteStudent(s, count); break;
            case 7: sortBySapId(s, count); break;
            case 8: sortByName(s, count); break;
            case 9: printf("AI-Assisted Academic Advisor will be added in Commit 4.\n"); break;
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
            float cgpa = calculateCGPA(s[i]);
            printf("\nSAP ID: %ld | Roll No: %s | Name: %s\n", s[i].sap_id, s[i].roll_no, s[i].name);
            printf("Phone: %s | Email: %s | Year: %d | Sem: %d\n", s[i].phone, s[i].email, s[i].year, s[i].semester);
            printf("CGPA: %.2f\n", cgpa);
            return;
        }
    }
    printf("Student not found.\n");
}

/* 3. Calculate CGPA from available SGPA values */
float calculateCGPA(struct Student st) {
    float sum = 0;
    int sem_count = 0;
    for (int i = 0; i < 8; i++) {
        if (st.sgpa[i] >= 0) {
            sum += st.sgpa[i];
            sem_count++;
        }
    }
    if (sem_count == 0) return 0;
    return sum / sem_count;
}

void displayAllCGPAs(struct Student s[], int count) {
    printf("\n--- CGPA of Each Student ---\n");
    for (int i = 0; i < count; i++) {
        printf("%ld  %-18s  CGPA: %.2f\n", s[i].sap_id, s[i].name, calculateCGPA(s[i]));
    }
}

/* 4. Calculate average CGPA for each year (1st to 4th) */
void yearAverageCGPA(struct Student s[], int count) {
    printf("\n--- Year-Wise Average CGPA ---\n");
    for (int yr = 1; yr <= 4; yr++) {
        float sum = 0;
        int yr_students = 0;
        for (int i = 0; i < count; i++) {
            if (s[i].year == yr) {
                sum += calculateCGPA(s[i]);
                yr_students++;
            }
        }
        if (yr_students > 0) {
            printf("Year %d: Average CGPA = %.2f (%d student(s))\n", yr, sum / yr_students, yr_students);
        } else {
            printf("Year %d: No students\n", yr);
        }
    }
}

/* 5. Display all student records */
void displayAllStudents(struct Student s[], int count) {
    printf("\n%-10s %-11s %-16s %-11s %-19s %-4s %-4s %-5s\n",
           "SAP ID", "Roll No", "Name", "Phone", "Email", "Yr", "Sem", "CGPA");
    for (int i = 0; i < count; i++) {
        printf("%-10ld %-11s %-16s %-11s %-19s %-4d %-4d %.2f\n",
               s[i].sap_id, s[i].roll_no, s[i].name, s[i].phone,
               s[i].email, s[i].year, s[i].semester, calculateCGPA(s[i]));
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

/* 7. Sort and display students in increasing order of SAP ID */
void sortBySapId(struct Student s[], int count) {
    struct Student temp[MAX];
    for (int i = 0; i < count; i++) temp[i] = s[i];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j].sap_id > temp[j + 1].sap_id) {
                struct Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }
    printf("\n--- Sorted by SAP ID ---");
    displayAllStudents(temp, count);
}

/* 8. Sort and display students in increasing order of Name */
void sortByName(struct Student s[], int count) {
    struct Student temp[MAX];
    for (int i = 0; i < count; i++) temp[i] = s[i];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0) {
                struct Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }
    printf("\n--- Sorted by Name ---");
    displayAllStudents(temp, count);
}