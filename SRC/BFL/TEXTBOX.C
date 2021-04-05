#include <conio.h>
#include <GRAPHICS.H>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include<bios.h>

#include"INCLUDE/TEXTBOX.H"
#include"INCLUDE/MOUSE.H"
#include"INCLUDE/BUTTON.H"
#include"INCLUDE/GENERAL.H"
char get_ch(void);

void BFL_textbox_action(BFL_textbox* textboxPtr)
{
    char get_char;
    if (MouseX > textboxPtr->position_left &&
        MouseX < textboxPtr->position_right &&
        MouseY > textboxPtr->position_top &&
	    MouseY < textboxPtr->position_bottom &&
        press == 1
        )
    {
        textboxPtr->is_in_the_box = 1;
    }
    if (textboxPtr->is_in_the_box == 1)
    {
        mouse_enable = 0;
        get_char=get_ch();
        textboxPtr->reDraw = RESET;
	// textboxP/tr->cursor_count++;
	/*
        if(textboxPtr->cursor_count == 60000)
        {
            textboxPtr->cursor_count = 0;
        }
        if(textboxPtr->cursor_count == 0||textboxPtr->cursor_count == 30000)
        {
            textboxPtr->reDraw = 1;
        }
        */
        if(get_char != -1)
        {
            if(get_char == 0x0D)//CR
            {
                textboxPtr->is_in_the_box = 0;
                mouse_enable = 1;
            }
            else if(get_char == 0x08)//Backspace
            {
                if(textboxPtr->current_length >= 0)
                {
                    textboxPtr->display_text[textboxPtr->current_length] = '\0';
                    textboxPtr->true_text[textboxPtr->current_length] = '\0';
                    textboxPtr->current_length--;
                    textboxPtr->reDraw = SET;
                }
                else
                {
                    ;
                }  
            }
            else
            {
                if(textboxPtr->current_length > textboxPtr->word_length - 2)//from -1
                {
                    ;
                }
                else
                {
                    (textboxPtr->current_length)++;
                    
                    textboxPtr->true_text[textboxPtr->current_length] = get_char;
                    textboxPtr->true_text[textboxPtr->current_length+1] = '\0';
                    if(textboxPtr->is_secret == RESET)
                    {
                        textboxPtr->display_text[textboxPtr->current_length] = get_char;
                        textboxPtr->display_text[textboxPtr->current_length+1] = '\0';
                    }
                    else
                    {
                        textboxPtr->display_text[textboxPtr->current_length] = '*';
                        textboxPtr->display_text[textboxPtr->current_length+1] = '\0';
                    }
                    textboxPtr->reDraw = SET;
                }
            }
        }
    }
}
void BFL_textbox_draw(BFL_textbox* textboxPtr)
{
    if(textboxPtr->reDraw == SET)
    {
        settextstyle(SANS_SERIF_FONT,0,textboxPtr->size);
        settextjustify(5,18);

        if(textboxPtr->is_shadow_enable == SET)
        {
            setfillstyle(SOLID_FILL,textboxPtr->color_shadow);
            bar(textboxPtr->position_shadow_left,textboxPtr->position_shadow_top,textboxPtr->position_shadow_right,textboxPtr->position_shadow_bottom);
        }
        setfillstyle(SOLID_FILL,textboxPtr->color_box);
        bar(textboxPtr->position_left,
            textboxPtr->position_top,
            textboxPtr->position_right,
            textboxPtr->position_bottom);
        //settextstyle(3,HORIZ_DIR,5);
        setcolor(textboxPtr->color_text);
        outtextxy(textboxPtr->position_left+5,textboxPtr->position_top,textboxPtr->display_text);
        //outtextxy(0,0,textboxPtr->true_text);

        /*
        if(textboxPtr->cursor_count < 30000)
        {
            setlinestyle(0,0,1);
            line(
                textboxPtr->position_left+(textboxPtr->current_length+1)*22,
            textboxPtr->position_top,
	        textboxPtr->position_left+(textboxPtr->current_length+1)*22,
	        textboxPtr->position_bottom);
        }
        */
    }
}
char get_ch()
{
    int get_char = -1;
    char return_char = -1;
    if (bioskey(1))
    {
        get_char = bioskey(0);
        switch (get_char)
        {
        case 0x0E08:
            return_char = 0x08;//backspace
            break;
        case 0x1C0D:
            return_char = 0x0D;//CR
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

            
        case 0x1E41:
            return_char = 'A';
            break;
        case 0x3042:
            return_char = 'B';
            break;
        case 0x2E43:
            return_char = 'C';
            break;
        case 0x2044:
            return_char = 'D';
            break;
        case 0x1245:
            return_char = 'E';
            break;
        case 0x2146:
            return_char = 'F';
            break;
        case 0x2247:
            return_char = 'G';
            break;
        case 0x2348:
            return_char = 'H';
            break;
        case 0x1749:
            return_char = 'I';
            break;
        case 0x244A:
            return_char = 'J';
            break;
        case 0x254B:
            return_char = 'K';
            break;
        case 0x264C:
            return_char = 'L';
            break;
        case 0x324D:
            return_char = 'M';
            break;
        case 0x314E:
            return_char = 'N';
            break;
        case 0x184F:
            return_char = 'O';
            break;
        case 0x1950:
            return_char = 'P';
            break;
        case 0x1051:
            return_char = 'Q';
            break;
        case 0x1352:
            return_char = 'R';
            break;
        case 0x1F53:
            return_char = 'S';
            break;
        case 0x1454:
            return_char = 'T';
            break;
        case 0x1655:
            return_char = 'U';
            break;
        case 0x2F56:
            return_char = 'V';
            break;
        case 0x1157:
            return_char = 'W';
            break;
        case 0x2D58:
            return_char = 'X';
            break;
        case 0x1559:
            return_char = 'Y';
            break;
        case 0x2C5A:
            return_char ='Z';
            break;

        }
    }
    return return_char;
}
