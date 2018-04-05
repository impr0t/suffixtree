//
//  suffixtree.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <iostream>

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
SuffixTreeNode* SuffixTree::process(std::string text, std::vector<Suffix*> suffixarray, std::vector<Prefix*> lcparray)
{
    SuffixTreeNode *root = new SuffixTreeNode(NULL, "", 0, -1, -1, -1);
    
    long lcpPrev = 0;
    SuffixTreeNode *cur = root;
    
    for (int i = 0; i < suffixarray.size(); i++)
    {
        Suffix *s = suffixarray[i];
        
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
                                              suffix->getSuffixText(),
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
                                                 "",
                                                 cur->stringDepth + offset,
                                                 edgeStart,
                                                 edgeStart + offset - 1,
                                                 -1);
    
    midNode->children[midChar] = cur->children[startChar];
    cur->children[startChar]->parent = midNode;
    cur->children[startChar]->edgeStart += offset;
    cur->children[startChar] = midNode;
    return midNode;
}


