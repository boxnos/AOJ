#!/bin/bash
echo $1 | ./main | gnuplot -p -e 'set size ratio -1; plot "-" using 1:2 with lines; pause -1;'
