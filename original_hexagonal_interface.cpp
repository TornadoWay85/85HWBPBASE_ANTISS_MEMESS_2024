#define _CRT_SECURE_NO_WARNINGS
#include "Init6.h"

cHexagonal gHexagonalInterface;

cHexagonal::cHexagonal()
{
	//VMProtectBeginUltra("cHexagonal::cHexagonal");
	fSpaceBetweenBlocksAndTitles=0;
	szTitle[0]=0;
	szEndTitle[0]=0;
	iStyle=0;
	//VMProtectEnd();
}

void cHexagonal::AddString(int position,int index,int r,int g,int b,char*fmt,...)
{
	HexagonalStringEntry tmp;
	va_list va_alist;
	char buf[256];
	//VMProtectBeginMutation("cHexagonal::AddString");
	va_start(va_alist,fmt);
	_vsnprintf(buf,sizeof(buf),fmt,va_alist);
	va_end(va_alist);
	tmp.iPosition=position;
	tmp.iIndexOfCapsule=index;
	tmp.r=r;
	tmp.g=g;
	tmp.b=b;
	strcpy(tmp.szString,buf);
	VStringEntrys.push_back(tmp);
	//VMProtectEnd();
}

int cHexagonal::CalculateHeightCapsule()
{
	int iRetVal;
	//VMProtectBeginMutation("cHexagonal::CalculateHeightCapsule");
	iRetVal=heightenginefont+4;
	//VMProtectEnd();
	return iRetVal;
}

int cHexagonal::CalculateWidthByStrings()
{
	unsigned int i;
	int height,lenght,lenghtmax;
	//VMProtectBeginMutation("cHexagonal::CalculateWidthByStrings");
	lenghtmax=0;
	for(i=0;i<VStringEntrys.size();i++)
	{
		gEngine.pfnDrawConsoleStringLen(VStringEntrys[i].szString,&lenght,&height);
		lenghtmax=lenght>lenghtmax?lenght:lenghtmax;
	}
	lenghtmax+=20;
	//VMProtectEnd();
	return lenghtmax;
}

int cHexagonal::CalculateWidthByXLeftSide(int numberofitems)
{
	int i,xmore;
	//VMProtectBeginMutation("cHexagonal::CalculateWidthByXLeftSide");
	xmore=20;//triangulos de capsula de arriba y abajo
	for(i=0;i<numberofitems;i++)
		xmore+=10;
	//VMProtectEnd();
	return xmore;
}

void cHexagonal::SetTitles(char*title)
{
	//VMProtectBeginMutation("cHexagonal::SetTitles");
	if(title)strcpy(szTitle,title);
	//VMProtectEnd();
}

void cHexagonal::SetStyle(int style)
{
	//VMProtectBeginMutation("cHexagonal::SetStyle");
	iStyle=style;
	//VMProtectEnd();
}

void cHexagonal::SetPercentageBlock(int position,float value)
{
	HexagonBarEntry tmp;
	//VMProtectBeginMutation("cHexagonal::SetPercentageBlock");
	tmp.iIndex=position;
	tmp.fValue=value;
	VHexagonBarEntry.push_back(tmp);
	//VMProtectEnd();
}

void cHexagonal::ReleaseResources()
{
	//VMProtectBeginMutation("cHexagonal::ReleaseResources");
	VStringEntrys.clear();
	VHexagonBarEntry.clear();
	szTitle[0]=0;
	szEndTitle[0]=0;
	//VMProtectEnd();
}

void cHexagonal::DrawFillTriangle(int xa,int ya,int xb,int yb,int xc,int yc,int r,int g,int b,int a)
{
	//VMProtectBeginMutation("cHexagonal::DrawFillTriangle");
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glColor4ub(r,g,b,a);
	glBegin(GL_TRIANGLES);
	glVertex2f(xa,ya);
	glVertex2f(xb,yb);
	glVertex2f(xc,yc);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//VMProtectEnd();
}

void cHexagonal::DrawFillTriangleWithGradientUpToDown(int xa,int ya,int xb,int yb,int xc,int yc,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab)
{
	//VMProtectBeginMutation("cHexagonal::DrawFillTriangleWithGradientUpToDown");
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);
	glColor4ub(ra,ga,ba,aa);
	glVertex2f(xa,ya);
	glVertex2f(xb,yb);
	glColor4ub(rb,gb,bb,ab);
	glVertex2f(xc,yc);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//VMProtectEnd();
}

void cHexagonal::DrawFillRectangleWithGradientRightToLeft(int x,int y,int w,int h,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab)
{
	//VMProtectBeginMutation("cHexagonal::DrawFillRectangleWithGradientRightToLeft");
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor4ub(ra,ga,ba,aa);
	glVertex2f(x,y);
	glVertex2f(x,y+h);
	glColor4ub(rb,gb,bb,ab);
	glVertex2f(x+w,y+h);
	glVertex2f(x+w,y);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//VMProtectEnd();
}

void cHexagonal::DrawFillRectangleWithGradientUpToDown(int x,int y,int w,int h,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab)
{
	//VMProtectBeginMutation("cHexagonal::DrawFillRectangleWithGradientUpToDown");
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor4ub(ra,ga,ba,aa);
	glVertex2f(x,y);
	glVertex2f(x+w,y);
	glColor4ub(rb,gb,bb,ab);
	glVertex2f(x+w,y+h);
	glVertex2f(x,y+h);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//VMProtectEnd();
}

void cHexagonal::DrawLine(int xa,int ya,int xb,int yb,int r,int g,int b,int a)
{
	//VMProtectBeginMutation("cHexagonal::DrawLine");
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glColor4ub(r,g,b,a);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(xa,ya);
	glVertex2f(xb,yb);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//VMProtectEnd();
}

/*void DrawHexagonWithGradientLeftToRight(int x,int y,int w,int h,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab)
{
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor4ub(ra,ga,ba,aa);
	glVertex2f(x-9,y+h/2);
	glVertex2f(x,y+1);
	glColor4ub(rb,gb,bb,ab);
	glVertex2f(x+w,y+1);
	glVertex2f(x+w+9,y+h/2);
	glVertex2f(x+w,y+h-1);
	glColor4ub(ra,ga,ba,aa);
	glVertex2f(x,y+h-1);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

}*/

void cHexagonal::DrawHexagonWithGradientUpToDown(int x,int y,int w,int h,int ra,int ga,int ba,int aa,int rb,int gb,int bb,int ab)
{
	//VMProtectBeginMutation("cHexagonal::DrawHexagonWithGradientUpToDown");
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor4ub(ra,ga,ba,aa);
	glVertex2f(x,y+h-1);
	glVertex2f(x-9,y+h/2);
	glColor4ub(rb,gb,bb,ab);
	glVertex2f(x,y+1);
	//glRotatef(45,1.0f,1.0f,0.0);
	glVertex2f(x+w,y+1);
	glColor4ub(ra,ga,ba,aa);
	glVertex2f(x+w+9,y+h/2);
	glVertex2f(x+w,y+h-1);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	//VMProtectEnd();
}

POINT cHexagonal::DrawItemHexagon(int x,int y,int w,int h,bool background,int index,int numberofitems,int r,int g,int b,int a)
{
	unsigned int i;
	int xs,length,height;
	POINT pt;
	float fvalue;
	bool bIsBar;
	//VMProtectBeginMutation("cHexagonal::DrawItemHexagon");
	fvalue=0;
	bIsBar=false;
	for(i=0;i<VHexagonBarEntry.size();i++)
		if(VHexagonBarEntry[i].iIndex==index)
			{fvalue=VHexagonBarEntry[i].fValue,bIsBar=true;break;}
	if(bIsBar)
	{
		//DrawHexagonWithGradientLeftToRight(x,y,w,h,fvalue>0?255:0,0,0,fvalue>0?200:255,0,fvalue>=1?255:0,0,fvalue<1?255:200);
		DrawFillTriangle(x,y+1,x,y+h-1,x-9,y+h/2,fvalue>0?255:0,0,0,fvalue>0?200:255);//Triangulo Izq Interior
		DrawFillTriangle(x+w,y+1,x+w,y+h-1,x+w+9,y+h/2,0,fvalue>=1?100:0,fvalue>=1?255:0,fvalue<1?255:200);//Triangulo Der Interior
		DrawFillRectangleWithGradientRightToLeft(x,y+1,w,h-1,255,0,0,200,0,100,255,200);
		if(fvalue<1)
			FillRGBA(x+(int)((float)w*fvalue),y+1,w-(int)((float)w*fvalue),h-1,0,0,0,255);//BarraNegra
	}
	else
	{
		if(numberofitems>1)
		{
			DrawFillTriangle(x,y+1,x,y+h-1,x-9,y+h/2,r,g,b,a);//Triangulo Izq Interior
			DrawFillTriangle(x+w,y+1,x+w,y+h-1,x+w+9,y+h/2,r,g,b,a);//Triangulo Der Interior
		}
		if(background)
			FillRGBA(x,y+1,w,h-1,r,g,b,a);//Fondo
	}
	for(i=0;i<VStringEntrys.size();i++)
	{
		if(index==VStringEntrys[i].iIndexOfCapsule)
		{
			switch(VStringEntrys[i].iPosition)
			{
				case HEX_STRING_POS_LEFT:default:
					xs=x+5;
					break;
				case HEX_STRING_POS_RIGHT:
					gEngine.pfnDrawConsoleStringLen("459.45",&length,&height);
					xs=x+w-length-lengthcharenginefont;
					break;
				case HEX_STRING_POS_CENTER:
					gEngine.pfnDrawConsoleStringLen(VStringEntrys[i].szString,&length,&height);
					xs=w/2-length/2+x;
					break;
			}
			DrawConString(xs,y+3,VStringEntrys[i].r,VStringEntrys[i].g,VStringEntrys[i].b,VStringEntrys[i].szString);
		}
	}
	pt.x=iStyle?x+10:x-10,pt.y=y+h;
	//VMProtectEnd();
	return pt;
}

void cHexagonal::DrawTitleHexagon(int x,int y,int w,int hfont,int h,int selected,int numberofitems)
{
	int i,xb,yb,xs,length,height;

	DrawFillTriangleWithGradientUpToDown(x,y+1,x-9,y+hfont/2,x,y+hfont-1,0,0,0,255,255,000,000,255);//Triangulo Izq Interior
	DrawFillTriangleWithGradientUpToDown(x+w,y+1,x+w+9,y+hfont/2,x+w,y+hfont-1,0,0,0,255,255,000,000,255);//Triangulo Der Interior
	DrawFillRectangleWithGradientUpToDown(x,y+1,w,hfont-1,0,0,0,255,255,000,000,255);//Fondo

	//oglSubtractive = true;
	//gEngfuncs.pfnFillRGBA(x+5,cvar.guifont?y+6:y+(hfont/3+1),5,cvar.guifont?5:hfont/3,136,131,127,200); // Box Filling
	//oglSubtractive = false;
	//blackBorder(x+5,cvar.guifont?y+6:y+(hfont/3+1),5,cvar.guifont?5:hfont/3); // Black Border
	// Window Title
	gEngine.pfnDrawConsoleStringLen(szTitle,&length,&height);
	xs=w/2-length/2+x;
	DrawConString(xs,y+5,255,255,255,szTitle);
	//DibujarSeleccionado hacia abajo
	if(!iStyle)
	{
		DrawLine(x-8,y+hfont/2,x-20,y+hfont/2,255,000,000,255);
		xb=x-35;
		yb=y+3*hfont/2+fSpaceBetweenBlocksAndTitles;
		if(numberofitems>1)
			for(i=0;i!=selected;i++)
				xb-=10,yb+=hfont;
		else
			yb+=h/2;
		DrawLine(x-20,y+hfont/2,xb,yb,255,000,000,255);
		DrawLine(xb,yb,numberofitems==1?xb+24:xb+17,yb,255,000,000,255);
	}
	else
	{
		DrawLine(x+w+8,y+hfont/2,x+w+20,y+hfont/2,255,000,000,255);
		xb=x+w+35;
		yb=y+3*hfont/2+fSpaceBetweenBlocksAndTitles;
		if(numberofitems>1)
			for(i=0;i!=selected;i++)
				xb+=10,yb+=hfont;
		else
			yb+=h/2;
		DrawLine(x+w+20,y+hfont/2,xb,yb,255,000,000,255);
		DrawLine(xb,yb,numberofitems==1?xb-24:xb-17,yb,255,000,000,255);
	}
	//VMProtectEnd();
}



void cHexagonal::DrawEndHexagon(int x,int y,int w,int hfont,int h,int selected,int numberofitems)
{
	int i,xb,yb,xs,length,height;
	DrawFillTriangleWithGradientUpToDown(x,y+1,x-9,y+hfont/2,x,y+hfont-1,255,000,000,255,0,0,0,255);//Triangulo Izq Interior
	DrawFillTriangleWithGradientUpToDown(x+w,y+1,x+w+9,y+hfont/2,x+w,y+hfont-1,255,000,000,255,0,0,0,255);//Triangulo Der Interior
	DrawFillRectangleWithGradientUpToDown(x,y+1,w,hfont-1,255,000,000,255,0,0,0,255);//Fondo

	//oglSubtractive = true;
	//gEngfuncs.pfnFillRGBA(x+5,cvar.guifont?y+6:y+(hfont/3+1),5,cvar.guifont?5:hfont/3,136,131,127,200); // Box Filling
	//oglSubtractive = false;
	//blackBorder(x+5,cvar.guifont?y+6:y+(h/3+1),5,cvar.guifont?5:h/3); // Black Border
	if(szEndTitle)
	{
		// Window Title
		gEngine.pfnDrawConsoleStringLen(szEndTitle,&length,&height);
		xs=w/2-length/2+x;
		DrawConString(xs,y+3,255,255,255,szEndTitle);
	}
	//Dibujar seleccionado hacia arriba
	if(!iStyle)
	{
		DrawLine(x+w+8,y+hfont/2,x+w+20,y+hfont/2,255,000,000,255);
		xb=x+w+35;
		yb=y+hfont/2-fSpaceBetweenBlocksAndTitles;
		if(numberofitems>1)
			for(i=numberofitems;i!=selected;i--)
				xb+=10,yb-=hfont;
		else
			yb-=h/2;
		DrawLine(x+w+20,y+hfont/2,xb-10,yb,255,000,000,255);
		DrawLine(xb-10,yb,numberofitems==1?xb-26:xb-27,yb,255,000,000,255);
	}
	else
	{
		DrawLine(x-8,y+hfont/2,x-20,y+hfont/2,255,000,000,255);
		xb=x-35;
		yb=y+hfont/2-fSpaceBetweenBlocksAndTitles;
		if(numberofitems>1)
			for(i=numberofitems;i!=selected;i--)
				xb-=10,yb-=hfont;
		else
			yb-=h/2;
		DrawLine(x-20,y+hfont/2,xb+10,yb,255,000,000,255);
		DrawLine(xb+10,yb,numberofitems==1?xb+26:xb+27,yb,255,000,000,255);
	}
	//VMProtectEnd();
}

void cHexagonal::DrawWindow(int x,int y,int w,int h,bool background,int selected,int numberofitems)
{
	int i,hfont;
	POINT pt;
	//VMProtectBeginMutation("cHexagonal::DrawWindow");
	hfont=heightenginefont;
	pt.x=x;
	pt.y=(y-(heightenginefont+4));
	DrawTitleHexagon(pt.x,pt.y,w,hfont+4,h,selected,numberofitems);
	pt.x=iStyle?x+10:x-10;pt.y=y+fSpaceBetweenBlocksAndTitles;
	for(i=0;i<numberofitems;i++)
		pt=DrawItemHexagon(pt.x,pt.y,w,h?h:hfont+4,background,i,numberofitems,64,64,64,200);
	/*pt.x-=10,*/pt.y+=fSpaceBetweenBlocksAndTitles;
	DrawEndHexagon(pt.x,pt.y,w,hfont+4,h,selected,numberofitems);
	//VMProtectEnd();
}