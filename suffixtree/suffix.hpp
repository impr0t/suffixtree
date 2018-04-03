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
    int index;
    std::string text;
    
public:
    Suffix();
    ~Suffix();
    void setIndex(int ind);
    void setSuffixText(std::string text);
    int getIndex();
    std::string getSuffixText();
    static int compare(const Suffix &s1, const Suffix &s2);
};

#endif /* suffix_hpp */
