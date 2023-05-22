.include "/sdcard/Download/latex/digital-design/trunk/assembly/setup/m328Pdef/m328Pdef.inc"

ldi r16, 0b00011100
out DDRD, r16 ;Defining pins 2,3 and 4 as outputs

sbi DDRB, 5 ; Defining pin 13 as output
ldi r16, 0b00000101 
out TCCR0B, r16 ;Setting prescaler value as 1024. So new clock value is 15625 Hz.

ldi r31, 0b00000000

ldi r16, 0b00000000 ;g0
ldi r17, 0b00000000 ;g1
ldi r18, 0b00000000 ;g2

again:
mov r10,r16 ;0b0000000(g0)

mov r11, r17
lsl r11 ;0b000000(g1)0

mov r12, r18
lsl r12
lsl r12 ;0b00000(g2)00

or r10, r11
or r10, r12; r10 has 0b00000(g2)(g1)(g0)
lsl r10
lsl r10 ;r10 has 0b000(g2)(g1)(g0)00
mov r19, r10

jmp loop

loop:ldi r24, 0b00100000
     eor r31, r24
     out PORTB, r31
     ldi r25, 0b00100000 ;lp2 runs 32 times
     rcall delay
     cpi r31, 0b00000000
     breq loop ;If clock is low(i.e., r31 is 0), go to loop
     rcall outp ;else jump to outp

outp:
out PORTD, r19; g0@2 , g1@3 , g2@4

   rjmp inc
     delay: 
       lp2:
	   IN r26, TIFR0
	   ldi r27, 0b00000001
	   and r26, r27
	   breq delay ;loop breaks after 256 times
	   out TIFR0, r27 ;Clearing the TOV0 flag
	   dec r25
	   brne lp2 ;loop breaks after 32 times
	   ret

inc:
ldi r28, 0b00000001
mov r10, r16 
mov r11, r16 ;g0
eor r10, r28 ;not g0

mov r13, r17;g1
mov r9, r17;g1
mov r14, r17
eor r14, r28; not g1

mov r5, r18;g2
mov r1, r18; g2
mov r6, r18
eor r6, r28; not g2
mov r0,r6 ;not g2

and r5, r11; g2 and g0
and r13, r10; g1 and not g0 
or r5, r13; G2
mov r18, r5

and r6, r11 ;not g2 and g0
or r6, r13; G1
mov r17, r6

and r0, r14 ;not g2 and not g1
and r9, r1 ;g1 and g2
or r0, r9; G0
mov r16, r0

jmp again
