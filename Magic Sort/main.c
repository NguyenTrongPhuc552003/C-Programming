#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/*
 * input: N natural numbers
 * output: N natural numbers sorted based on the sum of their digits
 * To solve this problem, we need to arrange a sequence of natural numbers according to the following rule:
 * - The sum of the digits of whichever number is smaller will be ranked first.
 * - If the sum of the digits of the numbers is equal, the smaller number will be placed first.
 * Description: The program reads N natural numbers from the user and sorts them based on the sum of their digits.
 * - The program uses the qsort function to sort the array of numbers based on the sum of their digits.
 * - The sum of digits of a number is calculated by dividing the number by 10 and adding the remainder to the sum.
 * - The compare function compares the sum of digits of two numbers and returns the difference.
 * - The magic_sort function splits the input string into an array of integers, sorts the array using qsort, and prints the sorted array.
 * */

// split string into array of integers
int *array_split(char [], int);

// sum of digits of a number
int sum_of_digits(int);

// compare function for qsort
int compare(const void *, const void *);

// sort the array based on the sum of digits of each element
void magic_sort(char [], int);

int main()
{
    char arr[100];
    int n;

    printf("Enter the amount: ");
    if (scanf_s("%d", &n) != 1) {
        printf("Invalid input for amount.\n");
        return 1;
    }

    // Consume the leftover newline character after scanf_s
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the array: ");
    if (fgets(arr, sizeof(arr), stdin) != NULL) {
        // Remove the newline character if it's present
        size_t length = strlen(arr);
        if (length > 0 && arr[length - 1] == '\n') {
            arr[length - 1] = '\0';
        }
        magic_sort(arr, n);
    } else {
        printf("Error reading input.\n");
    }
    return 0;
}

int *array_split(char arr[], int n) {
    int *result = (int*)malloc(n * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    int i = 0;
    char *token = strtok_s(arr, " ", &arr);
    while (token != NULL && i < n) {
        result[i++] = strtol(token, NULL, 10);
        token = strtok_s(NULL, " ", &arr);
    }
    return result;
}

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int compare(const void *a, const void *b) {
    int sum_a = sum_of_digits(*(int*)a);
    int sum_b = sum_of_digits(*(int*)b);
    if (sum_a == sum_b) {
        return *(int*)a - *(int*)b;
    }
    return sum_a - sum_b;
}

void magic_sort(char arr[], int n) {
    int *p = array_split(arr, n);
    if (p == NULL) {
        return;
    }
    qsort(p, n, sizeof(int), compare);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    free(p);
}
