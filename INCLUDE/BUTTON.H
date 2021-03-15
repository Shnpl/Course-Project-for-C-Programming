#ifndef __BUTTON_H__
#define __BUTTON_H__
typedef struct BFL_button_struct
{

	int color_rest;
	int color_hover;
    int color_text;
    int color_shadow;
	//int color_press;
    
    int reDraw_status ;
	
    int position_left;
    int position_top;
    int position_right;
    int position_bottom;

    int position_text_left;
    int position_text_top;
    int text_size;

    int is_shadow_enable;
    int position_shadow_left;
    int position_shadow_top;
    int position_shadow_right;
    int position_shadow_bottom;

    char display_text[51];
    int text_length;
    
    int status;//左键单击 PRESS (1) 右键单击2,未点击HOVER (0)
} BFL_button;
/*按钮重绘函数
输入参数:buttonPtr 为BFL_button结构体指针,包含某按钮的各项属性
返回值:N/A
*/
void BFL_button_draw(BFL_button* buttonPtr);//按钮重绘函数

/*按钮响应函数
输入参数:buttonPtr 为BFL_button结构体指针,包含某按钮的各项属性
返回值:N/A
*/
void BFL_button_action(BFL_button* buttonPtr);//按钮响应函数
#endif