#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	Node *o, *e1;
        double a1, a2;

	a1 = M_PI/3;
	a2 = (2*M_PI)/3;

	o = loadtxt("o.dat");
	e1 = loadtxt("e1.dat");
        
	print(o);
}
    

