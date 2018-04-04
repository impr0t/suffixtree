#include "lcp.hpp"

std::vector<Prefix*> Lcp::build(std::vector<Suffix*> suffixArray)
{
    // the lcp array technically counts the spaces between so it
    // can be one shorter than the suffix array.
    std::vector<Prefix*> longestCommonPrefixArray(suffixArray.size() - 1, 0);
    
    for (int i = 0; i < suffixArray.size() - 1; i++)
    {
        Suffix *t = suffixArray[i];
        Suffix *ti = suffixArray[i + 1];
        
        std::string tmpSuffixText1 = t->getSuffixText();
        std::string tmpSuffixText2 = ti->getSuffixText();
        
        long characterCount = 0;
        
        for (int c = 0; c < tmpSuffixText1.length(); c++)
        {
            char c1 = tmpSuffixText1[c];
            char c2 = tmpSuffixText2[c];
            
            if (c1 == c2)
            {
                characterCount++;
            }
            else
            {
                Prefix *p = new Prefix();
                p->setLength(characterCount);
                p->setPrefixText(t->getSuffixText().substr(0, characterCount));
                longestCommonPrefixArray[i] = p;
                characterCount = 0;
                break;
            }
        }
    }

    last = longestCommonPrefixArray;
    return last;
}
