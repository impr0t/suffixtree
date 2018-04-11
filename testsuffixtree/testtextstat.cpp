//
//  testtextstat.cpp
//  testsuffixtree
//
//  Created by Brad Lindsay on 2018-04-09.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <string>
#include "include/catch.hpp"
#include "../suffixtree/textstat.hpp"

SCENARIO("A textstat object needs to be created.") {
    GIVEN("A null string") {
        std::string s;
        TextStat *t = new TextStat(s);
        REQUIRE(t != NULL);
        delete t;
    }
    
    GIVEN("An empty string") {
        std::string s = "";
        TextStat *t = new TextStat(s);
        REQUIRE(t != NULL);
        delete t;
    }
    
    GIVEN("A populated string") {
        std::string s = "ababaa";
        TextStat *t = new TextStat(s);
        REQUIRE(t != NULL);
        delete t;
    }
}

SCENARIO("Get information on the longest common prefix.") {
    GIVEN("The string = 'ababaa'") {
        TextStat *t = new TextStat("ababaa");
        std::string r = t->getLongestSubstring();
        REQUIRE(r.length() == 3);
    }
}

SCENARIO("Finding a substring.") {
    GIVEN("The string = 'ababaa'") {
        TextStat *t = new TextStat("ababaa");
        std::string r = t->findSubString("ba");
        REQUIRE(r.compare("Not Found!") != 0);
    }
}

SCENARIO("Getting all substrings.") {
    GIVEN("This string = 'ababaa'") {
        TextStat *t = new TextStat("ababaa");
        std::string r = t->getAllSubstrings("ba");
        REQUIRE(r.length() > 0);
    }
}
