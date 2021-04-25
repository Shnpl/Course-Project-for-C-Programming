#ifndef __PINYIN_H__
#define __PINYIN_H__

/*
拼音文本框 组件对应的结构体 存放了拼音文本框 
和其当前对应的是否重绘状态。页面内调用的相应的
BFL_pinyin_draw()函数根据此属性决定是否需要重绘该组件
*/
struct word_to_choose;
typedef struct word_to_choose* Word_List;
typedef struct word_to_choose* Word_Position;

struct word_to_choose
{
    char word[4];
    Word_Position prev;
    Word_Position next;
};


typedef struct BFL_pinyin_struct{
    
    int color_textbox;
    int color_select_box;
    int color_text;

    int position_textbox_left;
    int position_textbox_top;
    int position_textbox_right;
    int position_textbox_bottom;

    int position_pinyin_left;
    int position_pinyin_top;
    int position_pinyin_right;
    int position_pinyin_bottom;

    char CHN_text[50];
    char* CHN_text_ptr;
    int CHN_length_counter ;//要初始化为0

    char input_text[50];
    char* input_text_ptr;
    int input_length_counter;//要初始化为0

    int is_in_the_box;
    int reDraw;
    Word_List word_list_head;
    Word_Position word_list_write_ptr;
    Word_Position word_list_display_ptr;
    int status_change;
    int length;

    void* buffer;
    int buffer_size;
}BFL_pinyin;


void BFL_pinyin_action(BFL_pinyin* pinyinPtr);

void BFL_pinyin_draw(BFL_pinyin* pinyinPtr);
#endif