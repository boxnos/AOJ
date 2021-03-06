Finding Missing Cards
=====================

太郎が花子と一緒にトランプ遊びをしようとしたところ、52枚あるはずのカードが
n 枚のカードしか手元にありません。これらの n
枚のカードを入力として、足りないカードを出力するプログラムを作成して下さい。

太郎が最初に持っていたトランプはジョーカーを除く52枚のカードです。

52枚のカードは、スペード、ハート、クラブ、ダイヤの４つの絵柄に分かれており、各絵柄には13のランクがあります。

Input
-----

最初の行に太郎が持っているカードの枚数 n (n ≤ 52)が与えられます。

続いて *n*
組のカードがそれぞれ１行に与えられます。各組は１つの空白で区切られた文字と整数です。文字はカードの絵柄を表し、スペードが'S'、ハートが'H'、クラブが'C'、ダイヤが'D'で表されています。整数はそのカードのランク(1
〜 13)を表しています。

Output
------

足りないカードをそれぞれ1行に出力して下さい。各カードは入力と同様に１つの空白で区切られた文字と整数です。出力するカードの順番は以下のとおりとします：

-   絵柄がスペード、ハート、クラブ、ダイヤの順番で優先的に出力する。
-   絵柄が同じ場合は、ランクが小さい順に出力する。

Sample Input
------------

    47
    S 10
    S 11
    S 12
    S 13
    H 1
    H 2
    S 6
    S 7
    S 8
    S 9
    H 6
    H 8
    H 9
    H 10
    H 11
    H 4
    H 5
    S 2
    S 3
    S 4
    S 5
    H 12
    H 13
    C 1
    C 2
    D 1
    D 2
    D 3
    D 4
    D 5
    D 6
    D 7
    C 3
    C 4
    C 5
    C 6
    C 7
    C 8
    C 9
    C 10
    C 11
    C 13
    D 9
    D 10
    D 11
    D 12
    D 13

Sample Output
-------------

    S 1
    H 3
    H 7
    C 12
    D 8

Note
----

**[多次元配列[C/C++]](javascript:void(0))**

配列の要素が二方向に連続して並んでいるものを２次元配列と呼びます（二方向に連続したインデックスによってアクセスできるということであり、実際のメモリ領域では二方向にはなりません）。「配列の配列」と表現することができ、１次元配列の各要素が１次元配列を持っているような構造になります。下図は２次元配列の概念図です：

![](IMAGE/ITP1/2Darray.png)

サイズには、各方向の配列の要素の数を示し、[   ]
の中に整数値の定数を指定します。例えば、縦方向のサイズが
5、横方向のサイズが 7 の２次元配列は以下のように宣言します：

    int month[5][7];

１つ目の方向の１要素について、2
つ目の方向のサイズ分だけ要素があります。month[5][7]では、合計 5 × 7 ＝
35 の要素が確保されます。

上記２次元配列変数 month において、縦方向のインデックスが
3、横方向のインデックスが 1 である要素にアクセスするには month[3][1]
と記述します。例：

    int month[5][7], value;
    month[1][5] = 3;
    month[3][1] = 7;
    month[4][6] = 0;
    value = month[3][1]; // value の値は7

**[[C/C++]](javascript:void(0))**

以下のように、持っているカードの状態を 4 &times 13
の２次元配列に記録します。

    int cards[4][13]; // bool でもよい

配列の縦方向が絵柄、横方向がランクに対応します。この場合縦方向のインデックスは以下のように対応させます：

-   0: S
-   1: H
-   2: C
-   3: D

例えば、cards[2][4] が true (1) の場合 クラブの 5
を持っている、という状態にします。

入力情報をもとに cards[i][j] の状態を記録し、cards[i][j] が false
のカードを順番に出力します。

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

