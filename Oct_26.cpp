// https://practice.geeksforgeeks.org/problems/the-smurfs4201/1

class Solution{
public:
    int findMin(int n, char a[]){
        int r = 0 , g = 0 , b = 0;
        for(int i = 0 ; i < n ; ++i) {
            char c = a[i];
            if(c == 'R')
                r ++;
            else if(c == 'G')
                g ++;
            else
                b ++;
        }
        if(r == n || g == n || b == n) {
            return n;
        }
        if(((r % 2 == 0) && (g % 2 == 0) && (b % 2 == 0)) || ((r % 2 != 0) && (g % 2 != 0) && (b % 2 != 0))) {
            return 2;
        } else {
            return 1;
        }
    }
};