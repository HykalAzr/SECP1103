#include <stdio.h>
#include <string.h>

//#define ENABLE_MANUAL_DEBUG
#define MAX_STUDENTS 50
#define MAX_QUESTIONS 20
#define MAX_LENS 20

void readFile(char students_Name[][MAX_LENS], char students_Id[][MAX_LENS], char students_Answer[][MAX_QUESTIONS], int* numStudents, char* ansScheme) {
    FILE* file = fopen("C:\\Users\\HAIKAL\\GitHubRepo\\SECP1103\\ProjectAssignment\\InputFile\\StudentAnswers.dat", "r"); // Absolute Path
    //FILE* file = fopen("InputFile\\StudentAnswers.dat", "r"); // Relative Path
    if (file == NULL) {
        printf("Error opening student file.\n");
        return;
    }
    
    FILE* fileAns = fopen("C:\\Users\\HAIKAL\\GitHubRepo\\SECP1103\\ProjectAssignment\\InputFile\\CorrectAnswer.txt", "r"); // Absolute Path
    //FILE* fileAns = fopen("InputFile\\CorrectAnswer.txt", "r"); // Relative Path
    if (fileAns == NULL) {
        printf("Error reading answer file.\n");
        return;
    }
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        fscanf(fileAns, " %c", ansScheme + i);
    }

    *numStudents = 0;

    #ifdef ENABLE_MANUAL_DEBUG
    printf("numStudents\t: %d\n", *numStudents);
    #endif
    
    while (!feof(file) && *numStudents < MAX_STUDENTS) {
        fscanf(file, "%s %s", students_Name[*numStudents], students_Id[*numStudents]);
        for (int i = 0; i < MAX_QUESTIONS; i++) {
            fscanf(file, " %c ", students_Answer[*numStudents] + i);
        }
        (*numStudents)++;
        #ifdef ENABLE_MANUAL_DEBUG
        //printf("students_Name\t: %s\n", students_Name[*numStudents]);
        printf("numStudents\t: %d\n", *numStudents);
        #endif
    }

    fclose(file);
    fclose(fileAns);
}

void compareAnswer(const char correctAnswers[MAX_QUESTIONS], const char student_Name[MAX_LENS], const char student_Id[MAX_LENS], const char student_Answer[MAX_LENS], int* numMissed, int missedQuestions[], char missedAnswers[][2]) {
    *numMissed = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (student_Answer[i] != correctAnswers[i]) {
            missedQuestions[*numMissed] = i + 1;
            missedAnswers[*numMissed][0] = correctAnswers[i];
            missedAnswers[*numMissed][1] = student_Answer[i];
            (*numMissed)++;
        }
    }
}

void printMissQuestion(const int numMissed, const int missedQuestions[], const char missedAnswers[][2]) {
    printf("List of the questions missed:\n");
    printf("Question\tCorrect Answer\tStudent Answer\n");

    for (int i = 0; i < numMissed; i++) {
        printf("%-8d\t%c\t\t%c\n", missedQuestions[i], missedAnswers[i][0], missedAnswers[i][1]);
    }
}

void printReport(const char correctAnswers[], const char students_Name[MAX_STUDENTS][20], const char students_Id[MAX_STUDENTS][20], const char students_Answer[MAX_STUDENTS][MAX_QUESTIONS], const int numStudents, int missedQuestions[], char missedAnswers[][2]) {
    FILE* file = fopen("C:\\Users\\HAIKAL\\GitHubRepo\\SECP1103\\ProjectAssignment\\OutputFile\\GradeReport.txt", "w"); // Absolute Path
    // FILE* file = fopen("OutputFile\\GradeReport.txt", "w"); // Relative Path

    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }

    fprintf(file, "LIST OF STUDENTS AND GRADES\n\n");
    fprintf(file, "NAME\t\t\tID\t\t\t\tPERCENTAGE\tGRADE\n");

    for (int i = 0; i < numStudents; i++) {
        int numMissed;
        compareAnswer(correctAnswers, students_Name[i], students_Id[i], students_Answer[i], &numMissed, missedQuestions, missedAnswers);
        float percentage = (float)(MAX_QUESTIONS - numMissed) / MAX_QUESTIONS * 100;
        char grade;

        if (percentage >= 80) {
            grade = 'A';
        } else if (percentage >= 70) {
            grade = 'B';
        } else if (percentage >= 60) {
            grade = 'C';
        } else {
            grade = 'F';
        }

        #ifdef ENABLE_MANUAL_DEBUG
        printf("%-12s\t%s\t\t%.0f%%\t\t\t%c\n", students_Name[i], students_Id[i], percentage, grade);
        #endif

        fprintf(file, "%-12s\t%s\t\t%.0f%%\t\t\t%c\n", students_Name[i], students_Id[i], percentage, grade);
    }

    fclose(file);
}


int main() {

    int numStudents = 0;
    int missedQuestions[MAX_QUESTIONS];
    char missedAnswers[MAX_QUESTIONS][2];
    char studentID[MAX_LENS];
    char ansScheme[MAX_QUESTIONS];

    char students_Name[MAX_STUDENTS][MAX_LENS];
    char students_Id[MAX_STUDENTS][MAX_LENS];
    char students_Answer[MAX_STUDENTS][MAX_QUESTIONS];

    readFile(students_Name, students_Id, students_Answer, &numStudents, ansScheme);

    #ifdef ENABLE_MANUAL_DEBUG
    printf("numStudent\t: %d\n", numStudents);
    printf("Answer\t: %s\n", ansScheme);
    #endif

    while(1) {
        printf("Enter the student ID (put 0 to print report & exit): ");
        scanf("%s", studentID);

        if(strcmp(studentID, "0") == 0)
            break;
        
        char student_NameOut[MAX_LENS];
        char student_IdOut[MAX_LENS];
        char student_AnswerOut[MAX_QUESTIONS];
        int found = 0;
        for (int i = 0; i < numStudents; i++) {
            if (strcmp(students_Id[i], studentID) == 0) {
                strcpy(student_NameOut, students_Name[i]);
                strcpy(student_IdOut, students_Id[i]);
                strncpy(student_AnswerOut, students_Answer[i], 20);
                #ifdef ENABLE_MANUAL_DEBUG
                printf("%-12s\t%s\t\n", student_NameOut, student_IdOut);
                #endif
                found = 1;
                break;
            }
        }

        if (found) {
            int numMissed;

            compareAnswer(ansScheme, student_NameOut, student_IdOut, student_AnswerOut, &numMissed, missedQuestions, missedAnswers);

            printf("\nEXAM RESULT\n\n");
            printf("Name\t\t: %s\n", student_NameOut);
            printf("Student ID\t: %s\n", student_IdOut);
            printf("Number of questions missed.\t: %d\n\n", numMissed);
            printMissQuestion(numMissed, missedQuestions, missedAnswers);

            float percentage = (float)(MAX_QUESTIONS - numMissed) / MAX_QUESTIONS * 100;
            char grade;

            if (percentage >= 80) {
                grade = 'A';
            } else if (percentage >= 70) {
                grade = 'B';
            } else if (percentage >= 60) {
                grade = 'C';
            } else {
                grade = 'F';
            }

            printf("\nPercentage: %.0f%%, GRADE : %c\n", percentage, grade);
        } else {
            printf("Student not found.\n");
        }

    }

    printReport(ansScheme, students_Name, students_Id, students_Answer, numStudents, missedQuestions, missedAnswers);

    return 0;
}