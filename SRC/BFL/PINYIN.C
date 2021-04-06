#include <conio.h>
#include <GRAPHICS.H>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include "INCLUDE/pinyin.H"
#include "INCLUDE/MOUSE.H"
#include "INCLUDE/BUTTON.H"
#include "INCLUDE/GENERAL.H"
#include "INCLUDE/PINYIN.H"
//临时注释：输入法框放在左下角，左边位置0，上360，右边300，下480
char get_ch_pinyin(void);
void BFL_pinyin_action(BFL_pinyin *pinyinPtr)
{
    char get_char;
    if (MouseX > pinyinPtr->position_textbox_left &&
	MouseX < pinyinPtr->position_textbox_right &&
	MouseY > pinyinPtr->position_textbox_top &&
	MouseY < pinyinPtr->position_textbox_bottom &&
	press == 1)
    {
	pinyinPtr->is_in_the_box = 1;
    }
    if (pinyinPtr->is_in_the_box == 1)
    {
	mouse_enable = 0;
	get_char = get_ch_pinyin();
	pinyinPtr->reDraw = RESET;
	// pinyinPtr->cursor_count++;
	/*
	if(pinyinPtr->cursor_count == 60000)
	{
	    pinyinPtr->cursor_count = 0;
	}
	if(pinyinPtr->cursor_count == 0||pinyinPtr->cursor_count == 30000)
	{
	    pinyinPtr->reDraw = 1;
	}
	*/
	if (get_char != -1)
	{
	    if (get_char == 0x0D) //CR
	    {
		pinyinPtr->is_in_the_box = 0;
		mouse_enable = 1;
	    }
        
	    else
	    {
            *(pinyinPtr->input_text_ptr) = get_char;
            *((pinyinPtr->input_text_ptr)+1) = '\0';
            (pinyinPtr->input_text_ptr)++;
            pinyinPtr->reDraw = SET;
	    }

	    /*
	    else if(get_char == 0x08)//Backspace
	    {
		if(pinyinPtr->current_length >= 0)
		{
		    pinyinPtr->display_text[pinyinPtr->current_length] = '\0';
		    pinyinPtr->current_length--;
		    pinyinPtr->reDraw = SET;
		}
		else
		{
		    ;
		}
	    }
	    else
	    {
		if(pinyinPtr->current_length > pinyinPtr->word_length - 2)//from -1
		{
		    ;
		}
		else
		{
		    (pinyinPtr->current_length)++;

		    pinyinPtr->true_text[pinyinPtr->current_length] = get_char;
		    pinyinPtr->true_text[pinyinPtr->current_length+1] = '\0';
		    if(pinyinPtr->is_secret == RESET)
		    {
			pinyinPtr->display_text[pinyinPtr->current_length] = get_char;
			pinyinPtr->display_text[pinyinPtr->current_length+1] = '\0';
		    }
		    else
		    {
			pinyinPtr->display_text[pinyinPtr->current_length] = '*';
			pinyinPtr->display_text[pinyinPtr->current_length+1] = '\0';
		    }
		    pinyinPtr->reDraw = SET;
		}
	    }
	    */
	}
    }
}
void BFL_pinyin_draw(BFL_pinyin *pinyinPtr)
{
    if (pinyinPtr->reDraw == SET)
    {
        settextstyle(SANS_SERIF_FONT, 0, 4);
        settextjustify(5, 18);
        /*
        if (pinyinPtr->is_shadow_enable == SET)
        {
            setfillstyle(SOLID_FILL, pinyinPtr->color_shadow);
            bar(pinyinPtr->position_shadow_left, pinyinPtr->position_shadow_top, pinyinPtr->position_shadow_right, pinyinPtr->position_shadow_bottom);
        }
        */
        setfillstyle(SOLID_FILL, pinyinPtr->color_textbox);
        bar(pinyinPtr->position_textbox_left,
            pinyinPtr->position_textbox_top,
            pinyinPtr->position_textbox_right,
            pinyinPtr->position_textbox_bottom);
        //settextstyle(3,HORIZ_DIR,5);

        setfillstyle(SOLID_FILL,pinyinPtr->color_select_box);
        bar(0,360,300,480);
        

        setcolor(pinyinPtr->color_text);
        outtextxy(0+5, 360, pinyinPtr->input_text);
        //outtextxy(0,0,pinyinPtr->true_text);

        /*
        if(pinyinPtr->cursor_count < 30000)
        {
            setlinestyle(0,0,1);
            line(
            pinyinPtr->position_left+(pinyinPtr->current_length+1)*22,
            pinyinPtr->position_top,
            pinyinPtr->position_left+(pinyinPtr->current_length+1)*22,
            pinyinPtr->position_bottom);
        }
        */
    }
}
char get_ch_pinyin()
{
    int get_char = -1;
    char return_char = -1;
    if (bioskey(1))
    {
        get_char = bioskey(0);
        switch (get_char)
        {
        case 0x0E08:
            return_char = 0x08; //backspace
            break;
        case 0x1C0D:
            return_char = 0x0D; //CR
            break;
        case 0x0231:
            return_char = '1';
            break;
        case 0x0332:
            return_char = '2';
            break;
        case 0x0433:
            return_char = '3';
            break;
        case 0x0534:
            return_char = '4';
            break;
        case 0x0635:
            return_char = '5';
            break;
        case 0x0736:
            return_char = '6';
            break;
        case 0x0837:
            return_char = '7';
            break;
        case 0x0938:
            return_char = '8';
            break;
        case 0x0a39:
            return_char = '9';
            break;
        case 0x0b30:
            return_char = '0';
            break;
        case 0x1071:
            return_char = 'q';
            break;
        case 0x1177:
            return_char = 'w';
            break;
        case 0x1265:
            return_char = 'e';
            break;
        case 0x1372:
            return_char = 'r';
            break;
        case 0x1474:
            return_char = 't';
            break;
        case 0x1579:
            return_char = 'y';
            break;
        case 0x1675:
            return_char = 'u';
            break;
        case 0x1769:
            return_char = 'i';
            break;
        case 0x186f:
            return_char = 'o';
            break;
        case 0x1970:
            return_char = 'p';
            break;
        case 0x1e61:
            return_char = 'a';
            break;
        case 0x1f73:
            return_char = 's';
            break;
        case 0x2064:
            return_char = 'd';
            break;
        case 0x2166:
            return_char = 'f';
            break;
        case 0x2267:
            return_char = 'g';
            break;
        case 0x2368:
            return_char = 'h';
            break;
        case 0x246a:
            return_char = 'j';
            break;
        case 0x256b:
            return_char = 'k';
            break;
        case 0x266c:
            return_char = 'l';
            break;
        case 0x2c7a:
            return_char = 'z';
            break;
        case 0x2d78:
            return_char = 'x';
            break;
        case 0x2e63:
            return_char = 'c';
            break;
        case 0x2f76:
            return_char = 'v';
            break;
        case 0x3062:
            return_char = 'b';
            break;
        case 0x316e:
            return_char = 'n';
            break;
        case 0x326d:
            return_char = 'm';
            break;
        case 0x342e:
            return_char = '.';
            break;
        ///
        case 0x4f31:
            return_char = '1';
            break;
        case 0x5032:
            return_char = '2';
            break;
        case 0x5133:
            return_char = '3';
            break;
        case 0x4b34:
            return_char = '4';
            break;
        case 0x4c35:
            return_char = '5';
            break;
        case 0x4d36:
            return_char = '6';
            break;
        case 0x4737:
            return_char = '7';
            break;
        case 0x4838:
            return_char = '8';
            break;
        case 0x4939:
            return_char = '9';
            break;
        case 0x5230:
            return_char = '0';
            break;
        case 0x0F09:
            return_char = 0x09;
        }
    }
    return return_char;
}
//后面的是范例
/*
void init(BFL_pinyin* pinyinPtr)
{
    pinyinPtr->color_textbox = LIGHTGRAY;
    pinyinPtr->color_select_box = LIGHTGRAY;
    pinyinPtr->color_text = BROWN;
    pinyinPtr->reDraw = SET;

    pinyinPtr->position_textbox_left = 250;//可修改
    pinyinPtr->position_textbox_top = 190;//可修改
    pinyinPtr->position_textbox_right = 460;//可修改
    pinyinPtr->position_textbox_bottom = pinyinPtr->position_textbox_top + 40;

    pinyinPtr->CHN_length_counter = 0;
    memset((pinyinPtr->CHN_text),0,50);
    CHN_text_ptr = (pinyinPtr->CHN_text);
    
    pinyinPtr->input_length_counter = 0;
    memset((pinyinPtr->input_text),0,50);
    pinyinPtr->input_text_ptr = (pinyinPtr->input_text)
    
    BFL_pinyin_draw(pinyinPtr);
    
    pinyinPtr->reDraw = RESET;
}
*/