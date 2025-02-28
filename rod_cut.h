#ifndef ROD_CUT_H
#define ROD_CUT_H


#define MAX_ROD_LENGTH 10000
#define MAX_LINES 100
#define MAX_MEMOIZED 100
#define ARRAY_SIZE MAX_MEMOIZED
#define NO_VALUE_YET -1

typedef int (*rod_cut_func_ptr)(int rodLength, int lengths[], int values[], int pieceCount);
extern rod_cut_func_ptr rod_cut_provider;


int parse_input_file(const char *filename, int lenghts[], int values[]);
void read_input(int lengths[], int values[], int peiceCount);
int solve_rod_cutting(int rodLength, int lengths[], int values[], int peiceCount);
void print_solution(int rodLength, int lengths[], int values[], int peiceCount);
rod_cut_func_ptr initialize_cache(rod_cut_func_ptr real_provider);


#endif