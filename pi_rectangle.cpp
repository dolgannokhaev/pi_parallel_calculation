#include <iostream>
#include <iomanip>
#include <omp.h>

const double PI_REAL = 3.14159265358979323846;

int main(int argc, char* argv[]) {
    long long num_steps = 100000000; 
    int num_threads = 1; 

    if (argc >= 2) {
        num_steps = std::atoll(argv[1]);
    }
    if (argc >= 3) {
        num_threads = std::atoi(argv[2]);
    }

    omp_set_num_threads(num_threads);

    double step = 1.0 / num_steps;
    double sum = 0.0;

    double start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (long long i = 0; i < num_steps; ++i) {
        double x = step * i;
        sum += 4.0 / (1.0 + x * x);
    }

    double pi = step * sum;
    double run_time = omp_get_wtime() - start_time;

    std::cout << std::fixed << std::setprecision(15);
    std::cout << "PI real value = " << PI_REAL << std::endl;
    std::cout << "PI calculated = " << pi << std::endl;
    std::cout << "DIfference = " << pi - PI_REAL << std::endl;
    
    std::cout << "N = " << num_steps << std::endl;
    std::cout << "Threads used =  " << num_threads << std::endl;
    std::cout << "Run time = " << run_time << std::endl;

    return 0;
}
