N=${1:-1000000000}
THREADS=${2:-1}

g++ -O3 -fopenmp pi_rectangle.cpp -o pi_rectangle

./pi_rectangle $N $THREADS

