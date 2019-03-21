/* il s agit de prendre une image et de la modifier */

#include "ima.h"
#include <limits.h>

#define min(a,b)   (a<b ? a : b)
#define max(a,b) (a>b ? a : b)

int val_r_pixel(Image * im, int i,int j) {   
  int r;
 
       r =*(im->data +(im->sizeX*j*3) + i* 3);
    
 return r;
}




int val_g_pixel(Image * im, int i,int j) {   
  int g;
       g =*((im->data +(im->sizeX*j*3) + i* 3) + 1);
   return g;
}


int val_b_pixel(Image * im,int i,int j) {  
  int b ;
      b =*((im->data +(im->sizeX*j*3) + i* 3) + 2);
  return b;
}



/*
int  moyenne_r_pixel(Image * im) { 
  GLubyte r;
  int i,j;
  for(i=1; i<im->sizeX;i++){ 
    for(j=1; j<im->sizeY; j++){
      r =(val_r_pixel(im,i,j)+ val_r_pixel(im,i-1,j-1)+val_r_pixel(im,i-1,j)+val_r_pixel(im,i+1,j)+val_r_pixel(im,i+1,j+1)+val_r_pixel(im,i,j+1)+ val_r_pixel(im,i+1,j+1)+val_r_pixel(im,i+1,j)+val_r_pixel(im,i+1,j-1))/9;
    }}
  return r;
}



int moyenne_g_pixel(Image *im){
  GLubyte g;
 int i,j;
  for(i=1; i<im->sizeX;i++){ 
    for(j=1; j<im->sizeY; j++){
      g= (val_g_pixel(im,i,j)+ val_g_pixel(im,i-1,j-1)+val_g_pixel(im,i-1,j)+
	  val_g_pixel(im,i+1,j)+val_g_pixel(im,i+1,j+1)+val_g_pixel(im,i,j+1)+
	  val_g_pixel(im,i+1,j+1)+val_g_pixel(im,i+1,j)+val_g_pixel(im,i+1,j-1))/9;
    }}
  
  return g;
}


int moyenne_b_pixel(Image *im){
  GLubyte b;
 int i,j;
 i=im->sizeX;
 j=im->sizeY;
  for(i=1; i<im->sizeX; i++){
    for(j=1; j<im->sizeY; j++){
      
      b =  (val_b_pixel(im,i,j)+ val_b_pixel(im,i-1,j-1)+val_b_pixel(im,i-1,j)+
	    val_b_pixel(im,i+1,j)+val_b_pixel(im,i+1,j+1)+val_b_pixel(im,i,j+1)+
	    val_b_pixel(im,i+1,j+1)+val_b_pixel(im,i+1,j)+val_b_pixel(im,i+1,j-1))/9;

 
    }}
 return b;
}
*/

void moyenne_general(Image * im) {
  // int i=10,j=10;
  //int m_g;
  GLubyte r,g,b;
  int i,j;
  Image *is=im ;

 for(i=1; i<im->sizeX; i++){
   for(j=1; j<im->sizeY; j++){
    

	  r =(val_r_pixel(im,i,j)+ val_r_pixel(im,i-1,j-1)+val_r_pixel(im,i-1,j)+
	      val_r_pixel(im,i+1,j)+val_r_pixel(im,i+1,j+1)+val_r_pixel(im,i,j+1)+ 
	      val_r_pixel(im,i+1,j+1)+val_r_pixel(im,i+1,j)+val_r_pixel(im,i+1,j-1))/9;
	
       g= (val_g_pixel(im,i,j)+ val_g_pixel(im,i-1,j-1)+val_g_pixel(im,i-1,j)+
	   val_g_pixel(im,i+1,j)+val_g_pixel(im,i+1,j+1)+val_g_pixel(im,i,j+1)+
	   val_g_pixel(im,i+1,j+1)+val_g_pixel(im,i+1,j)+val_g_pixel(im,i+1,j-1))/9;
       
       b =  (val_b_pixel(im,i,j)+ val_b_pixel(im,i-1,j-1)+val_b_pixel(im,i-1,j)+
	     val_b_pixel(im,i+1,j)+val_b_pixel(im,i+1,j+1)+val_b_pixel(im,i,j+1)+
	     val_b_pixel(im,i+1,j+1)+val_b_pixel(im,i+1,j)+val_b_pixel(im,i+1,j-1))/9;
       
       *(is->data +(is->sizeX*j*3) + i* 3)=r;
       *((is->data +(is->sizeX*j*3) + i* 3)+1)= g;
       *((is->data +(is->sizeX*j*3) + i* 3)+2)=b;
       
	 }}}



void moyenne_general1(Image * im) {
  // int i=10,j=10;
  //int m_g;
  GLubyte r,g,b;
  int i,j;
   Image *is =im;
   int s,t;

  
  for(i=1; i<im->sizeX; i++){
   for(j=1; j<im->sizeY; j++){
  
     for(i=1; i<is->sizeX; i++){
       for(j=1; j<is->sizeY; j++){
	 
         *(im->data +(im->sizeX*j*3) + i* 3)=251;
	 *((im->data +(im->sizeX*j*3) + i* 3)+1)=125;
	 *((im->data +(im->sizeX*j*3) + i* 3)+2)=79;
	 

	 r =(val_r_pixel(im,i,j)+ val_r_pixel(im,i-1,j-1)+val_r_pixel(im,i-1,j)+
	      val_r_pixel(im,i+1,j)+val_r_pixel(im,i+1,j+1)+val_r_pixel(im,i,j+1)+ 
	      val_r_pixel(im,i+1,j+1)+val_r_pixel(im,i+1,j)+val_r_pixel(im,i+1,j-1))/9;
	  
	  g= (val_g_pixel(im,i,j)+ val_g_pixel(im,i-1,j-1)+val_g_pixel(im,i-1,j)+
	      val_g_pixel(im,i+1,j)+val_g_pixel(im,i+1,j+1)+val_g_pixel(im,i,j+1)+
	   val_g_pixel(im,i+1,j+1)+val_g_pixel(im,i+1,j)+val_g_pixel(im,i+1,j-1))/9;
       
       b =  (val_b_pixel(im,i,j)+ val_b_pixel(im,i-1,j-1)+val_b_pixel(im,i-1,j)+
	     val_b_pixel(im,i+1,j)+val_b_pixel(im,i+1,j+1)+val_b_pixel(im,i,j+1)+
	     val_b_pixel(im,i+1,j+1)+val_b_pixel(im,i+1,j)+val_b_pixel(im,i+1,j-1))/9;
       
       *(is->data +(is->sizeX*j*3) + i* 3)=r;
       *((is->data +(is->sizeX*j*3) + i* 3)+1)= g;
        *((is->data +(is->sizeX*j*3) + i* 3)+2)=b;
       
   }}
	 }}}


void moyenne_ponderee(Image * im,int a,int t,int c) {
  // int i=10,j=10;
  //int m_g;
  GLubyte r,g,b;
  int i,j;
  int aa,tt,cc;
  int a1=1,a2=2,a3=3,a4=4,a5=5,a6=6,a7=7,a8=8;
  int t1=8,t2=7,t3=6,t4=5,t5=4,t6=3,t7=2,t8=1;
  int c1=10,c2=5,c3=12,c4=4,c5=2,c6=100,c7=20,c8=7;
  
  aa=a+a1+a2+a3+a4+a5+a6+a7+a8;
  tt=t+t1+t2+t3+t4+t5+t6+t7+t8;
  cc=c+c1+c2+c3+c4+c5+c6+c7+c8;

  for(i=100; i<im->sizeX; i++){
    for(j=100; j<im->sizeY; j++){
    
   
      r =((val_r_pixel(im,i,j)*a)+ (val_r_pixel(im,i-1,j-1)*a1)+(val_r_pixel(im,i-1,j)*a2)+
(val_r_pixel(im,i+1,j)*a3)+(val_r_pixel(im,i+1,j+1)*a4)+(val_r_pixel(im,i,j+1)*a5)+
	  ( val_r_pixel(im,i+1,j+1)*a6)+(val_r_pixel(im,i+1,j)*a7)+(val_r_pixel(im,i+1,j-1)*a8))/aa;
      
      g= ((val_g_pixel(im,i,j)*t)+( val_g_pixel(im,i-1,j-1)*t1)+(val_g_pixel(im,i-1,j)*t2)+
	  (val_g_pixel(im,i+1,j)*t3)+(val_g_pixel(im,i+1,j+1)*t4)+(val_g_pixel(im,i,j+1)*t5)+(  val_g_pixel(im,i+1,j+1)*t6)+(val_g_pixel(im,i+1,j)*t7)+(val_g_pixel(im,i+1,j-1)*t8))/tt;
       
      b =  ((val_b_pixel(im,i,j)*c)+ (val_b_pixel(im,i-1,j-1)*c1)+(val_b_pixel(im,i-1,j)*c2)+  (val_b_pixel(im,i+1,j)*c3)+(val_b_pixel(im,i+1,j+1)*c4)+(val_b_pixel(im,i,j+1)*c5)+( val_b_pixel(im,i+1,j+1)*c6)+(val_b_pixel(im,i+1,j)*c7)+(val_b_pixel(im,i+1,j-1)*c8))/cc;
       
     
       *(im->data +(im->sizeX*j*3) + i* 3)=r;
       *((im->data +(im->sizeX*j*3) + i* 3)+1)= g;
       *((im->data +(im->sizeX*j*3) + i* 3)+2)=b;
      
    }
  }
}


int accentuer_le_contraste(Image *im){
  int i,j,x,y,z;
  float r =1;
   int m;
    int tab[9];
    int tab1[9];
    int tab2[9];
  // int max;
  //int distance =0;
  int dr1,dr2,dr3,dr4,dr5,dr6,dr7,dr8;

  for(i=1; i<im->sizeX;i++){ 
    for(j=1; j<im->sizeY; j++){
      for(x=0; x<9;x++){  
	for(y=0; y<9;y++){  
	  for(z=0; z<9;z++){   

	    tab[x]= val_r_pixel(im,i,j);
	tab[x+1]= val_r_pixel(im,i-1,j-1);
	tab[x+2]= val_r_pixel(im,i,j-1);
	tab[x+3]= val_r_pixel(im,i+1,j-1);
	tab[x+4]= val_r_pixel(im,i+1,j);
	tab[x+5]= val_r_pixel(im,i+1,j+1);
	tab[x+6]= val_r_pixel(im,i,j+1);
	tab[x+7]= val_r_pixel(im,i-1,j+1);
	tab[x+8]= val_r_pixel(im,i-1,j);


	tab1[y]= val_g_pixel(im,i,j);
	tab1[y+1]= val_g_pixel(im,i-1,j-1);
	tab1[y+2]= val_g_pixel(im,i,j-1);
	tab1[y+3]= val_g_pixel(im,i+1,j-1);
	tab1[y+4]= val_g_pixel(im,i+1,j);
	tab1[y+5]= val_g_pixel(im,i+1,j+1);
	tab1[y+6]= val_g_pixel(im,i,j+1);
	tab1[y+7]= val_g_pixel(im,i-1,j+1);
	tab1[y+8]= val_g_pixel(im,i-1,j);



	tab2[z]= val_b_pixel(im,i,j);
	tab2[z+1]= val_b_pixel(im,i-1,j-1);
	tab2[z+2]= val_b_pixel(im,i,j-1);
	tab2[z+3]= val_b_pixel(im,i+1,j-1);
	tab2[z+4]= val_b_pixel(im,i+1,j);
	tab2[z+5]= val_b_pixel(im,i+1,j+1);
	tab2[z+6]= val_b_pixel(im,i,j+1);
	tab2[z+7]= val_b_pixel(im,i-1,j+1);
	tab2[z+8]= val_b_pixel(im,i-1,j);
 
		printf("tab[%d]=%d\n",x,tab[x]); 
		printf("tab1[%d]=%d\n",y,tab1[y]); 
		printf("tab2[%d]=%d\n",z,tab2[z]); 


  for(i=1; i<im->sizeX;i++){ 
    for(j=1; j<im->sizeY; j++){
      for(x=0; x<9;x++){  
	for(y=0; y<9;y++){  
	  for(z=0; z<9;z++){   

		dr1= ((tab[x+1] - tab[x])* (tab[x+1]*tab[x])) + ((tab1[y+1] - tab1[y])* (tab1[y+1] * tab1[y])) + ((tab2[z+1] - tab2[z])* (tab2[z+1]*tab2[z]));
		dr2= ((tab[x+2] - tab[x])* (tab[x+2]*tab[x])) + ((tab1[y+2] - tab1[y])* (tab1[y+2] * tab1[y])) + ((tab2[z+2] - tab2[z])* (tab2[z+2]*tab2[z]));
		dr3= ((tab[x+3] - tab[x])* (tab[x+3]*tab[x])) + ((tab1[y+3] - tab1[y])* (tab1[y+3] * tab1[y])) + ((tab2[z+3] - tab2[z])* (tab2[z+3]*tab2[z]));
		dr4= ((tab[x+4] - tab[x])* (tab[x+4]*tab[x])) + ((tab1[y+4] - tab1[y])* (tab1[y+4] * tab1[y])) + ((tab2[z+4] - tab2[z])* (tab2[z+4]*tab2[z]));
		dr5= ((tab[x+5] - tab[x])* (tab[x+5]*tab[x])) + ((tab1[y+5] - tab1[y])* (tab1[y+5] * tab1[y])) + ((tab2[z+5] - tab2[z])* (tab2[z+5]*tab2[z]));
		dr6= ((tab[x+6] - tab[x])* (tab[x+6]*tab[x])) + ((tab1[y+6] - tab1[y])* (tab1[y+6] * tab1[y])) + ((tab2[z+6] - tab2[z])* (tab2[z+6]*tab2[z]));
		dr7= ((tab[x+7] - tab[x])* (tab[x+7]*tab[x])) + ((tab1[y+7] - tab1[y])* (tab1[y+7] * tab1[y])) + ((tab2[z+7] - tab2[z])* (tab2[z+7]*tab2[z]));
		dr8= ((tab[x+8] - tab[x])* (tab[x+8]*tab[x])) + ((tab1[y+8] - tab1[y])* (tab1[y+8] * tab1[y])) + ((tab2[z+8] - tab2[z])* (tab2[z+8]*tab2[z]));
	  }}}}}}}}}}
  /*
 printf("%d\n",dr1); 
 printf("%d\n",dr2);
 printf("%d\n",dr3);      
 printf("%d\n",dr4);
 printf("%d\n",dr5);
 printf("%d\n",dr6);      
 printf("%d\n",dr7);
 printf("%d\n",dr8);
  */
}
