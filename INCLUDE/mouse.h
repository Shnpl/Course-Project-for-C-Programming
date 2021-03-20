#ifndef _mouse_h_
#define _mouse_h_
/*
鼠标 图形绘制
输入：int x ， int y 鼠标的x,y值
输出：无
*/
void mouse(int,int);

/*
鼠标 初始化函数
输入：无
输出：无
*/
void BFL_mouse_init(void);

/*
鼠标 读取目前鼠标位置
输入：无
输出：int* nx int* ny int* nbuttons 鼠标的x,y位置与鼠标的点击状态
*/
void mread(int *,int *,int*);

/*
鼠标 保存鼠标背景
输入：无
输出：int x , int y 保存背景的x，y值
*/
void save_bk_mou(int x,int y);

/*
鼠标 清除鼠标背景
输入：int x,int y 背景的x,y 值
输出：无
*/
void clrmous(int x,int y);

/*
鼠标 鼠标重绘函数
输入：无
输出：无
*/
void BFL_mouse_draw(void);

/*
鼠标 鼠标清除函数
输入：无
输出：无
*/
void BFL_clear_mouse(void);

/*
鼠标 鼠标响应函数
输入：无
输出：无
*/
void BFL_mouse_action(void);

/*鼠标x值*/
extern int MouseX;

/*鼠标y值*/
extern int MouseY;

/*鼠标形状*/
extern int MouseS;

/*鼠标点击状态*/
extern int press;// 0 没按 1 左键

/*鼠标绘制是否启用 标志符*/
extern int mouse_enable;

/*鼠标是否重绘 标志符*/
extern int mouse_redraw;
/*背景保存 指针*/
extern void *buffer;
/*鼠标 中断寄存器*/
extern union REGS regs;
#endif
