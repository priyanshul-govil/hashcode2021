program=$1

clang++ -std=c++17 $program -o program

cd input

for i in *; do 
    
    filePath=$(echo ../output/$(echo $i))
    ../program < $i > $filePath 
done