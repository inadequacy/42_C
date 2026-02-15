*This project has been created as part of the 42 curriculum by cbrooks-*

# Push_Swap

### Description

Sorts ints.

### Instructions

Make will create the file "push_swap" which you can run with either a string of numbers, or through standard input

### Resources

Not that complicated of a task. Tried my own logic first which failed dramatically then changed it to run with a Radix Sort Algoritm. For <= 3 inputs there's a seperate logic, and for 5 (because Radix sucks for those).

# Radix Sort
from google:
"an integer sorting algorithm that sorts data with integer keys by grouping the keys by individual digits that share the same significant position and value (place value). Radix sort uses counting sort as a subroutine to sort an array of numbers."

key take aways: it converts the numbers to their final position (0 -> i).
sorts based on last digit, then 2nd to last etc etc. based on longest number.

It has a time complexity of O(d * (n + b)), where d is the number of digits, n is the number of elements, and b is the base of the number system being used.