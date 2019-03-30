# Number-and-difference-calculator
This program reads a list of numbers from a file(the file name is provided by the user) and
perform the followings:
a.) Stores these numbers in a dynamically allocated array(Initially I did not know the size of the
array), I started with any size and grow the array as needed(You are not allowed to use
the std vector class). at the end, array was be the same size as the number of numbers
in the file.It consists a function that allows to resize the array.


b.) Calculates the frequency(the number of occurrences of each number in the array), the frequency
difference between each consecutive elements in the array, then store that in a two dimensional
array that has the following format:
23 12 16
11 28 18
3 46 36
12 10 .
. . .
. . .
