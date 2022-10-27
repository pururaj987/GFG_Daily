// https://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

// Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.

// Approach - 
// 1. We will use the apporach of building a BST from its preorder traversal.
// 2. The first element in given array will be the root and for subsequent elements , we will check whether its left and right node are returning NULL or not.
// 3. If both are returning 0 or NULL , it will be a leaf node.
// 4. Basically , if a element is greater than bound , function will return 0 or NULL.

class Solution {
  private:
    int checkLeaf(int arr[] , int &i ,  int n , int bound , vector<int> &ans) {
        if(i == n) {
            return 0;
        }
        if(arr[i] > bound) {
            return 0;
        }
        int temp = arr[i++];
        int left = checkLeaf(arr , i , n , temp , ans);
        int right = checkLeaf(arr , i , n ,  bound , ans);
        if(left == 0 && right == 0) {
            ans.push_back(temp);
        }
        return temp;
    }
  public:
    vector<int> leafNodes(int arr[],int n) {
        int i = 0;
        vector<int> ans;
        checkLeaf(arr , i , n , INT_MAX , ans);
        return ans;
    }
};

