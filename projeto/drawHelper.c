#include <stdio.h>

void drawnGallow(int errorTotal, int errorsMax)
{
	char a = 219;
    char b = 220;
   
	
	float whatDraw = ((float)errorTotal/errorsMax) * 100;
	if(whatDraw == 0)
	{   
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c                \n", a);
    	printf("         %c              \n", a);
    	printf("         %c                 \n", a);
    	printf("         %c              \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else if(whatDraw > 0 && whatDraw <= 14.28)
	{
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c      O           \n", a);
    	printf("         %c              \n", a);
    	printf("         %c                \n", a);
    	printf("         %c              \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else if(whatDraw > 14.28 && whatDraw <= 14.28*2)
	{
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c      O           \n", a);
    	printf("         %c      |         \n", a);
   	 	printf("         %c                 \n", a);
    	printf("         %c              \n", a);
   	 	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else if(whatDraw > 14.28*2 && whatDraw <= 14.28*3)
	{
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c      O           \n", a);
    	printf("         %c     /|         \n", a);
    	printf("         %c                 \n", a);
    	printf("         %c              \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else if(whatDraw > 14.28*3 && whatDraw <= 14.28*4)
	{
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c      O           \n", a);
    	printf("         %c     /|\\         \n", a);
    	printf("         %c               \n", a);
    	printf("         %c              \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else if(whatDraw > 14.28*4 && whatDraw <= 14.28*5)
	{   
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c      O           \n", a);
    	printf("         %c     /|\\         \n", a);
    	printf("         %c      |           \n", a);
    	printf("         %c              \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else if(whatDraw >= 14.28*5 && whatDraw <= 14.28*6)
	{    
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);     
    	printf("         %c      |           \n", a);                          
    	printf("         %c      O           \n", a);
   		printf("         %c     /|\\         \n", a);
    	printf("         %c      |           \n", a);
    	printf("         %c     /          \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else if(whatDraw > 14.28*6 && whatDraw < 14.28*7)
	{   
    	printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c      O           \n", a);
    	printf("         %c     /|\\         \n", a);
    	printf("         %c      |           \n", a);
    	printf("         %c     / \\         \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
	else
	{
		printf("         %c%c%c%c%c%c%c%c           \n", a,b,b,b,b,b,b,b);
    	printf("         %c      |           \n", a);
    	printf("         %c      X           \n", a);
    	printf("         %c     /|\\         \n", a);
    	printf("         %c      |           \n", a);
    	printf("         %c     / \\         \n", a);
    	printf("         %c                  \n", a);
    	printf("OooooooOOOOOOOoooooOooooooooo\n");    
	}
}
