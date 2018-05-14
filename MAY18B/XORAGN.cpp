#include <iostream>
using namespace std;

int main() {
    //Enter the number of testcases
    int testcases;
    cin >> testcases;
    // Iterate a while loop for each test case
    while(testcases--) {
        int arrayLength;
        cin >> arrayLength;
        // declare array of arrayLength
        int inputArray[arrayLength];
        // Question logic - Suppose we have two integers A and B 
        // Answer = (A+A)^(A+B)^(B+A)+(B+B)
        // = (A+A)^(A+B)^(A+B)^(B+B)
        // = (A+A)^(B+B)    (Because A^A=0 and A^B=B^A and A^0=A)
        // = (2A)^(2B)
        // = 2*(A^B)
        // So, answer is twice the XOR of each element in the array
        int xorResult;
        for(int i=0; i < arrayLength; i++) {
            cin >> inputArray[i];
            // Perform logic
            if(i == 0) {
                xorResult = inputArray[i];
            } else {
                xorResult = xorResult ^ inputArray[i];
            }
        }
        // Double the value
        xorResult = 2 * xorResult;
        // Print out the result
        cout << xorResult << endl;
    }
  return 0;
}

