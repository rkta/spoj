#!/usr/bin/env python3

import sys

for line in sys.stdin.readlines()[1:]:
    a, b = line.split()
    a = a[::-1]
    b = b[::-1]

    c = int(a) + int(b)
    c = str(c)[::-1]

    print(int(c))
