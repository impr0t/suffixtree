//
//  suffixarray.cpp
//  suffixarray
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "helpers.hpp"
#include "suffixarray.hpp"
#include "suffix.hpp"

/**
 * Constructor
 * */
SuffixArray::SuffixArray(std::string text)
{
    this->text = text;
    this->textLength = this->text.length();
}

/**
 * Destructor
 * */
SuffixArray::~SuffixArray()
{
}

/**
 * Build function for the suffix array, takes text and produces
 * a suffix array from that text.
 * */
std::vector<Suffix*> SuffixArray::build()
{
    last.clear();
    
    /* we're iterating through our given text, and generating
     * all given suffixes */
    for (int i = 0; i < textLength; i++)
    {
        Suffix *s = new Suffix();
        s->setIndex(i);
        s->setSuffixText(text.substr(i, text.length() - i));
        last.push_back(s);
    }
    /* sort the entire suffixes vector */
    std::sort(last.begin(), last.end(), Suffix::compare);
    
    return last;
}
