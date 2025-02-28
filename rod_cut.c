#include "rod_cut.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }


  // Read pairs (length, value) from input
  int lengths[MAX_LINES];
  int values[MAX_LINES];
  int pieceCount = parse_input_file(argv[1], lengths, values);

  // if there isn't anything to read, notify user
  if (pieceCount == 0) {
    fprintf(stderr, "No piece definitions read from input!\n");
    return EXIT_FAILURE;
  }

  // Cache
  rod_cut_provider = initialize_cache(solve_rod_cutting);
  if (!rod_cut_provider) {
      fprintf(stderr, "Error: Failed to initialize cache.\n");
      return EXIT_FAILURE;
  }
  // Read rod lengths from stdin and compute results
  read_input(lengths, values, pieceCount);
  
  return EXIT_SUCCESS;
}