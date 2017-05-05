#!/usr/bin/env python3
import sys

for line in sys.stdin.readlines()[1:]:
    c,k,w = line.split()

    c = int(c)
    k = int(k)
    w = int(w)

    if c * w <= k:
        print('yes')
    else:
        print('no')
