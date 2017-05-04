#!/usr/bin/env python3

import sys
from math import sqrt

list = []

for line in sys.stdin.readlines()[1:]:
    list.append(line.split())

primes = [2, 3]

for elem in list:
    limit = int(elem[1])
    pp = int(elem[0])

    if pp <= primes[-1]:
        pp = primes[-1]

    if pp % 2 == 0:
        pp -= 1

    while pp <= limit:
        test = True
        pp += 2
        sqrtpp = sqrt(pp)
        for a in primes[1:]:
            if a > sqrtpp:
                break

            if not pp % a:
                test = False

        if test:
            primes.append(pp)

    for prime in primes:
        if prime >= int(elem[0]) and prime <= limit:
            print(prime)

    print()
