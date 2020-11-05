#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "heapsort.eps"
set key right bottom
set xlabel "Size of n"
set ylabel "Time (microseconds)"
plot 'heapsort_data.txt' using 1:2 t "Real Times", 'heapsort_data.txt' using 1:3 t "Estimated Times" w l
_end_
