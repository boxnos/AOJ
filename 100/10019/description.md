Sum of Numbers
==============

与えられた数の各桁の和を計算するプログラムを作成して下さい。

Input
-----

複数のデータセットが入力として与えられます。各データセットは１つの整数
*x* を含む１行で与えられます。

*x* は 1000 桁以下の整数です。

*x* が 0
のとき入力の終わりとします。このデータセットに対する出力を行ってはいけません。

Output
------

各データセットに対して、*x* の各桁の和を１行に出力して下さい。

Sample Input
------------

    123
    55
    1000
    0

Sample Output
-------------

    6
    10
    1

Note
----

**[文字列の入力[C/C++]](javascript:void(0))**

文字列はchar型の配列で表すことができます。この場合、scanfの指定子を%sとして読み込むことができます。

    char number[1001];
    scanf("%s", number);

文字列はC++のstringクラスを利用することができます。この場合cinで読み込むことができます。

    string number;
    cin >> number;

**[アスキーコード[C/C++]](javascript:void(0))**

文字も数値として扱われています。アスキーコードにおいて、数字は連続したコードが割り当てられているので、文字である数字を整数に変換したい場合は
'0'
という文字を対象となる文字から引きます。以下にいくつか、例をあげます：

    int a = '0' - '0'; // a は 0 
    int b = '1' - '0'; // b は 1
    int c = '2' - '0'; // c は 2

例えば、文字列 number の文字 *i*
を数字に変換する場合は以下のように記述します：

    int num;
    num = number[i] - '0';

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

