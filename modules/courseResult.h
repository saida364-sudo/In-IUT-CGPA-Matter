#ifndef COURSE_RESULT_H
#define COURSE_RESULT_H

#include "course.h"

typedef struct {
    Course course;
    double marks;
    int isCompleted; 
} CourseResult;

int getUniqueSemesters(CourseResult results[], int n, int semesters[]);
int filterBySemester(CourseResult results[], int n, int semester, CourseResult filtered[]);
void viewCourseResult(CourseResult result);

CourseResult createCourseResult(Course *course, double marks, int isCompleted);

#endif