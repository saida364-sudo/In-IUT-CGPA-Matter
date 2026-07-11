#ifndef COURSE_H
#define COURSE_H

typedef struct {
    char code[10];
    char name[50];
    double credit;
    int semester;
} Course;

Course createCourse(char code[], char name[], double credit, int semester);

#endif