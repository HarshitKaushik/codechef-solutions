#include<stdio.h>

// Function to return gcd of a and b
int gcdf(int a, int b)
{
    if (a == 0)
        return b;
    return gcdf(b % a, a);
}

// Problem logic
int main()
{
int testcaseCount;
scanf("%d", &testcaseCount);
// For each test case, iterate the while loop
while(testcaseCount--) {
    int arrayLength;
    scanf("%d", &arrayLength);
    // declare an array of arrayLength
    int array[arrayLength];
    int gcd;
    for(int i=0; i < arrayLength; i++) {
        scanf("%d", &array[i]);
        if (i == 0) {
           // If it's the first element, then we take it as the default value of gcd
           gcd = array[i]; 
        } else {
            // Else we calculate the gcd of ith element and previous value of gcd
            gcd = gcdf(gcd, array[i]);
        }
    }
    if (gcd > 1) {
        // If the gcd of the entire array is more than 1, it is impossible to make gcd 1 by any number of deletions
        // Hence, print the -1 as the result 
        printf("-1\n");
    } else {
        // If the gcd is equal to 1 then there is no need for deletions and hence, print 0 as result
        printf("0\n");
    }
}
// end while loop
return 0;
}
