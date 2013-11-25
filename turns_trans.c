/*****************************************************
This program was produced by the
CodeWizardAVR V1.25.9 Standard
Automatic Program Generator
© Copyright 1998-2008 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 11.11.2013
Author  : rtm                             
Company : F4CG                            
Comments: 


Chip type           : ATmega8
Program type        : Application
Clock frequency     : 8,000000 MHz
Memory model        : Small
External SRAM size  : 0
Data Stack size     : 256
*****************************************************/

#include <mega8.h>
#include <delay.h>


void ledoff(void)
{
  PORTD.0 = 1;
  PORTD.1 = 1;
  PORTD.2 = 1;
  PORTD.3 = 1;
  PORTD.4 = 1;
  PORTD.5 = 1;
  PORTB.6 = 1;
}

interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
      if (PINB.1 == 0) {
        PORTD.4 = 0;
        PORTB.6 = 0;
      } else if (PINB.2 == 0) {
        PORTD.0 = 0;
        PORTD.1 = 0;
        PORTD.3 = 0;
        PORTD.4 = 0;
        PORTD.5 = 0;
        PORTB.6 = 0;
      } else if (PINB.3 == 0) {
        PORTD.2 = 0;
        PORTD.0 = 0;
        PORTD.3 = 0;
        PORTD.4 = 0;
        PORTD.5 = 0;
      } else if (PINB.4 == 0) {
        PORTD.2 = 0;
        PORTD.3 = 0;
        PORTD.4 = 0;
        PORTD.5 = 0;
        PORTB.6 = 0;
      } else if (PINB.5 == 0) {
        PORTD.1 = 0;
        PORTD.2 = 0;
        PORTD.4 = 0;
        PORTB.6 = 0;
      } else {
        ledoff();
      };
}

interrupt [TIM2_COMP] void timer2_comp_isr(void)
{
ledoff();
}

char i = 0;

interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
TCNT1=0;
if (i==0) {
 PORTC.3 = 1;
 PORTD.7 = 0;
 i = 1;
} else if (i == 1) {
 PORTC.3 = 0;
 PORTD.7 = 1;
 i = 0;
};
}

interrupt [TIM1_COMPB] void timer1_compb_isr(void)
{
TCNT1=0;
if (i==0) {
 PORTC.2 = 1;
 PORTD.6 = 0;
 i = 1;
} else if (i == 1) {
 PORTC.2 = 0;
 PORTD.6 = 1;
 i = 0;
};
}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port B initialization
// Func7=Out Func6=Out Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=0 State6=0 State5=P State4=P State3=P State2=P State1=P State0=T 
PORTB=0xFE;
DDRB=0xC0;

// Port C initialization
// Func6=In Func5=In Func4=In Func3=In Func2=Out Func1=Out Func0=In 
// State6=T State5=T State4=T State3=T State2=0 State1=0 State0=T 
PORTC=0x13;
DDRC=0x0C;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTD=0x3F;
DDRD=0xFF;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
TCCR0=0x00;
TCNT0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x05;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x0F;
OCR1AL=0x42;
OCR1BH=0x0F;
OCR1BL=0x42;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 31,250 kHz
// Mode: Normal top=FFh
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x06;
TCNT2=0x00;
OCR2=0x70;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
MCUCR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x40;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

#asm("sei")

while (1)
      {
      if (PINB.0 == 1) {
        TIMSK=0xC0;
      } else {
        TIMSK=0x40;
      };
      if (PINC.0 == 0) {
        if (PINB.0 == 1) {
          TIMSK=0xD0;
        } else {
          TIMSK=0x50;
        };
      } else if (PINC.1 == 0) {
        if (PINB.0 == 1) {
          TIMSK=0xC8;
        } else {
          TIMSK=0x48;
        };
      } else {
        if (PINB.0 == 1) {
          TIMSK=0xC0;
        } else {
          TIMSK=0x40;
        };
        PORTC.2 = 0;
        PORTC.3 = 0;
        PORTD.6 = 0;
        PORTD.7 = 0;
        i = 0;
      };
      delay_ms(50);
      if (PINC.4 == 0) {
        PORTB.7 = 0;
      } else {
        PORTB.7 = 1;
      };
      
      };
}
