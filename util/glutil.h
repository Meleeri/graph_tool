#ifndef GLUTIL_H
#define GLUTIL_H

#define GLEW_STATIC

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);


#endif