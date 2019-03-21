#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

#include <GL/gl.h>	

struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    GLubyte *data;

};


struct pixelsomme {
  GLubyte r;
  GLubyte g;
  GLubyte b;
  

};

typedef struct pixel pixel;
typedef struct Image Image;
typedef unsigned short utab [3][3][3];


int ImageLoad_PPM(char *filename, Image *image);
void imagesave_PPM(char *filename, Image *image);
/*
void floattoint3(float, float, float, int *, int *, int *);
void inttofloat3(int, int, int, float *, float *, float*);
void rgbtohls(float, float, float, float *, float *, float *);
void hlstorgb(float, float, float, float *, float *, float *);
void modifclr(GLubyte *, GLubyte *, int);
void dlr27(Image *), dlr54(Image *), dlr27fs(Image *);
*/

void gris_uniforme (Image *);
/*void untrait (Image *), untraitOK (Image *);
void moserr (Image *), mosprox(Image *);
Image * try2  (Image *);
Image * toclut  (Image *);
*/
int val_r_pixel(Image *,int,int);
int val_g_pixel(Image *,int,int);
int val_b_pixel(Image *,int,int);
/*
int moyenne_r_pixel(Image*);
int moyenne_g_pixel(Image *);
int moyenne_b_pixel(Image *);
*/

int max(int*,int);
void moyenne_general(Image *); 
void moyenne_general1(Image *); 
void moyenne_ponderee(Image *,int,int,int); 
int accentuer_le_contraste(Image *);
