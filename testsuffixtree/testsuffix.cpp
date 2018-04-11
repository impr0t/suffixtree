//
//  testsuffix.cpp
//  testsuffixtree
//
//  Created by Brad Lindsay on 2018-04-10.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include "include/catch.hpp"
#include "../suffixtree/suffix.hpp"

SCENARIO("Constructing a new suffix.") {
    Suffix *p = new Suffix();
    REQUIRE(p->getIndex() == 0);
    REQUIRE(p->getSuffixText().length() == 0);
}

SCENARIO("Setting suffix text.") {
    GIVEN("A string = 'text'") {
        Suffix *p = new Suffix();
        p->setSuffixText("text");
        REQUIRE(p->getSuffixText().compare("text") == 0);
    }
}

SCENARIO("Getting suffix index.") {
    GIVEN("A string = 'text'") {
        Suffix *p = new Suffix();
        p->setIndex(4);
        REQUIRE(p->getIndex() == 4);
    }
}

SCENARIO("Comparing two suffixes.") {
    GIVEN("Two equal suffixes.") {
        Suffix *s1 = new Suffix();
        Suffix *s2 = new Suffix();
        s1->setSuffixText("text");
        s2->setSuffixText("text");
        REQUIRE(Suffix::compare(s1, s2) == 0);
    }
    
    GIVEN("Two different suffixes.") {
        Suffix *s1 = new Suffix();
        Suffix *s2 = new Suffix();
        s1->setSuffixText("text");
        s2->setSuffixText("tsst");
        REQUIRE(Suffix::compare(s1, s2) != 0);
    }
}
