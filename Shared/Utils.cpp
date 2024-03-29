/*
** Utils.cpp for Plazza in /Storage/Epitech/Plazza
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Tue Apr 16 16:05:56 2013 maxime ginters
** Last update Wed May 29 18:23:32 2013 vincent leroy
*/

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <sys/time.h>
#include <cmath>
#include <limits>

#include "Utils.hpp"

void split(std::string const& s, char c, std::vector<std::string> &elems)
{
    std::istringstream ss(s);
    std::string item;
    while (std::getline(ss, item, c))
        elems.push_back(trim(item));
}

static inline std::string &ltrim(std::string &s)
{
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

static inline std::string &rtrim(std::string &s)
{
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

std::string &trim(std::string &s)
{
        return ltrim(rtrim(s));
}

uint32 GetMSTime()
{
    timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

uint32 GetMSTimeDiffToNow(uint32 time)
{
    return GetMSTimeDiff(time, GetMSTime());
}

uint32 GetMSTimeDiff(uint32 prev, uint32 now)
{
    return now - prev;
}

bool FuzzyCompare(float f1, float f2)
{
    if (std::fabs(f1 - f2) < std::numeric_limits<float>::epsilon())
        return true;
    return false;
}

void Mod2PI(float &angle)
{
    if (angle < 0.f)
        angle = M_PI * 2 + angle;
    else if (angle > M_PI * 2)
        angle -= M_PI * 2;
}
