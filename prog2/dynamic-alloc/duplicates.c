#include <stdlib.h>
/*  Create a function called getDuplicates. This function will take in an array of integers
 *  along with its size, and your goal is to check the array for duplicates. Get all of the duplicates
 *  of the array and return this as an array to the calling function. If there are no duplicates found
 *  return an empty array.
*/

/* DON'T TOUCH THESE ARE TESTCASES */
int main(void) {
    int *dupes, i;

    int case1[] = { 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };
    int answers1[] = { 3, 4, 5, 6, 7 };
    dupes = getDuplicates(case1, sizeof(case1) / sizeof(int));
    for(i = 0; i < 5 && dupes[i] == answers1[i]; i++) {}
    printf("TEST CASE 1: %s", i == 5 ? "SUCCEEDED" : "FAILED");

    int case2[] = { 1, 1 };
    int answers2[] = { 1 };
    dupes = getDuplicates(case2, sizeof(case2) / sizeof(int));
    for(i = 0; i < 1 && dupes[i] == answers1[i]; i++) {}
    printf("TEST CASE 2: %s", i == 2 ? "SUCCEEDED" : "FAILED");

    int case3[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    dupes = getDuplicates(case3, sizeof(case3) / sizeof(int));
    printf("TEST CASE 3: %s", dupes == NULL ? "SUCCEEDED" : "FAILED");
}