#include <math.h>
#include <stdio.h>
#include <windows.h>

int main() {
	
	// F(x) = sin(x)
	
	// Declaring screen mertics
	const int SCR_WIDTH = 80;
	const int SCR_HEIGT = 25; 
	
	// Declaring interval
	const double LEFT = 0;
	const double RIGHT = 6;
	
	// Declaring an array
	char scr[SCR_HEIGT][SCR_WIDTH];
	
	// X-step
	const double dx = (RIGHT-LEFT)/SCR_WIDTH;
	
	// Calculating Y-step
	double Fmax = cos(LEFT);
	double Fmin = cos(LEFT);
	
	double x,y,Fcurrent;
	
	// Calculating max and min values of function
	for(x = LEFT; x <= RIGHT; x += dx) {
		Fcurrent = cos(x);
		if(Fcurrent > Fmax) Fmax = Fcurrent;
		if(Fcurrent < Fmin) Fmin = Fcurrent;
	}
	
	const double dy = (Fmax-Fmin)/SCR_HEIGT;
	
	// Initializing array with spaces
	for(int i = 0; i < SCR_HEIGT; i++)
		for(int j = 0; j < SCR_WIDTH; j++)
			scr[i][j] = ' ';
			
	// Bulding a graphic	
	int Xcurrent,Ycurrent;
	for(Xcurrent = 0; Xcurrent < SCR_WIDTH; Xcurrent++) {
		x = Xcurrent * dx + Fmin;
		Fcurrent = cos(x);
		Ycurrent = (Fmax - Fcurrent)/dy;
		scr[Ycurrent][Xcurrent] = '*';
	}
	
			
	// Printing result array
	for(int i = 0; i < SCR_HEIGT; i++) {
		for(int j = 0; j < SCR_WIDTH; j++)
			printf("%c",scr[i][j]);
			Sleep(100);
		printf("\n");
	}
	
}
