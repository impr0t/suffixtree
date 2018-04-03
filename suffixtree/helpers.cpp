//
//  helpers.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-02.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "helpers.hpp"


/**
 This function allows a message to be logged to console.
 
 @param message the message to be logged.
 */
void Helpers::Log(std::string message)
{
    std::cout << message << std::endl;
}

/**
 This function allows multiple messages to be logged to the console.
 The message are separated by spaces.
 
 @param messages A vector containing all messages to be printed.
 */
void Helpers::Log(std::vector<std::string> messages)
{
    for (int i = 0; i < messages.size(); i++) {
        std::cout << messages[i] << " ";
    }
    std::cout << std::endl;
}

/**
 This function logs a message to the console in all upper case.
 
 @param message The message to be logged to the console in upper case.
 */
void Helpers::LogHeader(std::string message)
{
    std::transform(message.begin(), message.end(), message.begin(), toupper);
    std::cout << message << std::endl << std::endl;
}
