#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  
#include<dos.h>  
void flood(int,int,int,int);  
void main()  
{  
    intgd=DETECT,gm;  
    initgraph(&gd,&gm,"C:/TURBOC3/bgi");  
    rectangle(50,50,250,250);  
    flood(55,55,10,0);  
    getch();  
}  
void flood(intx,inty,intfillColor, intdefaultColor)  
{  
    if(getpixel(x,y)==defaultColor)  
    {  
        delay(1);  
        putpixel(x,y,fillColor);  
        flood(x+1,y,fillColor,defaultColor);  
        flood(x-1,y,fillColor,defaultColor);  
        flood(x,y+1,fillColor,defaultColor);  
        flood(x,y-1,fillColor,defaultColor);  
    }  
}  
