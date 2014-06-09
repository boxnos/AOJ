Simple Calculator
=================

２つの整数 *a*, *b* と１つの演算子 *op* を読み込んで、*a* *op* *b*
を計算するプログラムを作成して下さい。ただし、演算子 *op*
は、"+"(和)、"-"(差)、"\*"(積)、"/"(商)、のみとし、割り算で割り切れない場合は、小数点以下を切り捨てたものを計算結果とします。

Input
-----

入力は複数のデータセットから構成されています。各データセットの形式は以下のとおりです：

*a* *op* *b*

*op* が '?' のとき
入力の終わりを示します。このケースの出力は行ってはいけません。

Output
------

各データセットについて、計算結果を１行に出力して下さい。

Sample Input
------------

    1 + 2
    56 - 18
    13 * 2
    100 / 10
    27 + 81
    0 ? 0

Sample Output
-------------

    3
    38
    26
    10
    108

Note
----

**[数値と文字の入力[C/C++]](javascript:void(0))**

整数、文字、整数をそれぞれ変数 x、op、y に空白区切りで読み込むには、

    cin >> a >> op >> b;

または

    scanf("%d %c %d", &a, &op, &b);

と記述します。

**[if-else if-else による分岐処理[C/C++/Java]](javascript:void(0))**

if-else if-else 文で演算子に対応した計算を行います。

    if ( op == '+' ){
    　和
    } else if ( op == '-' ){
    　差
    } else if ( op == '*' ){
    　積
    } else if ( op == '/' ){
    　商
    } else {
    　終了
    }

* * * * *

Source: Introduction to Programming , Aizu, Japan\
 <http://judge.u-aizu.ac.jp/onlinejudge/course.jsp>

 

