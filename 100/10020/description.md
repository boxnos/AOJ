Counting Characters
===================

与えられた英文に含まれる、各アルファベットの数を数えるプログラムを作成して下さい。
なお、小文字と大文字は区別しません。

Input
-----

複数の行にまたがる１つの英文が与えられます。

Output
------

与えられた英文に含まれる各アルファベットの数を以下に示す形式で出力して下さい：

    a : aの個数
    b : bの個数
    c : cの個数
      .
      .
    z : zの個数

Sample Input
------------

    This is a pen.

Sample Output
-------------

    a : 1
    b : 0
    c : 0
    d : 0
    e : 1
    f : 0
    g : 0
    h : 1
    i : 2
    j : 0
    k : 0
    l : 0
    m : 0
    n : 1
    o : 0
    p : 1
    q : 0
    r : 0
    s : 2
    t : 1
    u : 0
    v : 0
    w : 0
    x : 0
    y : 0
    z : 0

Note
----

**[アスキーコードへの変換[C/C++]](javascript:void(0))**

a を 0、b を 1、c を 3、、、z を 25
というふうに各アルファベットに対応した番号を割り当てることができれば、サイズが
26 である整数型の配列をカウンタとすることができます。

アルファベットの a 〜 z
には連続したアスキーコードが割り当てられているので、文字から 'a'
を引くと対応した番号が得られます。

例えば、以下のようにして数えることができます：

    int num = ch - 'a';  // 文字 ch の番号
    counter[num]++; 

**[EOFまでの読み込み[C/C++]](javascript:void(0))**

入力をEOFまで行うためには、以下のように記述します：

    // C
    char ch;

    while ( scanf("%c", &ch) != EOF ){
        // ここで ch がアルファベットなら、数える
    }

    // C++
    char ch;

    while ( cin >> ch ){
        // ここで ch がアルファベットなら、数える
    }

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

