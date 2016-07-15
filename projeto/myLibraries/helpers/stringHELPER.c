#include <stdio.h>
#include <string.h>


/*
	function that prints the string someString
	between the colun minumun(colMin), and colun maximum(colMax)

	if the colMin is > 0, then the values [0,colMin-1] 
	the values will be printed as SPACES	

	return 0 to a sucessful execution
*/
int printStringMiddle_Colmin_Colmax(char *someString, 
                                    int colMin, int colMax)
{	
	/*
		variable that will receive the colun to start printing the string someString
	*/
	int colToStartPrint_someString = ((colMin - colMax)/2) - (strlen(someString)/2);
	
	//first for (to values before colMin)
	int colMinAux = 0;
	for(; colMinAux < colMin; colMinAux++)
	{
		printf(" ");//print SPACES the intervale before
					//minimun especified colun minumun
	}
	
	//print spaces before reaching the col to start printing the string someString
	int colCurrent = colMinAux;
	for(;colCurrent < colToStartPrint_someString;colCurrent++)
	{
		printf(" ");
	}
	
	puts(someString);
	
	return 0;
}
