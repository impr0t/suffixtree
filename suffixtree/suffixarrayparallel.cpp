//
//  suffixarrayparallel.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-05.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <vector>
#include <thread>
#include "suffixarrayparallel.hpp"
#include "suffix.hpp"

SuffixArrayParallel::SuffixArrayParallel(std::string text)
{
    this->text = text;
    this->textlength = text.length();
    
}
SuffixArrayParallel::~SuffixArrayParallel() {}

void SuffixArrayParallel::buildSection(long &start, long &end, std::vector<Suffix*> &res)
{
    for (long i = start; i < end; i++)
    {
        Suffix *s = new Suffix();
        s->setIndex(i);
        s->setSuffixText(text.substr(i, text.length() - 1));
        res[i] = s;
    }
}

std::vector<Suffix*> SuffixArrayParallel::build()
{
    last.clear();
    last.resize(textlength);
    
    long start = 0;
    long end1 = textlength / 4;
    long end2 = 2 * (textlength / 4);
    long end3 = 3 * (textlength / 4);
    long end4 = 4 * (textlength / 4) + (textlength % 4);
    
    std::thread t1(&SuffixArrayParallel::buildSection, this, std::ref(start), std::ref(end1), std::ref(last));
    std::thread t2(&SuffixArrayParallel::buildSection, this, std::ref(end1), std::ref(end2), std::ref(last));
    std::thread t3(&SuffixArrayParallel::buildSection, this, std::ref(end2), std::ref(end3), std::ref(last));
    std::thread t4(&SuffixArrayParallel::buildSection, this, std::ref(end3), std::ref(end4), std::ref(last));
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    /* sort the entire suffixes vector */
    std::sort(last.begin(), last.end(), Suffix::compare);

    return last;
}
