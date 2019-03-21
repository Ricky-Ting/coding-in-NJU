
g++ generate_data.cpp -o generate_data

./generate_data > data/test1.in
sleep 1
./generate_data > data/test2.in
sleep 1
./generate_data > data/test3.in
sleep 1

./generate_data > data/test4.in
sleep 1

./generate_data > data/test5.in
sleep 1

./generate_data > data/test6.in
sleep 1

./generate_data > data/test7.in
sleep 1

./generate_data > data/test8.in
sleep 1

./generate_data > data/test9.in
sleep 1

./generate_data > data/test10.in
sleep 1

./generate_data > data/test11.in
sleep 1

./generate_data > data/test12.in
sleep 1

./generate_data > data/test13.in
sleep 1

./generate_data > data/test14.in
sleep 1

./generate_data > data/test15.in
sleep 1

./generate_data > data/test16.in
sleep 1

./generate_data > data/test17.in
sleep 1

./generate_data > data/test18.in
sleep 1

./generate_data > data/test19.in
sleep 1

./generate_data > data/test20.in
sleep 1

g++ My.cpp -o My


./My < data/test1.in > data/test1.out

./My < data/test2.in > data/test2.out

./My < data/test3.in > data/test3.out

./My < data/test4.in > data/test4.out

./My < data/test5.in > data/test5.out

./My < data/test6.in > data/test6.out

./My < data/test7.in > data/test7.out

./My < data/test8.in > data/test8.out

./My < data/test9.in > data/test9.out

./My < data/test10.in > data/test10.out

./My < data/test11.in > data/test11.out

./My < data/test12.in > data/test12.out

./My < data/test13.in > data/test13.out

./My < data/test14.in > data/test14.out

./My < data/test15.in > data/test15.out

./My < data/test16.in > data/test16.out

./My < data/test17.in > data/test17.out

./My < data/test18.in > data/test18.out

./My < data/test19.in > data/test19.out

./My < data/test20.in > data/test20.out


g++ ref.cpp -o ref


./ref < data/test1.in > data/ref_test1.out

./ref < data/test2.in > data/ref_test2.out

./ref < data/test3.in > data/ref_test3.out

./ref < data/test4.in > data/ref_test4.out

./ref < data/test5.in > data/ref_test5.out

./ref < data/test6.in > data/ref_test6.out

./ref < data/test7.in > data/ref_test7.out

./ref < data/test8.in > data/ref_test8.out

./ref < data/test9.in > data/ref_test9.out

./ref < data/test10.in > data/ref_test10.out

./ref < data/test11.in > data/ref_test11.out

./ref < data/test12.in > data/ref_test12.out

./ref < data/test13.in > data/ref_test13.out

./ref < data/test14.in > data/ref_test14.out

./ref < data/test15.in > data/ref_test15.out

./ref < data/test16.in > data/ref_test16.out

./ref < data/test17.in > data/ref_test17.out

./ref < data/test18.in > data/ref_test18.out

./ref < data/test19.in > data/ref_test19.out

./ref < data/test20.in > data/ref_test20.out

cd data

diff test1.out ref_test1.out

diff test2.out ref_test2.out

diff test3.out ref_test3.out

diff test4.out ref_test4.out

diff test5.out ref_test5.out

diff test6.out ref_test6.out

diff test7.out ref_test7.out

diff test8.out ref_test8.out

diff test9.out ref_test9.out

diff test10.out ref_test10.out

diff test11.out ref_test11.out

diff test12.out ref_test12.out

diff test13.out ref_test13.out

diff test14.out ref_test14.out

diff test15.out ref_test15.out

diff test16.out ref_test16.out

diff test17.out ref_test17.out

diff test18.out ref_test18.out

diff test19.out ref_test19.out

diff test20.out ref_test20.out













