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
#include "suffix.hpp"
#include "prefix.hpp"

class SuffixTree
{
public:
    SuffixTreeNode *getRoot();
    SuffixTreeNode *build(std::string text, std::vector<Suffix*> suffixarray, std::vector<Prefix*> lcparray);
    SuffixTreeNode *findSubstring(SuffixTreeNode *cur, std::string text);
private:
    SuffixTreeNode *createNewLeaf(SuffixTreeNode *cur, std::string text, Suffix* suffix);
    SuffixTreeNode *forkEdge(SuffixTreeNode *cur, std::string text, long edgeStart, long offset);
    int charCheck (std::string t1, std::string t2);
    SuffixTreeNode *root;
};

#endif /* suffixtree_hpp */
