if [ $1 ] ; then
  arg=$1
else
  arg=$(basename `pwd`)
fi

for i in "https://judgedat.u-aizu.ac.jp/testcases/${arg}/"{1..40} ;do 
  echo "#in" $i
  curl $i/in
  echo "#out" $i
  curl $i/out
done
