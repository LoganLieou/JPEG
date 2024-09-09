#include "lib/tga.h"

int main(void) {
	struct TGAImage image = make_image_size(1920, 1080, RGBA);
	write_tga_file(&image, "out.tga", false);
}
