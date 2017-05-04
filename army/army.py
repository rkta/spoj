#!/usr/bin/env python3

import sys

sys.stdin = open('sample.input', 'r')

list = []
sublist = []

for line in sys.stdin.readlines()[2:]:
    if line != '\n':
        sublist.append(line.rstrip())
        continue

    if sublist:
        list.append(sublist)
    sublist = []

list.append(sublist)

print(len(list))
print(list)
print()

for fight in list:
    print(fight)
    NG, NM = fight[0].split()
    godz = fight[1].split()
    mecha = fight[2].split()

    if max(godz) > max(mecha):
        print(max(godz), max(mecha))
        print('No chance')
        print('Godzilla')
    elif max(mecha) > max(godz):
        print(max(godz), max(mecha))
        print('No chance')
        print('MechaGodzilla')

    else:
        while len(godz) > 0 and len(mecha) > 0:
            if min(godz) < min(mecha):
                print('godz lose 1')
                godz.remove(min(godz))
                print(godz, mecha)
                print()
            elif min(mecha) < min(godz):
                print('mecha lose 1')
                mecha.remove(min(mecha))
                print(godz, mecha)
                print()
            else:
                mecha.remove(min(mecha))
                print('mecha lose 1 coz mecha')
                print(godz, mecha)
                print()

        if len(godz) == 0:
            print('MechaGodzilla')
        else:
            print('Godzilla')
