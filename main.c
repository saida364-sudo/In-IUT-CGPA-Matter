#include <stdio.h>
#include <string.h>
#include "course.h"
#include "courseResult.h"
#include "student.h"
#include "gpa.h"

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;
    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);

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
    
    int semesters[100];
    int n_semesters = getUniqueSemesters(results, n_courses, semesters);

    for (int s = 0; s < n_semesters; s++)
    {
        int currentSemester = semesters[s];
        printf("\n=============================\n");
        printf("Semester %d\n", currentSemester);
        printf("=============================\n");

        CourseResult filteredResults[1000];
        int n_filtered = filterBySemester(results, n_courses, currentSemester, filteredResults);

        for (int i = 0; i < n_filtered; i++)
        {
            viewCourseResult(filteredResults[i]);
            if (filteredResults[i].isCompleted)
            {
                printf("Grade: %s (GP: %.2f)\n\n", getLetterGrade(filteredResults[i]), getGradePoint(filteredResults[i].marks));
            }
            else
            {
                printf("Grade: N/A\n\n");
            }
        }

        double semesterGPA = calculateGPA(filteredResults, n_filtered);
        printf("Semester %d GPA: %.2f\n", currentSemester, semesterGPA);
    }

    double finalGPA = calculateGPA(results, n_courses);
    printf("\n---------------------------\n");
    printf("Calculated Overall CGPA: %.2f\n", finalGPA);
    printf("---------------------------\n");
printf("\n--- Expected CGPA Calculator ---\n");
double currentCGPA, completedCredits, expectedMarks, remainingCredits;

printf("Enter your current CGPA: ");
scanf("%lf", &currentCGPA);
printf("Enter your total completed credits: ");
scanf("%lf", &completedCredits);
printf("Enter your expected marks for remaining courses (out of 100): ");
scanf("%lf", &expectedMarks);
printf("Enter your remaining credits: ");
scanf("%lf", &remainingCredits);

double expectedCGPA = getExpectedCGPA(currentCGPA, completedCredits, expectedMarks, remainingCredits);
printf("Based on your input, your expected CGPA will be: %.2f\n", expectedCGPA);
Student s1 = createStudent("John Doe", "12345");
Course c1 = createCourse("CSE 4202", "SP2", 3.0, 4);
CourseResult r1 = createCourseResult(&c1, 85.0, 1);
addCourseResult(&s1, r1);
printf("Student: %s (ID: %s)\n", s1.name, s1.id);
printf("CGPA: %.2f\n", calculateStudentCGPA(s1));

void displayRankedStudents(Student students[], int n) {
    printf("\n--- Student Ranking (Descending CGPA) ---\n");
    printf("Rank\tName\t\tCGPA\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        // Calculate CGPA once for display
        float cgpa = calculateStudentCGPA(students[i]);
        printf("%d\t%s\t\t%.2f\n", i + 1, students[i].name, cgpa);
    }
}
    return 0;
}