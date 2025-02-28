#include "rod_cut.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


// Parses input file, Returns 0 if unable, Else returns number of valid pairs.
int parse_input_file(const char *filename, int lenghts[], int values[]) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file.");
    return 0;
  }

  int count = 0;
  while (fscanf(file, "%d,%d", &lenghts[count], &values[count]) == 2) {
    if (lenghts[count] <= 0 || values[count] < 0) {
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
  printf("valid pairs: %d\n", count);
  return count;
}

// Processes user input and validates it.
void read_input(int lengths[], int values[], int pieceCount) {
  int rodLength;
  printf("Enter rod Lengths, One per line, press Ctrl+D to stop:\n");
  while (scanf("%d", &rodLength) == 1) {
    if (rodLength <= 0) {
        fprintf(stderr, "Invalid rod length: %d. Must be positive.\n", rodLength);
        continue;
    }

    int max_value = (*rod_cut_provider)(rodLength, lengths, values, pieceCount);
  }
}
