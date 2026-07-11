#include <stdio.h>
#include <assert.h>
#include "gpa.h"

int testRequiredGPA()
{
    double required = calculateRequiredGPA(3.0, 15.0, 3.25, 15.0);
    return (required >= 3.49 && required <= 3.51); 
}

int main()
{
    printf("GPA module tests\n");
    if (testRequiredGPA())
    {
        printf("Required GPA test passed!\n");
        return 0;
    }
    else
    {
        printf("Required GPA test failed!\n");
        return 1;
    }
}