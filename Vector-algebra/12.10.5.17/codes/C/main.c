#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"
int main()
{
	int m=2, n=1;
        double **o, **e1, **T1, **T2;
        double a1, a2;


	o = loadtxt("o.dat",2,1);
	e1 = loadtxt("e1.dat",2,1);
        a1 = M_PI/3;
	a2 = (2*M_PI)/3;
        
	T1 = linalg_thet(a1);
        T2 = linalg_thet(a2);

	print(T1,m,n);
	print(T2,m,n);
	save1(T1,m,n);
	save(T2,m,n);
}
		
