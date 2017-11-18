from tests import *
import itertools

memoization = {
    "maxsize": 0,
    "solutions": []
    }
pieces = [[1, 1, 1], [1,-4,1]]

def create_mat(n):
    return '0' * n

def calc_size(pieces):
    return 4 

def p(matrice):
    for i, v in enumerate(matrice):
	if (i != 0 and i % 4 == 0):
	    w('\n')
	w(v)

def check(pieces):
    return bool(size(piece))

def length(piece):
    l = 1
    for pos in piece:
        if pos > 0:
            l += pos
    return l

def height(piece):
    return len([x for x in piece if  x <= 0]) + 1

def replace_char(s, i, replace):
    s = list(s)
    s[i] = replace
    return "".join(s)

def draw(i, piece, matrice):
    matrice = replace_char(matrice, i, '1')
    for x in piece:        
        i += x
        matrice = replace_char(matrice, i, '1')
    return matrice

def iterator(matrice):
    return [i for i, x in enumerate(matrice) if x == '0']

def fit(piece):
    return True

def is_occupied(matrice, x):
    return bool(int(matrice[x]))

def place(x, piece, matrice, size):
    if not is_occupied(matrice, x):
	for pos_piece in piece:
            x += pos_piece
            if is_occupied(matrice, x):
                return False
        return True
    return False

def is_possible(piece, size, x):
    return  (length(piece) <= size - x % size 
             and height(piece) <= size - x / size
             )

def test_all_places(pieces, size):
    matrice = create_mat(size**2)
    for piece in pieces:
	for i in iterator(matrice):
            if is_possible(piece, size, i):
                if (place(i, piece, matrice, size)):
                    matrice = draw(i, piece, matrice)
                    break
    return matrice

def main(pieces):
    size = calc_size(pieces)
    for i in itertools.permutations(pieces):
        matrice = test_all_places(pieces, size)
        if (matrice):
            return matrice
        size += 1 

p(main(pieces))
