#include <stdio.h>
#include "course.h"
#include "courseResult.h"

int testFilterBySemester()
{
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Course c2 = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    Course c3 = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

    CourseResult results[3] = {
        createCourseResult(&c1, 240, 1),
        createCourseResult(&c2, 105, 1),
        createCourseResult(&c3, 210, 1)
    };

    CourseResult filtered[3];
    int count = filterBySemester(results, 3, 1, filtered);

    return (count == 2) && (filtered[0].course.semester == 1) && (filtered[1].course.semester == 1);
}

int testGetUniqueSemesters()
{
    Course c1 = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Course c2 = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    Course c3 = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

    CourseResult results[3] = {
        createCourseResult(&c1, 240, 1),
        createCourseResult(&c2, 105, 1),
        createCourseResult(&c3, 210, 1)
    };

    int semesters[3];
    int count = getUniqueSemesters(results, 3, semesters);

    return (count == 2) && (semesters[0] == 1 || semesters[0] == 2);
}

int main()
{
    printf("Course result module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testFilterBySemester()) passed++;

    total++;
    if (testGetUniqueSemesters()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}