#!/usr/bin/env python3

import sys

list = []

for line in sys.stdin.readlines():
    list.append(int(line.rstrip('\n')))

for elem in list:
    if elem == 42:
        sys.exit()
    else:
        print(elem)
