#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

int generate_image(const std::string & name_file);
std::vector<double> read_ppm(std::string filename);


#endif
