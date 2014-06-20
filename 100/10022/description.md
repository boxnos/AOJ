Finding a Word
==============

１つの単語 *W* と文章 *T* が与えられます。*T* の中にある *W*
の数を出力するプログラムを作成して下さい。

文章 *T* に含まれるスペースまたは改行で区切られた文字列を単語 *T~i~*
とします。すべての *T~i~* において単語 *W*
と同じになるものを数えて下さい。

なお、大文字と小文字は区別しません。

Constraints
-----------

-   Wの文字列の長さは10を超えません。
-   Tの１行あたりの文字列の長さは1000を超えません。

Input
-----

１行目に単語 *W* が与えられます。

続いて、複数の行にまたがった文章与えられます。END\_OF\_TEXT
という文字列が文章の終わりを示します。

Output
------

単語 *W* の数を出力して下さい。

Sample Input
------------

    computer
    Nurtures computer scientists and highly-skilled computer engineers
    who will create and exploit "knowledge" for the new era.
    Provides an outstanding computer environment.
    END_OF_TEXT

Sample Output
-------------

    3

Note
----

**[文字列の空白区切り入力[C++]](javascript:void(0))**

cin
は文字列を空白・タブ・改行区切りで入力するので、cinを使い文章の単語を１つ１つ読み込み、目的の単語と等価演算を行っていきます。

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

