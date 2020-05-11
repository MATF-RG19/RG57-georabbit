#include <cstdlib>
#include <GL/glut.h>

/* Dimenzije prozora */
static int window_width, window_height;

/* Deklaracije callback funkcija. */
static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);

int main(int argc, char **argv){

    /* Inicijalizuje se GLUT.*/
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    
    /* Kreira se prozor. */
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    /*Registruju se callback funkcije.*/
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    
    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    
    glutMainLoop();
    
    return 0;
    
}
static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
    
    /* Podesava se viewport. */
    glViewport(0, 0, width, height);

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (float) width / height, 1, 10);
}

static void on_display(void){

    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);
    
    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            1, 25);
    
     /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            10/5, 20/5, 30/5,
            0, 0, 0,
            0, 1, 0
        );
    
    /* Koordinatni sistem. */
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(10,0,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,10,0);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,10);
    glEnd();
    
    glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y){

    switch(key){
    
        case 27:
            /* Zavrsava se program. */
            exit(0);
            break;
    }
}

