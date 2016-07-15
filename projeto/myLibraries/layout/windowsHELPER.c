#include <stdio.h>
#include <stdlib.h>

void set_DOS_size(int height, int width)
{
	char command_line[50];
	sprintf(command_line, "mode con:cols=%d lines=%d", width, height);
	
	system(command_line);
}
