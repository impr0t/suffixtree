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

class Lcp
{
private:
    std::vector<int> last;
public:
    std::vector<int> build(std::string text, std::vector<int> suffixArray);
};

#endif /* lcp_hpp */
