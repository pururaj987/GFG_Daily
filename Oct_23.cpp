// https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output1813/1

// A number is called a stepping number if all adjacent digits have an absolute difference of 1,
// e.g. '321' is a Stepping Number while 421 is not. Given two integers n and m, find the count of all the stepping numbers in the range [n, m].

// Input: n = 0, m = 21
// Output: 13
// Explanation: Stepping no's are 0 1 2 3 4 5
// 6 7 8 9 10 12 21

// Approach 1 - Run a loop from n to m and for every number check whether it is step number or not.
// TC - O(N)
// SC - O(1)

// Approach 2 - Apply BFS
// 1. We know that every single digit number will be a step number , so we take all digits 0 - 9 and we try to make step number starting with these digits.
// 2. Ex - Take digit 1
// 2.a - Push 1 to queue
// 2.b - Take 1 out from queue and check if it is step number and whether it lies in the range [n , m].
// 2.c - If it is a valid step number , include it in the answer.
// 2.d - Now , we will add digits adjacent to 1 and add it in the front of 1.
// 2.e - Generate two step numbers using 1 , one by adding (lastDigit -1) and one by adding (lastDigit + 1) in front of 1.
// 2.f - If lastDigit is 0 , then we will only consider the case in which we add (lastDigit+1) and for last digit 9 , we will consider the case with (lastDigit - 1)
// 2.g - According to edge cases , push the new step numbers into queue.
// 3. Repeat the above steps.

class Solution{
private:
    void bfs(int num , int n , int m , int &stepCount) {
        queue<int> q;
        q.push(num);
        while(!q.empty()) {
            int stepNum = q.front();
            q.pop();
            if(stepNum >= n && stepNum <= m) {
                stepCount ++;
            }
            if(stepNum == 0 || stepNum > m) {
                continue;
            }
            int lastDigit = stepNum % 10;
            int stepA = stepNum*10 + (lastDigit - 1);
            int stepB = stepNum*10 + (lastDigit + 1);
            if(lastDigit == 0) {
                q.push(stepB);
            } else if(lastDigit == 9) {
                q.push(stepA);
            } else {
                q.push(stepA);
                q.push(stepB);
            }
        }
    }
    
public:
    int steppingNumbers(int n, int m)
    {
        int stepCount = 0;
        for(int i = 0 ; i <= 9 ; ++i) {
            bfs(i , n , m , stepCount);
        }
        return stepCount;
    }
};

