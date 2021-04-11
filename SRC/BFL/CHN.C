#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "INCLUDE/CHN.H"

void CHN_print(int x, int y, char *s, int size, int color)
{
	FILE *hzk_p = NULL;														 //定义汉字库文件指针
	unsigned char quma, weima;												 //定义汉字的区码和位码
	unsigned long offset;													 //定义汉字在字库中的偏移量
	unsigned char mask[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01}; //功能数组，用于显示汉字点阵
	int i, j, pos;
	char *charPtr = s;

	char tempChar = 0;
	char tempString[2] = {'\0'};

	switch (size) //不同的size对应不同的汉字库，实现了汉字的大小可根据需要改变
	{
	case 16:
	{
		char mat[32]; //16*16的汉字需32字节的数组来存储
		int y0 = y;
		//int x0=x;
		hzk_p = fopen("./LIB/HZK16", "rb"); //使用路径
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT); //左部对齐，顶部对齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
			outtextxy(10, 10, "Can't open hzk16 file!Press any key to quit...");
			getch();
			exit(1);
		}
		settextstyle(0, 0, 2);
		setcolor(color);
		while (*charPtr != '\0')
		{

			tempChar = *charPtr;
			if (tempChar > 0)
			{
				tempString[0] = tempChar;
				tempString[1] = '\0';
				outtextxy(x, y0 + 2, tempString);
				x += size + 1;
				charPtr++;
			}
			else
			{
				y = y0;
				quma = *charPtr - 0xa0;		   //求出区码
				weima = *(charPtr + 1) - 0xa0; //求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 32L;
				fseek(hzk_p, offset, SEEK_SET);
				fread(mat, 32, 1, hzk_p);

				for (i = 0; i < 16; i++)
				{
					pos = 2 * i;
					for (j = 0; j < 16; j++)
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL)
						{
							putpixel(x + j, y, color);
						}
					}
					y++;
				}
				x += size + 1; //给x 一偏移量
				charPtr += 2;  //一个汉字的内码需要2字节，所以加2
			}
		}
		break;
	}

	case 24:
	{
		char mat[72]; //24*24矩阵需要72字节来存储
		int y0 = y;
		// int x0=x;
		hzk_p = fopen("./LIB/Hzk24k", "rb");
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //左部对齐，顶部对齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 3); //黑体笔划输出，水平输出，24*24点阵
			outtextxy(10, 10, "Can't open hzk24 file!Press any key to quit...");
			getch();
			exit(1);
		}
		settextstyle(0, 0, 3);
		setcolor(color);
		while (*charPtr != '\0')
		{
			tempChar = *charPtr;
			if (tempChar > 0)
			{
				tempString[0] = tempChar;
				tempString[1] = '\0';
				outtextxy(x, y0 + 2, tempString);
				x += size + 1;
				charPtr++;
			}
			else
			{
				y = y0;
				quma = *charPtr - 0xa0;		   //求出区码
				weima = *(charPtr + 1) - 0xa0; //求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 72L;
				fseek(hzk_p, offset, SEEK_SET);
				fread(mat, 72, 1, hzk_p);
				for (i = 0; i < 24; i++)
				{
					pos = 3 * i;
					for (j = 0; j < 24; j++)
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL)
							putpixel(x + j, y, color);
					}
					y++;
				}
				x += size + 1;
				charPtr += 2;
			}
		}
		break;
	}

	case 32:
	{
		char mat[128]; //32*32的汉字需128字节的数组来存储
		int y0 = y;
		//int x0=x;
		hzk_p = fopen("./LIB/HZK32S", "rb");
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //左部对齐，顶部对齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 3); //黑体笔划输出，水平输出，24*24点阵
			outtextxy(10, 10, "Can't open hzk32 file!Press any key to quit...");
			getch();
			exit(1);
		}
		settextstyle(0, 0, 4);
		setcolor(color);
		while (*charPtr != '\0')
		{
			tempChar = *charPtr;
			if (tempChar > 0)
			{
				tempString[0] = tempChar;
				tempString[1] = '\0';
				outtextxy(x, y0 + 2, tempString);
				x += size + 1;
				charPtr++;
			}
			else
			{
				y = y0;
				quma = *charPtr - 0xa0;		   //求出区码
				weima = *(charPtr + 1) - 0xa0; //求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 128L;
				fseek(hzk_p, offset, SEEK_SET);
				fread(mat, 128, 1, hzk_p);

				for (i = 0; i < 32; i++)
				{
					pos = 4 * i;
					for (j = 0; j < 32; j++)
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL)
						{
							putpixel(x + j, y, color);
						}
					}
					y++;
				}
				x += size + 1;
				charPtr += 2;
			}
		}
		break;
	}

	case 48:
	{
		char mat[288]; //48*48的汉字需288字节的数组来存储
		int y0 = y;
		//int x0=x;
		hzk_p = fopen("./LIB/Hzk48k", "rb");
		if (hzk_p == NULL)
		{
			settextjustify(LEFT_TEXT, TOP_TEXT);	 //左部对齐，顶部对齐
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 3); //黑体笔划输出，水平输出，24*24点阵
			outtextxy(10, 10, "Can't open hzk48 file!Press any key to quit...");
			getch();
			exit(1);
		}
		settextstyle(0, 0, 6);
		setcolor(color);
		while (*charPtr != '\0')
		{
			tempChar = *charPtr;
			if (tempChar > 0)
			{
				tempString[0] = tempChar;
				tempString[1] = '\0';
				outtextxy(x, y0 + 2, tempString);
				x += size + 1;
				charPtr++;
			}
			else
			{
				y = y0;
				quma = *charPtr - 0xa0;							 //求出区码
				weima = *(charPtr + 1) - 0xa0;					 //求出位码
				offset = (94 * (quma - 1) + (weima - 1)) * 288L; //求出要显示的汉字在字库文件中的偏??
				fseek(hzk_p, offset, SEEK_SET);					 //重定位文件指针
				fread(mat, 288, 1, hzk_p);						 //读出该汉字的具体点阵数据,1为读入的项

				for (i = 0; i < 48; i++)
				{
					pos = 6 * i;
					for (j = 0; j < 48; j++)
					{
						if ((mask[j % 8] & mat[pos + j / 8]) != NULL)
						{
							putpixel(x + j, y, color);
						}
					}
					y++;
				}
				x += size + 1;
				charPtr += 2;
			}
		}
		break;
	}
	default:
		break;
	}
	fclose(hzk_p);
}
