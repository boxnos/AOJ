Toggling Case
=============

与えられた文字列の小文字と大文字を入れ替えるプログラムを作成してください。

Input
-----

文字列が1行に与えられます。

Output
------

与えられた文字列の小文字と大文字を入れ替えた文字列を出力して下さい。アルファベット以外の文字はそのまま出力して下さい。

Constraints
-----------

-   入力される文字列の長さ \< 1200

Sample Input
------------

    fAIR, LATER, OCCASIONALLY CLOUDY.

Sample Output
-------------

    Fair, later, occasionally cloudy.

Note
----

**[文字の入力[C/C++]](javascript:void(0))**

１行の文字列を読み込むには、改行が入力されるまで文字を読み込みます。例えば、以下のように記述することができます：

    char ch;

    while(1){
        scanf("%c", &ch);
        .
        .
        .// 変換して出力
        .
        .
        if ( ch == '\n' ) break;
    }

**[文字の判定[C/C++]](javascript:void(0))**

小文字・大文字の判定・変換は cctype
（C++言語の場合）をインクルードして以下の関数を使うことができます：

-   int islower(char ch): ch が小文字なら true を返す
-   int isupper(char ch): ch が大文字なら true を返す
-   int tolower(char ch): ch の小文字を返す
-   int toupper(char ch): ch の大文字を返す

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

