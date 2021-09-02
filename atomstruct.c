#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142
static GLdouble angle = 0;
static int submenu;
static int mainmenu;
static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
void circle(double rad)
{
    double i;
    glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void drawString(double x, double y, double z, char *string)
{
    char *c;
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for(c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

void drawhead(double x, double y, double z, char *string)
{
    char *c;
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for(c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawsubhead(double x, double y, double z, char *string)
{
    char *c;
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for(c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void nuc(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for(i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void eleright(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}
void eleleft(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));
    }
    glEnd();
}
void eletop(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}
void eledown(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}
void eletr(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eletl(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledl(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledr(double rad)
{
    double i;
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    for(i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void display()
{
    glClearColor(0, 0, 0.1, 0.9);

    if(value == -1)
    {
        char prn[] = "A Mini Project On";
        drawsubhead(-150, 450, 0, prn);
        char pro[] = "ATOM STRUCTURE SIMULATION";
        drawhead(-350, 350, 0, pro);

        char in[] = "Press enter to Continue";
        drawhead(-250, 100, 0, in);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if(value != -1)
    {
        nuc(250);
        char n[] = "NUCLEUS";
        drawString(-90, 20, 0, n);
        char d[] = "(NEUTRON + PROTON)";
        drawString(-180, -30, 0, d);
        if (value == 0)
        {
            char nu[] = "SELECT THE ELEMENT USING MENU";
            drawhead(-490, 900, 0, nu);
        }
    }
    if(value == 1)
    {
        char n[] = "HYDROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 2)
    {
        char n[] = "HELIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 3)
    {
        char n[] = "LITHIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 4)
    {
        char n[] = "BERYLLIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 5)
    {
        char n[] = "BORON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 6)
    {
        char n[] = "CARBON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 7)
    {
        char n[] = "NITROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 8)
    {
        char n[] = "OXYGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 9)
    {
        char n[] = "FLUORINE";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 10)
    {
        char n[] = "NEON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }

    glutSwapBuffers();
}
void rotatel()
{
    angle = angle + 1.5;
    if(angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
}
void rotater()
{
    angle = angle - 1.5;
    if(angle <= 0)
    {
        angle = angle + 360;
    }
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
}
void mouseControl(int button, int state, int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
            glutIdleFunc(rotatel);
}
void keyboard(unsigned char key, int x, int y)
{
    if(key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if(key == 's')
    {
        glutIdleFunc(NULL);
    }
    else if(key == 32)
    {
        glutIdleFunc(rotatel);
    }
    else if(key == 'q' || key == 'Q')
    {
        exit(0);
    }
    else if(key == 27)
    {
        glutReshapeWindow(700, 700);
    }
}
void menu(int option)
{
    if(option == 15)
    {
        exit(0);
    }
    else if(option == 11)
    {
        glutIdleFunc(rotatel);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
        angle = 0;
    }
    else if(option == 13)
    {
        glutIdleFunc(rotater);
    }
    else if(option==14){
        value=-1;
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glutPostRedisplay();
}
void createMenu(void)
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START ANTICLOCKWISE SIMULATION", 11);
    glutAddMenuEntry("STOP SIMULATION", 12);
    glutAddMenuEntry("START CLOCKWISE SIMULATION", 13);
    glutAddMenuEntry("GOTO HOME SCREEN",14);
    glutAddMenuEntry("EXIT", 15);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("ATOM SIMULATION");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    createMenu();
    glutMainLoop();
    return 0;
}

