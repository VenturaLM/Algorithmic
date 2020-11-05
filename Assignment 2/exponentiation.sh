#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "exponentiation.eps"
set key right bottom
set xlabel "Matrix order"
set ylabel "Time (microseconds)"
plot 'Data.txt' using 1:2 t "Times exponentiation" w l, 'Data.txt' using 1:3 t "Times Divide and Conquer exponentiation" w l, 'Data.txt' using 1:4 t "Times Iterative Divide and Conquer exponentiation" w l
_end_