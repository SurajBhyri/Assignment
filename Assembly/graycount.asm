.include "/sdcard/Download/latex/digital-design/trunk/assembly/setup/m328Pdef/m328Pdef.inc"

ldi r16, 0b00011100
out DDRD, r16 ;Defining pins 2,3 and 4 as outputs

sbi DDRB, 5 ; Defining pin 13 as output
ldi r16, 0b00000101 
out TCCR0B, r16 ;Setting prescaler value as 1024. So new clock value is 15625 Hz.
ldi r31, 0b00000000

ldi r16, 0b00000000 ;b0
ldi r17, 0b00000000 ;b1
ldi r18, 0b00000000 ;b2
 
btog:
mov r19,r18 ;b2 to r19(g2)
eor r18,r17 ;b2 xor b1 stored in r18(g1)
eor r17,r16 ;b1 xor b0 stored in r17(g0)
lsl r19
lsl r19
lsl r19
lsl r19 ;r19 has 0b000(g2)0000
lsl r18
lsl r18
lsl r18 ;r18 has 0b0000(g1)000
lsl r17
lsl r17 ;r17 has 0b00000(g0)00
or r19,r18
or r19,r17 ; r19 has 0b000(g2)(g1)(g0)00

;lp1: ldi r25, 0b01111011 ;lp2 runs 123 times
    ; rcall dy
   ;  rcall outp
  ;   dy: 
 ;      lp3:
;	   IN r26, TIFR0
;	   ldi r27, 0b00000001
;	   and r26, r27
;	   breq delay
;	   out TIFR0, r27
;	   dec r25
;	   brne lp3
;	   ret
;outp:
;out PORTD, r19; g0@2 , g1@3 , g2@4

	
jmp loop

loop:ldi r24, 0b00100000
     eor r31, r24
     out PORTB, r31
     ldi r25, 0b00100000 ;lp2 runs 32 times
     rcall delay
     cpi r31, 0b00000000
     breq loop
     rcall outp


;lp1: ldi r25, 0b01000000 ;lp2 runs 123 times
 ;    rcall dy
  ;   rcall outp
   ;  dy: 
    ;   lp3:
;	   IN r26, TIFR0
;	   ldi r27, 0b00000001
;	   and r26, r27
;	   breq delay
;	   out TIFR0, r27
;	   dec r25
;	   brne lp3
;	   ret
outp:
out PORTD, r19; g0@2 , g1@3 , g2@4

   rjmp gtob
     delay: 
       lp2:
	   IN r26, TIFR0
	   ldi r27, 0b00000001
	   and r26, r27
	   breq delay
	   out TIFR0, r27
	   dec r25
	   brne lp2
	   ret
gtob:
clr r23
clr r24
clr r25
mov r23, r19
cbr r23, 0b11101111
lsr r23	
lsr r23
lsr r23
lsr r23 ;r23 has 0b0000000(g2)
mov r24, r19
cbr r24, 0b11110111
lsr r24
lsr r24
lsr r24 ;r24 has 0b0000000(g1)
mov r25, r19
cbr r25, 0b11111011
lsr r25
lsr r25 ;r25 has 0b0000000(g0)

mov r26, r23 ;G2 to r26(B2)
eor r23, r24 ;G2 xor G1(B1)
mov r27, r23
eor r27, r25 ;G2 xor G1 xor G0(B0)

;inc
ldi r28, 0b00000001
mov r29,r27
eor r29, r28; not(B0)
mov r16, r29 ;c

mov r17, r23 ;r17 has B1
eor r17,r27 ;B1 xor B0(b)

mov r30,r23 ;B1
mov r0, r26 ;B2
eor r30, r28 ;not B1
eor r0, r28 ;not B2
mov r20, r26 ;B2
mov r21, r23 ;B1
mov r22, r27 ;B0

and r30, r20 ; notB1 and B2
and r20, r29 ;B2 and not B0
and r0, r21 ;notB2 and B1
and r0, r22 ;notB2 and B1 and B0
or r0, r20
or r0, r30
mov r18, r0 ;(a)
jmp btog
