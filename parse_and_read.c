#include "rod_cut.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


// Parses input file, Returns 0 if unable, Else returns number of valid pairs.
int parse_input_file(const char *filename, int lengths[], int values[]) {
  FILE *file = fopen(filename, "r");
  if (!file) {
      perror("Error opening file.");
      return 0;
  }

  int count = 0;
  printf("Reading input file: %s\n", filename);

  while (fscanf(file, "%d,%d", &lengths[count], &values[count]) == 2) {
      printf("Read pair: %d, %d\n", lengths[count], values[count]);

      if (lengths[count] <= 0 || values[count] < 0) {
          fprintf(stderr, "Invalid input: Lengths must be positive, values must be non-negative.\n");
          continue;
      }
      count++;
      if (count >= MAX_LINES) {
          fprintf(stderr, "Warning: Maximum number of input lines (%d) reached.\n", MAX_LINES);
          break;
      }
  }

  fclose(file);
  printf("Valid pairs read: %d\n", count);
  return count;
}

// Processes user input and validates it.
void read_input(int lengths[], int values[], int pieceCount) {
  int rodLength;
  printf("Enter rod Length, press Ctrl+D to stop:\n");

  while (scanf("%d", &rodLength) == 1) {
      if (rodLength <= 0) {
          fprintf(stderr, "Invalid rod length: %d. Must be positive.\n", rodLength);
          continue;
      }

      printf("Received rod length: %d\n", rodLength);

      // Check if function pointer is set
      if (!rod_cut_provider) {
          fprintf(stderr, "Error: rod_cut_provider is NULL! Segmentation fault likely here.\n");
          exit(EXIT_FAILURE);
      }

      // Call the rod cutting function
      printf("Calling rod_cut_provider(%d)...\n", rodLength);
      int max_value = (*rod_cut_provider)(rodLength, lengths, values, pieceCount);
      
      printf("Max Value computed: %d\n", max_value);
      print_solution(rodLength, lengths, values, pieceCount);
  }
}