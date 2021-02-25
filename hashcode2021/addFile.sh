count=$1

for i in $(seq 1 $count); do
    read url
    ch=$(($i + 96))
    wget "$url" -O input/$(printf "\\$(printf %o "$ch")").txt
done