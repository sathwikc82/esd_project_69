#include<reg51.h>
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
sbit ir=P1^0;
sbit relay=P2^3;
 
void lcdinit();
void lcddis(unsigned char *s);
void lcddat(unsigned char);
void lcdcmd(unsigned char);
void delay();
void main()
{
lcdinit();
      lcdcmd(0x01);
      lcddis("   AUTOMATIC ROOM  ");
      lcdcmd(0xc0);
      lcddis("  LIGHT CONTROL USING IR  ");
      while(1)
  {
    if(ir==1)
    {
      lcdcmd(0x01);
      lcddis("  SENSOR DETECTED  ");
      lcdcmd(0xc0);
      lcddis("  LIGHT ON   ");
      relay=0;
      while(ir==1);
    }
    else
    {
      lcdcmd(0x01);
      lcddis("  NOSENSOR DETECTED  ");
      lcdcmd(0xc0);
      lcddis("  LIGHT OFF  ");
      relay=1;
    }
  }
}
void lcdinit()
{
      lcdcmd(0x38);
      lcdcmd(0x10);
      lcdcmd(0x06);
      lcdcmd(0x0c);
      lcdcmd(0x80);
}
void lcddis(unsigned char *s)
{
      unsigned char w;
      for(w=0;s[w]!='\0';w++)
  {
      lcddat(s[w]);
  }
}
void lcddat(unsigned char val)
{
      P3=val;
      rs=1;
      rw=0;
      en=1;
      delay();
      en=0;
}
void lcdcmd(unsigned char val)
{
      P3=val;
      rs=0;
      rw=0;
      en=1;
      delay();
      en=0;
}
void delay()
{
      unsigned int v;
      for(v=0;v<=3000;v++);
}
