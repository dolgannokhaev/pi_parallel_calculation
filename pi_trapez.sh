N=${1:-1000000000}
THREADS=${2:-1}

g++ -O3 -fopenmp pi_trapez.cpp -o pi_trapez

./pi_trapez $N $THREADS