#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int testcases;
  // Enter number of testcases
  scanf("%d", &testcases);
  // Iterate each testcase
  while(testcases--) {
    // Enter arrayLength and swapLimit
    int arrayLength, swapLimit;
    scanf("%d%d", &arrayLength, &swapLimit);
    // motuArray contains the even-indexed elements
    // tomuArray contains the odd-indexed elements
    int motuArrayLength = arrayLength/2, tomuArrayLength = arrayLength/2;
    if (arrayLength%2 != 0) {
      // if arrayLength is odd, increment motuArrayLength
      motuArrayLength++;
    }
    //Declare the arrays
    int originalArray[arrayLength];
    int motuArray[motuArrayLength]; 
    int tomuArray[tomuArrayLength];
    // Declare indexes and sum variables
    int motuArrayIndex = 0;
    int tomuArrayIndex = 0;
    int motuArraySum = 0;
    int tomuArraySum = 0;
    // input the array and collect the sum of odd and even elements
    for (int i=0; i<arrayLength; i++) {
      scanf("%d", &originalArray[i]);
      if (i%2 == 0) {
        motuArray[motuArrayIndex++] = originalArray[i];
        motuArraySum += originalArray[i];
      } else {
        tomuArray[tomuArrayIndex++] = originalArray[i];
        tomuArraySum += originalArray[i];
      }
    }
    // if tomuArraySum > motuArraySum, he already wins. Print YES
    if (tomuArraySum > motuArraySum) {
      printf("YES\n");
      continue;
    }
    // Sort motu's and tomu's array
    // This problem can be solved by the greedy strategy that
    // We use each swap to exchange the largest element in motuArray by
    // smallest element in tomu's array. Best case maximisation for Tomu
    sort(motuArray, motuArray + motuArrayLength);
    sort(tomuArray, tomuArray + tomuArrayLength);
    bool tomuWins = false;
    for (int k=0; k<swapLimit && motuArrayLength-k-1 >= 0 && k <= tomuArrayLength-1; k++) {
      if (motuArray[motuArrayLength-k-1] > tomuArray[k]) {
        motuArraySum -= motuArray[motuArrayLength-k-1];
        motuArraySum += tomuArray[k];
        tomuArraySum += motuArray[motuArrayLength-k-1];
        tomuArraySum -= tomuArray[k];
        if (tomuArraySum > motuArraySum) {
          tomuWins = true;
          printf("YES\n");
          break;
        }
      }
    }
    if (swapLimit == 0 || !tomuWins) {
      printf("NO\n");
    }
  }
  return 0;
}
