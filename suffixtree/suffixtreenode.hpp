//
//  suffixtreenode.hpp
//  suffixtreenode
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef suffixtreenode_hpp
#define suffixtreenode_hpp

#include <map>

class SuffixTreeNode
{
public:
    SuffixTreeNode(SuffixTreeNode *parent, std::string edgeText,
                   long stringDepth, long edgeStart, long edgeEnd, long index)
    {
        this->parent = parent;
        this->stringDepth = stringDepth;
        this->edgeText = edgeText;
        this->edgeStart = edgeStart;
        this->edgeEnd = edgeEnd;
        this->index = index;
    }
    
    ~SuffixTreeNode() { }
    SuffixTreeNode *parent;
    std::map<char, SuffixTreeNode*> children;
    std::string edgeText;
    long stringDepth;
    long edgeStart;
    long edgeEnd;
    long index;
};

#endif /*suffixtreenode_hpp*/
