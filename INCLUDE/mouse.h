#ifndef _mouse_h_
#define _mouse_h_

void mouse(int,int);//è®¾è?¡é¼ æ ?
void BFL_mouse_init(void);//åˆå?‹åŒ–
void mread(int *,int *,int*);//æ”¹åæ ‡ä¸ç”?
void save_bk_mou(int x,int y);//å­˜é¼ æ ‡èƒŒæ™?
void clrmous(int x,int y);//æ¸…é™¤é¼ æ ‡
void BFL_mouse_draw(void);   //æ›´æ–°é¼ æ ‡
void BFL_clear_mouse(void);
void BFL_mouse_action(void);
extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;// 0 Ã»°´ 1 ×ó¼ü
extern int mouse_enable;
extern int mouse_redraw;
extern void *buffer;
extern union REGS regs;
#endif
