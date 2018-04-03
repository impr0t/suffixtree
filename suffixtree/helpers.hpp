//
//  helpers.hpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-02.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include <string>

class Helpers {
public:
    static void Log(std::string message);
    static void Log(std::vector<std::string> messages);
    static void LogHeader(std::string message);
};

#endif /* helpers_hpp */
