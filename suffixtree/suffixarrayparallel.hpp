//
//  suffixarrayparallel.hpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-05.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef suffixarrayparallel_hpp
#define suffixarrayparallel_hpp

#include <string>
#include <vector>

#include "suffix.hpp"

class SuffixArrayParallel {
public:
    SuffixArrayParallel(std::string text);
    ~SuffixArrayParallel();
    std::vector<Suffix*> build();
    void buildSection(long &start, long &end, std::vector<Suffix*> &res);
private:
    std::vector<Suffix*> last;
    std::string text;
    long textlength;
};


#endif /* suffixarrayparallel_hpp */
