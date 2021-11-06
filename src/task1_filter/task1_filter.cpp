// Task 1 - Load a 512x512 image lena.raw
//        - Apply specified per-pixel transformation to each pixel
//        - Save as result.raw

#include <fstream>
#include <iostream>

// Size of the framebuffer
const unsigned int SIZE = 512;

// A simple RGB struct will represent a pixel in the framebuffer
struct Pixel {
    // TODO: Define correct data type for r, g, b channel
    uint8_t g;
    uint8_t r;
    uint8_t b;
};

int main()
{
    // Initialize a framebuffer
    auto framebuffer = new Pixel[SIZE][SIZE];

    // TODO: Open file lena.raw (this is 512x512 RAW GRB format)
    std::ifstream input_file("lena.raw", std::ios::binary);

    // TODO: Read data to framebuffer and close the file
    input_file.read(reinterpret_cast<char *>(framebuffer), SIZE * SIZE * 3);
    input_file.close();

    uint8_t l;
    // Traverse the framebuffer
    for (unsigned int y = 0; y < SIZE; y++) {
        for (unsigned int x = 0; x < SIZE; x++) {
            // TODO: Apply pixel operation
            l = 0.3*framebuffer[y][x].r + 0.59*framebuffer[y][x].g + 0.11*framebuffer[y][x].b;
            framebuffer[y][x].r = l;
            framebuffer[y][x].g = l;
            framebuffer[y][x].b = l;

        }
    }

    // TODO: Open file result.raw
    std::cout << "Generating result.raw file ..." << std::endl;
    std::ofstream output_file("result.raw", std::ios::binary);

    // TODO: Write the framebuffer to the file and close it
    output_file.write(reinterpret_cast<char *>(framebuffer), SIZE * SIZE * 3);
    output_file.close();

    std::cout << "Done." << std::endl;
    delete[] framebuffer;
    return EXIT_SUCCESS;
}
