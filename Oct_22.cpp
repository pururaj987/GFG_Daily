// https://practice.geeksforgeeks.org/problems/filling-bucket0529/1

// Given a Bucket having a capacity of N litres and the task is to determine that by how many ways you can fill it using two bottles of capacity of 1 Litre and 2 Litre only. 
// Find the answer modulo 10^8.

// Input:
// 3
// Output:
// 3 
// Explanation:
// Let O denote filling by 1 litre bottle and
// T denote filling by 2 litre bottle.
// So for N = 3, we have :
// {OOO,TO,OT}. Thus there are 3 total ways.

class Solution {
    private:
    const int mod = 1e8;
    int solve(int n) {
        if(n == 0) {
            return 1;
        }
        if(n < 0) {
            return 0;
        }
        return (solve(n-1) + solve(n-2)) % mod;
    }
    
  public:
    int fillingBucket(int n) {
        int a = 0 , b = 1;
        for(int i = 2 ;i  < n+2 ; ++i) {
            int temp = (a + b) % mod;
            a = b;
            b = temp;
        }
        return b % mod;
    }
};

