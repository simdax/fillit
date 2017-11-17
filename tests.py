import sys

mat = []
for i in range(16):
     mat.append('.')

def w(a):
    sys.stdout.write(a)

def p_mat():
    for i in range(16):
        if (i and not(i % 4)):
            w('\n')
        w(mat[i])

p_mat()

