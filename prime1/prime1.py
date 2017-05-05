#!/usr/bin/env python3

import sys
from math import sqrt

primes = [2, 3, 5, 7]

limit = 32001
pp = primes[-1]

while pp < limit:
    isPrime = True
    pp += 2
    sqrtpp = sqrt(pp)
    for a in primes[1:]:
        if a > sqrtpp:
            break

        if not pp % a:
            isPrime = False

    if isPrime:
        primes.append(pp)


count = int(input())

for line in sys.stdin.readlines():

    m, n = line.split()
    m = int(m)
    n = int(n)


    primeset = []

    if n <= primes[-1]:
        for prime in primes:
            if prime >= m and prime <= n:
                primeset.append(prime)

    elif m > primes[-1]:
        limit = int(sqrt(n) + 1)

        if m % 2 == 0:
            start = m + 1
        else:
            start = m

        for pp in range(start, n + 1, 2):
            isPrime = True
            for prime in primes:
                if prime > limit:
                    break
                if pp % prime == 0:
                    isPrime = False
                    break
            if isPrime:
                primeset.append(pp)

    elif m <= primes[-1] and n >= primes[-1]:
        for prime in primes:
            if prime >= m and prime <= n:
                primeset.append(prime)

        limit = int(sqrt(n) + 1)
        start = primes[-1] + 2

        for pp in range(start, n + 1, 2):
            isPrime = True
            for prime in primes:
                if prime > limit:
                    break
                if pp % prime == 0:
                    isPrime = False
                    break
            if isPrime:
                primeset.append(pp)
    else:
        sys.exit(1)

    #print('m, n: %d %d len: %s' % (m, n, len(primeset)))
    #continue
    for no in primeset:
        print(no)
        #sys.stdout.write(str(no) + '\n')

    count -= 1

    if count > 0:
        print()
