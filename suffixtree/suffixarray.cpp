//
//  suffixarray.cpp
//  suffixarray
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <thread>
#include <chrono>

#include "helpers.hpp"
#include "suffixarray.hpp"
#include "suffix.hpp"


/**
 This function builds a suffix array from a given piece of text.

 @param text The given text to process.
 @return A vector of suffix pointers containing all suffix information for the
 given string.
 */
std::vector<Suffix*> SuffixArray::build(std::string text)
{
    this->text = text;
    this->textlength = text.length();
    
    last.clear();
    
    /* we're iterating through our given text, and generating
     * all given suffixes */
    for (int i = 0; i < textlength; i++)
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

/**
 This function builds a suffix array from a given piece of text using
 multithreading to process the job faster.
 
 @param text The given text to process.
 @return A vector of suffix pointers containing all suffix information for the
 given string.
 */
std::vector<Suffix *> SuffixArray::buildParallel(std::string text)
{
    this->text = text;
    this->textlength = text.length();
    
    last.clear();
    last.resize(textlength);
    
    const int maxThreads = 5;
    std::vector<std::thread> threads;
    for (int i = 0; i < maxThreads; i++) {
        long s = 0;
        long e = 0;
        
        s = i * (textlength / maxThreads);
        e = (i + 1) * (textlength / maxThreads);
        if ((i + 1) == maxThreads) (e += textlength % maxThreads);
        
        std::thread th(&SuffixArray::buildSection, this, std::ref(s), std::ref(e), std::ref(last));
        threads.emplace_back(std::move(th));
    }
    
    for (auto &t : threads) {
        t.join();
    }
    
    /* sort the entire suffixes vector */
    std::sort(last.begin(), last.end(), Suffix::compare);
    
    return last;
}

/**
 This function builds sections of the suffix array. This function is used with
 the buildParallel function.

 @param start This is the start index of the section to process.
 @param end This is the end index of the section to process.
 @param res This is the reference to the vector to populate with the result.
 */
void SuffixArray::buildSection(long &start, long &end, std::vector<Suffix *> &res)
{
    // THIS IS BRUTAL.
    for (long i = start; i < end; i++)
    {
        Suffix *suff = new Suffix();
        suff->setIndex(i);
        suff->setSuffixText(text.substr(i, textlength - 1));
        thread_mutex.lock();
        res[i] = suff;
        thread_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

/**
 This function returns the last created suffix array.

 @return A vector of suffix pointers.
 */
std::vector<Suffix *> SuffixArray::getLast()
{
    return last;
}
