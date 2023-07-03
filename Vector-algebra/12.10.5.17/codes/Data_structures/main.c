#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	Node *o, *e1, *c, *b;
        double a1, a2, c1 ,s1, c2, s2;
        double *x, *y ;
	
	a1 = M_PI/3;
	a2 = (2*M_PI)/3;

	o = loadtxt("o.dat");
	e1 = loadtxt("e1.dat");
        
	c1 = cos(a1);
	s1 = sin(a1);

	c2 = cos(a2);
	s2 = sin(a2);

        c = createMatrix(2,1);
	x = (double *)malloc(2*sizeof(double));
	x[0] = c1;
	x[1] = s1;
	c = assign(2,1,x);

        b = createMatrix(2,1);
	y = (double *)malloc(2*sizeof(double));
	y[0] = c2;
	y[1] = s2;
	b = assign(2,1,y);

	print(b);
	print(c);
        savef("b.dat",b,2,1);
	savef("c.dat",c,2,1);
	
}
    

