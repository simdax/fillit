from tests import *
import itertools
import math

memoization = {
    "maxsize": 0,
    "solutions": []
    }
pieces = ["d,d,d", "d,dh,d"]

def create_mat(n):
    return '0' * n

def calc_size(pieces):
    return 4 

def p(matrice):
    for i, v in enumerate(matrice):
	if (i != 0 and i % math.sqrt(len(matrice)) == 0):
	    w('\n')
	w(v)

def replace_char(s, i, replace):
    s = list(s)
    s[i] = replace
    return "".join(s)

def length(piece):
    return piece.count('d')

def height(piece):
    return piece.count('h')

def iterator(matrice):
    return [i for i, x in enumerate(matrice) if x == '0']

def is_occupied(matrice, x):
    return bool(int(matrice[x]))

def get_pos(size, lettres):
    res = 0
    for lettre in lettres:
        res += {
            'h': -size,
            'd': 1,
        }[lettre]
    return res

def draw(i, piece, matrice, size):
    matrice = replace_char(matrice, i, '1')
    pos += get_pos(size, piece)
    for x in pos:
        matrice = replace_char(matrice, x, '1')
    return matrice

def place(x, piece, matrice, size):
    if not is_occupied(matrice, x):
        for pos in get_pos(size, piece)
        x += pos
        if is_occupied(matrice, x):
            return False
        return True
    return False

def is_possible(piece, size, x):
    return  (length(piece) <= size - x % size 
             and height(piece) <= size - x / size
             )

def test_all_places(matrice, piece, size):
    for i in iterator(matrice):
#        print matrice
        if (is_possible(piece, size, i) and
            place(i, piece, matrice, size)):
            return draw(i, piece, matrice, size)
    return False

def test_all_pieces(pieces, size):
    matrice = create_mat(size**2)
    for piece in pieces:
        matrice = test_all_places(matrice, piece, size)
	if not matrice:
            return False
    return matrice

def main(pieces):
    size = calc_size(pieces)
    for i in itertools.permutations(pieces):
        matrice = test_all_pieces(pieces, size)
        if (matrice):
            return matrice
        size += 1 

p(main(pieces))
