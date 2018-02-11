//
//  main.cpp
//  OpenGL Hello world
//
//  Created by Jayzy on 2018/2/5.
//  Copyright © 2018年 MountainJay. All rights reserved.
//

#include <stdio.h>

#include "GLTools.h"
#include <GLUT/GLUT.h>

GLBatch triangleBatch;
GLShaderManager shaderManager;
//                   0,0              w  h
void ChangeSize(int w,int h)
{
    glViewport(0,0, w, h);
}
//
void SetupRC()
{
    glClearColor(0.0f,0.0f,1.0f,1.0f);
    shaderManager.InitializeStockShaders();
    GLfloat vVerts[] = {
    -0.3f,0.0f,0.0f,
    0.8f,0.0f,0.0f,
    0.0f,0.2f,0.0f,
    };
    triangleBatch.Begin(GL_TRIANGLES, 3);
    triangleBatch.CopyVertexData3f(vVerts);
    triangleBatch.End();
}

void RenderScene(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    GLfloat vRed[] = {1.0f,0.0f,0.0f,1.0f};
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY,vRed);
    triangleBatch.Draw();
    glutSwapBuffers();
}

int main(int argc,char* argv[]){
    
    gltSetWorkingDirectory(argv[0]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
    glutInitWindowSize(800,800);
    glutCreateWindow("Triangle");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    GLenum err = glewInit();
    if(GLEW_OK != err) {
        fprintf(stderr,"glew error:%s\n",glewGetErrorString(err));
        return 1;
    }
    SetupRC();
    glutMainLoop();
    return 0;

}













