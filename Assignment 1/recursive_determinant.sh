#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "recursive_determinant.eps"
set key right bottom
set xlabel "Matrix order"
set ylabel "Time (microseconds)"
plot 'recursive_determinant_data.txt' using 1:2 t "Real Times", 'recursive_determinant_data.txt' using 1:3 t "Estimated Times" w l
_end_
