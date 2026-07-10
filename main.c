#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;

    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0);

    for (int i = 0; i < n_courses; i++)
    {
        int isCompleted;
        double marks = 0.0;
        
        printf("Is %s completed? (1 for Yes, 0 for No): ", courses[i].name);
        scanf("%d", &isCompleted);
        
        if (isCompleted)
        {
            printf("Marks for %s: ", courses[i].name);
            scanf("%lf", &marks);
        }
        
        results[i] = createCourseResult(&courses[i], marks, isCompleted);
    }

    printf("\n--- Academic Transcript ---\n");
    for (int i = 0; i < n_courses; i++)
    {
        viewCourseResult(results[i]);
        if (results[i].isCompleted)
        {
            printf("Grade: %s (GP: %.2f)\n\n", getLetterGrade(results[i]), getGradePoint(results[i]));
        }
        else
        {
            printf("Grade: N/A\n\n");
        }
    }

    double finalGPA = calculateGPA(results, n_courses);
    printf("---------------------------\n");
    printf("Calculated CGPA: %.2f\n", finalGPA);
    printf("---------------------------\n");

    return 0;
}