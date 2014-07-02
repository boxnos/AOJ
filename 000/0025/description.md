Hit and Blow
============

Let's play Hit and Blow game. *A* imagines four numbers and *B* guesses
the numbers. After *B* picks out four numbers, *A* answers:

-   The number of numbers which have the same place with numbers *A*
    imagined (Hit)
-   The number of numbers included (but different place) in the numbers
    *A* imagined (Blow)

For example, if *A* imagined numbers:

    9 1 8 2

and *B* chose:

    4 1 5 9

*A* should say 1 Hit and 1 Blow.

Write a program which reads four numbers *A* imagined and four numbers
*B* chose and prints the number of Hit and Blow respectively. You may
assume that the four numbers are all different and within from 0 to 9.

Input
-----

The input consists of multiple datasets. Each dataset set consists of:

    a1 a2 a3 a4
    b1 b2 b3 b4

, where

    a1 (the first number A imagined: 0 - 9)
    a2 (the second number A imagined: 0 - 9)
    a3 (the third number A imagined: 0 - 9)
    a4 (the fourth number A imagined: 0 - 9)
    b1 (the first number B chose: 0 - 9);
    b2 (the second number B chose: 0 - 9);
    b3 (the third number B chose: 0 - 9);
    b4 (the fourth number B chose: 0 - 9);

The input ends with EOF.

Output
------

For each dataset, print the number of Hit and Blow in a line. These two
numbers should be separated by a space.

Sample Input
------------

    9 1 8 2
    4 1 5 9
    4 6 8 2
    4 6 3 2

Output for the Sample Input
---------------------------

    1 1
    3 0

* * * * *

Source: PC Koshien 2003 , All-Japan High School Programming Contest,
Aizu-Wakamatsu, Japan, 2003\
 <http://www.pref.fukushima.jp/pc-concours/>

 

