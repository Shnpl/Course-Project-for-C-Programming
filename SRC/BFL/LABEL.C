
#include <conio.h>
#include <GRAPHICS.H>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include"INCLUDE/TEXTBOX.H"
#include"INCLUDE/MOUSE.H"
#include"INCLUDE/BUTTON.H"
#include"INCLUDE/GENERAL.H"
#include"INCLUDE/LABEL.H"
#include"INCLUDE/CHN.H"


void BFL_label_action(BFL_label* labelPtr)
{

}

void BFL_label_draw(BFL_label* labelPtr)
{
    if(labelPtr->reDraw == SET)
    {
        setfillstyle(SOLID_FILL,labelPtr->color_box);
        bar(labelPtr->position_left,labelPtr->position_top,labelPtr->position_right,labelPtr->position_bottom);
        if((labelPtr->display_type) == 0)
        {
            CHN_print(labelPtr->position_text_left,
            labelPtr->position_text_top,
            labelPtr->display_text,
            labelPtr->size,
            labelPtr->size,
            labelPtr->color_text,
            labelPtr->word_length);
        }
        else
        {
            settextstyle(0,0,labelPtr->en_size);
            setcolor(labelPtr->color_text);
            outtextxy(labelPtr->position_text_left,
            labelPtr->position_text_top,
            labelPtr->display_text);
        }

        labelPtr->reDraw = RESET;
    }
}