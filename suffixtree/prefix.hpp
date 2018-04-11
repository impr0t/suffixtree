//
//  prefix.hpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-03.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef prefix_hpp
#define prefix_hpp

#include <stdio.h>
#include <string>

class Prefix {
private:
    long length;
    std::string text;
public:
    void setLength(long length);
    void setPrefixText(std::string text);
    long getLength();
    std::string getPrefixText();
};

#endif /* prefix_hpp */
