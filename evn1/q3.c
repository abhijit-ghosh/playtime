/* Programming Challenge from Evernote Website

Given a list of integers, your task is to write a program to output an 
integer-valued list of equal length such that the output element at 
index 'i' is the product of all input elements except for the input 
element at 'i'.

In other words, let inputArray by an integer array of length 'n'. 
The solution,computed into outputArray, would be:

for each j from 1 to n-2:

outputArr[ j ] = inputArray[0] * inputArray[1] * inputArray[2] * ... * 
                 inputArray[j-1] * inputArray[j+1] * inputArray[j+2] 
                 *...* inputArray[n-1]

for j = 0

outputArray[0] = inputArray[1] * inputArray[2] * ... * inputArray[n-1]

for j = n-1

outputArray[n-1] = inputArray[0] * inputArray[1] * inputArray[2] * ... * inputArray[n-2]

As an example, if inputArray = { 1, 2, 3, 4 }, then

outputArray = { 2*3*4, 1*3*4, 1*2*4, 1*2*3 }.

Your program should run in O(n) time and should be space efficient.
Input format

First line of input contains N , number of elements in list.

Next N lines will each contain an element (a signed integer)
Output format

Print the output list of numbers.
Sample input
4
1
2
3
4

Sample output
24
12
8
6

Constraint

You may assume that:

The input array size will always have at least two elements in it, that is, n >= 2.
The product of any subset of the input will never exceed the value of a 64 bit integer.
The maximum length of input array is 1000.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int numElements = 0;
  scanf("%d", &numElements);
  if (numElements == 0) return 0;
  int *inputArray = malloc(sizeof(int) * numElements);
  if (!inputArray) return 1;
  int i=0;
  int num;
  while (scanf("%d", &num) != EOF) {
    inputArray[i++] = num;
    if (i == numElements) break;
  }
  if (i != numElements) return 1;

  long long product = 1;
  for (i=1; i<numElements; i++)
    product *= inputArray[i];
  printf("%lld\n", product);
  for (i=1; i<numElements; i++) {
    product /= inputArray[i];
    product *= inputArray[i-1];
    printf("%lld\n", product);
  }
  return 0;
}
