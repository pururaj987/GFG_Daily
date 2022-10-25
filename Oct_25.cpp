// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// Maximum of all subarrays of size k

// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

// Input:
// N = 9, K = 3
// arr[] = 1 2 3 1 4 5 2 3 6
// Output: 
// 3 3 4 5 5 5 6 
// Explanation: 
// 1st contiguous subarray = {1 2 3} Max = 3
// 2nd contiguous subarray = {2 3 1} Max = 3
// 3rd contiguous subarray = {3 1 4} Max = 4
// 4th contiguous subarray = {1 4 5} Max = 5
// 5th contiguous subarray = {4 5 2} Max = 5
// 6th contiguous subarray = {5 2 3} Max = 5
// 7th contiguous subarray = {2 3 6} Max = 6

// Approach 1- Using Muliset in c++

// Multiset stores elements in descending order and allows duplicate elements
// 1. Take first window of size k and insert its elements to multiset.
// 2. Push the first element to ans vector.
// 3. Loop from i = k to i == n-1.
// 4. In every iteration , remove the first element of previous window i.e arr[i-k] by using lower bound method of multiset and push the arr[i] to multiset and
//    push the first element of set to ans vector.

// TC - O(NLogN) - Mulitset takes O(logn) for insertion and deletion
// SC - O(k) - At max , k elements are present in the set

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        multiset<int , greater<int>> q;
        vector<int> ans;
        for(int i = 0 ; i < k ; ++i) {
            q.insert(arr[i]);
        }
        ans.push_back(*(q.begin()));
        for(int i = k ; i < n ; ++i) {
            q.erase(q.lower_bound(arr[i-k]));
            q.insert(arr[i]);
            ans.push_back(*(q.begin()));
        }
        return ans;
    }
};

// Approach 2 - Use a doubly ended queue which is deque in c++ and allows insertion and deletion from both front and end.

// TC - O(N) - queue takes O(1) for insertion and deletion from front and end.
// SC - O(k) - At max , k elements are present in queue.

// 1. Take first window of size k and for every index i , keep removing index from back of queue till nums[dq.back()] < nums[i]. Then push index i to queue.
// 2. After first window is done , push nums[dq.front()] to ans vector.
// 3. Loop from i = k to i = n-1.
// 4. In every iteration , check if index of first element of previous window is present at front of queue and if its present , pop from front of queue.
//    keep removing index from back of queue till nums[dq.back()] < nums[i]. Then push index i to queue.
//    Push index at the front of queue to ans vector.

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0 ; i < k ; ++i) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i = k ; i < n ; ++i) {
            // check if an index of previous windows is present
            if(dq.front() == i-k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

