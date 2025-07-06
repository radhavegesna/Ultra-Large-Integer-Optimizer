#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultralarge_int.h" 
#include "ultralarge_int.c"

// Structure to hold file data
typedef struct {
    ultralargeint *numbers;  // Pointer to dynamically allocated array of UltraLargeInt
    ultralargeint target;     // Target UltraLargeInt
    int size;                // Number of integers read
} FileData;

// Function to read the file and populate FileData
FileData read_file(const char *filename) {
    FileData data;
    data.numbers = NULL; // Initialize to NULL
    data.size = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the target
    char target_str[MAX_DIGITS]; // Assuming MAX_DIGITS is defined in ultralarge_int.h
    fscanf(file, "%s", target_str);
    init_large_int(&data.target); // Initialize target

    // Read the number of integers
    fscanf(file, "%d", &data.size);

    // Allocate memory for the UltraLargeInt array
    data.numbers = (ultralargeint *)malloc(data.size * sizeof(ultralargeint));
    if (data.numbers == NULL) {
        perror("Error allocating memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read the integers
    for (int i = 0; i < data.size; i++) {
        char number_str[MAX_DIGITS];
        fscanf(file, "%s", number_str);
        init_large_int(&data.numbers[i]); // Initialize each number
    }

    fclose(file);
    return data;
}

// Function to count pairs that match the target difference
int count_pairs(ultralargeint *data, int n, const ultralargeint *target) {
    int solutions = 0;

    // Sort the data using qsort
    qsort(data, n, sizeof(ultralargeint), compare_large_ints); // Implement this function

    for (int left = 0, right = n - 1; left < right;) {
        // Compare data[left] and data[right] with target
        ultralargeint diff;
         subtract_large_ints(&data[right], &data[left],&diff); // Implement this function
        if (compare_large_ints(&diff, target) == 0) {
            solutions++;
            left++;
            right--;
        } else if (compare_large_ints(&diff, target) < 0) {
            left++;
        } else {
            right--;
        }
    }
    return solutions;
}

// Function to count pairs from a file
int count_pairs_file(const char *filename) {
    FileData data = read_file(filename);
    int result = count_pairs(data.numbers, data.size, &data.target);

    // Free allocated memory
    free(data.numbers);
    return result;
}