https://practice.geeksforgeeks.org/problems/satisfy-the-equation5847/1

Given an array A[ ] of N of  integers, find the index of values that satisfy A + B = C + D where A,B,C & D are integers values in the array.
Note: As there may be multiple pairs satisfying the equation return lexicographically smallest order of  A, B, C and D and return all as -1 if 
there are no pairs satisfying the equation.

Input:
N = 7
A[] = {3, 4, 7, 1, 2, 9, 8}
Output:
0 2 3 5
Explanation:
A[0] + A[2] = 3+7 = 10
A[3] + A[5] = 1+9 = 10

class Solution {
  private:
    // function to compare two vectoes lexicographically
    bool cmp(vector<int> &a , vector<int> &b) {
        if(a.empty()) {
            return true;
        }
        for(int i = 0 ; i < 4 ; ++i) {
            if(a[i] == b[i]) {
                continue;
            }
            return b[i] < a[i];
        }
        return false;
    }
    
  public:
    vector<int> satisfyEqn(int arr[], int n) {
        unordered_map<int , vector<pair<int,int>>> mp;

        // for every possible sum , push to map all possible pairs
        for(int i = 0 ; i < n ; ++i) {
            for(int j = i + 1 ; j < n ; ++j) {
                int currSum = arr[i] + arr[j];
                mp[currSum].push_back({i , j});
            }
        }
        
        vector<int> res;
        for(auto it : mp) {
            if(it.second.size() >= 2) {
                vector<pair<int,int>> v = it.second;
                // for every sum , we have multiple pairs
                vector<int> temp = {v[0].first , v[0].second , -1 , -1};
                for(int i = 1 ; i < v.size() ; ++i) {
                    if(v[i].first != temp[0] && v[i].second != temp[1] && v[i].first != temp[1] && v[i].second != temp[0]) {
                        temp[2] = v[i].first;
                        temp[3] = v[i].second;
                        break;
                    }
                }
                if(temp[3] == -1) {
                    continue;
                }
                // comparing the resultant vector and the current vector lexicographically
                if(cmp(res , temp)) {
                    res = temp;
                }
            }
        }
        if(res.empty()) {
            return {-1 , -1 , -1 , -1};
        } else {
            return res;
        }
    }
};



