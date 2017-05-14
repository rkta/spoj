#!/usr/bin/env python3

import sys
from math import sqrt

#sys.stdin = open('sample.input', 'r')

#primes = [2, 3, 5, 7, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
primes = []

with open('/home/kt/primes', 'r') as f:
    for line in f:
        primes.append(int(line))

#for line in sys.stdin.readlines()[1:]:
#    number = int(line)
#    sqrtnumber = sqrt(number) + 1

    number = 495873
    sqrtnumber = sqrt(number) + 1
    factors = []
    divisors = [1]

    print('number: %f' % number)
    print('sqrtnumber: %d' % sqrtnumber)
    for prime in primes:
#        print(prime, end=' ')
        if prime > sqrtnumber:
            print('prime > sqrtnumber')
            break
        if number % prime == 0:
            factors.append(prime)
            div = prime
            while div <= sqrtnumber:
                if number % div == 0:
                    wait = input(div)
                    divisors.append(div)
                    if div**2 != number:
                        divisors.append(int(number/div))
                    wait = input(factors)
                    div += prime
                    if div in divisors:
                        print('div in divisors')
                        div += prime
                else:
                    break

#    print()
    print(factors)
    print(sorted(divisors))
    print(len(divisors))
#    print(sum(factors))
#    S = str(sum(factors))
#    output = ''
#    output = output + S + '\n'
#    sys.stdout.write(output)
