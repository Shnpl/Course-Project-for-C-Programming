#ifndef _mouse_h_
#define _mouse_h_

void mouse(int,int);//设�?�鼠�?
void BFL_mouse_init(void);//初�?�化
void mread(int *,int *,int*);//改坐标不�?
void save_bk_mou(int x,int y);//存鼠标背�?
void clrmous(int x,int y);//清除鼠标
void BFL_mouse_draw(void);   //更新鼠标
void BFL_clear_mouse(void);
void BFL_mouse_action(void);
extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;// 0 û�� 1 ���
extern int mouse_enable;
extern int mouse_redraw;
extern void *buffer;
extern union REGS regs;
#endif
