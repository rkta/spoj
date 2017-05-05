#!/usr/bin/env python3

import sys

list = []

for line in sys.stdin.readlines():
    list.append(line.split())

list = list[:-1]

for elem in list:
    word = elem[0] * int(elem[1])
    for c in elem[0]:
        print(word)
        word = word[1:] + word[0]
