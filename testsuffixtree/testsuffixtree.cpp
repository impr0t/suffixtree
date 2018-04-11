//
//  testsuffixtree.cpp
//  testsuffixtree
//
//  Created by Brad Lindsay on 2018-04-10.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include "include/catch.hpp"
#include "../suffixtree/helpers.hpp"
#include "../suffixtree/suffixarray.hpp"
#include "../suffixtree/lcparray.hpp"
#include "../suffixtree/suffixtree.hpp"

SCENARIO("Building a new suffix tree.") {
    SuffixArray *sa = new SuffixArray();
    sa->build("text");
    
    LcpArray *lcp = new LcpArray();
    lcp->build(sa->getLast());
    
    SuffixTree *st = new SuffixTree();
    st->build("text", sa->getLast(), lcp->getLast());
    
    REQUIRE(st->getRoot() != NULL);
}

SCENARIO("Finding a substring in the suffix tree.") {
    SuffixArray *sa = new SuffixArray();
    sa->build("text");
    
    LcpArray *lcp = new LcpArray();
    lcp->build(sa->getLast());
    
    SuffixTree *st = new SuffixTree();
    st->build("text$", sa->getLast(), lcp->getLast());
    SuffixTreeNode *n = st->findSubstring(st->getRoot(), "te", 0);
    REQUIRE(n != NULL);
}
