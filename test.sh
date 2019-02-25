#! /bin/bash

wget http://www.engr.colostate.edu/me/facil/dynamics/files/bird.avi
./huff -o .compressed bird.avi
./huff -d -o .decompressed.avi .compressed
diff bird.avi .decompressed.avi
