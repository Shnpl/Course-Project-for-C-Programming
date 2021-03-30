/* SYSTEM INCLUDES START */
#include <STDIO.H>
#include <GRAPHICS.H>
#include <STDLIB.H>
#include <DOS.H>
#include <STRING.H>
/* SYSTEM INCLUDE END */

/* BFL INCLUDES START */
#include"INCLUDE/GENERAL.H"
#include"INCLUDE/MOUSE.H"
#include"INCLUDE/BUTTON.H"
#include"INCLUDE/TEXTBOX.H"
#include"INCLUDE/CHN.H"
#include"INCLUDE/LABEL.H"
#include"INCLUDE/PINYIN.H"
/*BFL INCLUDES END*/

/*OTHER INCLUDES START*/

/*OTHER INCLUDES END*/

/* INTERNAL FUNCTION DEFINITION START */

void test_button_exit_init(BFL_button *);
void test_pinyin_0_init(BFL_pinyin* );

/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int TEST(char *user_ID)
{
    /* DEFINITION START */

    int page = -1;

    BFL_button button_exit;
    BFL_pinyin pinyin_0;

    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX, MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */

    test_button_exit_init(&button_exit);
    test_pinyin_0_init(&pinyin_0);

    /* COMPONENTS INIT END */

    /* DRAW START */
    setfillstyle(1, LIGHTGRAY);
    bar(0, 420, 640, 480);

    /* DRAW END */

    /*WHILE*/
    while (page == -1)
    {
        /*ACTION START*/
        BFL_mouse_action();
        BFL_pinyin_action(&pinyin_0);
        BFL_button_action(&button_exit);

        /* ACTION END */

        /*CODE START*/
        if (button_exit.status == PRESS)
        {
            page = 0;
            break;
        }
        /*CODE END*/

        /* REDRAW START */
        BFL_button_draw(&button_exit);
        BFL_pinyin_draw(&pinyin_0);
        BFL_mouse_draw();
        /* REDRAW  END */
    }

    delay(200); //防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;
}
void test_pinyin_0_init(BFL_pinyin *pinyinPtr)
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
    pinyinPtr->CHN_text_ptr = (pinyinPtr->CHN_text);
    memset((pinyinPtr->input_text),0,50);
    pinyinPtr->input_text_ptr = (pinyinPtr->input_text);
    BFL_pinyin_draw(pinyinPtr);
    
    pinyinPtr->reDraw = RESET;
}

void test_button_exit_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 480;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 585;
    buttonPtr->position_bottom = 460;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 10;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "退出");
    buttonPtr->text_length = 2;

    buttonPtr->status = REST;
}
