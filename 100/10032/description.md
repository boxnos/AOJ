Stacking Blocks I
=================

ロボットを操作して、ブロックの山を作る。各ブロックにはアルファベット１文字で示された色が着いている。ロボットは以下の命令を実行する：

-   push c: 色がｃであるブロックを山に積む
-   pop: 山の頂点からブロックを１つ取り除く
-   quit: 終了する

最初、山は空（から）である。

ロボットへの命令を読み込んで、取り除かれたブロックの色を順番に出力するプログラムを作成せよ。

Input
-----

入力は命令の列からなる。１つの命令が１行に与えられる。命令の種類は上述した通りである。ブロックの色ｃは、aからzまでのアルファベットで与えられる。

quit命令でプログラムを終了せよ。

Output
------

取り除かれたブロックの色を順番に出力せよ。１つの色を１行に出力せよ。

Constraints
-----------

山に含まれるブロックの数が1000を超えることはない。

誤った命令は与えられない。

Sample Input
------------

    push a
    push b
    push c
    pop
    pop
    push t
    pop
    quit

Sample Output
-------------

    c
    b
    t

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

