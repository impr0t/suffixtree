//
//  suffixtree.hpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef suffixtree_hpp
#define suffixtree_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "suffixtreenode.hpp"

class SuffixTree
{
public:
    void process(std::string text, std::vector<int> suffixarray, std::vector<int> lcparray);
    SuffixTreeNode *createNewLeaf(SuffixTreeNode *node, std::string text, int suffix);
    SuffixTreeNode *breakEdge(SuffixTreeNode *node, std::string text, int start, int offset);
};

#endif /* suffixtree_hpp */
