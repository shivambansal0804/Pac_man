#include<iostream>
#include<graphics.h>
using namespace std;

int xmin,xmax,ymin,ymax;

void liang_barsky(int* arr)
{
    int x1 = arr[0] , y1 = arr[1] , x2 = arr[2] , y2 = arr[3];
    int xx1,xx2,yy1,yy2,dx,dy;
    float t1,t2,p[4],q[4],temp;

    dx=x2-x1;
	dy=y2-y1;

	p[0]=-dx;
	p[1]=dx;
	p[2]=-dy;
	p[3]=dy;

	q[0]=x1-xmin;
	q[1]=xmax-x1;
	q[2]=y1-ymin;
	q[3]=ymax-y1;

	for(int i=0;i<4;i++)
	{
		if(p[i]==0)
		{
			cout<<"line is parallel to one of the clipping boundary";
			if(q[i]>=0)
			{
				if(i<2)
				{
					if(y1<ymin)
					{
						y1=ymin;
					}

					if(y2>ymax)
					{
						y2=ymax;
					}

					line(x1,y1,x2,y2);
				}

				if(i>1)
				{
					if(x1<xmin)
					{
						x1=xmin;
					}

					if(x2>xmax)
					{
						x2=xmax;
					}

					line(x1,y1,x2,y2);
				}
			}
		}
	}

	t1=0;
	t2=1;

	for(int i=0;i<4;i++)
	{
		temp=q[i]/p[i];

		if(p[i]<0)
		{
			if(t1<=temp)
				t1=temp;
		}
		else
		{
			if(t2>temp)
				t2=temp;
		}
	}

	if(t1<t2)
	{
		xx1 = x1 + t1 * p[1];
		xx2 = x1 + t2 * p[1];
		yy1 = y1 + t1 * p[3];
		yy2 = y1 + t2 * p[3];
		line(xx1,yy1,xx2,yy2);
	}
}

int main()
{
    xmin=100,ymin=120,xmax=425,ymax=375;
	int i,gd=DETECT,gm;

	initgraph(&gd,&gm,"");
    setcolor(WHITE);
    outtextxy(100,0,"SHIVAM BANSAL 2K18/CO/335");
    outtextxy(100 , 20 , "BEFORE CLIPPING");

	rectangle(xmin,ymin,xmax,ymax);
	int line1[] = {50,50,200,200};
    int line2[] = {250,215,350,250};
    int line3[] = {150,100,400,50};
    int line4[] = {200,450,500,200};

    drawpoly(2 , line1);
    drawpoly(2 , line2);
    drawpoly(2 , line3);
    drawpoly(2 , line4);

	getch();
	cleardevice();
	outtextxy(100,0,"SHIVAM BANSAL 2K18/CO/335");
    outtextxy(100 , 20 , "AFTER CLIPPING");
    rectangle(xmin,ymin,xmax,ymax);
    liang_barsky(line1);
    liang_barsky(line2);
    liang_barsky(line3);
    liang_barsky(line4);

	getch();
	closegraph();
}










