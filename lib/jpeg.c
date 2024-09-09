#include "jpeg.h"

// TODO implement this, what is DCT?
void discrete_cosine_transform(struct TGAImage *image) {
    double alpha, sum;
    int N = image->bytes_pp * image->height * image->width;
    unsigned char *result = (unsigned char *)malloc(N);
    for (int i = 0; i < N; ++i) {
        if (i == 0)
            alpha = sqrt(1.0 / N);
        else
            alpha = sqrt(2.0 / N);

        sum = 0.0;
        for (int j = 0; j < N; ++j)
            sum += image->data[j] * cos((M_PI * i * (2 * j + 1)) / (2.0 * N));
        result[i] = alpha * sum;
    }
    image->data = result;
}