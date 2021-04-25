/* SYSTEM INCLUDES START */
#include <STDIO.H>
#include <GRAPHICS.H>
#include <STDLIB.H>
#include <MALLOC.H>
#include <DOS.H>
#include <STRING.H>
#include <BIOS.H>
/* SYSTEM INCLUDE END */

/* BFL INCLUDES START */
#include "INCLUDE/GENERAL.H"
#include "INCLUDE/MOUSE.H"
#include "INCLUDE/BUTTON.H"
#include "INCLUDE/TEXTBOX.H"
#include "INCLUDE/CHN.H"
#include "INCLUDE/LABEL.H"
/*BFL INCLUDES END*/

/*OTHER INCLUDES START*/
#include "INCLUDE/MY_SERV.H"
#include "INCLUDE/CHK_APMT.H"
/*OTHER INCLUDES END*/

/* INTERNAL FUNCTION DEFINITION START */

void my_serv_button_exit_init(BFL_button *);
void my_serv_button_delete_init(BFL_button *);

void my_serv_button_up_init(BFL_button *);
void my_serv_button_down_init(BFL_button *);

void my_serv_button_next_init(BFL_button *);
void my_serv_button_prev_init(BFL_button *);

void my_serv_button_confirm_init(BFL_button *);

void list_draw(My_List *listPtr);
void list_action(My_List *listPtr);
void list_save(My_List *listPtr);
void list_init(My_List *listPtr, char *user_ID);

void num_to_province(int in,char* dest)
{
    switch (in)
    {
    case 1:
        strcpy(dest,"京");
        break;
    case 2:
        strcpy(dest,"沪");
        break;
    case 3:
        strcpy(dest,"津");
        break;
    case 4:
        strcpy(dest,"渝");
        break;
    case 5:
        strcpy(dest,"蒙");
        break;
    case 6:
        strcpy(dest,"宁");
        break;
    case 7:
        strcpy(dest,"新");
        break;
    case 8:
        strcpy(dest,"藏");
        break;
    case 9:
        strcpy(dest,"桂");
        break;
    case 10:
        strcpy(dest,"黑");
        break;
    case 11:
        strcpy(dest,"辽");
        break;
    case 12:
        strcpy(dest,"吉");
        break;
    case 13:
        strcpy(dest,"冀");
        break;
    case 14:
        strcpy(dest,"鲁");
        break;
    case 15:
        strcpy(dest,"晋");
        break;
    case 16:
        strcpy(dest,"陕");
        break;
    case 17:
        strcpy(dest,"甘");
        break;
    case 18:
        strcpy(dest,"青");
        break;
    case 19:
        strcpy(dest,"豫");
        break;
    case 20:
        strcpy(dest,"皖");
        break;
    case 21:
        strcpy(dest,"鄂");
        break;
    case 22:
        strcpy(dest,"湘");
        break;
    case 23:
        strcpy(dest,"苏");
        break;
    case 24:
        strcpy(dest,"浙");
        break;
    case 25:
        strcpy(dest,"赣");
        break;
    case 26:
        strcpy(dest,"闽");
        break;
    case 27:
        strcpy(dest,"粤");
        break;
    case 28:
        strcpy(dest,"琼");
        break;
    case 29:
        strcpy(dest,"川");
        break;
    case 30:
        strcpy(dest,"滇");
        break;
    case 31:
        strcpy(dest,"贵");
        break;
    default:
        break;
    }
}
void list_init(My_List *listPtr, char *user_ID)
{
    FILE *check_appointment_file;
    char itoa_temp[20] = {'\0'};


    //MEMORY INITIALIZE
    listPtr->main_list_head = (Main_List_List)malloc(sizeof(struct MAIN_LIST_NODE));

    listPtr->main_list_ptr = listPtr->main_list_head;
    listPtr->delete_list_head = (Delete_List)malloc(sizeof(struct DELETE_NODE));

    listPtr->chk_apmt_list_head = (CHK_APMT_List)malloc(sizeof(struct CHK_APMT_NODE));
    listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_head;

    listPtr->position_left = 155;
    listPtr->position_top = 55;
    listPtr->position_right = 600;
    listPtr->position_bottom = 375;
    listPtr->color_box = LIGHTGRAY;
    listPtr->color_text = YELLOW;
    listPtr->color_lightened = LIGHTRED;

    listPtr->is_next_item = RESET;
    listPtr->is_prev_item = RESET;


    listPtr->is_delete = RESET;
    listPtr->redraw = SET;

    listPtr->item = 1;
    listPtr->total_item = 0;
    //delete list INITIALIZE
    if (listPtr->delete_list_head == NULL)
    {
        outtextxy(0, 0, "MEMORY ERROR");
    }
    listPtr->delete_list_head->next = NULL;
    listPtr->delete_list_ptr = listPtr->delete_list_head;

    //年检预约的文件操作与链表操作
    if (listPtr->chk_apmt_list_head == NULL)
    {
        outtextxy(0, 0, "MEMORY ERROR");
    }
    listPtr->chk_apmt_list_head->next = NULL;
    if ((check_appointment_file = fopen("./FILE/CHK_APMT.TXT", "at+")) == NULL)
    {
        outtextxy(0, 0, "FILE ERROR");
    }

    while (!feof(check_appointment_file))
    {
        listPtr->chk_apmt_list_ptr->next = malloc(sizeof(struct CHK_APMT_NODE));
        if (listPtr->chk_apmt_list_ptr->next == NULL)
        {
            outtextxy(0, 0, "MEMORY ERROR");
        }
        if ((fread(&(listPtr->chk_apmt_list_ptr->next->check_appointment_node), sizeof(check_appointment), 1, check_appointment_file)) == 0)
        {
            free(listPtr->chk_apmt_list_ptr->next);
            listPtr->chk_apmt_list_ptr->next = NULL;
            break;
        }
        listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_ptr->next;
        listPtr->chk_apmt_list_ptr->next = NULL;
    }
    fclose(check_appointment_file);
    //主链表的操作 将各个链表读入主链表中
    if (listPtr->main_list_head == NULL)
    {
        outtextxy(0, 0, "MEMORY ERROR");
    }

    listPtr->main_list_head->next = NULL;
    listPtr->main_list_head->front = NULL;
    listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_head->next;
    while (listPtr->chk_apmt_list_ptr != NULL)
    {
        //READ CHECK APPOINTMENT DATA FROM FILES
        if (strcmp(listPtr->chk_apmt_list_ptr->check_appointment_node.user_id, user_ID) == 0)
        {
            listPtr->main_list_ptr->next = (Main_List_Position)malloc(sizeof(struct MAIN_LIST_NODE));
            if (listPtr->main_list_ptr->next == NULL)
            {
                outtextxy(0, 0, "MEMORY ERROR");
            }
            listPtr->main_list_ptr->next->front = listPtr->main_list_ptr; //FRONT PTR OF NEW NODE POINT TO CURRENT NODE新节点的前向指针指向现在的节点
            listPtr->main_list_ptr->next->next = NULL;                    //NEXT PTR OF NEW NODE POINT TO CURRENT NODE新节点的后向指针指向 NULL
            listPtr->main_list_ptr = listPtr->main_list_ptr->next;

            strcpy(listPtr->main_list_ptr->ID, listPtr->chk_apmt_list_ptr->check_appointment_node.service_ID);
            
            num_to_province(listPtr->chk_apmt_list_ptr->check_appointment_node.car_province,listPtr->main_list_ptr->info1);
            strcat(listPtr->main_list_ptr->info1, listPtr->chk_apmt_list_ptr->check_appointment_node.car_licence);
            
            strcpy(listPtr->main_list_ptr->info2,listPtr->chk_apmt_list_ptr->check_appointment_node.liason);
            strcpy(listPtr->main_list_ptr->info3,listPtr->chk_apmt_list_ptr->check_appointment_node.tel);
            
            itoa(listPtr->chk_apmt_list_ptr->check_appointment_node.year,itoa_temp,10);
            strcpy(listPtr->main_list_ptr->info4,itoa_temp);
            strcat(listPtr->main_list_ptr->info4,"年");

            itoa(listPtr->chk_apmt_list_ptr->check_appointment_node.month,itoa_temp,10);
            strcat(listPtr->main_list_ptr->info4,itoa_temp);
            strcat(listPtr->main_list_ptr->info4,"月");

            itoa(listPtr->chk_apmt_list_ptr->check_appointment_node.day,itoa_temp,10);
            strcat(listPtr->main_list_ptr->info4,itoa_temp);
            strcat(listPtr->main_list_ptr->info4,"日");

            strcpy(listPtr->main_list_ptr->status, "正在处理");
            listPtr->main_list_ptr->type = 0;
            listPtr->total_item++;
        }
        listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_ptr->next;
    }
    listPtr->main_list_ptr->next = NULL;
    listPtr->main_list_ptr = listPtr->main_list_head->next;
}

/* INTERNAL FUNCTION DEFINITION END */

/*MAIN FUNCTION*/
int MY_SERV(char *user_ID)
{
    /* DEFINITION START */

    int page = _MY_SERV;

    BFL_button button_exit;
    BFL_button button_delete;

    BFL_button button_up;
    BFL_button button_down;
    BFL_button button_prev;
    BFL_button button_next;

    BFL_button button_confirm;

    FILE *check_appointment_file;

    My_List main_list;

    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX, MouseY);
    cleardevice();
    setbkcolor(YELLOW);
    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */

    list_init(&main_list, user_ID);

    my_serv_button_exit_init(&button_exit);
    my_serv_button_delete_init(&button_delete);

    my_serv_button_up_init(&button_up);
    my_serv_button_down_init(&button_down);

    my_serv_button_confirm_init(&button_confirm);

    /* COMPONENTS INIT END */

    /* DRAW START */

    setfillstyle(1, LIGHTGRAY);
    bar(0, 420, 640, 480);

    CHN_print(22, 21, "我的", 48, DARKGRAY);
    CHN_print(22, 71, "服务", 48, DARKGRAY);

    CHN_print(20, 20, "我的", 48, RED);
    CHN_print(20, 70, "服务", 48, RED);

    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(150 + 5, 25 + 5, 605 + 5, 380 + 5);

    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(150, 25, 605, 55);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(150, 55, 605, 380);

    setfillstyle(SOLID_FILL, WHITE);
    bar(153, 28, 155, 377);
    bar(153, 28, 602, 30);
    bar(600, 28, 602, 377);
    bar(153, 375, 602, 377);

    CHN_print(160, 35, "服务ID", 16, YELLOW);
    CHN_print(245, 35, "服务类型", 16, YELLOW);
    CHN_print(320, 35, "服务信息", 16, YELLOW);
    CHN_print(520, 35, "服务状态", 16, YELLOW);

    /* DRAW END */

    /*WHILE*/
    while (page == _MY_SERV)
    {
        /* REDRAW START */

        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_delete);
        BFL_button_draw(&button_up);
        BFL_button_draw(&button_down);
        BFL_button_draw(&button_confirm);

        list_draw(&main_list);
        BFL_mouse_draw();

        /* REDRAW END */

        /* ACTION START */

        BFL_mouse_action();

        BFL_button_action(&button_exit);
        BFL_button_action(&button_delete);

        BFL_button_action(&button_up);
        BFL_button_action(&button_down);
        BFL_button_action(&button_confirm);

        list_action(&main_list);

        /* ACTION  END */

        /*CODE START*/

        if (button_down.status == PRESS)
        {
            main_list.is_next_item = SET;
            delay(150);
        }
        if (button_up.status == PRESS)
        {
            main_list.is_prev_item = SET;
            delay(150);
        }
        if (button_delete.status == PRESS)
        {
            main_list.is_delete = SET;
            delay(150);
        }

        if (button_exit.status == PRESS)
        {
            page = _MAIN_PAGE;
            break;
        }
        if (button_confirm.status == PRESS)
        {
            list_save(&main_list);
            page = _MY_INFO;
            break;
        }

        /*CODE END*/
    }
    delay(200); //防止下一页面的按钮因为按下鼠标的时长而误操作
    return page;
}

void my_serv_button_exit_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 520;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 610;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 15;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "退出");

    buttonPtr->status = REST;
}

void my_serv_button_delete_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 30;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 140;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 15;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "删除");

    buttonPtr->status = REST;
}

void my_serv_button_up_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = CYAN;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 270;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 375;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 5;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "向上");

    buttonPtr->status = REST;
}

void my_serv_button_down_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = CYAN;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 390;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 495;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 5;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "向下");

    buttonPtr->status = REST;
}

void my_serv_button_confirm_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
    buttonPtr->color_hover = LIGHTRED;
    buttonPtr->color_text = YELLOW;
    buttonPtr->color_shadow = DARKGRAY;

    buttonPtr->reDraw_status = SET;

    buttonPtr->position_left = 160;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 240;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "确认");

    buttonPtr->status = REST;
}

void list_action(My_List *listPtr)
{    
    Main_List_Position temp_ptr = NULL;
    //ITEM MOVE NEXT
    if (listPtr->is_next_item == SET)
    {
        
        listPtr->is_next_item = RESET;
        listPtr->redraw = SET;
        if (listPtr->item < listPtr->total_item)
        {
            (listPtr->item)++;
            listPtr->main_list_ptr = listPtr->main_list_ptr->next;
        }
        else //IF REACH THE END
        {
            listPtr->item = 1;
            listPtr->main_list_ptr = listPtr->main_list_head->next;
        }
    }
    //ITEM MOVE PREV
    if (listPtr->is_prev_item == SET)
    {
        listPtr->is_prev_item = RESET;
        listPtr->redraw = SET;
        if (listPtr->item > 1)
        {
            (listPtr->item)--;
            listPtr->main_list_ptr = listPtr->main_list_ptr->front;
        }
        else //IF REACH THE HEAD
        {
            while(listPtr->main_list_ptr->next != NULL)
            {
                listPtr->main_list_ptr = listPtr->main_list_ptr->next;
                listPtr->item++;
            }
        }
    }
    //DELETE ITEM
    if (listPtr->is_delete == SET)
    {
        //IF THE LIST IS EMPTY
        if (listPtr->main_list_head->next == NULL)
        {
            return;
        }
        
        if (listPtr->main_list_ptr->next == NULL)//LAST ITEM
        {
            //SAVE ID TO THE DELETE_LIST
            listPtr->delete_list_ptr->next = (Delete_Position)malloc(sizeof(struct DELETE_NODE));
            if (listPtr->delete_list_ptr->next == NULL)
            {
                outtextxy(0, 0, "MEMORY ERROR");
            }
            //INITIALIZE THE NEW NODE OF DELETE_LIST
            listPtr->delete_list_ptr = listPtr->delete_list_ptr->next;
            listPtr->delete_list_ptr->next = NULL;
            //COPY
            strcpy(listPtr->delete_list_ptr->service_ID, listPtr->main_list_ptr->ID);
            //LAST ITEM
            if (listPtr->main_list_ptr->front == listPtr->main_list_head)
            {
                listPtr->main_list_head->next = NULL;
                free(listPtr->main_list_ptr);
                listPtr->main_list_ptr = listPtr->main_list_head;
                (listPtr->item)--;
            }
            else
            {
                temp_ptr = listPtr->main_list_ptr->front;
                listPtr->main_list_ptr->front->next = listPtr->main_list_ptr->next;
                free(listPtr->main_list_ptr);
                listPtr->main_list_ptr = temp_ptr;
                (listPtr->item)--;
            }
        }
        else//NOT THE LAST ITEM
        {
            //SAVE ID TO THE DELETE_LIST
            listPtr->delete_list_ptr->next = (Delete_Position)malloc(sizeof(struct DELETE_NODE));
            if (listPtr->delete_list_ptr->next == NULL)
            {
                outtextxy(0, 0, "MEMORY ERROR");
            }
            //INITIALIZE THE NEW NODE OF DELETE_LIST
            listPtr->delete_list_ptr = listPtr->delete_list_ptr->next;
            listPtr->delete_list_ptr->next = NULL;
            //COPY
            strcpy(listPtr->delete_list_ptr->service_ID, listPtr->main_list_ptr->ID);

            temp_ptr = listPtr->main_list_ptr->next;
            listPtr->main_list_ptr->front->next = listPtr->main_list_ptr->next;
            listPtr->main_list_ptr->next->front = listPtr->main_list_ptr->front;

            free(listPtr->main_list_ptr);
            listPtr->main_list_ptr = temp_ptr;
        }

        (listPtr->total_item)--;
        listPtr->is_delete = RESET;
        listPtr->redraw = SET;
    }
}

void list_draw(My_List *listPtr)
{
    int i = 0;
    int item_per_page = 3;
    int page_count = 0;
    int item_count = 0;

    int y_now = listPtr->position_top + 5;
    int x_now = listPtr->position_left + 5;

    Main_List_Position draw_main_list_ptr = listPtr->main_list_head->next;

    char debug4[20] = {'\0'};
    char debug5[20] = {'\0'};
    char debug6[20] = {'\0'};
    char debug7[20] = {'\0'};

    if (listPtr->redraw == SET)
    {
        setfillstyle(SOLID_FILL, YELLOW);
        bar(0, 0, 200, 20);

        setfillstyle(SOLID_FILL, listPtr->color_box);
        bar(listPtr->position_left, listPtr->position_top, listPtr->position_right, listPtr->position_bottom);

        page_count = ((listPtr->item) - 1) / item_per_page;

        CHN_print(0, 0, debug4, 16, RED);
        CHN_print(50, 0, debug5, 16, RED);
        CHN_print(100, 0, debug6, 16, RED);
        CHN_print(150, 0, debug7, 16, RED);

        if (draw_main_list_ptr == NULL)
        {
            listPtr->redraw = RESET;
            return;
        }
        //ITEMS INFRONT OF CURRENT PAGE
        while (i < page_count * item_per_page)
        {
            draw_main_list_ptr = draw_main_list_ptr->next;
            i++;
        }
	    setfillstyle(1,LIGHTGRAY);
        bar(0,200,100,400);
        itoa(page_count,debug4,10);
        CHN_print(0,200,debug4,32,RED);
        itoa(listPtr->total_item,debug5,10);
        CHN_print(0,300,debug5,32,RED);

        while (item_count + item_per_page * page_count < listPtr->item - 1)
        {
            CHN_print(160, y_now, draw_main_list_ptr->ID, 16, YELLOW);

            if (draw_main_list_ptr->type == 0)
            {
                CHN_print(245, y_now, "年检预约", 16, YELLOW);

                CHN_print(320, y_now, draw_main_list_ptr->info1, 16, YELLOW);
                CHN_print(320, y_now+25, draw_main_list_ptr->info2, 16, YELLOW);
                CHN_print(320, y_now+50, draw_main_list_ptr->info3, 16, YELLOW);
                CHN_print(320, y_now+75, draw_main_list_ptr->info4, 16, YELLOW);

                CHN_print(520, y_now, draw_main_list_ptr->status, 16, YELLOW);
            }
            draw_main_list_ptr = draw_main_list_ptr->next;
            item_count++;
            y_now += 100;
        }
        //选中项
        setfillstyle(SOLID_FILL, listPtr->color_lightened);
        bar(listPtr->position_left, y_now - 2, listPtr->position_right, y_now + 100 - 2);
        CHN_print(160, y_now, draw_main_list_ptr->ID, 16, YELLOW);
        if (draw_main_list_ptr->type == 0)
        {
            CHN_print(245, y_now, "年检预约", 16, YELLOW);
            CHN_print(320, y_now, draw_main_list_ptr->info1, 16, YELLOW);
            CHN_print(320, y_now+25, draw_main_list_ptr->info2, 16, YELLOW);
            CHN_print(320, y_now+50, draw_main_list_ptr->info3, 16, YELLOW);
            CHN_print(320, y_now+75, draw_main_list_ptr->info4, 16, YELLOW);

            CHN_print(520, y_now, draw_main_list_ptr->status, 16, YELLOW);
        }
        
        draw_main_list_ptr = draw_main_list_ptr->next;
        item_count++;
        y_now += 100;
        //该页剩余的项
        while (item_count + item_per_page * page_count < listPtr->total_item && item_count <  item_per_page)
        {
            CHN_print(160, y_now, draw_main_list_ptr->ID, 16, YELLOW);
            if (draw_main_list_ptr->type == 0)
            {
                CHN_print(245, y_now, "年检预约", 16, YELLOW);
                CHN_print(320, y_now, draw_main_list_ptr->info1, 16, YELLOW);
                CHN_print(320, y_now+25, draw_main_list_ptr->info2, 16, YELLOW);
                CHN_print(320, y_now+50, draw_main_list_ptr->info3, 16, YELLOW);
                CHN_print(320, y_now+75, draw_main_list_ptr->info4, 16, YELLOW);
                CHN_print(520, y_now, draw_main_list_ptr->status, 16, YELLOW);
            }
            
            draw_main_list_ptr = draw_main_list_ptr->next;
            item_count++;
            y_now += 100;
        }
    }
    listPtr->redraw = RESET;
}

void list_save(My_List *listPtr)
{
    FILE *check_appointment_file;

    listPtr->delete_list_ptr = listPtr->delete_list_head->next; // MOVE THE PTR OF DELETE_LIST TO ITS HEAD
    while (listPtr->delete_list_ptr != NULL)
    {
        listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_head; //MOVE THE PTR OF chk_apmtLIST TO ITS HEAD
        while (listPtr->chk_apmt_list_ptr->next != NULL)
        {
	    if (strcmp(listPtr->chk_apmt_list_ptr->next->check_appointment_node.service_ID, listPtr->delete_list_ptr->service_ID) == 0)
            {
                free(listPtr->chk_apmt_list_ptr->next);
                listPtr->chk_apmt_list_ptr->next = listPtr->chk_apmt_list_ptr->next->next;
            }
            listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_ptr->next;
        }
        listPtr->delete_list_ptr = listPtr->delete_list_ptr->next;
    }

    listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_head->next;
    if ((check_appointment_file = fopen("./FILE/CHK_APMT.TXT", "wt")) == NULL)
    {
        outtextxy(0, 0, "FILE ERROR");
    }
    while (listPtr->chk_apmt_list_ptr != NULL)
    {
        fwrite(&(listPtr->chk_apmt_list_ptr->check_appointment_node), sizeof(check_appointment), 1, check_appointment_file);
        listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_ptr->next;
    }
    fclose(check_appointment_file);

    //FREE THE MEMORY OF chk_apmt_list
    listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_head->next;
    while (listPtr->chk_apmt_list_ptr != NULL)
    {
        listPtr->chk_apmt_list_head->next = listPtr->chk_apmt_list_ptr->next;
        free(listPtr->chk_apmt_list_ptr);
        listPtr->chk_apmt_list_ptr = listPtr->chk_apmt_list_head->next;
    }
    free(listPtr->chk_apmt_list_head);
    listPtr->chk_apmt_list_head = NULL;

    //FREE THE MEMORY OF main_list
    listPtr->main_list_ptr = listPtr->main_list_head->next;
    while (listPtr->main_list_ptr != NULL)
    {
        listPtr->main_list_head->next = listPtr->main_list_ptr->next;
        free(listPtr->main_list_ptr);
        listPtr->main_list_ptr = listPtr->main_list_head->next;
    }
    free(listPtr->main_list_head);
    listPtr->main_list_head = NULL;
}