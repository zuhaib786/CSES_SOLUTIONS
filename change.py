fp = open('input.txt')
i = 0

for line in fp:
    if i %2 == 0:
        st = line.strip('\n')
        print(st)
    i += 1
