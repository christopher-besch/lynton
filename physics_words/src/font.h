#pragma once
#include <map>
#include <string>
#include <vector>

struct Char {
    // contain x and y positions of filled pixels
    std::vector<std::pair<int, int>> pixels;
    int                              height;
    int                              width {0};
    int                              spacing {0};
};

std::map<char, Char> load_font(const std::string& path);
