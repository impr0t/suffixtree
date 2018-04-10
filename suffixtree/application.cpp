//
//  application.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//
#define DEBUG 1

#include <sstream>
#include <iostream>
#include <stdio.h>
#include <vector>

#include "textstat.hpp"

int main(int argc, char *argv[])
{
    std::string input = "";
    Helpers::Log("Please enter text to process: ");
    std::getline(std::cin, input);
    Helpers::Log("Received : " + input);
    
    std::string toProc(input);
    TextStat *t = new TextStat(toProc);
    
    int option;
    while(true) {
        Helpers::LogHeader("query away");
        Helpers::Log("1: View Suffix Array");
        Helpers::Log("2: View LCP Array");
        Helpers::Log("3: View Suffix Tree");
        Helpers::Log("4: Get Longest Substring");
        Helpers::Log("5: Substring Query");
        Helpers::Log("6: Exit");
        
        std::getline(std::cin, input);
        std::stringstream mySteam(input);
        if (mySteam >> option) {
            switch (option) {
                case 1: { t->viewSuffixArray(); break; }
                case 2: { t->viewLcpArray(); break; }
                case 3: { t->viewSuffixTree(); break; }
                case 4: { Helpers::Log(t->getLongestSubstring()); break; }
                case 5: {
                    Helpers::Log("Enter query string:");
                    std::getline(std::cin, input);
                    Helpers::Log(t->findSubString(input));
                    break;
                }
                case 6: {
                    delete t;
                    return 0;
                }
                default: Helpers::Log("Sorry, I didn't get that. Try again.");
            }
        }
    }
}
