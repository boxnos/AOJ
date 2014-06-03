Swapping Two Numbers
====================

２つの整数 *x*, *y*
を読み込み、それらを値が小さい順に出力するプログラムを作成して下さい。

ただし、この問題は以下に示すようにいくつかのデータセットが与えられることに注意して下さい。

Input
-----

入力は複数のデータセットから構成されています。各データセットは空白で区切られた２つの整数
*x*, *y* を含む１行から構成されています。

*x* と *y* がともに 0
のとき入力の終わりを示し、このデータセットに対する出力を行ってはいけません。

Output
------

各データセットごとに、*x* と *y*
を小さい順に並べたものを１行に出力して下さい。*x* と *y*
の間には１つの空白を入れて下さい。

Sample Input
------------

    3 2
    2 2
    5 3
    0 0

Sample Output
-------------

    2 3
    2 2
    3 5

Note
----

**[C/C++](javascript:void(0))**

*x* と *y* がともに 0 となるまで for
ループ等でデータセットを処理します。

処理の内容は、if else 文によって *x* と *y* の大小関係を調べて、 x y
と出力するか y x と出力するか分岐させます。

    if ( x が y より小さいなら ){
        x, y の順に出力;
    } else {
        y, x の順に出力;
    }

* * * * *

 
