#include <stdio.h>
#include <string.h>
#include "student.h"

int testCreateStudent() {
    Student s = createStudent("John Doe", "12345");
    return strcmp(s.name, "John Doe") == 0 && strcmp(s.id, "12345") == 0;
}

int testAddCourseResult() {
    Student s = createStudent("John Doe", "12345");
    Course c = createCourse("CSE 4202", "SP2", 3.0, 4); 
    
    CourseResult r = createCourseResult(&c, 85.0, 1); 
    addCourseResult(&s, r);
    return s.n_results == 1;
}

int main() {
    printf("Student module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCreateStudent()) passed++;

    total++;
    if (testAddCourseResult()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    return (passed == total) ? 0 : 1;
    return 0;
}