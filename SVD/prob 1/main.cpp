#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int
main(void)
{
    mat data_1, data_2, data_3;

    data_1.load("data_1.txt", raw_ascii);
    data_2.load("data_2.txt", raw_ascii);
    data_3.load("data_3.txt", raw_ascii);
    int row = data_1.n_rows;

    mat data = zeros(row , 6);
    data.cols(0,1) = data_1;
    data.cols(2,3) = data_2;
    data.cols(4,5) = data_3;
    mat matrix = ones(row, 3);
    mat plot_data = zeros(row, 7);
    plot_data.col(0) = data_1.col(0);
    plot_data.col(1) = data_1.col(1);
    plot_data.col(3) = data_2.col(1);
    plot_data.col(5) = data_3.col(1);
    for(int i = 0; i < 3; i++)
    {
        matrix.col(1) = data.col(2*i);
        matrix.col(2) = exp(-data.col(2*i));
        vec output = solve(matrix, data.col(2*i+1));
        vec results = matrix*output;
        plot_data.col(2*i+2) = results;
        cout << "error is " << pow(arma::norm(data.col(2*i+1) - results), 2) << endl;;
    }
    plot_data.save("plot_new.csv", csv_ascii);
}
