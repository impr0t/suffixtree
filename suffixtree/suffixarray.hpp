//
//  suffixarray.hpp
//  suffixarray
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef suffixarray_hpp
#define suffixarray_hpp

#include <string>
#include <vector>
#include <mutex>

#include "suffix.hpp"

class SuffixArray
{
private:
    long textlength;
    std::string text;
    std::mutex thread_mutex;
    std::vector<Suffix*> last;
    void buildSection(long &start, long &end, std::vector<Suffix*> &res);
public:
    std::vector<Suffix*> build(std::string text);
    std::vector<Suffix*> buildParallel(std::string text);
    std::vector<Suffix*> getAllSubstringPositions(std::string text);
    std::vector<Suffix*> getLast();
};

#endif /* suffixarray_hpp */
