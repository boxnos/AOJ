Hello World
===========

オンラインレッスンへようこそ。

このコース（Introduction to
Programming）は、プログラミングを始めたばかりの方向けの初級問題のみを含みます。各問題には解説やヒントが与えられています。このコースである程度力を身に付けたら、Volume
の問題にチャレンジしてみましょう。

まずは、慣例に従って Hello World を作成しましょう。

"Hello World" と標準出力にプリントするプログラムを作成して下さい。

Input
-----

この問題に入力はありません。

Output
------

"Hello World" と一行に出力して下さい。

最後の改行を忘れないようにしましょう。必要な空白や改行がなかったり、余計な空白や改行を出力すると'Presentation
Error'となり不正解になってしまいますので、注意して下さい。

Sample Input
------------

    No input

Sample Output
-------------

    Hello World

Note
----

**[C/C++の解説](javascript:void(0))**

C/C++のプログラムはプログラムの起点となるmain関数を含まなければなりません。main関数はシステムに正常終了を通知するためにreturn
0; として0を返します。

    int main(){
        .
        .
        return 0;
    }

{と}で囲まれた部分が関数の内容で、ここに記述された命令文が上から下に順番に実行されます。

C言語で標準出力に文字列を出力するためには printf
関数を使用することができます：

    printf("文字列");

ここで "\\n" は改行コードを表します。

C++では printf 関数に加えて、cout を使用することができます：

    cout 


    文字列の中に改行を含める場合は、改行コード "\n" を含めます。例えば、文字列 "Hello" の後に改行を加え出力する場合は、以下のように記述します。



    printf("文字列\n");
    または
    cout 

\

**[JAVAの解説](javascript:void(0))**

AOJにJavaのプログラムを提出する場合は、'Main'という名前のクラスを作成します。クラスMainの中にプログラムの起点となるmainメソッドを記述します。

    class Main{
        .
        .
        public static void main(String[] args){
            .
            .
        }
    }

\

**[Cの模範解答](javascript:void(0))**

    #include<stdio.h>

    int main(){
        
        printf("Hello World\n");    

        return 0;
    }

\

**[C++の模範解答](javascript:void(0))**

    #include<iostream>
    using namespace std;

    int main(){

        cout << "Hello World\n";

        return 0;
    }

\

**[JAVAの模範解答](javascript:void(0))**

    class Main{
        public static void main(String[] args){
            System.out.println("Hello World");
        }
    }

* * * * *

 

