#include "gpa.h"

const double gradeBoundaries[] = {80, 75, 70, 65, 60, 55, 50, 45, 40};
const double gradePoints[] = {4.00, 3.75, 3.50, 3.25, 3.00, 2.75, 2.50, 2.25, 2.00};
const char *gradeLetters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D"};

double getPercentage(CourseResult result)
{
    double full_marks = result.course.credit * 100.0;
    if (full_marks <= 0.0) return 0.0;
    return (result.marks / full_marks) * 100.0;
}

double getGradePoint(double marks) {
    if (marks >= 80) return 4.0;
    return 0.0;
}

char *getLetterGrade(CourseResult result)
{
    double percentage = getPercentage(result);
    for (int i = 0; i < 9; i++)
    {
        if (percentage >= gradeBoundaries[i]) return (char *) gradeLetters[i];
    }
    return "F";
}

double calculateGPA(CourseResult results[], int n) {
    double totalPoints = 0;
    double totalCredits = 0;
    for (int i = 0; i < n; i++) {
        totalPoints += getGradePoint(results[i].marks) * results[i].course.credit;
        totalCredits += results[i].course.credit;
    }
    return totalPoints / totalCredits;
}
double getExpectedCGPA(double currentCGPA, double completedCredits, double expectedMarks, double remainingCredits) {
    double totalEarnedPoints = currentCGPA * completedCredits;
    double expectedPoints = (expectedMarks / 100.0) * 4.0 * remainingCredits; // Based on 4.0 scale
    return (totalEarnedPoints + expectedPoints) / (completedCredits + remainingCredits);
}