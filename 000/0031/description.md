Weight
======

![](IMAGE1/weight.gif)

Your grandmother is using a pair of scales. If you put objects which
have the same weight on the two scalepans respectively, the scales keep
balance. On the other hand, if you put objects which have different
weight, the scales will tip to the heavier side.

There are ten weights of 1g, 2g, 4g, 8g, 16g, 32g, 64g, 128g, 256g, and
512g for the scale.

She said, "This scale can weigh in grams."

You said, "So, Can we weigh this juice?"

Then, grandmother put the juice on the left scalepan, and put weight of
8g, 64g, 128g on the right scalepan, and said "Sum of these weights is
200g, So, juice weighs 200g. Well, is it correct?"

Write a program which prints the weights on the right scalepan to weight
a given object. Your program should print the weights in ascending order
of their weight. You can assume that the weight of given object is less
than or equal to 1023, the total weight of the weights.

Input
-----

There are several test cases. Each test case consists of the weight of
object which is put on the left scalepan. The input terminates with EOF.

Output
------

For each test case print weights on the right scalepan. Adjacent weight
should be separated by a space

Sample Input
------------

    5
    7
    127

Output for the Sample Input
---------------------------

    1 4
    1 2 4
    1 2 4 8 16 32 64

Hint
----

The weight of the weight is 2^*n*^ (*n* = 0, 1, .... 9)g.

* * * * *

Source: PC Koshien 2004 , All-Japan High School Programming Contest,
Aizu-Wakamatsu, Japan, 2004\
 <http://www.pref.fukushima.jp/pc-concours/>

 

