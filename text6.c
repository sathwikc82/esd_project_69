#include<reg51.h>

sbit output=P2^0;
sbit output1=P2^1;
sbit output2=P2^2;
sbit output3=P2^3;


void msdelay(unsigned int time)  // Function for creating delay in milliseconds.

{

    unsigned i,j ;

    for(i=0;i<time;i++)    

    for(j=0;j<1275;j++);

}


void servo_delay(int times)     // Creating Delay in multilple of 50us using 8051 Timers

{

    int m;

    for(m=0;m<times;m++)

    {

        TH0=0xFF;

        TL0=0xD2;

        TR0=1;

        while(TF0==0);

        TF0=0;

        TR0=0;

    }

}

void main()

{

    int n;

    TMOD=0x01;                // Selecting Timer 0, Mode 1

    output=0;

    while(1)

    {

        for(n=13;n<28;n=n+2)

        {

            output=1;

            servo_delay(n);     

            output=0;

            servo_delay(260);

            msdelay(200);
					
					output1=1;

            servo_delay(n);     

            output1=0;

            servo_delay(260);

            msdelay(200);
					  output2=1;

            servo_delay(n);     

            output2=0;

            servo_delay(260);

            msdelay(200);
						output3=1;

            servo_delay(n);     

            output3=0;

            servo_delay(260);

            msdelay(200);

        }

    }

}

