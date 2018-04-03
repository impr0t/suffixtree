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
    SuffixTreeNode(SuffixTreeNode *parent, int stringDepth, int edgeStart, int edgeEnd)
    {
        this->parent = parent;
        this->stringDepth = stringDepth;
        this->edgeStart = edgeStart;
        this->edgeEnd = edgeEnd;
    }
    
    ~SuffixTreeNode() { }
    SuffixTreeNode *parent;
    std::map<char, SuffixTreeNode> children;
    int stringDepth;
    int edgeStart;
    int edgeEnd;
};

#endif /*suffixtreenode_hpp*/
