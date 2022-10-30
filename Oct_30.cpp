// https://practice.geeksforgeeks.org/problems/chicks-in-a-zoo1159/1

// Initially, the zoo have a single chick. A chick gives birth to 2 chicks every day and the life expectancy of a chick is 6 days.
// Zoo officials want to buy food for chicks so they want to know the number of chicks on an Nth day. Help the officials with this task.

// Input: N = 3
// Output: 9
// Explanation: First day there is only 1 chick.
// On second day total number of chicks = 3.
// On third day total number of chicks = 9

// Input: N = 2 
// Output: 3
// Explanation: First day there is only 1 chick.
// On second day total number of chicks = 3

// Approach -
// 1. We will create an expires array which will store the number of chicks that will expire on the ith day.
// 2. Keep a counter of chicks and set it to 1.
// 3. Run a loop from 1 to n and for each i , decrease the counter by expires[i] and set expires[i + 6] to count * 2.
// 4. Increment the counter by (counter * 2).
// 5. Return the counter.

class Solution {
public:
	long long int NoOfChicks(int n){
	    long long int cnt = 1;
	    vector<long long int> expires(50 , 0);
	    expires[6] = 1;
	    for(int i =1 ; i < n ; ++i) {
	        cnt -= (expires[i]);
	        expires[i+6] += cnt*2;
	        cnt += (cnt * 2);
	    }
	    return cnt;
	}
};