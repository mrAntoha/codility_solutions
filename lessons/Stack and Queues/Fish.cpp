/*
https://codility.com/demo/results/trainingQ33NNF-BGB/
*/

#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<int> fishes;
    
    for (size_t i = 0; i < B.size(); i++)
    {
        while (true)
        {
            if (B[i] == 0)
            {
                if (fishes.empty())
                {
                    fishes.push(i);
                    break;
                }
                
                int topIdx = fishes.top();
                
                if (B[topIdx] == 1)
                {
                    if (A[i] > A[topIdx])
                        fishes.pop();
                    else
                        break;
                }
                else
                {
                    fishes.push(i);
                    break;
                }
            }
            else
            if (B[i] == 1)
            {
                fishes.push(i);
                break;
            }
        }
    }
    
    return fishes.size();
}