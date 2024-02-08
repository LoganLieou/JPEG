#include "util.hpp"

image AIF(string fname) {
    freopen("fname", "r", stdin);
    int n, m; cin >> n >> m;
    image img(n, vector<vector<uint8_t>>(m, vector<uint8_t>()));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s; cin >> s;
            // NOTE: need to split on ' ' for line anyways
            vector<string> rgbStr = split(',', remove("()", s));
            for (string rgb : rgbStr) {
                img[i][j].push_back(static_cast<uint8_t>(stoi(rgb)));
            }
        }
    }
    return img;
}

tuple<d_image, d_image, d_image> color_space_conversion(image img) {
    int h = img.size(), w = img[0].size();
    d_image Y(h, vector<double>(w)), Cb(h, vector<double>(w)), Cr(h, vector<double>(w));

    // row of pixels in image
    for (int i = 0; i < h; ++i) {
        // pixel in row
        // R at index 0, G at index 1, B at index 2
        for (int j = 0; j < w; ++j) {
            // RGB calculation of luminance
            Y[i][j] = 
                0.299 * img[i][j][0] + 0.587 * img[i][j][1] + 0.114 * img[i][j][2];
            // RGB calculation of blue chrominance
            Cb[i][j] =
                -0.1687 * img[i][j][0] - 0.3313 * img[i][j][1] + 0.5 * img[i][j][2] + 128;
            // RGB calculation of red chrominance
            Cr[i][j] =
                0.5 * img[i][j][0] - 0.4187 * img[i][j][1] - 0.0813 * img[i][j][2] + 128;
        }
    }
    return tuple<d_image, d_image, d_image>(Y, Cb, Cr);
}

tuple<d_image, d_image, d_image> chrominance_downsampling(d_image Y, d_image Cb, d_image Cr) {
    int h = Y.size(), w = Y[0].size();
    d_image new_Cb(h, vector<double>(w)), new_Cr(h, vector<double>(w));

    // each average value of a 4 pixel block will take up a single pixel
    // we then upscale the image back to res
    for (int i = 0; i < h-4; i += 4) {
        for (int j = 0; j < w-4; j += 4) {
            // calculate the average of a 4x4 box of pixels
            double sb = 0, sr = 0;
            for (int x = i; x < i + 4; ++x) {
                for (int y = j; y < j + 4; ++y) {
                    sb += Cr[x][y];
                    sr += Cr[x][y];
                }
            }
            sb /= 16.0;
            sr /= 16.0;

            // upscale chrominance to original size
            for (int x = i; x < i + 4; ++x) {
                for (int y = j; y < j + 4; ++y) {
                    new_Cb[x][y] = sb;
                    new_Cr[x][y] = sr;
                }
            }
        }
    }
    return tuple<d_image, d_image, d_image>(Y, Cb, Cr);
}

// split a string on some delimeter
vector<string> split(char c, string s) {
    vector<string> res;
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            res.push_back(temp);
            temp = "";
            continue;
        }
        temp += s[i];
    }
    return res;
}

// remove a string from another string
string remove(string substring, string &s) {
    string res = "";
    for (char c : s) {
        if (substring.find(c) != string::npos)
            continue;
        res += c;
    }
    return res;
}