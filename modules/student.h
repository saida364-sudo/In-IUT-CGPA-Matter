#ifndef STUDENT_H
#define STUDENT_H

#include "courseResult.h"

typedef struct Student {
    char name[100];
    char id[20];
    CourseResult results[100];
    int n_results;
} Student;

Student createStudent(char name[], char id[]);
void addCourseResult(Student *student, CourseResult result);
double calculateStudentCGPA(Student student);
void rankStudents(Student students[], int n);
#endif