#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

// reduce boilerplate in main file
GLFWwindow *setup();
void terminate();

const char *read_file(std::string path);
unsigned int make_program(const char *vertexPath, const char *fragmentPath);
