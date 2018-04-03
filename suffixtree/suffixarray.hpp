//
//  suffixarray.hpp
//  suffixarray
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef suffixarray_hpp
#define suffixarray_hpp

#include <vector>
#include "suffix.hpp"

class SuffixArray
{
private:
    std::string text;
    long textLength;
    std::vector<int> last;
    std::vector<Suffix> suffixes;
    
public:
    SuffixArray(std::string text);
    ~SuffixArray();
    std::vector<int> build();
};

#endif /* suffixarray_hpp */
