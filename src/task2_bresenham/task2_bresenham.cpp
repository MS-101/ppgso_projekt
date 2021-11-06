// Task 3 - Implement Bresenham drawing alg.
//        - Draw a star using lines
//        - Make use of std::vector to define the shape
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#include <ppgso/ppgso.h>

// Size of the framebuffer
const unsigned int SIZE = 512;

struct Point {
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x,y;
};

struct Pixel {
    Pixel(uint8_t r, uint8_t g, uint8_t b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    uint8_t r;
    uint8_t g;
    uint8_t b;
};

// Bresenham drawing algorithm
void drawLine(ppgso::Image& framebuffer, Point& from, Point& to) {
    // TODO: Implement Bresenham drawing algorithm
    int x1 = from.x;
    int x2 = to.x;
    int y1 = from.y;
    int y2 = to.y;

    std::cout << "Drawing line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << std::endl;

    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    int dy = abs(y2 - y1);

    if (dx >= dy) {
        int p = 2*dy - dx;

        int step;
        if (y2 > y1) {
            step = 1;
        } else {
            step = -1;
        }

        while (x <= x2) {
            framebuffer.setPixel(x, y, {0, 0, 0});
            x++;
            if (p < 0) {
                p = p + 2*dy;
            } else {
                p = p + 2*dy - 2*dx;
                y += step;
            }
        }
    } else {
        int p = 2*dx - dy;

        if (y1 < y2) {
            while (y <= y2) {
                framebuffer.setPixel(x, y, {0, 0, 0});
                y++;
                if (p < 0) {
                    p = p + 2*dx;
                } else {
                    p = p + 2*dx - 2*dy;
                    x++;
                }
            }
        } else {
            while (y >= y2) {
                framebuffer.setPixel(x, y, {0, 0, 0});
                y--;
                if (p < 0) {
                    p = p + 2*dx;
                } else {
                    p = p + 2*dx - 2*dy;
                    x++;
                }
            }
        }
    }
}

int main()
{
    // Use ppgso::Image as our framebuffer
    ppgso::Image framebuffer(SIZE, SIZE);
    framebuffer.clear({255, 255, 255});

    // TODO: Generate star points
    std::vector<Point> points;

    unsigned int vertices_count = 4;
    unsigned int radius = 100;
    int center_x = 200;
    int center_y = 200;

    Point *firstPoint;
    for (unsigned int i = 0; i < vertices_count; i++) {
        int outer_x = center_x + (int)round(radius * cos(2*M_PI*i/vertices_count));
        int outer_y = center_y + (int)round(radius * sin(2*M_PI*i/vertices_count));
        if (i == 0) {
            firstPoint = new Point(outer_x, outer_y);
        }
        auto *outerPoint = new Point(outer_x, outer_y);
        points.push_back(*outerPoint);

        if (i == vertices_count - 1) {
            points.push_back(*firstPoint);
        }
    }

    // Draw lines
    for(unsigned int i = 0; i < points.size() - 1; i++) {
        drawLine(framebuffer, points[i], points[i+1]);
    }

    // Save the result
    std::cout << "Generating task2_bresenham.bmp file ..." << std::endl;
    ppgso::image::saveBMP(framebuffer, "task2_bresenham.bmp");

    std::cout << "Done." << std::endl;
    return EXIT_SUCCESS;
}