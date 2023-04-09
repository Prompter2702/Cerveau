#include "../Header/image.hpp"

// Function to generate a random image
int generate_image(const std::string & name_file)
{
    std::vector<Pixel> pixels(100 * 100, {0, 0, 0});
    // Randomly choose the shape (circle or square)
    bool is_circle = std::rand() % 2 == 0;

    // Randomly choose the radius
    int r = 5 + std::rand() % 40 ;

    // Randomly choose the center point
    int cx = 2 + r + std::rand() % (96 - 2*r);
    int cy = 2 + r + std::rand() % (96 - 2*r);

    if (is_circle) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int dx = i - cx;
                int dy = j - cy;
                if (dx * dx + dy * dy <= r * r) {
                    pixels[i + j * 100] = {255, 255, 255};
                }
            }
        }
    } else {
        int x1 = std::max(0, cx - r);
        int x2 = std::min(99, cx + r);
        int y1 = std::max(0, cy - r);
        int y2 = std::min(99, cy + r);
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                pixels[i + j * 100] = {255, 255, 255};
            }
        }
    }

    // Write the pixels to a PPM file
    std::ofstream ppm(name_file);
    ppm << "P3\n100 100\n255\n";
    for (const auto& pixel : pixels) {
        ppm << static_cast<int>(pixel.red) << " "
            << static_cast<int>(pixel.green) << " "
            << static_cast<int>(pixel.blue) << " ";
    }
    ppm.close();

    return is_circle;
}


std::vector<double> read_ppm(std::string filename) 
{
    std::ifstream ppm(filename, std::ios::binary);
    if (!ppm.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }

    std::string magic_number;
    ppm >> magic_number;
    if (magic_number != "P3") {
        std::cerr << "Error: Unsupported file format." << std::endl;
        exit(1);
    }

    int width, height, max_val;
    ppm >> width >> height >> max_val;
    if (max_val != 255) {
        std::cerr << "Error: Unsupported maximum value." << std::endl;
        exit(1);
    }

    std::vector<double> pixels;
    pixels.reserve(width * height);

    int red, green, blue;
    while (ppm >> red >> green >> blue) {
        double pixel = (red + green + blue)/3.0;
        pixels.push_back(pixel);
    }

    ppm.close();
    return pixels;
}