struct test_eq{
    double a, b, c;
    double x1, x2;
    solutions_count_t n_roots;
};

void run_tests_from_file(FILE *file);
int validate_solution(struct equation* test);



