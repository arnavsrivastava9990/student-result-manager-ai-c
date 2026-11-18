# AI-Assisted Student Record and Result Management System

**University:** University of Petroleum and Energy Studies (UPES)  
**Program:** B.Tech CSE — Semester I  
**Course:** Programming in C (`PRC1001`)  
**Author:** Arnav Srivastava (`590042233`)

## Overview

A console-based, menu-driven Student Record and Result Management System written in C. The application manages student profiles, computes semester-based CGPAs and year-wise averages, supports sorting and deletion, and includes an **AI-Assisted Academic Advisor** implemented with `if-else` decision logic.

## Features

### Part A — Core C Functionality
1. **Add Student Details:** Stores SAP ID, Roll No., Name, Phone No., Email ID, Year (1st–4th), Current Semester (1–8), and SGPAs for all 8 semesters (pre-loaded with 5 sample students).
2. **Search & Display Record:** Looks up a student by SAP ID and prints their full profile, CGPA, and academic advice.
3. **Individual CGPA Calculation:** Computes each student's CGPA from their available semester SGPAs.
4. **Year-Wise Average CGPA:** Calculates the average CGPA across students in each academic year (1st to 4th).
5. **Display All Records:** Prints a formatted summary table of all stored students.
6. **Delete Student Record:** Removes a student record by SAP ID.
7. **Sort by SAP ID:** Displays all student records in increasing order of SAP ID.
8. **Sort by Name:** Displays all student records in increasing alphabetical order of Name.

### Part B — AI-Assisted Academic Advisor
Evaluates each student's CGPA using `if-else` rules designed with AI assistance and verified manually:
- **8.50 – 10.00:** Excellent performance
- **7.00 – 8.49:** Good performance
- **5.50 – 6.99:** Needs improvement
- **Below 5.50:** Requires immediate attention

## Repository Structure

```text
├── 590042233.c
├── README.md
├── AI_USAGE_LOG.md
└── tests/
    ├── sample_input.txt
    └── sample_output.txt
```

## How to Compile and Run

```bash
gcc 590042233.c -o student_system
./student_system
```

On Windows (MinGW):

```bash
gcc 590042233.c -o student_system.exe
student_system.exe
```

## Sample Test Run

You can feed the test inputs directly from the `tests/` folder:

```bash
./student_system < tests/sample_input.txt
```
