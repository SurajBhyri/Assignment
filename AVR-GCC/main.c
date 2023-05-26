#include <avr/io.h>

int main(void) {

	int a,b,d,e,f,g,h,i,j,k,l,m,n,o,p,q;
DDRD|=1<<PD2;
DDRB|=1<<PB5;
TCCR1B|=0b00000010 ;//Setting prescaler as8
while(1){
       a=0b00000000;
       b=0b00100000;
lp1:   a^=b;
       PORTB=a;
       d=0b00011111;
      // goto delay;
	       
	            ;e=TCNT1;
                    ;f=16384;
                    ;g=e&f;
		    ;o=g>>14;
		    ;h=TCNT1;
		    ;i=32768;
		    ;j=h&i;
		    ;p=j>>15;
	            ;k=o|p;
		    ;q=k<<2;
		    ;PORTD=q;
                    
	       delay:
		dllp:
		     l=TIFR1;
		     m=0b00000001;
		     n=l&m;
	            e=TCNT1;
                    f=16384;
                    g=e&f;
		    o=g>>14;
		    h=TCNT1;
		    i=32768;
		    j=h&i;
		    p=j>>15;
	            k=o|p;
		    q=k<<2;
		    PORTD=q;
		     if(n==0){
			     goto delay;
		     }
		     else{
			     TIFR1=0b00000001;
--d;
if(d==0){
	goto lp1;
}
else{
	goto dllp;
    }
                          }
 }
return 0;
}

