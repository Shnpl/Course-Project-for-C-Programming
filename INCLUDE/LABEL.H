#ifndef __LABEL_H__
#define __LABEL_H__
/*
label 组件对应的结构体 存放了LABEL组件的组件颜色，文字颜色，四周的位置
显示的文字，文字长度，和其当前对应的是否重绘状态。页面内调用的相应的
BFL_label_draw()函数根据此属性决定是否需要重绘该组件
*/
typedef struct BFL_label_struct{
    
    int color_box;
    int color_text;

    int position_left;
    int position_top;
    int position_right;
    int position_bottom;

    char display_text[51];
    int word_length;
    //int letter_distance;

    int reDraw;

}BFL_label;

/*LABEL响应函数 响应某LABEL的各个操作，并存储在相应的位置
输入参数:labelPtr 为BFL_label结构体指针,包含某label的各项属性
返回值:N/A
*/
void BFL_label_action(BFL_label* labelPtr);

/*LABEL重绘函数 根据label结构体的内容，对label进行绘制 
输入参数:labelPtr 为BFL_label结构体指针,包含某label的各项属性
返回值:N/A
*/
void BFL_label_draw(BFL_label* labelPtr);
#endif