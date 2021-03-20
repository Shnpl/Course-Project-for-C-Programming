#ifndef _mouse_h_
#define _mouse_h_
/*
��� ͼ�λ���
���룺int x �� int y ����x,yֵ
�������
*/
void mouse(int,int);

/*
��� ��ʼ������
���룺��
�������
*/
void BFL_mouse_init(void);

/*
��� ��ȡĿǰ���λ��
���룺��
�����int* nx int* ny int* nbuttons ����x,yλ�������ĵ��״̬
*/
void mread(int *,int *,int*);

/*
��� ������걳��
���룺��
�����int x , int y ���汳����x��yֵ
*/
void save_bk_mou(int x,int y);

/*
��� �����걳��
���룺int x,int y ������x,y ֵ
�������
*/
void clrmous(int x,int y);

/*
��� ����ػ溯��
���룺��
�������
*/
void BFL_mouse_draw(void);

/*
��� ����������
���룺��
�������
*/
void BFL_clear_mouse(void);

/*
��� �����Ӧ����
���룺��
�������
*/
void BFL_mouse_action(void);

/*���xֵ*/
extern int MouseX;

/*���yֵ*/
extern int MouseY;

/*�����״*/
extern int MouseS;

/*�����״̬*/
extern int press;// 0 û�� 1 ���

/*�������Ƿ����� ��־��*/
extern int mouse_enable;

/*����Ƿ��ػ� ��־��*/
extern int mouse_redraw;
/*�������� ָ��*/
extern void *buffer;
/*��� �жϼĴ���*/
extern union REGS regs;
#endif
