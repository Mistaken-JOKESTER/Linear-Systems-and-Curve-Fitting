#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int
main(void)
{
    // desired h is {1, 1, −1, −1}
    mat h = "1 0 0 0; 1 1 0 0; -1 1 1 0; -1 -1 1 1; 0 -1 -1 1; 0 0 -1 -1; 0 0 0 -1";
    h.print();

    // Part A
    vec y_desired = "1, 2, -1, -4, -1, 2, 1";
    vec x = solve(h, y_desired);
	x.print("x_ln: ");
	vec y = h * x;
	y.print("y: ");
	std::cout << "Error: " << norm(y - y_desired) << "\n";

    // Part B
    y_desired = "-1";
	mat A_sub = h.row(2);
	A_sub.print("A_sub: ");
	x = solve(A_sub, y_desired);
	x.print("x_ln: ");
	y = conv(vec("1 1 -1 -1"), x);
	y.print("y: ");

    // Part C
    y_desired = "-1, -4, -1";
	A_sub = h.rows(2, 4);
	A_sub.print("A_sub: ");
	x = solve(A_sub, y_desired);
	x.print("x_ln: ");
	y = conv(vec("1 1 -1 -1"), x);
	y.print("y: ");

    // Part D
    y_desired = "0, 0, 0, 0, 0, 0";
	A_sub = join_vert(h.rows(0, 3), h.rows(5, 6));
	A_sub.print("A_sub: ");
	x = solve(A_sub, y_desired);
	x.print("x_ln: ");
	y = conv(vec("1 1 -1 -1"), x);
	y.print("y: ");
	return 0;
}
