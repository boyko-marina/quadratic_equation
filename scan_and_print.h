#ifndef SCAN_AND_PRINT
#define SCAN_AND_PRINT

/// The list of possible number of roots
typedef enum{
    NO_ROOTS = 0, ///< Points that number of roots is 0
    ONE_ROOT = 1, ///< Points that number of roots is 1
    TWO_ROOTS = 2, ///< Points that number of roots is 2
    INF_ROOTS = 3, ///< Points that number of roots is infinite
} solutions_count_t;

/// Structure of equation
struct equation{
    double a, b, c; ///< a-coefficient, b-coefficient, c-coefficient
    double x1, x2; ///< x1 - 1st root, x2 - 2nd root
    solutions_count_t n_roots; ///< The number of roots
};

void print_hello_words();
void scan_symbols(struct equation* eq);
void clean_buffer();
void print_result(struct equation* eq);

#endif
