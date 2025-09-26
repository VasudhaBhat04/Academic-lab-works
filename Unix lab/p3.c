
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <string.h>

// Global variable for setjmp/longjmp
jmp_buf env;

void testLinkAndUnlink() {
    // Create a new file
    FILE *file = fopen("testfile.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "This is a test file.\n");
    fclose(file);

    // Create a hard link to the file
    if (link("testfile.txt", "testfile_link.txt") == -1) {
        perror("Error creating hard link");
        exit(EXIT_FAILURE);
    }
    printf("Hard link created.\n");

    // Remove the original file
    if (unlink("testfile.txt") == -1) {
        perror("Error unlinking original file");
        exit(EXIT_FAILURE);
    }
    printf("Original file unlinked.\n");

    // Remove the hard link
    if (unlink("testfile_link.txt") == -1) {
        perror("Error unlinking hard link");
        exit(EXIT_FAILURE);
    }
    printf("Hard link unlinked.\n");
}

void testSetjmpLongjmp(int val) {
    
    int result = setjmp(env);
    if (result != 0) {
        // This code is executed when longjmp() is called
        printf("Returned to setjmp() after longjmp() with value %d\n", result);
        return;
    }
    printf("In setjmp() block.\n");

    // Simulate some condition
    if (val == 1) {
        // Jump back to the setjmp point with value 42
        longjmp(env, 42);
    }

    // This will not be printed if longjmp() is called
    printf("This will not be printed if longjmp() is called.\n");
}

int main() {
    printf("Demonstrating link() and unlink():\n");
    testLinkAndUnlink();

    printf("\nDemonstrating setjmp() and longjmp():\n");
    testSetjmpLongjmp(0);

    return 0;
}
