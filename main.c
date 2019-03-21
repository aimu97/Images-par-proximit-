#include <unistd.h>     
#include <math.h>
#include "ima.h"

#include <GL/glut.h>
#include <GL/glu.h>	

Image *image;

#define ESCAPE 27

void Keyboard(unsigned char key, int x, int y)  {
  switch(key){
  case ESCAPE :
    exit(0);                   
    break;
  default:
    fprintf(stderr, "Unused key\n");
  }
}

void Mouse(int button, int state, int x, int y) {

  switch(button){
  case GLUT_LEFT_BUTTON:
    break;
  case GLUT_MIDDLE_BUTTON:
    break;
  case GLUT_RIGHT_BUTTON:
    break;    
  }
  glutPostRedisplay();
}

int Init(char *s) {

  image = (Image *) malloc(sizeof(Image));
  if (image == NULL) {
    fprintf(stderr, "Out of memory\n");
    return(-1);
  }
  if (ImageLoad_PPM(s, image)==-1) 
	return(-1);
  printf("tailles %d %d\n",(int) image->sizeX, (int) image->sizeY);

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glutReshapeWindow(image->sizeX, image->sizeY);
  
  return (0);
}
int ReInit() {

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glutReshapeWindow(image->sizeX, image->sizeY);
  
  return (0);
}

void Display(void) {
  GLint w;
  GLint h;

  glClear(GL_COLOR_BUFFER_BIT);

 w = glutGet(GLUT_WINDOW_WIDTH);
  h = glutGet(GLUT_WINDOW_HEIGHT);
  glDrawPixels(image->sizeX, image->sizeY, GL_RGB, GL_UNSIGNED_BYTE, 
	       image->data);

  glFlush();
}

void Reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble)h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void menuFunc(int item) {
  char s[256];
  int i,j;
  //  printf("%d\n ",item); 
  switch(item){
  case 0:
    free(image);
    exit(0);
    break;
  case 1:
  case 2:
  case 3:
     case 4:
    // printf("Tout gris\n");
    // val_r_pixel(image,i,j);
	Display();
    break;
   
  case 5:
    printf("Entrer le nom pour l'image dans cette taille\n");
    scanf("%s", &s[0]);
    imagesave_PPM(s, image);
    break;
  case 6:
    printf("Taille de l image : %d %d\n", (int) image->sizeX, (int) image->sizeY);
    break;
  default:
    break;
    
 case 7:
    printf(" \n");
    // val_r_pixel(image,1,1);
    printf("r=%d\n",val_r_pixel(image,1,1));
	Display();
    break;
    
  case 8:
        printf(" \n");
	printf("g=%d\n ",val_g_pixel(image,1,1));

	Display();
      break;
      
     case 9:
        printf(" \n");
	printf("b=%d\n ",val_b_pixel(image,1,1));
	Display();
   break;
   /*
 case 10:
    printf(" \n");
    printf("m-r=%d\n ", moyenne_r_pixel(image));
	Display();
    break;
   
        
  case 11:
        printf(" \n");
	printf("m-g=%d\n ",moyenne_g_pixel(image));
	Display();
  
      break;
      
 case 12:
        printf(" \n");
	printf("m-b=%d\n ",moyenne_b_pixel(image));
	Display();
  
      break;
   */
	
 case 13:
        printf(" \n");
       	moyenne_general(image);
	Display();

	break;
	
	
 case 14:
        printf(" \n");
        moyenne_ponderee(image,1,8,0 ); 
	Display();
	break;

case 15:
        printf(" \n");
	accentuer_le_contraste(image);

	Display();
	break; 

case 16:
  printf(" \n");
  moyenne_general1(image);
  Display();
  break; 



  }
}
int main(int argc, char **argv) {  

  if (argc<2) {
    fprintf(stderr, "Usage : palette nom_de_fichier\n");
    exit(0);
  }

  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(640,480);  
  glutInitWindowPosition(100, 100);  
  glutCreateWindow("VPUP8");  

  Init(argv[1]);

  glutCreateMenu(menuFunc);
  glutAddMenuEntry("Quit", 0);
 
  glutAddMenuEntry("Gris", 2);
  glutAddMenuEntry("GRIS", 3);
  glutAddMenuEntry("grey", 4);
  glutAddMenuEntry("Sauver", 5);
  glutAddMenuEntry("Informations", 6);
  //glutAddMenuEntry("valeur r", 7); 
  //glutAddMenuEntry("valeur g", 8); 
  //glutAddMenuEntry("valeur b", 9);
  //glutAddMenuEntry("valeur moy r", 10); 
  // glutAddMenuEntry("valeur moy g", 11); 
  //glutAddMenuEntry("valeur moy b", 12); 
  glutAddMenuEntry("moyenne general ", 13);  
   glutAddMenuEntry("moyenne ponderee", 14);   
     glutAddMenuEntry("contraste", 15);   
     glutAddMenuEntry("moyenne 2", 16); 
glutAttachMenu(GLUT_LEFT_BUTTON);
  
  glutDisplayFunc(Display);  
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(Keyboard);
  
  glutMouseFunc(Mouse);

  glutMainLoop();  

  return 1;
}
