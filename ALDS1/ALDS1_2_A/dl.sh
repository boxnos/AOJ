[[ $1 ]] && arg=$1 || arg=$(basename `pwd`); \
for i in "https://judgedat.u-aizu.ac.jp/testcases/$arg/"{1..10}; \
{ echo "# in $i"; curl $i/in ; echo "# out $i"; curl $i/out; }
