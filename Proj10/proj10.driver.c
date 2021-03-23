#include "/user/cse320/Projects/project10.support.h"
#include <stdio.h>
//	Jeffrey Valentic
//	December 2020
//	CSE 320 Project 10
//	Driver -> TESTING

int main()
{
    printf("\n============================================================\n");
    printf("\nCSE320 - Project 10 - Testing\n");
    // LENGTH Testing =====================================================================================================
    printf("\n============================================================\n");
    printf("\nLENGTH TEST\n\n");

    int len1 = length("TEST");
    int len2 = length("TEST1");
    int len3 = length("TEST12");
   
    int lenA1 = 4;
    int lenA2 = 5;
    int lenA3 = 6;
   
    printf("TEST 1: \t RESULT:   %d \n \t\t EXPECTED: %d \n \n", len1, lenA1);
    printf("TEST 2: \t RESULT:   %d \n \t\t EXPECTED: %d \n \n", len2, lenA2);
    printf("TEST 3: \t RESULT:   %d \n \t\t EXPECTED: %d \n \n", len3, lenA3);
    printf("\n");

    // COPY Testing =====================================================================================================
    printf("============================================================\n");
    printf("\nCOPY TEST\n\n");
    
    char dest1[100] = "destination";
    char dest2[100] = "this should say 'correct'";
    char dest3[100] = "this";

    const char *srce1 = "source";
    const char *srce2 = "correct";
    const char *srce3 = "that";

    copy(dest1, srce1);
    copy(dest2, srce2);
    copy(dest3, srce3);

    const char *copA1 = "source";
    const char *copA2 = "correct";
    const char *copA3 = "that";

    printf("TEST 1: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", dest1, copA1);
    printf("TEST 2: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", dest2, copA2);
    printf("TEST 3: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", dest3, copA3);
    printf("\n");

    // APPEND Testing =====================================================================================================
    printf("============================================================\n");
    printf("\nAPPEND TEST\n\n");
    
    char apDest1[100] = "A start: ";
    char apDest2[100] = "B start: ";
    char apDest3[100] = "C start: ";
    
    const char* apSrce1 = "Mars";
    const char* apSrce2 = "115";
    const char* apSrce3 = "UGHHH";
    
    append(apDest1, apSrce1);
    append(apDest2, apSrce2);
    append(apDest3, apSrce3);
    
    const char* appA1 = "A start: Mars";
    const char* appA2 = "B start: 115";
    const char* appA3 = "C start: UGHHH";
    
    printf("TEST 1: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", apDest1, appA1);
    printf("TEST 2: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", apDest2, appA2);
    printf("TEST 3: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", apDest3, appA3);
    printf("\n");

    // DUPLICATE Testing =====================================================================================================
    printf("============================================================\n");
    printf("\nDUPLICATE TEST\n\n");

    const char dSrce1[100] = "Mars";
    const char dSrce2[100] = "115";
    const char dSrce3[100] = "UGHHH";

    char* result1 = duplicate(dSrce1);
    char* result2 = duplicate(dSrce2);
    char* result3 = duplicate(dSrce3);

    printf("TEST 1: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", result1, dSrce1);
    printf("TEST 2: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", result2, dSrce2);
    printf("TEST 3: \t RESULT:   %s \n \t\t EXPECTED: %s \n \n", result3, dSrce3);
    printf("\n");

    // COMPARE Testing =====================================================================================================
    printf("============================================================\n");
    printf("\nCOMPARE TEST\n\n");

    const char* cSrce_A1 = "Mars";
    const char* cSrce_A2 = "Mark";

    const char* cSrce_B1 = "Artsy";
    const char* cSrce_B2 = "Zero";

    const char* cSrce_C1 = "Test1";
    const char* cSrce_C2 = "Test1";

    int comp1 = compare(cSrce_A1, cSrce_A2);
    int comp2 = compare(cSrce_B1, cSrce_B2);
    int comp3 = compare(cSrce_C1, cSrce_C2);

    printf("TEST 1: \t RESULT:   %d \n \t\t EXPECTED: + \n \n", comp1);
    printf("TEST 2: \t RESULT:   %d \n \t\t EXPECTED: - \n \n", comp2);
    printf("TEST 3: \t RESULT:   %d \n \t\t EXPECTED: 0 \n \n", comp3);
    printf("\n");
    printf("============================================================\n");
}
