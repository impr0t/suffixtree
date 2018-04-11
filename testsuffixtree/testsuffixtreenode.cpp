//
//  testsuffixtreenode.cpp
//  testsuffixtree
//
//  Created by Brad Lindsay on 2018-04-10.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include "include/catch.hpp"
#include "../suffixtree/suffixtreenode.hpp"

SCENARIO("Creating a new suffix tree node.") {
    SuffixTreeNode *n = new SuffixTreeNode(NULL, "text", 1, -1, -1, 0);
    
    REQUIRE(n->children.size() == 0);
    REQUIRE(n->edgeText.compare("text") == 0);
    REQUIRE(n->stringDepth == 1);
    REQUIRE(n->edgeStart == -1);
    REQUIRE(n->edgeEnd == -1);
    REQUIRE(n->index == 0);
}
