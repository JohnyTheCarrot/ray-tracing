#include <iostream>
#include <fstream>

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

int main() {
    const int imageWidth{256};
    const int imageHeight{256};
    uint8_t *image{ new uint8_t[imageWidth * imageHeight * 3] };
    size_t index{};

    for (int y{imageHeight - 1}; y >= 0; --y) {
        for (int x{}; x < imageWidth; ++x) {
            double r = double(x) / (imageWidth - 1);
            double g = double(y) / (imageHeight - 1);
            double b = 0.25;

            int rInt{static_cast<int>(255. * r)};
            int gInt{static_cast<int>(255. * g)};
            int bInt{static_cast<int>(255. * b)};

            image[index++] = rInt;
            image[index++] = gInt;
            image[index++] = bInt;
        }
    }

    stbi_write_png("out.png", imageWidth, imageHeight, 3 /* 1=Y, 2=YA, 3=RGB, 4=RGBA */, image, imageWidth * 3);

    delete[] image;

    return 0;
}
