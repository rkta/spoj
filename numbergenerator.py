import random
file = open("numberfile", "w")

count = 2 * 10**5 + 1
max = 5 * 10**5

for i in range(count):
    number = random.randrange(0, max)
    file.write('%s\n' % str(number))
