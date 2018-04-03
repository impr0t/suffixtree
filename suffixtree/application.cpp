//
//  application.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//
#define DEBUG 1

#include <iostream>
#include <stdio.h>
#include <vector>

#include "helpers.hpp"
#include "suffixtree.hpp"
#include "suffixarray.hpp"
#include "lcp.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        Helpers::LogHeader("There is nothing to do. Exiting.");
        return 1;
    }
    
    // capture string to process.
    std::string toProc(argv[1]);
    Helpers::Log("Received " + toProc + " for processing.");
    Helpers::Log("Appending $ to " + toProc + ".");
    toProc = toProc + "$";
    
    Helpers::Log("Creating suffix array for: " + toProc + ".");
    SuffixArray *sa = new SuffixArray(toProc);
    std::vector<int> result = sa->build();
    
    Helpers::Log("Creating LCP array for: " + toProc + ".");
    Lcp *lcp = new Lcp();
    std::vector<int> lcpresult = lcp->build(toProc, result);
    
    Helpers::Log("Creating suffix tree for: " + toProc + ".");
    SuffixTree *tree = new SuffixTree();
    tree->process(toProc, result, lcpresult);
    
    delete sa;
    delete lcp;
    delete tree;
}
