#include <stdio.h>
#include <string.h>
#include "student.h"

Student createStudent(char name[], char id[]) {
    Student s;
    strcpy(s.name, name);
    strcpy(s.id, id);
    s.n_results = 0;
    return s;
}

void addCourseResult(Student *student, CourseResult result) {
    student->results[student->n_results++] = result;
}

double calculateStudentCGPA(Student student) {
    double totalPoints = 0;
    double totalCredits = 0;
    for (int i = 0; i < student.n_results; i++) {
    
        totalPoints += getGradePoint(student.results[i].marks) * student.results[i].course.credit;
        totalCredits += student.results[i].course.credit;
    }
    return (totalCredits == 0) ? 0 : (totalPoints / totalCredits);
}