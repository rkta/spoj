#!/usr/bin/env python3

import sys

i = 0

for line in sys.stdin.readlines()[1:]:
    i += 1
    number, word = line.split()
    number = int(number)
    word = word[:number - 1] + word[number:]

    print(i, word)
