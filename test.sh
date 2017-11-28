#!/bin/bash

for i in {0..10}; do
echo test numero $i
Tetriminos-generator/tetri-gen -v -f 5
./parser sample.fillit | xargs ./fillit > nous
./claudio/fillit sample.fillit > cloclo
cat nous
cat cloclo
diff nous cloclo
done
