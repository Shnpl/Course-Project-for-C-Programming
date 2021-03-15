#ifndef __CHN_H__
#define __CHN_H__
/* 
中文输出函数 
输入参数:,x为左侧坐标，y为上侧坐标,s为指向字符串的指针 flag 为字符大小
part 为字符间隔大小(像素) ,color为字符颜色,length为字符(中文)个数S
返回值:N/A
*/
void CHN_print(int x, int y,char *s,int flag,int part,int color, int length); 
#endif

