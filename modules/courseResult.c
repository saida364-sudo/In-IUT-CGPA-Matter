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
int filterBySemester(CourseResult results[], int n_results, int semester, CourseResult filtered[])
{
    int count = 0;
    for (int i = 0; i < n_results; i++)
    {
        if (results[i].course.semester == semester)
        {
            filtered[count++] = results[i];
        }
    }
    return count;
}

int getUniqueSemesters(CourseResult results[], int n_results, int semesters[])
{
    int count = 0;
    for (int i = 0; i < n_results; i++)
    {
        int found = 0;
        for (int j = 0; j < count; j++)
        {
            if (semesters[j] == results[i].course.semester)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            semesters[count++] = results[i].course.semester;
        }
    }
    return count;
}