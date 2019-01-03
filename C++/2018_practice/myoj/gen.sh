#!/bin/zsh

cd ~/Desktop/myoj
g++ gen.cpp -o gen
./gen >1.in
sleep 1
./gen >2.in
sleep 1
./gen >3.in
sleep 1
./gen >4.in
sleep 1
./gen >5.in
sleep 1
./gen >6.in
sleep 1
./gen >7.in
sleep 1
./gen >8.in
sleep 1
./gen >9.in
sleep 1
./gen >10.in


g++ my.cpp -o my
./my <1.in >1.out
./my <2.in >2.out
./my <3.in >3.out
./my <4.in >4.out
./my <5.in >5.out
./my <6.in >6.out
./my <7.in >7.out
./my <8.in >8.out
./my <9.in >9.out
./my <10.in >10.out

g++ Correct.cpp -o Correct
./Correct <1.in >C1.out
./Correct <2.in >C2.out
./Correct <3.in >C3.out
./Correct <4.in >C4.out
./Correct <5.in >C5.out
./Correct <6.in >C6.out
./Correct <7.in >C7.out
./Correct <8.in >C8.out
./Correct <9.in >C9.out
./Correct <10.in >C10.out


diff 1.out C1.out
diff 2.out C2.out
diff 3.out C3.out
diff 4.out C4.out
diff 5.out C5.out
diff 6.out C6.out
diff 7.out C7.out
diff 8.out C8.out
diff 9.out C9.out
diff 10.out C10.out





