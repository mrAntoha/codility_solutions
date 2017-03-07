/*
https://codility.com/demo/results/trainingQ33NNF-BGB/
*/

#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<int> survivedFishes;
    
    for (size_t i = 0; i < B.size(); i++)
    {
        while (true)
        {
            if (B[i] == 0)
            {
                if (survivedFishes.empty())
                {
                    survivedFishes.push(i);
                    break;
                }
                
                int topIdx = survivedFishes.top();
                
                if (B[topIdx] == 1)
                {
                    if (A[i] > A[topIdx])
                        survivedFishes.pop();
                    else
                        break;
                }
                else
                {
                    survivedFishes.push(i);
                    break;
                }
            }
            else
            if (B[i] == 1)
            {
                survivedFishes.push(i);
                break;
            }
        }
    }
    
    return survivedFishes.size();
}