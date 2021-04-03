
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

        CHN_print(labelPtr->position_left+10,
        labelPtr->position_top+10,
        labelPtr->display_text,
        32,
        32,
        labelPtr->color_text,
        labelPtr->word_length);

        labelPtr->reDraw = RESET;
    }
}