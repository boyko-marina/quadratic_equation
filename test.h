struct test_eq{
    double a, b, c;
    double x1, x2;
    solutions_count_t n_roots;
};

int validate_solution(struct test_eq* tests);
int run_test();
void test_solve_equation();
