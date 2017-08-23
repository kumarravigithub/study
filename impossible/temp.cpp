//#include <iostream>
//
//// GLEW
//#include <GL/glew.h>
//
//// GLFW
//#include <GLFW/glfw3.h>
//
//
//// Shader Class
//#include "Shader.h"
//
//// SOIL2 JSpartan
//#include "SOIL2.h"
//
//const int WIDTH=500, HEIGHT=600;
//
//int main() {
//    
//    // Init GLFW
//    glfwInit( );
//    
//    // Set all the required options for GLFW
//    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
//    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
//    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
//    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
//    
//    glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
//    
//    // Create a GLFWwindow object that we can use for GLFW's functions
//    GLFWwindow *window = glfwCreateWindow( WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr );
//    
//    int screenWidth, screenHeight;
//    glfwGetFramebufferSize( window, &screenWidth, &screenHeight );
//    
//    if ( nullptr == window )
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate( );
//        
//        return EXIT_FAILURE;
//    }
//    
//    glfwMakeContextCurrent( window );
//    
//    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//    glewExperimental = GL_TRUE;
//    // Initialize GLEW to setup the OpenGL Function pointers
//    if ( GLEW_OK != glewInit( ) )
//    {
//        std::cout << "Failed to initialize GLEW" << std::endl;
//        return EXIT_FAILURE;
//    }
//    
//    // Define the viewport dimensions
//    glViewport( 0, 0, screenWidth, screenHeight );
//    // enable alpha support
//    glEnable( GL_BLEND );
//    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
//    
//    
//    // load shaders
//    Shader *ourShader = new Shader("res/shaders/core.vs","res/shaders/core.fs");
//    
//    GLfloat verticesFace2[] = {
//        1.0f, 1.0f, 0.0f,       1.0f, 0.0f, 0.0f,       1.0f, 1.0f, // top right corner
//        1.0f, -1.0f, 0.0f,      0.0f, 1.0f, 0.0f,       1.0f, 0.0f, // bottom right corner
//        -1.0f, -1.0f, 0.0f,     0.0f, 0.0f, 1.0f,       0.0f, 0.0f, // bottom left corner
//        -1.0f, 1.0f, 0.0f,      1.0f, 1.0f, 0.0f,       0.0f, 1.0f  // top left corner
//    };
//    
//    GLuint indicesFace2[] = {
//        0, 1, 2, // trainagle 1 right sided
//        2, 3, 0
//    };
//    
//    GLuint vaoFace2, vboFace2, eboFace2;
//    
//    glGenVertexArrays( 1, &vaoFace2 );
//    glBindVertexArray( vaoFace2 );
//    
//    glGenBuffers( 1, &vboFace2 );
//    glBindBuffer( GL_ARRAY_BUFFER, vboFace2 );
//    glBufferData( GL_ARRAY_BUFFER, sizeof( verticesFace2 ), verticesFace2, GL_STATIC_DRAW );
//    
//    glGenBuffers( 1, &eboFace2 );
//    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, eboFace2 );
//    glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indicesFace2 ), indicesFace2, GL_STATIC_DRAW );
//    
//    
//    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) 0 );
//    glEnableVertexAttribArray(0);
//    
//    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof( GLfloat ), (GLvoid *) ( 3 * sizeof( GLfloat ) ) );
//    glEnableVertexAttribArray(1);
//    
//    glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof( GLfloat ), (GLvoid *) ( 6 * sizeof( GLfloat ) ) );
//    glEnableVertexAttribArray(2);
//    
//    
//    // Load textures
//    GLuint texturesFace2[2];
//    glGenTextures(2, texturesFace2);
//    
//    int widthFace2, heightFace2;
//    unsigned char* imageFace2;
//    ourShader->Use();
//    
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texturesFace2[0]);
//    imageFace2 = SOIL_load_image("res/face1.jpg", &widthFace2, &heightFace2, 0, SOIL_LOAD_RGB);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthFace2, heightFace2, 0, GL_RGB, GL_UNSIGNED_BYTE, imageFace2);
//    SOIL_free_image_data(imageFace2);
//    glUniform1i(glGetUniformLocation(ourShader->Program, "face1"), 0);
//    
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    
//    glActiveTexture(GL_TEXTURE1);
//    glBindTexture(GL_TEXTURE_2D, texturesFace2[1]);
//    imageFace2 = SOIL_load_image("res/face2.jpg", &widthFace2, &heightFace2, 0, SOIL_LOAD_RGB);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthFace2, heightFace2, 0, GL_RGB, GL_UNSIGNED_BYTE, imageFace2);
//    SOIL_free_image_data(imageFace2);
//    glUniform1i(glGetUniformLocation(ourShader->Program, "face2"), 1);
//    
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    //glBindVertexArray(0);
//    
//    
//    
//    // Game loop
//    while ( !glfwWindowShouldClose( window ) )
//    {
//        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
//        glfwPollEvents( );
//        
//        
//        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);
//        glClear( GL_COLOR_BUFFER_BIT );
//        ourShader->Use();
//        
//        //glBindVertexArray(VAO);
//        
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        //glDrawArrays( GL_TRIANGLES, 0, 3 );
//        
//        
//        // Swap the screen buffers
//        glfwSwapBuffers( window );
//    }
//    
//    
//}
