#include<CONIO.H>
#include<GRAPHICS.H>
#include<dos.h>
#include<STDIO.H>
#include<STDLIB.H>
#include<STRING.H>
#include"INCLUDE/pinyin.H"
#include"INCLUDE/MOUSE.H"
#include"INCLUDE/BUTTON.H"
#include"INCLUDE/GENERAL.H"
#include"INCLUDE/PINYIN.H"
#include"INCLUDE/CHN.H"
//临时注释：输入法框放在左下角，左边位置0，上360，右边300，下480
char get_ch_pinyin(void);
struct PINYIN
{
    char word[4];
    char pinyin[8];
};

void BFL_pinyin_action(BFL_pinyin *pinyinPtr)
{
    struct PINYIN read_pinyin;
    Word_Position word_output_ptr = pinyinPtr->word_list_display_ptr;
    int x_0 = 0;
    char get_char;
    int i = 0;
    int j = 0;
    FILE* pinyin_file = NULL;
    if (MouseX > pinyinPtr->position_textbox_left &&
	MouseX < pinyinPtr->position_textbox_right &&
	MouseY > pinyinPtr->position_textbox_top &&
	MouseY < pinyinPtr->position_textbox_bottom &&
	press == 1)
    {
	    pinyinPtr->is_in_the_box = SET;
        pinyinPtr->status_change = IN;
        delay(150);

    }
    if (pinyinPtr->is_in_the_box == 1)
    {
        mouse_enable = 0;
        get_char = get_ch_pinyin();
        
        if (get_char != -1)
        {


            if (get_char == 0x0D) //CR
            {
                pinyinPtr->is_in_the_box = RESET;
                pinyinPtr->status_change = OUT;
                mouse_enable = 1;

                while(pinyinPtr->word_list_head->next != NULL)
                {
                    pinyinPtr->word_list_write_ptr = pinyinPtr->word_list_head->next;
                    pinyinPtr->word_list_head->next = pinyinPtr->word_list_write_ptr->next;
                    free(pinyinPtr->word_list_write_ptr);
                }
                pinyinPtr->word_list_write_ptr = pinyinPtr->word_list_head;
                pinyinPtr->word_list_display_ptr =pinyinPtr->word_list_head;

                memset(pinyinPtr->input_text_ptr,0,50);
                pinyinPtr->input_length_counter = 0;
                pinyinPtr->input_text_ptr = pinyinPtr->input_text;

                delay(150);
            }
            else if (get_char == 1)
            {   //因为头的存在 所以前和后并不是完全对应的
                if(
                pinyinPtr->word_list_display_ptr->prev->prev->prev->prev->prev != NULL
                &&pinyinPtr->word_list_display_ptr->prev->prev->prev->prev!= NULL
                &&pinyinPtr->word_list_display_ptr->prev->prev->prev!= NULL
                &&pinyinPtr->word_list_display_ptr->prev->prev!= NULL
                &&pinyinPtr->word_list_display_ptr->prev!= NULL
                &&pinyinPtr->word_list_display_ptr!= NULL
                 )
                {
                    pinyinPtr->word_list_display_ptr =pinyinPtr->word_list_display_ptr->prev->prev->prev->prev->prev;
                }
            }
            else if (get_char == 2)
            {
		        if(pinyinPtr->word_list_display_ptr->next->next->next->next->next->next != NULL
                &&pinyinPtr->word_list_display_ptr->next->next->next->next->next != NULL
                &&pinyinPtr->word_list_display_ptr->next->next->next->next!= NULL
                &&pinyinPtr->word_list_display_ptr->next->next->next!= NULL
                &&pinyinPtr->word_list_display_ptr->next->next!= NULL
                &&pinyinPtr->word_list_display_ptr->next!= NULL
                &&pinyinPtr->word_list_display_ptr!= NULL)
                {
                    pinyinPtr->word_list_display_ptr =pinyinPtr->word_list_display_ptr->next->next->next->next->next;
                }
            }
            else if(get_char == '1' || get_char == '2' || get_char == '3' || get_char == '4'||
                    get_char == '5' || get_char == '6' || get_char == '7' || get_char == '8'||
                    get_char == '9')
            {

                j = get_char - '0';
                i = 0;
                word_output_ptr = pinyinPtr->word_list_display_ptr;
                while (i < j && word_output_ptr != NULL)
                {
                    word_output_ptr = word_output_ptr->next;
                    i++;
                }
                if(word_output_ptr != NULL && pinyinPtr->CHN_length_counter<10)
                {
                    strcat(pinyinPtr->CHN_text,word_output_ptr->word); 
                    (pinyinPtr->CHN_text_ptr)+= 2;
                    pinyinPtr->CHN_length_counter++;
                }

                while(pinyinPtr->word_list_head->next != NULL)
                {
                    pinyinPtr->word_list_write_ptr = pinyinPtr->word_list_head->next;
                    
                    pinyinPtr->word_list_head->next = pinyinPtr->word_list_write_ptr->next;
                    free(pinyinPtr->word_list_write_ptr);
                    
                }

                pinyinPtr->word_list_write_ptr = pinyinPtr->word_list_head;
                pinyinPtr->word_list_display_ptr =pinyinPtr->word_list_head; 
                memset(pinyinPtr->input_text,0,50);
                pinyinPtr->input_text_ptr = pinyinPtr->input_text;
                pinyinPtr->input_length_counter = 0;
            }
            else 
            {
		        while(pinyinPtr->word_list_head->next != NULL)
                {
                    pinyinPtr->word_list_write_ptr = pinyinPtr->word_list_head->next;
                    
                    pinyinPtr->word_list_head->next = pinyinPtr->word_list_write_ptr->next;
                    free(pinyinPtr->word_list_write_ptr);
                    
                }
                pinyinPtr->word_list_write_ptr = pinyinPtr->word_list_head;

                if(get_char == 0x08 )
                {
                    if(pinyinPtr->input_length_counter > 0)
                    {
                        (pinyinPtr->input_text_ptr)--;
                        (pinyinPtr->input_length_counter)--;
                        *(pinyinPtr->input_text_ptr) ='\0';
                        pinyinPtr->word_list_display_ptr = pinyinPtr->word_list_head;
                    }
                    else if(pinyinPtr->CHN_length_counter >0)
                    {
                        pinyinPtr->CHN_text_ptr -= 2;
                        *(pinyinPtr->CHN_text_ptr) = '\0';
                        *(pinyinPtr->CHN_text_ptr+1) = '\0';
                        pinyinPtr->CHN_length_counter --;
                        pinyinPtr->word_list_display_ptr = pinyinPtr->word_list_head;
                    }
                }
                else
                {
                    if( pinyinPtr->input_length_counter < pinyinPtr->length)
                    {
                        *(pinyinPtr->input_text_ptr) = get_char;
                        *((pinyinPtr->input_text_ptr)+1) = '\0';//后一位清空
                    
                        (pinyinPtr->input_text_ptr)++;
                        pinyinPtr->input_length_counter++;
                        pinyinPtr->word_list_display_ptr = pinyinPtr->word_list_head;
                    }
                }

                if((pinyin_file=fopen("./LIB/PINYIN.TXT","rt")) == NULL)
                {
                    settextjustify(LEFT_TEXT, TOP_TEXT); //左部对齐，顶部对齐
			        settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
                    outtextxy(0,0,"PINTIN.TXT FILE ERROR");
                    getch();
			        exit(1);
                }
                else
                {
                    
                   
                    while (! feof(pinyin_file))
                    {
                        if(fread(&read_pinyin,sizeof(read_pinyin),1,pinyin_file) == 0)
                        {
                            break;
                        }
                        if(strcmp(read_pinyin.pinyin,pinyinPtr->input_text) == 0)
                        {
                            pinyinPtr->word_list_write_ptr->next = malloc(sizeof(struct word_to_choose));
                            if(pinyinPtr->word_list_head == NULL)
                            {
                                outtextxy(0,0,"MEMORY ERROR");
                                getch();
                                exit(1);
                            }
                            pinyinPtr->word_list_write_ptr->next->prev = pinyinPtr->word_list_write_ptr;
                            pinyinPtr->word_list_write_ptr->next->next = NULL;
                            
                            pinyinPtr->word_list_write_ptr = pinyinPtr->word_list_write_ptr->next;
                            strcpy(pinyinPtr->word_list_write_ptr->word,read_pinyin.word);
                            
                            
                        }
                    }
                    fclose(pinyin_file);
                } 
            }

            pinyinPtr->reDraw = SET;
        }
    }
}
void BFL_pinyin_draw(BFL_pinyin *pinyinPtr)
{
    char display[20]={'\0'};
    char debug_2[20]={'\0'};
    int x_0 = 0;
    int i =0;
   
    Word_Position draw_ptr = pinyinPtr->word_list_display_ptr->next;

    if (pinyinPtr->reDraw == SET)
    {
        if(pinyinPtr->status_change == IN)
        {
            pinyinPtr->buffer_size = imagesize(  pinyinPtr->position_pinyin_left,
                                        pinyinPtr->position_pinyin_top,
                                        pinyinPtr->position_pinyin_right,
                                        pinyinPtr->position_pinyin_bottom);
            pinyinPtr->buffer = malloc(pinyinPtr->buffer_size);
            if (NULL == pinyinPtr->buffer)
            {
                CHN_print(0,0,"MEMORY ERROR, PRESS ANY KEY TO EXIT",16,RED);
                getch();
                exit(1);
            }
            getimage(   pinyinPtr->position_pinyin_left,
                        pinyinPtr->position_pinyin_top,
                        pinyinPtr->position_pinyin_right,
                        pinyinPtr->position_pinyin_bottom,
                        pinyinPtr->buffer);
            pinyinPtr->status_change = RESET;
        }
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
        CHN_print(pinyinPtr->position_textbox_left,(pinyinPtr->position_textbox_top+pinyinPtr->position_textbox_bottom)/2-8,pinyinPtr->CHN_text,16,RED);
        
        if(pinyinPtr->is_in_the_box == SET)
        {
            setfillstyle(SOLID_FILL,DARKGRAY);
            bar(pinyinPtr->position_pinyin_left,
                pinyinPtr->position_pinyin_top,
                pinyinPtr->position_pinyin_right,
                pinyinPtr->position_pinyin_bottom);

            setfillstyle(SOLID_FILL,pinyinPtr->color_select_box);
            bar(pinyinPtr->position_pinyin_left+5,
                pinyinPtr->position_pinyin_top+5,
                pinyinPtr->position_pinyin_right-5,
                pinyinPtr->position_pinyin_bottom-5);
            CHN_print(pinyinPtr->position_pinyin_left+10, pinyinPtr->position_pinyin_top+35, pinyinPtr->input_text,16,pinyinPtr->color_text);//字母
            
            x_0 = pinyinPtr->position_pinyin_left+10;
            while(i<5 && draw_ptr != NULL)
            {
                memset(display,0,20);
                itoa(i+1,display,10);
                strcat(display,".");
                strcat(display,draw_ptr->word);
                CHN_print(x_0,pinyinPtr->position_pinyin_top+10,display,16,BROWN);
                x_0 += 60;
                draw_ptr = draw_ptr->next;
                i++;
            }
        }

        if(pinyinPtr->status_change == OUT)
        {
            if(pinyinPtr->buffer == NULL)
            {

            }
            else
            {
                putimage(pinyinPtr->position_pinyin_left,
                pinyinPtr->position_pinyin_top,
                pinyinPtr->buffer,COPY_PUT);

                free(pinyinPtr->buffer);
                pinyinPtr->buffer = NULL;
            }
            pinyinPtr->status_change = RESET;
        }

        pinyinPtr->reDraw = RESET;
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
        // case 0x0b30:
        //     return_char = '0';
        //     break;
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
        // case 0x342e:
        //     return_char = '.';
        //     break;
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
        case 0x4B00:
            return_char = 1;//左箭头
            break;
        case 0x4D00:
            return_char = 2;//右箭头
            break;
        // case 0x5230:
        //     return_char = '0';
        //     break;
        // case 0x0F09:
        //     return_char = 0x09;
        }
    }
    return return_char;
}
