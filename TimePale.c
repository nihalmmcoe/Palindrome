#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

// Function to check if a string is a palindrome recursively
int isPalindrome(char *str, int start, int end) {
    // Base case: if we have checked all the characters
    if (start >= end) {
        return 1; // String is a palindrome
    }
    // Compare characters at the start and end
    if (*(str + start) != *(str + end)) {
        return 0; // String is not a palindrome
    }
    // Recursive call for the next pair of characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char input[MAX_INPUT_SIZE];
    int correctPalindromes = 0;
    time_t startTime, currentTime;

    // Get the current time
    time(&startTime);
    
    // Start the input loop
    printf("------------------------------------------\n");
    printf("   !!!Welcome to the palindrome game!!!\n");
    printf("------------------------------------------\n");
    printf("\n");
    
    printf("You have 1 minute to enter words.\n");
    printf("Game will check if they are palindromes.\n");
    printf("\n");
    printf("Your time has started...\n");
    printf("\n");

    while (1) {
        // Get the current time to check if 1 minutes have passed
        time(&currentTime);
        
        // Check if 1 minutes (60 seconds) have passed
        if (difftime(currentTime, startTime) >= 60) {
            break;
        }
        
        // Prompt user for input
        printf("Enter a word/words: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        
        // Remove the newline character at the end if present
        input[strcspn(input, "\n")] = '\0';
        
        // Check if the string is a palindrome using the recursive function
        if (isPalindrome(input, 0, strlen(input) - 1)) {
            printf("'%s' is a palindrome.\n", input);
            correctPalindromes++;
        } else {
            printf("'%s' is NOT a palindrome.\n", input);
        }
    }

    // Display the score after 2 minutes
    printf("\nTime's up! You entered %d correct palindrome(s).\n", correctPalindromes);
    
return 0;
}