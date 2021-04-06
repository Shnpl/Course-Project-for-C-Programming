#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__
/*
textbox 组件对应的结构体 存放了textbox组件的组件颜色，文字颜色，阴影颜色
及其四周的位置，阴影的位置，阴影是否开启，
显示的文字，文字长度，文字距离，是否为保密状态标志符，
是否在组件中标志符，
现在输入长度标志符
和其当前对应的是否重绘状态。

页面内调用的相应的
BFL_label_draw()函数根据此属性决定是否需要重绘该组件
*/
typedef struct BFL_textbox_struct{
    int color_box;
    int color_text;
    int color_shadow;
    int size;

    //int color_cursor;
    

    int position_left;
    int position_top;
    int position_right;
    int position_bottom;
    
    int is_shadow_enable;
    int position_shadow_left;
    int position_shadow_top;
    int position_shadow_right;
    int position_shadow_bottom;
    
    char display_text[51];
    char true_text[51];
    int word_length;
    int letter_distance;
    int is_secret ;
    int mode; //0:大小写均可 1:全部输出为小写 2：全部输出为大写
	//int cursor_count;
    int is_in_the_box;
    int reDraw;
    int current_length;
    
}BFL_textbox;


/*textbox响应函数 响应某textbox的各个操作，并存储在相应的位置
输入参数:textboxPtr 为BFL_textbox结构体指针,包含某textbox的各项属性
返回值:N/A
*/
void BFL_textbox_action(BFL_textbox* textboxPtr);

/*textbox重绘函数 根据textbox结构体的内容，对某textbox进行绘制 
输入参数:textboxPtr 为BFL_textbox结构体指针,包含某textbox的各项属性
返回值:N/A
*/
void BFL_textbox_draw(BFL_textbox* textboxPtr);
/*
键盘 获取按键函数
输入参数：无
返回值：按键字符
*/
char get_ch();

#endif