#include<reg51.h>
sbit mot1=P2^0;
sbit mot2=P2^1;
sbit mot3=P2^2;
sbit mot4=P2^3;

sbit s_left=P2^6;
sbit s_right=P2^7;

void forward (void);
void backward (void);
void left (void);
void right (void);

void forward (void)
{
  mot1=0;
	mot2=1;
	mot3=1;
	mot4=0;
}
void backward (void)
{
  mot1=0;
	mot2=1;
	mot3=0;
	mot4=1;
}
void left (void)
{
  mot1=0;
	mot2=1;
	mot3=0;
	mot4=0;
}
void right (void)
{
  mot1=0;
	mot2=0;
	mot3=1;
	mot4=0;
}
void stop (void)
{
  mot1=0;
	mot2=0;
	mot3=0;
	mot4=0;
}



void main()
{
	s_left=1;
	s_right=1;
	while(1)
	{ 
	 if(s_left==0 && s_right==0)
	 {
		 forward();
	 }
	 else if(s_left==1 && s_right==1)
	 {
		 stop();
	 }
	 else if(s_left==0 && s_right==1)
	 {
		 left();
	 }
	 else if(s_left==1 && s_right==0)
	 {
		 right();
	 }
 }
}