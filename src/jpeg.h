#ifndef JPEG_H
#define JPEG_H
#include "../lib/tga/tga.h"

struct TGAImage discrete_cosine_transform(struct TGAImage *image);
struct TGAImage convert(struct TGAImage *image);
void write_jpeg(struct TGAImage *image);
#endif
