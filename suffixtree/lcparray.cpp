#include "lcparray.hpp"


/**
 This function accepts a prebuilt suffix array and creates from it, an LCP array.

 @param suffixArray A prepopulated suffix array.
 @return A vector populated with prefix objects.
 */
std::vector<Prefix*> LcpArray::build(std::vector<Suffix*> suffixArray)
{
    // the lcp array technically counts the spaces between so it
    // can be one shorter than the suffix array.
    last.clear();
    last.resize(suffixArray.size() -1 , 0);
    
    // iterate through the size of our lcp array.
    for (int i = 0; i < last.size(); i++)
    {
        // populate each position in the vector with a blank prefix.
        last[i] = new Prefix();
        
        // pull the ith and ith+1 suffix from the suffix array.
        // we'll use these for comparison.
        Suffix *t = suffixArray[i];
        Suffix *ti = suffixArray[i + 1];
        
        // we'll just pull the text out of them for processing.
        std::string tmpSuffixText1 = t->getSuffixText();
        std::string tmpSuffixText2 = ti->getSuffixText();
        
        long characterCount = 0;

        // we'll iterate through them, using the first suffix as a guide.
        // i becomes i + 1 next iteration anyways.
        for (int c = 0; c < tmpSuffixText1.length(); c++)
        {
            // pull our comparitor characters.
            char c1 = tmpSuffixText1[c];
            char c2 = tmpSuffixText2[c];
            
            if (c1 == c2)
            {
                // if they're the same, start marking it down.
                characterCount++;
                last[i]->setLength(characterCount);
                last[i]->setPrefixText(t->getSuffixText().substr(0, characterCount));
            }
            else
            {
                // otherwise just press this and reset the character count.
                last[i]->setLength(characterCount);
                last[i]->setPrefixText(t->getSuffixText().substr(0, characterCount));
                characterCount = 0;
                break;
            }
        }
    }
    return last;
}


/**
 This function returns the last processed lcp array.

 @return A vector of prefix pointers.
 */
std::vector<Prefix *> LcpArray::getLast()
{
    return last;
}

/**
 Returns the longest common prefix among all given strings.

 @return A single prefix pointer to the prefix containing the longest substring.
 */
Prefix *LcpArray::getLongestCommonPrefix()
{
    long min = INT_MIN;
    Prefix* max = NULL;
    for (int i = 0; i < last.size(); i++) {
        if (last[i]->getLength() > min) {
            min = last[i]->getLength();
            max = last[i];
        }
    }
    
    return max;
}


