/*
https://codility.com/programmers/lessons/7-stacks_and_queues/brackets/

A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

        S is empty;
        S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
        S has the form "VW" where V and W are properly nested strings.

For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

    int solution(char *S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Assume that:

        N is an integer within the range [0..200,000];
        string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N) (not counting the storage required for input arguments).

*/

#include <stack>

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    
    std::stack<char> brackets;
    
    for (auto curBracket : S)
    {
        if (curBracket == '(' ||
            curBracket == '{' ||
            curBracket == '[')
            brackets.push(curBracket);
        else
        {
            if (brackets.empty())
                return 0;
            
            char topBracket = brackets.top();
            brackets.pop();
            
            if ((topBracket == '(' &&  curBracket != ')') ||
                (topBracket == '{' &&  curBracket != '}') ||
                (topBracket == '[' &&  curBracket != ']') )
                return 0;
        }
    }
 
    return brackets.empty() ? 1 : 0;
}