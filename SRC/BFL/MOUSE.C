#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include "INCLUDE/mouse.h"

/**************************
MOUSE.c
UPDATER: dengshuumin
FUNCTION: mouse action
ABSTRACT:
		A.mread
		B.newmouse
VERSION: 3.0
***************************/
int MouseX;
int MouseY;
int MouseS;
int press;
int mouse_redraw = 1;
int mouse_enable = 1;
void *buffer;
union REGS regs;

void BFL_mouse_init() //��ʼ��
{
	int retcode;
	int xmin, xmax, ymin, ymax, x_max = 625, y_max = 480;
	int size;

	xmin = 2;
	xmax = x_max - 1;
	ymin = 8;
	ymax = y_max - 2;
	regs.x.ax = 0;
	int86(51, &regs, &regs);
	retcode = regs.x.ax;
	if (retcode == 0)
	{
		printf("Mouse or Mouse Driver Obsent,Please Install!");
		delay(5000);
	}
	else
	{
		regs.x.ax = 7;
		regs.x.cx = xmin;
		regs.x.dx = xmax;
		int86(51, &regs, &regs);
		regs.x.ax = 8;
		regs.x.cx = ymin;
		regs.x.dx = ymax;
		int86(51, &regs, &regs);
	}
	MouseS = 0;
	MouseX = 320, MouseY = 240;
	save_bk_mou(320, 240);
}

/*****************************
FUNCTION: mouse
DESCRIPTION: ����ͬ��̬�����??
INPUT: x,y
RETURN: ��
******************************/
void mouse(int x, int y)
{
	switch (MouseS)
	{
	case 1: //�������??
	{
		setcolor(WHITE);
		setlinestyle(0, 0, 1);

		line(x - 1, y + 9, x - 1, y + 8);
		line(x, y + 7, x, y + 11);
		line(x + 1, y + 6, x + 1, y + 13);
		line(x + 2, y + 8, x + 2, y + 14);
		line(x + 3, y - 1, x + 3, y + 15);
		arc(x + 4, y - 1, 0, 180, 1);
		line(x + 4, y - 2, x + 4, y + 15);
		line(x + 5, y - 1, x + 5, y + 16);
		arc(x + 6, y + 3, 0, 180, 1);
		line(x + 6, y + 2, x + 6, y + 16);
		line(x + 7, y + 3, x + 7, y + 17);
		arc(x + 8, y + 5, 0, 180, 1);
		line(x + 8, y + 4, x + 8, y + 17);
		line(x + 9, y + 5, x + 9, y + 16);
		arc(x + 10, y + 7, 0, 180, 1);
		line(x + 10, y + 6, x + 10, y + 16);
		line(x + 11, y + 7, x + 11, y + 13);

		setcolor(DARKGRAY);
		line(x - 1, y + 9, x - 1, y + 8);
		line(x - 1, y + 8, x + 1, y + 6);
		line(x + 1, y + 6, x + 3, y + 10);
		line(x + 3, y + 10, x + 3, y - 1);
		arc(x + 4, y - 1, 0, 180, 1);
		line(x + 5, y - 1, x + 5, y + 5);
		arc(x + 6, y + 3, 0, 180, 1);
		line(x + 7, y + 3, x + 7, y + 7);
		arc(x + 8, y + 5, 0, 180, 1);
		line(x + 9, y + 5, x + 9, y + 9);
		arc(x + 10, y + 7, 0, 180, 1);
		line(x + 11, y + 7, x + 11, y + 13);
		arc(x + 7, y + 13, -90, 0, 4);
		line(x + 7, y + 17, x + 3, y + 15);
		line(x + 3, y + 15, x + 1, y + 13);
		line(x + 1, y + 13, x - 1, y + 9);
	}
	break;
	case 2: //���??
	{
		setcolor(DARKGRAY);
		setlinestyle(0, 0, 1);
		line(x + 1, y - 1, x + 9, y - 1);
		line(x + 1, y + 15, x + 9, y + 15);
		line(x + 5, y - 1, x + 5, y + 15);
	}
	break;
	case 3: //ʮ��
	{
		setcolor(WHITE);
		setlinestyle(0, 0, 1);
		line(x - 1, y + 7, x + 11, y + 7);
		line(x + 5, y - 1, x + 5, y + 15);
	}
	break;
	default: //Ĭ�����??
	{
		setlinestyle(0, 0, 1);
		setcolor(WHITE);
		line(x, y, x, y + 13);
		line(x + 1, y + 1, x + 1, y + 12);
		line(x + 2, y + 2, x + 2, y + 11);
		line(x + 3, y + 3, x + 3, y + 10);
		line(x + 4, y + 4, x + 4, y + 12);
		line(x + 5, y + 5, x + 5, y + 9);
		line(x + 5, y + 11, x + 5, y + 14);
		line(x + 6, y + 6, x + 6, y + 9);
		line(x + 6, y + 13, x + 6, y + 15);
		line(x + 7, y + 7, x + 7, y + 9);
		line(x + 8, y + 8, x + 8, y + 9);
		line(x + 9, y + 9, x + 9, y + 9);
		setcolor(DARKGRAY);
		line(x - 1, y - 1, x - 1, y + 14);
		line(x - 1, y + 14, x + 3, y + 11);
		line(x + 3, y + 11, x + 3, y + 12);
		line(x + 3, y + 12, x + 4, y + 13);
		line(x + 4, y + 13, x + 4, y + 14);
		line(x + 4, y + 14, x + 7, y + 17);
		line(x + 7, y + 17, x + 7, y + 13);
		line(x + 7, y + 13, x + 6, y + 12);
		line(x + 6, y + 12, x + 6, y + 11);
		line(x + 6, y + 11, x + 5, y + 10);
		line(x + 5, y + 10, x + 11, y + 10);
		line(x + 11, y + 10, x - 1, y - 2);
	}
	break;
	}
}
/***************************************
FUNCTION: mread
DESCRIPTION: ��ȡ�µļĴ�����Ϣ
INPUT: nx,ny,nbuttons
RETURN: ��
****************************************/
void mread(int *nx, int *ny, int *nbuttons)
{
	regs.x.ax = 3;
	int86(51, &regs, &regs);
	*nx = regs.x.cx;
	*ny = regs.x.dx;
	*nbuttons = regs.x.bx;
}

void BFL_mouse_action()
{
	int mouse_x_now;
	int mouse_y_now;
	int mouse_press_now;
	if (mouse_enable == 1)
	{
		mread(&mouse_x_now, &mouse_y_now, &mouse_press_now);
		if (mouse_x_now != MouseX || mouse_y_now != MouseY || mouse_press_now != press)
		{
			mouse_redraw = 1;
			if (buffer != NULL)
			{
				clrmous(MouseX, MouseY);
			}
			MouseX = mouse_x_now;
			MouseY = mouse_y_now;
			press = mouse_press_now;
		}
		else
		{
			mouse_redraw = 0;
		}
	}
}

void BFL_mouse_draw()
{
	if (mouse_enable == 1)
	{
		if (mouse_redraw == 1)
		{
			save_bk_mou(MouseX, MouseY);
			setwritemode(COPY_PUT);
			mouse(MouseX, MouseY);
		}
	}
}
void save_bk_mou(int nx, int ny) //����걳��??
{
	int size;

	size = imagesize(nx - 2, ny - 2, nx + 11, ny + 17);
	buffer = malloc(size);
	if (buffer != NULL)
		getimage(nx - 2, ny - 2, nx + 11, ny + 17, buffer);
	else
		printf("Error");
}

void clrmous(int nx, int ny) //������
{
	putimage(nx - 2, ny - 2, buffer, COPY_PUT);
	free(buffer);
	buffer = NULL; //避免野指�?
}
