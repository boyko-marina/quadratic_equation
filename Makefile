all:
	g++ main.o scan_and_print.o comparison_num.o solve_equation.o test.o -o main
	./main.exe
