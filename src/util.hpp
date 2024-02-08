#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

using image = vector<vector<vector<uint8_t>>>;
using d_image = vector<vector<double>>;

// image is as follows:
// h x w array where each point contains pixel information
// some double vector describing a point [R, G, B]

// TODO
image read_dng(string fname);
void write_dng(image img, string fname);

tuple<d_image, d_image, d_image> 
    color_space_conversion(image img);

tuple<d_image, d_image, d_image>
    chrominance_downsampling(d_image Y, d_image Cb, d_image Cr);

image AIF(string fname);

vector<string> split(char c, string s);
string remove(string substring, string &s);
