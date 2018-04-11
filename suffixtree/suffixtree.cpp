//
//  suffixtree.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <iostream>

#include "helpers.hpp"
#include "suffixtreenode.hpp"
#include "suffixtree.hpp"
#include "suffix.hpp"
#include "prefix.hpp"

/**
 This function creates a suffix tree from a suffix array and an lcp array.
 
 @param text The test to process.
 @param suffixarray the suffix array generated from the text.
 @param lcparray the lcp array generated from the text.
 @return the root suffix tree node to be reported.
 */
SuffixTreeNode* SuffixTree::build(std::string text, std::vector<Suffix*> suffixarray, std::vector<Prefix*> lcparray)
{
    SuffixTreeNode *root = new SuffixTreeNode(NULL, "", 0, -1, -1, -1);
    
    long lcpPrev = 0;
    SuffixTreeNode *cur = root;
    
    for (int i = 0; i < suffixarray.size(); i++)
    {
        Suffix *s = suffixarray[i];
        
        // traverse back up the tree.
        while (cur->stringDepth > lcpPrev)
        {
            cur = cur->parent;
        }
        
        if (cur->stringDepth == lcpPrev)
        {
            cur = createNewLeaf(cur, text, s);
        }
        else
        {
            long edgeStart = suffixarray[i-1]->getIndex() + cur->stringDepth;
            long offset = lcpPrev - cur->stringDepth;
            SuffixTreeNode *midNode = forkEdge(cur, text, edgeStart, offset);
            cur = createNewLeaf(midNode, text, s);
        }
        
        if (i < lcparray.size())
        {
            lcpPrev = lcparray[i]->getLength();
        }
    }
    
    this->root = root;
    return root;
}

/**
 This function creates a new leaf node in the suffix tree.

 @param cur The node to add the leaf to.
 @param text The full text from the input.
 @param suffix The suffix to use information from.
 @return a new leaf node.
 */
SuffixTreeNode *SuffixTree::createNewLeaf(SuffixTreeNode *cur, std::string text, Suffix *suffix)
{
    long edgeStart = suffix->getIndex() + cur->stringDepth;
    long edgeEnd = text.length() - 1;
    
    SuffixTreeNode *leaf = new SuffixTreeNode(cur,
                                              text.substr(edgeStart, edgeEnd),
                                              text.length() - suffix->getIndex(),
                                              edgeStart,
                                              edgeEnd,
                                              suffix->getIndex());
    
    cur->children[text[leaf->edgeStart]] = leaf;
    return leaf;
}


/**
 Forks a node

 @param cur the current node.
 @param text the full text from input.
 @param edgeStart the start position of the string
 @param offset the offset
 @return mid node with child attached.
 */
SuffixTreeNode *SuffixTree::forkEdge(SuffixTreeNode *cur, std::string text, long edgeStart, long offset)
{
    char startChar = text[edgeStart];
    char midChar = text[edgeStart + offset];
    
    SuffixTreeNode *midNode = new SuffixTreeNode(cur,
                                                 text.substr(edgeStart, offset),
                                                 cur->stringDepth + offset,
                                                 edgeStart,
                                                 edgeStart + offset - 1,
                                                 -1);
    
    midNode->children[midChar] = cur->children[startChar];
    cur->children[startChar]->parent = midNode;
    cur->children[startChar]->edgeStart += offset;
    
    long newLeafEdgeStart = cur->children[startChar]->edgeStart;
    
    cur->children[startChar]->edgeText = text.substr(newLeafEdgeStart);
    cur->children[startChar] = midNode;
    return midNode;
}

/**
 This function finds a substring within the larger body of text. It only returns
 a single result starting from index 0, and it used as a litmus test to ensure
 that the suffix array is properly populating itself.

 @param cur This is the current pointer to start traversal from.
 @param text This is the query text to search for in the suffix tree.
 @return A single suffix tree node pointer with all attached children.
 */
SuffixTreeNode *SuffixTree::findSubstring(SuffixTreeNode *cur, std::string text, int c)
{
    // if node is null, well... not much we can do.
    if (cur != NULL) {
        
        // go through all the children of the current node.
        for (auto elem : cur->children) {
            // if the first character tag matches investigate.
            if (elem.first == text[c]) {
                // pull the suffix from the tree.
                std::string suffix = elem.second->edgeText;
                // if they are exact matches, or the search text
                // exists INSIDE of the suffix, return the suffix.
                if ((suffix.compare(text) == 0)
                    || (charCheck(suffix, text.substr(c)) == 0))
                {
                    return cur;
                }
                else
                {
                    return findSubstring(elem.second, text, ++c);
                }
            }
        }
    }
    return NULL;
}

/**
 This function accepts two strings and does a character by character comparison
 by traversing them in linear fashion. If a character is found to be out of sync
 with the cohort string, the function will break and return false.

 @param t1 The suffix to check.
 @param t2 The query string to use to check against the suffix.
 @return Integer value of 0 or -1 indicating success. 0 = success.
 */
int SuffixTree::charCheck(std::string t1, std::string t2)
{
    // if the search string is bigger than the suffix no subtring
    // can be found.
    if (t1.length() < t2.length()) return -1;
    
    bool good = false;
    // go through character by character.
    for (int i = 0; i < t2.length(); i++) {
        // if both characters are == then good.
        good = (t1[i] == t2[i]) ? true : false;
        
        if (!good) break;
    }
    
    // return 0 if substring exists.
    return good ? 0 : -1;
}

/**
 This function returns the last created root.

 @return A single suffix tree node pointer.
 */
SuffixTreeNode *SuffixTree::getRoot() {
    return this->root;
}


