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


/**
 This function creates a new leaf node for the suffix tree.

 @param node parent node.
 @param text the text to use.
 @param suffix the suffix being used.
 @return a new leaf node.
 */
SuffixTreeNode *SuffixTree::createNewLeaf(SuffixTreeNode *node, std::string text, int suffix)
{
    return NULL;
}


/**
 This function forks an edge.

 @param node parent node
 @param text text being processed
 @param start starting character
 @param offset offset to be used for the midchar.
 @return a new node with attached children.
 */
SuffixTreeNode *SuffixTree::breakEdge(SuffixTreeNode *node, std::string text, int start, int offset)
{
    return NULL;
}

/**
 This function creates a suffix tree from a suffix array and an lcp array.

 @param text The test to process.
 @param suffixarray the suffix array generated from the text.
 @param lcparray the lcp array generated from the text.
 */
void SuffixTree::process(std::string text, std::vector<int> suffixarray, std::vector<int> lcparray)
{
    // create a new root node with no parent, depth 0, edge start -1, edge end -1
    SuffixTreeNode *root = new SuffixTreeNode(NULL, 0, -1, -1);
    
    int lcpPrev = 0;
    SuffixTreeNode *curNode = root;
    for (int i = 0; i < text.length(); i++) {
        int suffix = suffixarray[i];
        while (curNode->stringDepth > lcpPrev) {
            curNode = curNode->parent;
        }
        if (curNode->stringDepth == lcpPrev) {
            curNode = createNewLeaf(curNode, text, suffix);
        } else {
            int edgeStart = suffixarray[i - 1] + curNode->stringDepth;
            int offset = lcpPrev - curNode->stringDepth;
            SuffixTreeNode *midNode = breakEdge(curNode, text, edgeStart, offset);
            curNode = createNewLeaf(midNode, text, suffix);
        }
        if (i < text.length() - 1) {
            lcpPrev = lcparray[i];
        }
    }
}
