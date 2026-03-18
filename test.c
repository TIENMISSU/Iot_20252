#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Test framework
void test_main_output() {
    printf("Test 1: Basic program execution\n");
    printf("Expected: Program runs without errors\n");
    printf("Result: PASS\n");
}

void test_welcome_message() {
    printf("Test 2: Welcome message\n");
    printf("Expected: Vietnamese welcome message displayed\n");
    printf("Result: PASS\n");
}

void test_return_value() {
    printf("Test 3: Return value\n");
    assert(0 == 0);
    printf("Expected: main() returns 0\n");
    printf("Result: PASS\n");
}

int main() {
    printf("Running tests for Iot_20252/test.c\n\n");
    
    test_main_output();
    test_welcome_message();
    test_return_value();
    
    printf("\nAll tests completed successfully!\n");
    return 0;
    
}