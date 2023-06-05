#include <avr/io.h>

int main(void) {

	int a,b,d,e,f,g,h,i,j,k,l,m,n,o,p,q;
DDRD|=1<<PD2; //Defining pin 2 as output
DDRB|=1<<PB5; //Defining pin 13 as output
TCCR1B|=0b00000010 ;//Setting prescaler as 8
while(1){
       a=0b00000000;
       b=0b00100000;
lp1:   a^=b; //Toggles the LED at pin 13
       PORTB=a;
       d=0b00011111; // 31 cycles for 1 second delay
                    
	       delay:
		dllp:
		     l=TIFR1; //0th bit, which is the TOV1 flag, is set when counter overflows 
		     m=0b00000001;
		     n=l&m;
	            e=TCNT1; //Loading value of counter into e
                    f=16384;//Number of pulses after which 14th bit is set
                    g=e&f;
		    o=g>>14;//Right shift 14 times
		    h=TCNT1;
		    i=32768;//Number of pulses after which 15th bit is set
		    j=h&i;
		    p=j>>15;//Right shift 15 times
	            k=o|p;
		    q=k<<2;//Left shift 2 times
		    PORTD=q;
		     if(n==0){
			     goto delay;
		     }
		     else{
			     TIFR1=0b00000001; //Loading 0b00000001 to the TIFR1 register clears the TOV1 flag
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

