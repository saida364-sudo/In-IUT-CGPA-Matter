#include "course.h"
#include <stdio.h>
#include <string.h>

Course createCourse(char code[], char name[], double credit, int semester)
{
    Course c;
    strcpy(c.code, code);
    strcpy(c.name, name);
    c.credit = credit;
    c.semester = semester;
    return c;
}

void viewCourse(Course course)
{
    printf("Code: %s\n", course.code);
    printf("Name: %s\n", course.name);
    printf("Credit: %.1f\n", course.credit);
    printf("Semester: %d\n", course.semester);
}