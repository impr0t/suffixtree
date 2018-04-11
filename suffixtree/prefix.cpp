//
//  prefix.cpp
//  suffixtree
//
//  Created by Brad Lindsay on 2018-04-03.
//  Copyright © 2018 Brad Lindsay. All rights reserved.
//

#include "prefix.hpp"

/**
 Sets the prefix text.

 @param text the prefix text to set.
 */
void Prefix::setPrefixText(std::string text)
{
    this->text = text;
}

/**
 Gets the length of the prefix.

 @return the length of the prefix.
 */
long Prefix::getLength()
{
    return this->length;
}

/**
 Gets the text of the prefix.

 @return the text of the prefix.
 */
std::string Prefix::getPrefixText()
{
    return this->text;
}

/**
 Sets the length of the prefix.

 @param length length of the prefix.
 */
void Prefix::setLength(long length)
{
    this->length = length;
}



