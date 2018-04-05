//
//  helpers.hpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-02.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include <string>
#include <map>

#include "suffix.hpp"
#include "prefix.hpp"
#include "suffixtreenode.hpp"

class Helpers {
public:
    static void Log(std::string message);
    static void Log(std::vector<std::string> messages);
    static void LogHeader(std::string message);
    static void LogSuffixVec(std::vector<Suffix*> suffix);
    static void LogSuffix(Suffix *suffix);
    static void LogPrefixVec(std::vector<Prefix*> prefix);
    static void LogPrefix(Prefix *prefix);
    static void LogSuffixTree(SuffixTreeNode *node);
    static void LogSuffixTreeNode(SuffixTreeNode *node, long depth=0);
    static void LogSuffixTreeNodeChildren(std::map<char, SuffixTreeNode*> children, long depth=0);
};

#endif /* helpers_hpp */
