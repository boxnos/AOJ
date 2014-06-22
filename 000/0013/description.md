Switching Railroad Cars
=======================

![](IMAGE1/rail.gif)

\

This figure shows railway tracks for reshuffling cars. The rail tracks
end in the bottom and the top-left rail track is used for the entrace
and the top-right rail track is used for the exit. Ten cars, which have
numbers from 1 to 10 respectively, use the rail tracks.

We can simulate the movement (comings and goings) of the cars as follow:

-   An entry of a car is represented by its number.
-   An exit of a car is represented by 0

For example, a sequence

    1 6 0 8 10

demonstrates that car 1 and car 6 enter to the rail tracks in this
order, car 6 exits from the rail tracks, and then car 8 and car 10
enter.

Write a program which simulates comings and goings of the cars which are
represented by the sequence of car numbers. The program should read the
sequence of car numbers and 0, and print numbers of cars which exit from
the rail tracks in order. At the first, there are no cars on the rail
tracks. You can assume that 0 will not be given when there is no car on
the rail tracks.

Input
-----

    car number
    car number or 0
    car number or 0
      .
      .
      .
    car number or 0

Output
------

    car number
    car number
      .
      .
      .
    car number

Sample Input
------------

    1
    6
    0
    8
    10
    0
    0
    0

Output for the Sample Input
---------------------------

    6
    10
    8
    1

* * * * *

Source: PC Koshien 2003 , All-Japan High School Programming Contest,
Aizu-Wakamatsu, Japan, 2003\
 <http://www.pref.fukushima.jp/pc-concours/>

 

