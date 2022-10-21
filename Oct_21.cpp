// https://practice.geeksforgeeks.org/problems/reverse-spiral-form-of-matrix4033/1

// Given a matrix as 2D array. Find the reverse spiral traversal of the matrix. 

// Input: R = 3, C = 3
//   a = {{9, 8, 7},
//        {6, 5, 4},
//        {3, 2, 1}}
// Output: 5 6 3 2 1 4 7 8 9
// Explanation: Spiral form of the matrix
// in reverse order starts from the centre 
// and goes outward.

class Solution {
  public:
    vector<int> reverseSpiral(int m, int n, vector<vector<int>>&matrix)  {
        vector<int> spiral;
        vector<vector<bool>> seen(m , vector<bool>(n , false));
        int x = 0 , y = 0 , di = 0;
        int dr[] = {0 , 1 , 0 , -1};
        int dc[] = {1 , 0 , -1 , 0};
        for(int i = 0 ; i < m*n ; ++i) {
            spiral.push_back(matrix[x][y]);
            seen[x][y] = true;
            int newx = x + dr[di];
            int newy = y + dc[di];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n && !seen[newx][newy]) {
                x = newx;
                y = newy;
            } else {
                di = (di + 1) % 4;
                x += dr[di];
                y += dc[di];
            }
        }
        reverse(spiral.begin() , spiral.end());
        return spiral;
    }
};

