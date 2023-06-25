#include <algorithm>
#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"
#include "Ray.h"
#include "World.h"
#include "Sphere.h"
#include "Camera.h"
#include "utils.h"
#include "Materials/Lambert.h"
#include "Materials/Metal.h"

int main() {
    // Image
    double aspectRatio = 16.0 / 9.0;
    int imageWidth = 960;
    int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    int samplesPerPixel = 150;

    // Camera
    Camera camera{};

    uint8_t *image{ new uint8_t[imageWidth * imageHeight * 3] };

    // World
    World world{};

    double radii{ 0.7 };
    double z{ -1 };
    double distance{ 1.7 };

    std::shared_ptr<Lambert> materialLambert{ std::make_shared<Lambert>(Lambert{ { 52.0 / 255.0, 235.0 / 255.0, 61.0 / 225.0 } }) };

    std::shared_ptr<Metal> materialMetalRed{std::make_shared<Metal>(Metal{{235.0 / 255.0, 52.0 / 255.0, 52.0 / 225.0 } }) };
    std::shared_ptr<Metal> materialMetalGreen{std::make_shared<Metal>(Metal{{52.0 / 255.0, 235.0 / 255.0, 58.0 / 225.0 } }) };
    std::shared_ptr<Metal> materialMetalBlue{std::make_shared<Metal>(Metal{{52.0 / 255.0, 91.0 / 255.0, 235.0 / 225.0 } }) };
    std::shared_ptr<Metal> materialMetalYellow{std::make_shared<Metal>(Metal{{235.0 / 255.0, 226.0 / 255.0, 52.0 / 225.0 } }) };
    std::shared_ptr<Metal> materialMetalPink{std::make_shared<Metal>(Metal{{235.0 / 255.0, 52.0 / 255.0, 162.0 / 225.0 } }) };

    world.Add(std::make_unique<Sphere>(Sphere{ {0, -100.8, -1}, 100, materialLambert }));

    world.Add(std::make_unique<Sphere>(Sphere{{-distance, 0, z}, radii, materialMetalRed }));
    world.Add(std::make_unique<Sphere>(Sphere{{0, 0, z}, radii, materialMetalGreen }));
    world.Add(std::make_unique<Sphere>(Sphere{{distance, 0, z}, radii, materialMetalBlue }));
    world.Add(std::make_unique<Sphere>(Sphere{{0, 0, -2 * z}, radii, materialMetalPink }));

//    world.Add(std::make_unique<Sphere>(Sphere{ {-distance, distance, z}, radii }));
    world.Add(std::make_unique<Sphere>(Sphere{ {0, distance, z}, radii, materialMetalYellow }));
//    world.Add(std::make_unique<Sphere>(Sphere{ {distance, distance, z}, radii }));

    #pragma omp parallel for schedule(guided)
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
            double r{ sqrt(pixelColor.GetX() * scale) };
            double g{ sqrt(pixelColor.GetY() * scale) };
            double b{ sqrt(pixelColor.GetZ() * scale) };

            int rInt{static_cast<int>(255 * std::clamp(r, 0.0, 1.0))};
            int gInt{static_cast<int>(255 * std::clamp(g, 0.0, 1.0))};
            int bInt{static_cast<int>(255 * std::clamp(b, 0.0, 1.0))};
            int index{ ((imageHeight - y - 1) * imageWidth + x) * 3 };

            image[index++] = rInt;
            image[index++] = gInt;
            image[index++] = bInt;
        }
    }

    stbi_write_png("out.png", imageWidth, imageHeight, 3 /* 1=Y, 2=YA, 3=RGB, 4=RGBA */, image, imageWidth * 3);

    delete[] image;

    return 0;
}
