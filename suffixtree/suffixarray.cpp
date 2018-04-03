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
std::vector<int> SuffixArray::build()
{
    /* we're iterating through our given text, and generating
     * all given suffixes */
    for (int i = 0; i < textLength; i++)
    {
        Suffix s;
        s.setIndex(i);
        s.setSuffixText(text.substr(i, text.length() - i));
        suffixes.push_back(s);
    }
    
    /* sort the entire suffixes vector */
    std::sort(suffixes.begin(), suffixes.end(), Suffix::compare);
    
    /* store and report */
    last.clear();
    for (int i = 0; i < textLength; i++)
    {
        last.push_back(suffixes[i].getIndex());
    }
    
    // some cleanup.
    suffixes.clear();
    return last;
}
