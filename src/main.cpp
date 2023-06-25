#include <algorithm>

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"
#include "Ray.h"
#include "World.h"
#include "Sphere.h"
#include "Camera.h"
#include "utils.h"

int main() {
    // Image
    double aspectRatio = 16.0 / 9.0;
    int imageWidth = 960;
    int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    int samplesPerPixel = 5;

    // Camera
    Camera camera{};

    uint8_t *image{ new uint8_t[imageWidth * imageHeight * 3] };
    size_t index{};

    // World
    World world{};

    double radii{ 1 };
    double z{ -1 };
    double distance{ 1.5 };

    world.Add(std::make_unique<Sphere>(Sphere{ {0, -101.5, -1}, 100 }));

//    world.Add(std::make_unique<Sphere>(Sphere{ {-distance, 0, z}, radii }));
    world.Add(std::make_unique<Sphere>(Sphere{ {0, 0, z}, radii }));
//    world.Add(std::make_unique<Sphere>(Sphere{ {distance, 0, z}, radii }));

//    world.Add(std::make_unique<Sphere>(Sphere{ {-distance, distance, z}, radii }));
//    world.Add(std::make_unique<Sphere>(Sphere{ {0, distance, z}, radii }));
//    world.Add(std::make_unique<Sphere>(Sphere{ {distance, distance, z}, radii }));

    for (int y{imageHeight - 1}; y >= 0; --y) {
        for (int x{}; x < imageWidth; ++x) {
            Vector3 pixelColor{ 0, 0, 0 };
            for (int sample{}; sample < samplesPerPixel; ++sample) {
                double u{ double(x + RandomDouble()) / (imageWidth - 1) };
                double v{ double(y + RandomDouble()) / (imageHeight - 1) };
                Ray ray{ camera.GetRay(u, v) };
                pixelColor += ray.GetColor(world);
            }

            double scale = 1.0 / samplesPerPixel;

            int rInt{static_cast<int>(255 * std::clamp(pixelColor.GetX() * scale, 0.0, 1.0))};
            int gInt{static_cast<int>(255 * std::clamp(pixelColor.GetY() * scale, 0.0, 1.0))};
            int bInt{static_cast<int>(255 * std::clamp(pixelColor.GetZ() * scale, 0.0, 1.0))};

            image[index++] = rInt;
            image[index++] = gInt;
            image[index++] = bInt;
        }
    }

    stbi_write_png("out.png", imageWidth, imageHeight, 3 /* 1=Y, 2=YA, 3=RGB, 4=RGBA */, image, imageWidth * 3);

    delete[] image;

    return 0;
}
