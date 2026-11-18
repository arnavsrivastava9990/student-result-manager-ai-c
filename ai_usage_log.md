# AI Usage Log

**Project:** AI-Assisted Student Record and Result Management System

**Course:** Programming in C (`PRC1001`)

**Student:** \[Your Name\] (`[Your SAP ID]`)

## AI Assistance Record

| AI Tool | Prompt / Question Asked | How I Used / Verified the Response | 
| ----- | ----- | ----- | 
| \[AI Tool Used, e.g., ChatGPT\] | Suggest simple CGPA-based academic advice categories and short messages for a C program. | Used the four suggested categories (Excellent Performance, Good Performance, Needs Improvement, Requires Immediate Attention), adjusted the CGPA thresholds (`8.5`, `7.0`, `5.5`), and implemented them using `if-else` statements in `aiAcademicAdvisor()`. | 
| \[AI Tool Used, e.g., ChatGPT\] | Provide test cases for a CGPA calculation function when some semesters are not yet completed. | Tested the suggested cases manually with `-1.0` as the sentinel value for uncompleted semesters and verified that `calculateCGPA()` divides only by the number of available SGPAs. | 
| \[AI Tool Used, e.g., GitHub Copilot / ChatGPT\] | How do I avoid `fgets` skipping input after `scanf` and sort names case-insensitively in standard C? | Added a `clearInputBuffer()` helper after `scanf` calls and wrote a portable `compareNamesIgnoreCase()` function using `tolower()` from `<ctype.h>`, then compiled with `gcc -Wall -Wextra -std=c11` to verify zero warnings. | 

## Verification & Key Takeaways

* Every AI-suggested snippet was reviewed, adapted to match the `Student` struct, and tested locally with `gcc` before committing.

* Sorting functions operate on a temporary copy of the student array so the original insertion order is preserved.

* At least three distinct CGPA cases (`9.15`, `7.60`, `5.80`, and `4.33`) are demonstrated in `tests/sample_output.txt`.