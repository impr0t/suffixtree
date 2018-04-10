//
//  testsuffixtree.cpp
//  testsuffixtree
//
//  Created by Brad Lindsay on 2018-04-06.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include "include/catch.hpp"
#include "../suffixtree/suffixtree.hpp"

SCENARIO("A suffix tree needs to be dynamically allocated.") {
    
    GIVEN("A new suffix tree.") {
        SuffixTree *s = new SuffixTree();
        REQUIRE(s != NULL);
    }
}
