//! Type of data
//!
//! @param [in] NO_ROOTS if the number of roots is 0
//! @param [in] ONE_ROOT if the number of roots is 1
//! @param [in] TWO_ROOTS if the number of roots is 2
//! @param [in] INF_ROOTS if the number of roots is infinity


typedef enum{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
} solutions_count_t;

//! Structure of equation
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [in] x1 1st root
//! @param [in] x2 2nd root
//! @param [in] n_roots the number of roots

struct equation{
    double a, b, c;
    double x1, x2;
    solutions_count_t n_roots;
};

void print_hello_words();
void scan_symbols(struct equation* eq);
void clean_buffer();
void print_result(struct equation* eq);
