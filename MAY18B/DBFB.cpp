#include <iostream>
#define MOD 1000000007
#define lli long long int
using namespace std;

// Structure to store 2 by 2 matrix
struct matrix {
  lli x1;
  lli y1;
  lli x2;
  lli y2;
};

// Method to multiply two 2by2 matrices m1 and m2 with MOD
matrix multiply(matrix m1, matrix m2) {
  matrix result;
  result.x1 = (m1.x1*m2.x1 + m1.y1*m2.x2) % MOD;
  result.y1 = (m1.x1*m2.y1 + m1.y1*m2.y2) % MOD;
  result.x2 = (m1.x2*m2.x1 + m1.y2*m2.x2) % MOD;
  result.y2 = (m1.x2*m2.y1 + m1.y2*m2.y2) % MOD;
  return result;
}

// Method for matrix exponentiation by divide and conquer
matrix matrixExponentiation(matrix m, lli power) {
  if (power == 1) {
    return m;
  } else if (power % 2 != 0) {
    return multiply(m, matrixExponentiation(m, power - 1));
  } else {
    matrix result = matrixExponentiation(m, power/2);
    return multiply(result, result);
  }
}

int main() {
  int testcases;
  cin >> testcases;
  // Enter no. of testcases
  while (testcases--) {
    int m,n;
    cin >> m;
    cin >> n;
    lli firstArray[m], secondArray[m];
    // fibonacci matrix to be used for matrix exponentiation
    matrix finalFibonacciMultiplierMatrix = {
      1,
      1,
      1,
      0
    };
    // taking resultSum as 0
    lli resultSum = 0;
    for (int i = 0; i < m; i++) {
      cin >> firstArray[i];
    }
    for (int j = 0; j < m; j++) {
      cin >> secondArray[j];
    }
    // if n > 2, exponentiate the matrix by required number
    if (n > 2) {
      lli power = n - 2;
      finalFibonacciMultiplierMatrix = matrixExponentiation(finalFibonacciMultiplierMatrix, power);
    }
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < m; j++) {
        if (n == 1) {
          resultSum = (resultSum + firstArray[i]) % MOD;
        } else if (n == 2) {
          resultSum = (resultSum + secondArray[j]) % MOD;
        } else {
          // From derived formula
          resultSum = (resultSum + (finalFibonacciMultiplierMatrix.x1 * secondArray[j] + finalFibonacciMultiplierMatrix.y1 * firstArray[i]) % MOD) % MOD;
        }
      }
    }
    //print result
    cout << resultSum << endl;
  }
  return 0;
}
