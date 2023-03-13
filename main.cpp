#include <GL/glut.h>  
#include <math.h>

//Animation
GLfloat animYRot = 0.0;

//variables to move the camera
GLfloat camX = 0.0;
GLfloat camY = 0.0;
GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceX = 0.0;
GLfloat sceY = 0.0;
GLfloat sceZ = 0.0;

//variables to move the snowman
GLfloat objX = 0.0;
GLfloat objY = 0.0;
GLfloat objZ = 0.0;

//variables to translate the scene along z axis
GLfloat transX = 0.0;
GLfloat transY = 0.0;
GLfloat transZ = 0.0;

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);

}

void lighting() {
    GLfloat paleYellow[] = { 1.0,1.0,0.75,1.0 };
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    GLfloat position[] = { 0.0,0.0,0.0,1.0 };
    GLfloat position1[] = { 2.0,4.0,3.0,1.0 };



    //glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, paleYellow);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glLightfv(GL_LIGHT0, GL_AMBIENT, white);


    //glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT1, GL_POSITION, position1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, paleYellow);
    glLightfv(GL_LIGHT1, GL_AMBIENT, white);
    glFlush();
}


void cementFloor1() {/*
    const GLfloat yellow[4] = { 1.0,1,0,1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, yellow);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);*/

    glBegin(GL_QUADS);

    const GLfloat yellow[4] = { 1.0,1,0,1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, yellow);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);

    glColor3f(1, 1, 0);
    glVertex3f(-50,4,0);
    glVertex3f(-50,0,0);
    glVertex3f(50,0,0);
    glVertex3f(50,4,0);

    glVertex3f(-50, 4,0);
    glVertex3f(50, 4, 0);
    glVertex3f(50, 4, -10);
    glVertex3f(-50, 4, -10);

    glVertex3f(-50, 4,-10);
    glVertex3f(50, 4, -10);
    glVertex3f(50, 0, -10);
    glVertex3f(-50, 0, -10);

    glVertex3f(-50, 4, 0);
    glVertex3f(-50, 4, -10);
    glVertex3f(-50, 0, -10);
    glVertex3f(-50, 0, 0);

    glVertex3f(50, 4, -10);
    glVertex3f(50, 4, 0);
    glVertex3f(50,0, 0);
    glVertex3f(50, 0, -10);

    glEnd();
}

void pillar() {

    glBegin(GL_QUADS);

    glColor3f(1, 0, 0.76);

    glVertex3f(-30, 4, -4);
    glVertex3f(-28, 4, -4);
    glVertex3f(-28, 24, -4);
    glVertex3f(-30, 24, -4);

    glVertex3f(-28, 4, -4);
    glVertex3f(-28, 4, -6);
    glVertex3f(-28, 24, -6);
    glVertex3f(-28, 24, -4);

    glVertex3f(-30, 4, -6);
    glVertex3f(-30, 24, -6);
    glVertex3f(-28, 24, -6);
    glVertex3f(-28, 4, -6);

    glVertex3f(-30, 4, -4);
    glVertex3f(-30, 4, -6);
    glVertex3f(-30, 24, -6);
    glVertex3f(-30, 24, -4);




    glEnd();

    

}

void frontRoof() {
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(-52,24,2);
    glVertex3f(52,24,2);
    glVertex3f(52,24,-12);
    glVertex3f(-52,24,-12);
    glEnd();
}

void chairBase() {

    glColor3f(0.1f, 0, 0);

    //seat
    glBegin(GL_QUADS);

    glVertex3f(-23,9,-27);
    glVertex3f(-16, 9, -27);
    glVertex3f(-16, 9, -30);
    glVertex3f(-23, 9, -30);

    glVertex3f(-23, 10, -27);
    glVertex3f(-16, 10, -27);
    glVertex3f(-16, 10, -27);
    glVertex3f(-23, 10, -30);


    glVertex3f(-16, 10, -30);
    glVertex3f(-16, 10, -27);
    glVertex3f(-16, 9, -27);
    glVertex3f(-16, 9, -30);

    glVertex3f(-23, 10, -27);
    glVertex3f(-23, 10, -30);
    glVertex3f(-23, 9, -30);
    glVertex3f(-23, 9, -27);

    glVertex3f(-23, 10, -27);
    glVertex3f(-16, 10, -27);
    glVertex3f(-16, 9, -27);
    glVertex3f(-23, 9, -27);

    glVertex3f(-23, 10, -30);
    glVertex3f(-16, 10, -30);
    glVertex3f(-16, 9, -30);
    glVertex3f(-23, 9, -30);
    
    glEnd();


}

void chair() {


    chairBase();

    //glPushMatrix();
    //glTranslatef(0, 0, -3);
    //glRotatef(-90,1,0,0);
    //glPopMatrix();
}


void bin() {
    glColor3f(0, 0.5f, 0);

    glBegin(GL_QUADS);

    //base
    glVertex3f(-27, 4, -29);
    glVertex3f(-29, 4, -29);
    glVertex3f(-29, 4, -31);
    glVertex3f(-27, 4, -31);

    //front
    glVertex3f(-27, 4, -29);
    glVertex3f(-25, 4, -29);
    glVertex3f(-24.5, 10, -28.9f);
    glVertex3f(-27.5, 10, -28.9f);

    //back
    glVertex3f(-25, 4, -31);
    glVertex3f(-27, 4, -31);
    glVertex3f(-27.5, 8, -31.1f);
    glVertex3f(-24.5, 8, -31.1f);

    //glVertex3f(-24.5, 8, -31.1f);
    //glVertex3f(-24.5, 10, -28.9f);
    //glVertex3f(-27, 4, -29);
    //glVertex3f(-27, 4, -31);

    //glVertex3f(-27.5, 10, -28.9f);
    //glVertex3f(-27.5, 8, -31.1f);
    //glVertex3f(-29, 4, -31);
    //glVertex3f(-29, 4, -29);




    glEnd();



}

void ticketCounter() {

   
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    //left wall
    glVertex3f(-50, 4, -45);
    glVertex3f(-50, 4, -75);
    glVertex3f(-50, 40, -75);
    glVertex3f(-50, 40, -45);

    //back wall
    glVertex3f(-50, 4, -75);
    glVertex3f(-20, 4, -75);
    glVertex3f(-20, 40, -75);
    glVertex3f(-50, 40, -75);

    //left wall
    glVertex3f(-20, 4, -45);
    glVertex3f(-20, 4, -75);
    glVertex3f(-20, 40, -75);
    glVertex3f(-20, 40, -45);

    glColor3f(0.1f, 0, 0);


    //left pillar
    glVertex3f(-50, 4, -45);
    glVertex3f(-47, 4, -45);
    glVertex3f(-47, 30, -45);
    glVertex3f(-50, 30, -45);

    glVertex3f(-47, 4, -45);
    glVertex3f(-47, 30, -45);
    glVertex3f(-47, 30, -48);
    glVertex3f(-47, 4, -48);

    glVertex3f(-50, 4, -48);
    glVertex3f(-47, 4, -48);
    glVertex3f(-47, 40, -48);
    glVertex3f(-50, 40, -48);

    glVertex3f(-50, 4, -48);
    glVertex3f(-50, 4, -45);
    glVertex3f(-50, 30, -45);
    glVertex3f(-50, 30, -48);

    //right pillar
    glVertex3f(-23, 4, -45);
    glVertex3f(-20, 4, -45);
    glVertex3f(-20, 30, -45);
    glVertex3f(-23, 30, -45);

    glVertex3f(-20, 4, -45);
    glVertex3f(-20, 40, -45);
    glVertex3f(-20, 40, -48);
    glVertex3f(-20, 4, -48);

    glVertex3f(-23, 4, -48);
    glVertex3f(-20, 4, -48);
    glVertex3f(-20, 30, -48);
    glVertex3f(-23, 30, -48);

    glVertex3f(-23, 4, -48);
    glVertex3f(-23, 4, -45);
    glVertex3f(-23, 30, -45);
    glVertex3f(-23, 30, -48);

   

    //left wall
    glColor3f(0.5f, 0.5f, 0.5f);

    glVertex3f(-47, 4, -45);
    glVertex3f(-37, 4, -45);
    glVertex3f(-37, 30, -45);
    glVertex3f(-47, 30, -45);

    glVertex3f(-47, 4, -46);
    glVertex3f(-37, 4, -46);
    glVertex3f(-37, 40, -46);
    glVertex3f(-47, 40, -46);

    glVertex3f(-37, 4, -45);
    glVertex3f(-37, 4, -46);
    glVertex3f(-37, 30, -46);
    glVertex3f(-37, 30, -45);


    //right wall 
    glColor3f(0.5f, 0.5f, 0.5f);


    glVertex3f(-33, 4, -45);
    glVertex3f(-20, 4, -45);
    glVertex3f(-20, 30, -45);
    glVertex3f(-33, 30, -45);

    glVertex3f(-33, 4, -46);
    glVertex3f(-20, 4, -46);
    glVertex3f(-20, 30, -46);
    glVertex3f(-33, 30, -46);

    glVertex3f(-33, 4, -45);
    glVertex3f(-33, 4, -46);
    glVertex3f(-33, 30, -46);
    glVertex3f(-33, 30, -45);

    glVertex3f(-37, 14, -45);
    glVertex3f(-33, 14, -45);
    glVertex3f(-33, 30, -45);
    glVertex3f(-37, 30, -45);

    glVertex3f(-37, 14, -46);
    glVertex3f(-33, 14, -46);
    glVertex3f(-33, 30, -46);
    glVertex3f(-37, 30, -46);

    glVertex3f(-37, 14, -45);
    glVertex3f(-33, 14, -45);
    glVertex3f(-33, 14, -46);
    glVertex3f(-37, 14, -46);


   
    
    //roof
    glColor3f(1,0,1);
    glVertex3f(-51,30,-44);
    glVertex3f(-19, 30, -44);
    glVertex3f(-19, 31, -44);
    glVertex3f(-51, 31, -44);

    glVertex3f(-51, 30, -76);
    glVertex3f(-19, 30, -76);
    glVertex3f(-19, 31, -76);
    glVertex3f(-51, 31, -76);

    glVertex3f(-51, 31, -44);
    glVertex3f(-19, 31, -44);
    glVertex3f(-19, 31, -76);
    glVertex3f(-51, 31, -76);

    glVertex3f(-51, 30, -44);
    glVertex3f(-19, 30, -44);
    glVertex3f(-19, 30, -76);
    glVertex3f(-51, 30, -76);

    glVertex3f(-51, 31, -76);
    glVertex3f(-51, 31, -44);
    glVertex3f(-51, 30, -44);
    glVertex3f(-51, 30, -76);

    glVertex3f(-19, 31, -76);
    glVertex3f(-19, 31, -44);
    glVertex3f(-19, 30, -44);
    glVertex3f(-19, 30, -76);

    glEnd();

}

void atm() {

    glColor3f(1, 1, 0);

    glBegin(GL_QUADS);

    //left wall
    glVertex3f(-15, 4, -60);
    glVertex3f(-15, 4, -45);
    glVertex3f(-15, 30, -45);
    glVertex3f(-15, 30, -60);

    //right wall
    glVertex3f(0, 4, -60);
    glVertex3f(0, 4, -45);
    glVertex3f(0, 30, -45);
    glVertex3f(0, 30, -60);

    //back wall
    glVertex3f(-15, 4, -60);
    glVertex3f(-0, 4, -60);
    glVertex3f(-0, 30, -60);
    glVertex3f(-15, 30, -60);

    //roof
    glColor3f(1, 0, 0);
    glVertex3f(-16, 30,-44);
    glVertex3f(1, 30, -44);
    glVertex3f(1, 30,-61);
    glVertex3f(-16, 30, -61);
    glVertex3f(-16, 30, -61);
    
   
    glEnd();
}

void frontPath() {
    cementFloor1();
    pillar();

    glPushMatrix();
    glTranslatef(20, 0, 0);
    pillar();

    glTranslatef(20, 0, 0);
    pillar();

    glTranslatef(20, 0, 0);
    pillar();

    glPopMatrix();
    frontRoof();



}

void trackLongLine() {
    glColor3f(0, 0, 0);

    glBegin(GL_QUADS);

    glVertex3f(-50,0,-19);
    glVertex3f(-50, 0, -18.5);
    glVertex3f(-50, 0.5, -18.5);
    glVertex3f(-50, 0.5, -19);

    glVertex3f(-50, 0, -18.5);
    glVertex3f(50, 0, -18.5);
    glVertex3f(50, 0.5, -18.5);
    glVertex3f(50, 0.5, -18.5);

    glVertex3f(-50, 0.5, -18.5);
    glVertex3f(50, 0.5, -18.5);
    glVertex3f(50, 0.5, -19);
    glVertex3f(-50, 0.5, -19);

    glVertex3f(-50, 0, -19);
    glVertex3f(50, 0, -19);
    glVertex3f(50, 0.5, -19);
    glVertex3f(50, 0.5, -19);

    glVertex3f(50, 0, -19);
    glVertex3f(50, 0, -18.5);
    glVertex3f(50, 0.5, -18.5);
    glVertex3f(50, 0.5, -19);


    glEnd();

}
void trackCrossLine() {
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);

    glVertex3f(-49.5,0.2,-13.5);
    glVertex3f(-49.0, 0.2, -13.5);
    glVertex3f(-49.0, 0.2, -19.5);
    glVertex3f(-49.5, 0.2, -19.5);

    glVertex3f(-49.0, 0.2, -19.5);
    glVertex3f(-49.0, 0.2, -13.5);
    glVertex3f(-49.0, 0.0, -19.5);
    glVertex3f(-49.0, 0.0, -13.5);

    glVertex3f(-49.5, 0.2, -19.5);
    glVertex3f(-49.0, 0.2, -19.5);
    glVertex3f(-49.0, 0.0, -19.5);
    glVertex3f(-49.5, 0.0, -19.5);

    glVertex3f(-49.5, 0.2, -13.5);
    glVertex3f(-49.5, 0.2, -19.5);
    glVertex3f(-49.5, 0.0, -19.5);
    glVertex3f(-49.5, 0.0, -13.5);

    glVertex3f(-49.5, 0.2, -13.5);
    glVertex3f(-49.0, 0.2, -13.5);
    glVertex3f(-49.0, 0.0, -13.5);
    glVertex3f(-49.5, 0.0, -13.5);

    glVertex3f(-49.0, 0.0, -13.5);
    glVertex3f(-49.0, 0.0, -19.5);
    glVertex3f(-49.5, 0.0, -19.5);
    glVertex3f(-49.5, 0.0, -13.5);

    glEnd();

}


void track() {

     trackLongLine();
    glPushMatrix();
    glTranslatef(0, 0, 5);
    trackLongLine();
    glPopMatrix();

    for (int i = 0; i < 50; i++) {
        
        glTranslatef(2.0, 0, 0);
        trackCrossLine();
    }
}


void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    gluLookAt(10, 10, -10, 0.0, 0.0, -80.0, 0.0, 1.0, 0.0);

    //Front foot path
    frontPath();

    //railway track
    glPushMatrix();
    track();
    glPopMatrix();

    //Back foot path
    glPushMatrix();
    glTranslatef(0, 0, -25);
    frontPath();
    glPopMatrix();


    //Ticket counter
    glPushMatrix();
    ticketCounter();
    glPopMatrix();

    //ATM 
    atm();

    glutSwapBuffers();

}




void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        camY += 1;

    if (key == GLUT_KEY_DOWN)
        camY -= 1;

    if (key == GLUT_KEY_RIGHT)
        sceY += 1;

    if (key == GLUT_KEY_LEFT)
        sceY -= 1;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'l')
        objY += 1;

    if (key == 'r')
        objY -= 1;

    if (key == 'Z')
        transZ += 1;

    if (key == 'z')
        transZ -= 1;


    glutPostRedisplay();
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(120, aspect_ratio, 1.0f, 100.0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Railway Station");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

 
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);

    init();
    glutMainLoop();

    return 0;
}