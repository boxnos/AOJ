Shuffle
=======

１つのアルファベットが描かれた *n* 枚のカードの山をシャッフルします。

1回のシャッフルでは、下から *h*
枚のカードをまとめて取り出し、それを残ったカードの山の上に積み上げます。

カードの山は以下のように１つの文字列で与えられます。

    abcdeefab

最初の文字が一番下にあるカード、最後の文字が一番上にあるカードを示しています。

例えば、これを *h* が 4 でシャッフルすると、最初の4文字 abcd
が、残りの文字 eefab の末尾へ連結されるので以下のようになります：

    eefababcd

このシャッフルを何回か繰り返します。

カードの山の最初の並び（文字列）と *h*
の列をを読み込み、最後の並び（文字列）を出力するプログラムを作成して下さい。

Constraints
-----------

-   文字列の長さは200を超えない
-   シャッフルの回数は100を超えない

Input
-----

複数のデータセットが入力として与えられます。各データセットは以下の形式で与えられます：

    最初の並びを表す文字列
    シャッフル回数 m
    h1
    h2
      .
      .
    hm

最初の並びを表す文字列が "-" のとき入力の終わりとします。

Output
------

各データセットに対して、最後の並び（文字列）を１行に出力して下さい。

Sample Input
------------

    aabc
    3
    1
    2
    1
    vwxyz
    2
    3
    4
    -

Sample Output
-------------

    aabc
    xyzvw

Note
----

**[文字列の連結[C++]](javascript:void(0))**

string型では+演算子を使って文字列を連結することができます。例えば：

    string left = "abc";
    string right = "xyz";
    string str = left + right; // abcxyz

**[文字列の部分列（分割）[C++]](javascript:void(0))**

substr演算で文字列の部分列を抽出することができます。

    int h = 3;
    string str = "abcdef";
    string left = str.substr(0, h); // abc

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

