#!/bin/bash

git checkout nono2 parser
git checkout sim fillit

for i in {0..100}; do
echo test numero $i
Tetriminos-generator/tetri-gen -v -f 10
sleep 2
./parser sample.fillit

#./parser sample.fillit | xargs ./fillit > nous
#./claudio/fillit sample.fillit > cloclo
##cat nous
##cat cloclo
#diff nous cloclo
done
