#include "font.h"

#include "lynton.h"

#include <fstream>

std::map<char, Char> load_font(const std::string& path)
{
    std::fstream file;
    file.open(path);
    if(!file)
        raise_critical("Can't open font file!");

    std::string buf;
    int         height, spacing;
    std::getline(file, buf, '\n');
    height = std::stoi(buf.substr(11, buf.size() - 11));
    std::getline(file, buf, '\n');
    spacing = std::stoi(buf.substr(12, buf.size() - 12));
    std::getline(file, buf, '\n');

    std::map<char, Char> chars;
    while(std::getline(file, buf)) {
        // get to next character
        if(buf[0] == '-') {
            char code          = std::stoi(buf.substr(1, buf.size() - 1));
            chars[code].height = height;
            // read code
            for(int y = 0; y < height; ++y) {
                std::getline(file, buf, '\n');
                // todo: remove this horribility
                chars[code].width   = buf.size() / 2;
                chars[code].spacing = spacing;
                for(size_t x = 0; x < buf.size(); ++x) {
                    if(x % 2 && buf[x] != ' ')
                        chars[code].pixels.push_back({x / 2, y});
                }
            }
        }
    }
    return chars;
}
