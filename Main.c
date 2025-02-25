/*

Assignment: Developing a Student Grades Management System
Date: February 25, 2025
Student Name: Shayne McNeil
Student ID: W0454809

*/

#include <stdio.h>

int validateGrade(float grade) {
    if(grade < 0 || grade > 100) {
        printf("Invalid grade. Try again. \n");
        return 0;
    } else {
        return 1;
    }
}; 

float setMathGrade() {
    float grade;
    printf("Enter student's grade for Math: \n");
    scanf("%f", &grade);
    int isGradeValid = validateGrade(grade);
    if(isGradeValid == 1) {
        return grade;
    } else {
        return setMathGrade();
    }
}

float setPhysicsGrade() {
    float grade;
    printf("Enter student's grade for Physics: \n");
    scanf("%f", &grade);
    int isGradeValid = validateGrade(grade);
    if(isGradeValid == 1) {
        return grade;
    } else {
        return setPhysicsGrade();
    }
}

float setCompSciGrade() {
    float grade;
    printf("Enter student's grade for Computer Science: \n");
    scanf("%f", &grade);
    int isGradeValid = validateGrade(grade);
    if(isGradeValid == 1) {
        return grade;
    } else {
        return setCompSciGrade();
    }
}

int main() {

    int program_status = 1; // Set program status to track whether user wants to continue or not. Set to 1 to initiate the program.
    int number_students_processed = 0; // Set total number of students processed to 0 
    float class_average = 0; // Set class average to 0 to start

    while(program_status == 1) { // While user wants to continue, do this.
        // Prompt the user to input student details and ensure grades are between 0 and 100

        char student_fname[50];
        char student_lname[50];

        printf("Enter student's first name: \n");
        scanf("%s", &student_fname);
        printf("Enter student's last name: \n");
        scanf("%s", &student_lname);

        float math_grade = setMathGrade();
        float physics_grade = setPhysicsGrade();
        float computer_science_grade = setCompSciGrade();

        /* while(math_grade < 0 || math_grade > 100) {
            printf("Enter student's grade for Math: \n");
            scanf("%d", &math_grade);

            if(math_grade < 0 || math_grade > 100) {
                printf("Invalid input. Try again. \n");
            }
        }

        while(physics_grade < 0 || physics_grade > 100) {
            printf("Enter the student's grade for Physics: \n");
            scanf("%d", physics_grade);

            if(physics_grade < 0 || physics_grade > 100) {
                printf("Invalid input. Try again. \n");
            }
        }

        while(computer_science_grade < 0 || computer_science_grade > 100) {
            printf("Enter the student's grade for Computer Science: \n");
            scanf("%d", computer_science_grade);

            if(computer_science_grade < 0 || computer_science_grade > 100) {
                printf("Invalid input. Try again. \n");
            }
        } */

        float total_marks = math_grade + physics_grade + computer_science_grade;
        float average_marks = total_marks / 3;
        int pass_status = 0;

        if(average_marks >= 50) {
            pass_status = 1;
        }

        // Calculate and display total marks for student
        printf("Results for %s %s: \n", student_fname, student_lname);
        printf("Total Marks: %.2f \n", total_marks);
        printf("Average Marks: %.2f \n", average_marks);
        if(pass_status == 1) {
            printf("Status: Pass \n");
        } else {
            printf("Status: Fail \n");
        }

        number_students_processed++; // Add the current student processed to number of students processed total
        class_average += average_marks;
        class_average /= number_students_processed;

        int user_input = 0;
        printf("Would you like to process another student? Write 1 for yes and 0 for no. \n");
        scanf("%d", &user_input);

        if(user_input == 0) {
            printf("Total Students Added: %d \n", number_students_processed);
            printf("Class Average Marks: %.2f \n", class_average);
            printf("PROGRAM END.\n");
            program_status = 0;
            continue;
        } else {
            printf("Alright, let's add another student. \n");
            continue;
        }
    }
    
    return 0;
}