//
//  textlcparray.cpp
//  testsuffixtree
//
//  Created by Brad Lindsay on 2018-04-10.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include "include/catch.hpp"
#include "../suffixtree/suffixarray.hpp"
#include "../suffixtree/lcparray.hpp"

SCENARIO("Building a new lcp array from a suffix array.") {
    GIVEN("String = 'ababaa' to suffix array.") {
        SuffixArray *sa = new SuffixArray();
        sa->build("ababaa");
        
        LcpArray *lcp = new LcpArray();
        lcp->build(sa->getLast());
        
        REQUIRE(lcp->getLast().size() == sa->getLast().size() - 1);
    }
}

SCENARIO("Get the last created lcp array.") {
    GIVEN("String = 'ababaa' to suffix array.") {
        SuffixArray *sa = new SuffixArray();
        sa->build("ababaa");
        
        LcpArray *lcp = new LcpArray();
        lcp->build(sa->getLast());
        
        REQUIRE(lcp->getLast().size() > 0);
    }
}

SCENARIO("Get the longest common prefix.") {
    GIVEN("String = 'ababaa' to suffix array.") {
        SuffixArray *sa = new SuffixArray();
        sa->build("ababaa");
        
        LcpArray *lcp = new LcpArray();
        lcp->build(sa->getLast());
        
        REQUIRE(lcp->getLongestCommonPrefix()->getPrefixText().compare("ab"));
    }
}
