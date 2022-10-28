// https://practice.geeksforgeeks.org/problems/sequence-fun5018/1

// You have a sequence 2,5,16,65,........Given an integer n as input. You have to find the value at the nth position in the sequence.

// Input: n = 4
// Output: 65

// Input: n = 10
// Output: 9864101

class Solution {
	public:
	int NthTerm(int n){
	    if(n == 1) {
	        return 2;
	    }
        const int m = 1e9 + 7;
	    long long int start = 2;
	    long long int toMultiply = 2;
	    for(int i = 2 ; i <= n ; ++i) {
	        long long int temp = ((start * toMultiply) + 1) % m;
	        start = temp;
	        toMultiply ++;
	    }
	    return start % m;
	}

};