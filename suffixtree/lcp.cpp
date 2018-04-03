#include "lcp.hpp"

std::vector<int> Lcp::build(std::string text, std::vector<int> suffixArray)
{
    long n = suffixArray.size();
    std::vector<int> lcp(n, 0);
    std::vector<int> inverseSuffixArray(n, 0);
    
    // creating an inverse suffix array which contains
    // flipped values of our suffix array based on n.
    // if n = 5, n` = 0.
    for (int i = 0; i < n; i++)
    {
        inverseSuffixArray[suffixArray[i]] = i;
    }
    
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (inverseSuffixArray[i] == n - 1)
        {
            k = 0;
            continue;
        }
        
        int j = suffixArray[inverseSuffixArray[i] + 1];
        
        // identifying the longest common prefix.
        while (i + k < n && j + k < n && text[i + k] == text[j + k])
        {
            k++;
        }
        
        // set the longest common prefix.
        lcp[inverseSuffixArray[i]] = k;
        
        if (k > 0)
        {
            k--;
        }
    }
    
    last = lcp;
    return last;
}
