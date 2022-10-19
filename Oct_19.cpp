// https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1

// A Hamiltonian path, is a path in an undirected graph that visits each vertex exactly once.
// Given an undirected graph, the task is to check if a Hamiltonian path is present in it or not.

// Input:
// N = 4, M = 4
// Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
// Output:
// 1 
// Explanation: 
// There is a hamiltonian path: 
// 1 -> 2 -> 3 -> 4 

class Solution
{
    private:
    bool hamCheck(int node , vector<int> &vis , vector<int> adj[]) {
        vis[node] = 1;
        bool allFound = true;
        for(int i = 1 ; i < vis.size() ; ++i) {
            if(vis[i] == 0) {
                allFound = false;
                break;
            }
        }
        if(allFound) {
            return true;
        }
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(hamCheck(it , vis, adj)) {
                    return true;
                }
            }
        }
        vis[node] = 0;
        return false;
    }
    public:
    bool check(int N,int M,vector<vector<int>> edges)
    {
        vector<int> adj[N+1];
        for(auto v : edges) {
            int first = v[0];
            int second = v[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        vector<int> vis(N+1 , 0);
        for(int i = 1 ; i <= N ; ++i) {
            if(!vis[i]) {
                if(hamCheck(i , vis , adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};