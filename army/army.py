#!/usr/bin/env python3

import sys

lst = []
sublst = []

for line in sys.stdin.readlines()[2:]:
    if line != '\n':
        sublst.append(line.rstrip())
        continue

    if sublst:
        lst.append(sublst)
    sublst = []

lst.append(sublst)

for fight in lst:
    NG, NM = fight[0].split()
    godz = fight[1].split()
    mecha = fight[2].split()

    godz = [ int(i) for i in godz]
    mecha = [ int(i) for i in mecha]

    if max(godz) > max(mecha):
        print('Godzilla')
    elif max(mecha) > max(godz):
        print('MechaGodzilla')
    else:
        print('Godzilla')
