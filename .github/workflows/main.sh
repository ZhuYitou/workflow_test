cat>>1.txt<<EOF

EOF

cat 1.txt 2.txt > final.cpp

g++ final.cpp -o test

./test < in.txt > out.txt

echo (diff -q out.txt ans.txt)
return 0