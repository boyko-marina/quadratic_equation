typedef enum{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
} solutions_count_t;

struct equation{
    double a, b, c;
    double x1, x2;
    solutions_count_t n_roots;
};

void print_hello_words();
void scan_symbols(struct equation* eq);
void clean_buffer();
void print_result(struct equation* eq);
