struct test_eq{
    double a, b, c;
    double x1, x2;
    solutions_count_t n_roots;
};

int validate_solution(struct test_eq* test);
void scan_test_data(struct test_eq* test, char *argv[]);


