// Task 4 - Render the letter R using OpenGL
//        - Implement a function to generate bezier curve points
//        - Generate multiple points on each bezier curve
//        - Draw lines connecting the generated points using OpenGL

#include <iostream>
#include <vector>

#include <ppgso/ppgso.h>

#include <shaders/color_vert_glsl.h>
#include <shaders/color_frag_glsl.h>

const unsigned int SIZE = 512;

class BezierWindow : public ppgso::Window {
private:

    // Control points for the bezier curves
    // First curve is 4 control points
    // Rest of the curves are 3 control points, each reusing the last curve end
    // Defines the letter "R"
    std::vector<glm::vec2> controlPoints = {
            {0, 0},
            {0, 0},
            {-.1, -.2},
            { -.25, -.2},
            { -.4,  -.2},
            { -.4,   0},
            { -.25,  0},
            { -.4, 0},
            { -.4,  .2},
            { -.25,   .2},
            {-.1, .2},
            {0, 0},
            {0, 0},
            {0, 0},
            {.1, .2},
            { .25, .2},
            { .4,  .2},
            { .4,   0},
            { .25,  0},
            { .4, 0},
            { .4,  -.2},
            { .25,   -.2},
            {.1, -.2},
            {0, 0},
            {0, 0},
            {0, 0},
            {.2, -.1},
            { .2, -.25},
            { .2,  -.4},
            { 0,   -.4},
            { 0,  -.25},
            { 0, -.4},
            { -.2,  -.4},
            { -.2,   -.25},
            {-.2, -.1},
            {0, 0},
            {0, 0},
            {0, 0},
            {-.2, .1},
            { -.2, .25},
            { -.2,  .4},
            { 0,   .4},
            { 0,  .25},
            { 0, .4},
            { .2,  .4},
            { .2,   .25},
            {.2, .1},
            {0, 0},
            {0, 0},
    };

    // This will hold the bezier curve geometry once we generate it
    std::vector<glm::vec3> points;

    // GLSL Program to use for rendering
    ppgso::Shader program = {color_vert_glsl, color_frag_glsl};

    // These numbers are used to pass buffer data to OpenGL
    GLuint vao = 0, vbo = 0;

    // Compute points for Bezier curve using 4 control points
    glm::vec2 bezierPoint(const glm::vec2 &p0, const glm::vec2 &p1, const glm::vec2 &p2, const glm::vec2 &p3, const float t) {
        // TODO: Compute point on the Bezier curve
        glm::vec2 point;

        glm::vec2 bp0 = p0 + t*(p1-p0);
        glm::vec2 bp1 = p1 + t*(p2-p1);
        glm::vec2 bp2 = p2 + t*(p3-p2);

        glm::vec2 bp00 = bp0 + t*(bp1-bp0);
        glm::vec2 bp01 = bp1 + t*(bp2-bp1);
        point = bp00 + t*(bp01-bp00);

        //point.x = (1-t)*(1-t)*(1-t)*p0.x+3*(1-t)*(1-t)*t*p1.x+3*(1-t)*t*t*p2.x+t*t*t*p3.x;
        //point.y = (1-t)*(1-t)*(1-t)*p0.y+3*(1-t)*(1-t)*t*p1.y+3*(1-t)*t*t*p2.y+t*t*t*p3.y;

        //std::cout << "Generated point: (" << point.x << ", " << point.y << ")" << std::endl;

        return point;
    }

    // Compute points for a sequence of Bezier curves defined by a vector of control points
    // Each bezier curve will reuse the end point of the previous curve
    // count - Number of points to generate on each curve
    void bezierShape(int count) {
        for(int i = 1; i < (int) controlPoints.size(); i+=3) {
            for (int j = 0; j <= count; j++) {
                // TODO: Generate points for each Bezier curve and insert them
                int point1_id = i-1;
                while (point1_id > (int)controlPoints.size()) {
                    point1_id -= (int)controlPoints.size();
                }

                int point2_id = point1_id+1;
                while (point2_id > (int)controlPoints.size()) {
                    point2_id -= (int)controlPoints.size();
                }

                int point3_id = point2_id+1;
                while (point3_id > (int)controlPoints.size()) {
                    point3_id -= (int)controlPoints.size();
                }

                int point4_id = point3_id+1;
                while (point4_id > (int)controlPoints.size()) {
                    point4_id -= (int)controlPoints.size();
                }

                float cur_t = (float)(j)/(float)(count);

                glm::vec2 point = bezierPoint(controlPoints[point1_id], controlPoints[point2_id], controlPoints[point3_id], controlPoints[point4_id], cur_t); //= ??
                points.emplace_back(point, 0);
            }
        }
    }

public:
    BezierWindow() : Window{"task3_bezier", SIZE, SIZE} {
        // Generate Bezier curve points
        bezierShape(15);

        /*
        for (auto & point : points) {
            std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
        }
        */

        // Generate a vertex array object
        // This keeps track of what attributes are associated with buffers
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Generate a vertex buffer object, this will feed data to the vertex shader
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        // TODO: Pass the control points to the GPU
        glBufferData(GL_ARRAY_BUFFER, points.size()*sizeof(glm::vec3), points.data(), GL_STATIC_DRAW);

        // Setup vertex array lookup, this tells the shader how to pick data for the "Position" input
        auto position_attrib = program.getAttribLocation("Position");
        glVertexAttribPointer(position_attrib, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(position_attrib);

        // Set model matrix to identity
        program.setUniform("ModelMatrix", glm::mat4{});
        program.setUniform("ViewMatrix", glm::mat4{});
        program.setUniform("ProjectionMatrix", glm::mat4{});

        // Set the color uniform
        program.setUniform("OverallColor", glm::vec3{1.0f,1.0f,1.0f});
    }

    ~BezierWindow() final {
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }

    void onIdle() final {
        // Set gray background
        glClearColor(0.5f,0.5f,0.5f,0);

        // Clear depth and color buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw shape
        glBindVertexArray(vao);

        // TODO: Define the correct render mode
        glDrawArrays(GL_LINE_STRIP, 0, (int)points.size());
    }
};

int main() {
    // Create our window
    BezierWindow window;

    // Main execution loop
    while (window.pollEvents()) {}

    return EXIT_SUCCESS;
}
