#ifndef __LABEL_H__
#define __LABEL_H__
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
void BFL_label_action(BFL_label* labelPtr);
void BFL_label_draw(BFL_label* labelPtr);
#endif