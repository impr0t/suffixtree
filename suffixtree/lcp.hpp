//
//  lcp.hpp
//  lcp
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef lcp_hpp
#define lcp_hpp

#include <string>
#include <vector>

#include "suffix.hpp"
#include "prefix.hpp"

class Lcp
{
private:
    std::vector<Prefix*> last;
public:
    std::vector<Prefix*> build(std::vector<Suffix*> suffixArray);
};

#endif /* lcp_hpp */
