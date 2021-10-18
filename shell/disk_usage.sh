#!/bin/bash
# Report disk usage by file type

find . -type f -empty -prune -o -type f -printf "%s\t" -exec file --brief --mime-type '{}' \; | awk 'BEGIN {printf("%12s\t%12s\n","bytes","type")} {type=$2; a[type]+=$1} END {for (i in a) printf("%12u\t%12s\n", a[i], i)|"sort -nr"}'
