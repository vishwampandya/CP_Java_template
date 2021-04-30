for((i = 1; ; ++i)); do
    echo "Checking Testcase : "$i
    ./TestingSolution/gen $i > ./TestingSolution/genIn
     ./pipe.out $1 $2
     diff -w ./TestingSolution/out1 ./TestingSolution/out2 > diffCommandOutput.txt || break
    
done

printf "\n\n--------------------------------------------------------------------------------------------------------\n"

printf "Output Mismatch found!!!!\n\n"
echo "For testcase "$i" : "
cat ./TestingSolution/genIn
printf "\n\n"

echo "program 1 returned : "
cat ./TestingSolution/out1
printf "\n\n"

echo "program 2 returned : "
cat ./TestingSolution/out2
printf "\n\n"
echo "--------------------------------------------------------------------------------------------------------"
