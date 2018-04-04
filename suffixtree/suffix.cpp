#include <string>
#include "suffix.hpp"

Suffix::Suffix() {}
Suffix::~Suffix(){};

/** GETTER AND SETTERS **/

/**
 * Suffix Index Property Setter
 * */
void Suffix::setIndex(long ind)
{
    this->index = ind;
}

/**
 * Suffix Text Property Setter
 * */
void Suffix::setSuffixText(std::string suffix)
{
    this->text = suffix;
}

/**
 * Suffix Index Property Accessor.
 * Returns: index from the suffix object.
 * */
long Suffix::getIndex()
{
    return this->index;
}

/**
 * Suffix Text Property Accessor.
 * Returns: suffixtext from the suffix object.
 * */
std::string Suffix::getSuffixText()
{
    return this->text;
}

/**
 * Static suffix comparison function.
 * Returns: if s1 is smaller than s2 via string comparison 1; otherwise 0.
 * */
int Suffix::compare(const Suffix *s1, const Suffix *s2)
{
    return s1->text.compare(s2->text) < 0 ? 1 : 0;
}
