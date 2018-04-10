//
//  suffix.hpp
//  suffix
//
//  Created by Brad Lindsay on 2018-03-20.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef suffix_hpp
#define suffix_hpp

#include <algorithm>

class Suffix
{
private:
    long index;
    std::string text;
    
public:
    void setIndex(long ind);
    void setSuffixText(std::string text);
    long getIndex();
    std::string getSuffixText();
    static int compare(const Suffix *s1, const Suffix *s2);
};

#endif /* suffix_hpp */
