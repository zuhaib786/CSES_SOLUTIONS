import os
fp = open('input.txt')
source = '/home/zuhaib/Projects/CSES_SOLUTIONS'
dest = '/home/zuhaib/Projects/CSES_SOLUTIONS/Range Queries'
files = os.listdir(source)
data = set()
for line in fp:
    st = line.strip('\n')
    temp = st.split()
    st = ''
    for a in temp:
        st += a
    data.add(st+'.cpp')
for file in files:
    if file in data:
        print(file)
        source_file = os.path.join(source, file)
        dest_file = os.path.join(dest, file)
        os.rename(source_file, dest_file)
