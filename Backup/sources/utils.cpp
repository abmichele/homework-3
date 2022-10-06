#include "../headers/utils.h"

#include <string>
#include <ctime>
#include <sstream>

std::string timeToString(time_t time)
{
    auto tm = *localtime(&time);
    std::stringstream strstream;
    strstream << mktime(&tm);
    return strstream.str();
}
