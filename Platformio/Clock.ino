int A=31, B;
void setup()
{
    pinMode(13, HIGH);
    noInterrupts();
    TCCR1A=0;
    TCCR1B=0;
    TCNT1= 0;
    TCCR1B |=(1<<CS11);
    TIMSK1 |= (1<<TOIE1);
    interrupts();
}

ISR(TIMER1_OVF_vect)
{
    TCNT1= 0;
    B=(--A);
    if (B==0){
    digitalWrite(13, digitalRead(13)^1 );
    A=31;
        }
    }
void loop(){
    //bow
}