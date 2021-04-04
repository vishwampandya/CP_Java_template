for((i = 1; ; ++i)); do
    echo $i
    ./TestingSolution/gen $i > ./TestingSolution/genIn
     ./pipe.out $1 $2
     diff -w ./TestingSolution/out1 ./TestingSolution/out2 || break
    
done
