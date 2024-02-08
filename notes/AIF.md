---
title: Arbitrary Image Format for JPEG Compression Testing (AIF)
author: Logan Jackson
date: \today{}
---

## Abstract
The following document describes an arbitrary image format I'm using to test
code for the JPEG compression algorithm.

*Disambiguation:* This is not ARM Image Format (AIF)

## Description
First of all this is not efficient what so ever but it doesn't really matter
the file format is of the form [R, G, B] for all n rows and m columns the file
begins with space separated height and width values.

## Example Program
```c++
int n, m; cin >> n >> m;
vector<vector<vector<uint8_t>>> image(n, vector<uint8_t>(m));
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        string s; cin >> s;
        vector<string> rgbStr = split(',', remove("()", s));
        for (string rgb : rgbStr) {
            image[i][j].push_back(static_cast<uint8_t>(stoi(rgb)));
        }
    }
}
```
