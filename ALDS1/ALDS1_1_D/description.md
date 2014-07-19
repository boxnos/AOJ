最大の利益
==========

FX取引では、異なる国の通貨を交換することで為替差の利益を得ることができます。例えば、１ドル100円の時に
1000ドル買い、価格変動により 1ドル 108円になった時に売ると、(108円 \$-\$
100円) \$\\times\$ 1000ドル \$=\$ 8000円の利益を得ることができます。

ある通貨について、時刻 \$t\$ における価格 \$R[t]\$ (\$t =
1,2,,,N\$)が入力として与えられるので、価格の差 \$R[j] - R[i]\$
(ただし、\$j \> i\$ とする) の最大値を求めてください。

入力
----

最初の行に整数 \$N\$ が与えられる。

続く\$N\$行に整数 \$R[t]\$ (\$t = 1,2,,,N\$) が順番に与えられる。

出力
----

最大値を１行に出力せよ。

制約
----

-   \$ 2 \\leq N \\leq 200000\$
-   \$ 1 \\leq R[t] \\leq 10\^9\$

入力例 1
--------

    6
    2
    3
    1
    3
    4
    3

入力例 1 に対する出力
---------------------

    3

入力例 2
--------

    4
    4
    1
    2
    1

入力例 2 に対する出力
---------------------

    1

* * * * *

 
