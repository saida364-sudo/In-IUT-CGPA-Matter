#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int testCGPA()
{
    Course courses[2] = {
        createCourse("CSE 4107", "Structured Programming I", 3.0),
        createCourse("CSE 4108", "Structured Programming I Lab", 1.5)
    };
    CourseResult results[2] = {
        createCourseResult(&courses[0], 240, 1), // 80% -> 4.00
        createCourseResult(&courses[1], 105, 1)  // 70% -> 3.50
    };
    double expected = ((4.00 * 3.0) + (3.50 * 1.5)) / 4.5;
    double actual = calculateGPA(results, 2);
    return (actual - expected < 0.001) && (expected - actual < 0.001);
}

int testIncompleteCourse()
{
    Course courses[2] = {
        createCourse("CSE 4107", "Structured Programming I", 3.0),
        createCourse("CSE 4108", "Structured Programming I Lab", 1.5)
    };
    
    CourseResult results[2] = {
        createCourseResult(&courses[0], 240, 1),
        createCourseResult(&courses[1], 0, 0)
    };
    double expected = 4.00; 
    double actual = calculateGPA(results, 2);
    return (actual - expected < 0.001) && (expected - actual < 0.001);
}

int main()
{
    printf("GPA module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCGPA()) passed++;

    total++;
    if (testIncompleteCourse()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}