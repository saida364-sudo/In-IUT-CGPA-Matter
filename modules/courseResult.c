#include <stdio.h>
#include "courseResult.h"

CourseResult createCourseResult(Course *course, double marks, int isCompleted)
{
    CourseResult result;
    result.course = *course;
    result.marks = marks;
    result.isCompleted = isCompleted;
    return result;
}

void viewCourseResult(CourseResult result)
{
    printf("%s: %s\t\t [Credit: %.1f]\n",
           result.course.code, result.course.name, result.course.credit);
    if (result.isCompleted)
    {
        printf("Marks: %.2f\n", result.marks);
    }
    else
    {
        printf("Marks: Incomplete\n");
    }
}