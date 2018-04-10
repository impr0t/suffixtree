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
#include <iomanip>

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
    std::cout << std::endl << message << std::endl << std::endl;
}

/**
 Method for printing a suffix vector.
 
 @param suffix The suffix vector to print.
 */
void Helpers::LogSuffixVec(std::vector<Suffix *> suffix)
{
    for (int i = 0; i < suffix.size(); i++)
    {
        Helpers::LogSuffix(suffix[i]);
    }
}

/**
 Method for printing suffix information
 
 @param suffix the suffix to print the information from.
 */
void Helpers::LogSuffix(Suffix *suffix)
{
    std::cout << suffix->getIndex()
                << " "
                << suffix->getSuffixText()
                << std::endl;
}

/**
 Method for printing a prefix vector.

 @param prefix the prefix vector to be printed.
 */
void Helpers::LogPrefixVec(std::vector<Prefix *> prefix)
{
    for (int i = 0; i < prefix.size(); i++)
    {
        Helpers::LogPrefix(prefix[i]);
    }
}

/**
 method for printing a prefix.

 @param prefix The prefix to be printed.
 */
void Helpers::LogPrefix(Prefix *prefix)
{
    std::cout << prefix->getLength()
    << " "
    << prefix->getPrefixText()
    << std::endl;
}

/**
 Starts the logging operation for the suffix tree.

 @param node The root node to kick off the process.
 */
void Helpers::LogSuffixTree(SuffixTreeNode *node)
{
    Helpers::LogSuffixTreeNode(node, 0);
}

/**
 Logs a suffix tree node.

 @param node The node to log.
 @param depth The depth at which to log it.
 */
void Helpers::LogSuffixTreeNode(SuffixTreeNode *node, long depth)
{
    std::cout << "["
                << node->edgeStart << " : "
                << node->edgeEnd << " : "
                << node->edgeText << " : "
                << node->index << " : "
                << node->stringDepth
                << "]" << std::endl;
    Helpers::LogSuffixTreeNodeChildren(node->children, depth);
}

/**
 Logs the children of a suffix tree node

 @param children The children of the node.
 @param depth The depth at which to log them.
 */
void Helpers::LogSuffixTreeNodeChildren(std::map<char, SuffixTreeNode *> children, long depth)
{
    for (auto elem : children)
    {
        std::cout << elem.first;
        for (int i = 0; i < depth; i++) { std::cout << "--"; }
        Helpers::LogSuffixTreeNode(elem.second, depth + 1);
    }
}
