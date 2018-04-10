//
//  textstat.hpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-09.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef textstat_hpp
#define textstat_hpp

#include <string>
#include <map>

#include "helpers.hpp"
#include "prefix.hpp"
#include "suffix.hpp"
#include "suffixarray.hpp"
#include "suffixtree.hpp"
#include "lcparray.hpp"

class TextStat {
public:
    TextStat(std::string input);
    std::string getLongestSubstring();
    std::string findSubString(std::string query);
    void viewSuffixTree();
    void viewSuffixArray();
    void viewLcpArray();
private:
    void init();
    bool isinit = false;
    std::string text;
    SuffixArray *sa;
    SuffixTree *st;
    LcpArray *lcp;
};

#endif /* textstat_hpp */
