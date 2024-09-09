#ifndef JPEG_H
#define JPEG_H
#include "tga.h"
#include <math.h>

/* transform operations */
void discrete_cosine_transform(struct TGAImage *image);

/* IO */
void write_jpeg(struct TGAImage *image);

#endif
