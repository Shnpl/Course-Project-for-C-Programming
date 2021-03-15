#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__
typedef struct BFL_textbox_struct{
    int color_box;
    int color_text;
    int color_shadow;

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
	//int cursor_count;
    int is_in_the_box;
    int reDraw;
    int current_length;
    
}BFL_textbox;

void BFL_textbox_action(BFL_textbox* textboxPtr);
void BFL_textbox_draw(BFL_textbox* textboxPtr);

char get_ch();

#endif