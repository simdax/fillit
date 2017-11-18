import random

with open('tetrominos') as f:
    a = f.readlines()
b = []
c = []
for i in a:
    if (i == '\n'):
        b.append(c)
        c = []
    else:
        c.append(i)
piece = random.choice (b)
largeur = max([len(line) for line in piece])
longueur = len(piece)

#x = random.randint(0, 4 - largeur)
#y = random.randint(0, 4 - longueur)
print(largeur, longueur)
