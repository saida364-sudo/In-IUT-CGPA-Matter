#ifndef COURSE_RESULT_H
#define COURSE_RESULT_H

#include "course.h"

typedef struct CourseResult
{
    Course course;
    double marks;
    int isCompleted; 
} CourseResult;

CourseResult createCourseResult(Course *course, double marks, int isCompleted);
void viewCourseResult(CourseResult result);

#endif
int filterBySemester(CourseResult results[], int n_results, int semester, CourseResult filtered[]);
int getUniqueSemesters(CourseResult results[], int n_results, int semesters[]);