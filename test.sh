#!/bin/bash

git checkout nono2 parser
git checkout sim fillit

for i in {0..10}; do
echo test numero $i
Tetriminos-generator/tetri-gen -v -f 10
cat sample.fillit
./parser sample.fillit | xargs ./fillit > nous
./claudio/fillit sample.fillit > cloclo
##cat nous
##cat cloclo
diff nous cloclo
done
