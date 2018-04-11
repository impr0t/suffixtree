//
//  testprefix.cpp
//  testsuffixtree
//
//  Created by Brad Lindsay on 2018-04-10.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include "include/catch.hpp"
#include "../suffixtree/prefix.hpp"

SCENARIO("Constructing a new prefix.") {
    Prefix *p = new Prefix();
    REQUIRE(p->getLength() == 0);
    REQUIRE(p->getPrefixText().length() == 0);
}

SCENARIO("Setting prefix text") {
    GIVEN("A string = 'text'") {
        Prefix *p = new Prefix();
        p->setPrefixText("text");
        REQUIRE(p->getPrefixText().compare("text") == 0);
    }
}

SCENARIO("Getting prefix length") {
    GIVEN("A string = 'text'") {
        Prefix *p = new Prefix();
        p->setPrefixText("text");
        p->setLength(4);
        REQUIRE(p->getLength() == 4);
    }
}
