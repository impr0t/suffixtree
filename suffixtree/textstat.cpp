//
//  textstat.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-09.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <vector>
#include "textstat.hpp"

TextStat::TextStat(std::string input)
{
    // automatically tack on a $ ending character.
    this->text = input + "$";
    
    sa = new SuffixArray();
    lcp = new LcpArray();
    st = new SuffixTree();
}

/**
 This function is a lazy initialization function for this object. Given that
 processing the suffix array, lcp array, and suffix tree are all computationally
 expensive, it makes sense to provide a method to create them only when they
 absolutely need to be created.
 */
void TextStat::init()
{
    if (!isinit)
    {
        sa->build(text);
        lcp->build(sa->getLast());
        st->build(text, sa->getLast(), lcp->getLast());
        isinit = true;
    }
}

/**
 This function leverages the lcp array to determine the longest common substring
 available.

 @return A string containing the value of the longest common substring.
 */
std::string TextStat::getLongestSubstring()
{
    init();
    // search for prefix using the LCP array, super easy.
    Prefix* found = lcp->getLongestCommonPrefix();
    
    // if we find it (we will)
    if (found != NULL) {
        //report it back.
        return found->getPrefixText();
    }
    
    return "";
}

/**
 This function locates a substring in a given piece of text using suffix tree
 traversal, and reports it back to the user.

 @param query The substring to query the suffix tree for.
 @return A string indicating whether or not the substring was successfully
 located.
 */
std::string TextStat::findSubString(std::string query)
{
    init();
    // search for the substring using the suffix tree.
    SuffixTreeNode *found = st->findSubstring(st->getRoot(), query, 0);
    
    // report back if it's found.
    if (found != NULL) {
        return ("["+query+"]" + " was found at "
                + std::to_string(found->edgeStart));
    }
    
    // otherwise not found.
    return "Not Found!";
}

/**
 This function produces a visually pleasing suffix tree.
 */
void TextStat::viewSuffixTree()
{
    init();
    Helpers::LogHeader("PRODUCING SUFFIX TREE");
    Helpers::LogSuffixTree(st->getRoot());
}

/**
 This function produces a visually pleasing suffix array.
 */
void TextStat::viewSuffixArray()
{
    init();
    Helpers::LogHeader("PRODUCING SUFFIX ARRAY");
    Helpers::LogSuffixVec(sa->getLast());
}

/**
 This function produces a visually pleasing lcp array.
 */
void TextStat::viewLcpArray()
{
    init();
    Helpers::LogHeader("PRODUCING LCP ARRAY");
    Helpers::LogPrefixVec(lcp->getLast());
}

/**
 This function leverages the suffix array to discover all substrings in a
 given string by query.

 @param query The query string.
 @return a formatted string representing all found substrings.
 */
std::string TextStat::getAllSubstrings(std::string query)
{
    init();
    std::vector<Suffix*> r = sa->getAllSubstringPositions(query);
    std::string output = "";
    for (auto elem : r) {
        output += ("["
                   + std::to_string(elem->getIndex())
                   + " : "
                   + elem->getSuffixText()
                   + "]\r");
    }
    return output;
}
