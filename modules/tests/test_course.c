#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"

int testCourseCode()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 1);
    return strcmp(course.code, "CSE 4202") == 0;
}

int testCourseName()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 1);
    return strcmp(course.name, "Structured Programming II Lab") == 0;
}

int testCourseCredit()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 1);
    return course.credit == 1.5;
}

int testDynamicCourseList()
{
    int capacity = 5;
    Course* list = createCourseList(capacity);
    
    int isNotNull = (list != NULL);
    
    freeCourseList(list);
    return isNotNull;
}

int main()
{
    printf("Course module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCourseCode()) passed++;

    total++;
    if (testCourseName()) passed++;

    total++;
    if (testCourseCredit()) passed++;

    total++;
    if (testDynamicCourseList()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}