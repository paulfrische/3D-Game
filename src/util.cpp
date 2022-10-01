#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>


GLFWwindow* setup()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;
    glewInit();

    return window;
}

void terminate()
{
    glfwTerminate();
}

const char* read_file(const char* path)
{
    std::string content;
    std::ifstream file;
    std::stringstream content_stream;

    file.open(path);
    content_stream << file.rdbuf();
    file.close();
    content =  content_stream.str();

    return content.c_str();
}

void checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

unsigned int make_program(const char* vertexPath, const char* fragmentPath)
{
    /* const char* vertex_shader_source = read_file(vertexPath); */
    /* const char* fragment_shader_source = read_file(fragmentPath); */


    std::string vertex_shader_source;
    std::ifstream vertex_file;
    std::stringstream vertex_shader_source_stream;

    vertex_file.open(vertexPath);
    vertex_shader_source_stream << vertex_file.rdbuf();
    vertex_file.close();
    vertex_shader_source =  vertex_shader_source_stream.str();

    std::string fragment_shader_source;
    std::ifstream fragment_file;
    std::stringstream fragment_shader_source_stream;

    fragment_file.open(fragmentPath);
    fragment_shader_source_stream << fragment_file.rdbuf();
    fragment_file.close();
    fragment_shader_source =  fragment_shader_source_stream.str();

    const char* vertex_shader_source_const = vertex_shader_source.c_str();
    const char* fragment_shader_source_const = fragment_shader_source.c_str();

    unsigned int vertex_shader = 0;
    unsigned int fragment_shader = 0;

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source_const, nullptr);
    glCompileShader(vertex_shader);
    checkCompileErrors(vertex_shader, "VERTEX");

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source_const, nullptr);
    glCompileShader(fragment_shader);
    checkCompileErrors(fragment_shader, "FRAGMENT");

    unsigned int id = glCreateProgram();
    glAttachShader(id, vertex_shader);
    glAttachShader(id, fragment_shader);
    glLinkProgram(id);
    checkCompileErrors(id, "PROGRAM");

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return id;
}
