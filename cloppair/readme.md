CLOPPAIR - Closest Point Pair
#geometry

You are given N points on a plane and your task is to find a pair of points with the smallest euclidean distance between them.

All points will be unique and there is only one pair with the smallest distance.
Input

First line of input will contain N (2<=N<=50000) and then N lines follow each line contains two integers giving the X and Y coordinate of the point. Absolute value of X,Y will be atmost 10^6.
Output

Output 3 numbers a b c, where a,b (a<b) are the indexes (0 based) of the point pair in the input and c is the distance between them. Round c to 6 decimal digits.

See samples for more clarification.

 

Input: 
5 
0 0
0 1
100 45
2 3
9 9

Output: 
0 1 1.000000

Input: 
5
0 0
-4 1
-7 -2
4 5
1 1

Output: 
0 4 1.414214

https://www.spoj.com/problems/CLOPPAIR/
