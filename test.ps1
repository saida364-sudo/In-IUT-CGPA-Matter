gcc -I modules modules\tests\test_course.c modules\course.c -o modules\tests\test_course.exe
.\modules\tests\test_course.exe

gcc -I modules modules\tests\test_course_result.c modules\course.c modules\courseResult.c -o modules\tests\test_course_result.exe
.\modules\tests\test_course_result.exe

gcc -I modules modules\tests\test_gpa.c modules\course.c modules\courseResult.c modules\gpa.c -o modules\tests\test_gpa.exe
.\modules\tests\test_gpa.exe