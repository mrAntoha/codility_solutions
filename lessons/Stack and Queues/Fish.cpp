/*
https://codility.com/demo/results/trainingQ33NNF-BGB/
*/

#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<int> survivedFishes;
    
    for (size_t i = 0; i < B.size(); i++)
    {
        if (B[i] == 0)
        {
            while (!survivedFishes.empty() && B[survivedFishes.top()] == 1)
            {
                int topIdx = survivedFishes.top();

                if (A[i] > A[topIdx])
                    survivedFishes.pop();
                else
                    break;
            }
            
            if (survivedFishes.empty() || B[survivedFishes.top()] == 0)
            {
                survivedFishes.push(i);
            }
        }
        else // B[i] == 1
        {
            survivedFishes.push(i);
        }
    }
    
    return survivedFishes.size();
}