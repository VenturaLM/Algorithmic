#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "iterative_determinant.eps"
set key right bottom
set xlabel "Matrix order"
set ylabel "Time (microseconds)"
plot 'iterative_determinant_data.txt' using 1:2 t "Real Times", 'iterative_determinant_data.txt' using 1:3 t "Estimated Times" w l
_end_
