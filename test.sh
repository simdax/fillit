#!/bin/bash


Tetriminos-generator/tetri-gen -v -f 10

./parser Tetriminos-generator/sample.fillit | xargs solver/solver > nous
./claudio/fillit Tetriminos-generator/sample.fillit > cloclo
diff nous cloclo
