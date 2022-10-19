// Print Diagonally
// Give a N * N square matrix A, return all the elements of its anti-diagonals from top to bottom.

// https://practice.geeksforgeeks.org/problems/print-diagonally4331/1

// SC - O(N*N)
// TC - O(N*N)
class Solution{
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> grid)
	{
	    int n = grid.size();
	    vector<int> ans;
	    // First we will print the elements that are on the second diagonal and above it
	    for(int i = 0 ; i < n ; ++i) {
	        int row = 0;
	        int col = i;
	        while(col >= 0) {
	            ans.push_back(grid[row][col]);
	            row ++;
	            col --;
	        }
	    }
	    
	    // Then we will print elements below the second diagonal
	    for(int j = 1 ; j < n ; ++j) {
	        int row = j;
	        int col = n-1;
	        while(row < n) {
	            ans.push_back(grid[row][col]);
	            row ++;
	            col --;
	        }
	    }
	    return ans;
 	}

};


