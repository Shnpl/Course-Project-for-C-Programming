/* SYSTEM INCLUDES START */
#include <STDIO.H>
#include <GRAPHICS.H>
#include <STDLIB.H>
#include<MALLOC.H>
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
#include"INCLUDE/MY_SERV.H"
#include"INCLUDE/CHK_APMT.H"
/*OTHER INCLUDES END*/

/* INTERNAL FUNCTION DEFINITION START */

void my_serv_button_exit_init(BFL_button*);
void my_serv_button_delete_init(BFL_button*);

void my_serv_button_up_init(BFL_button*);
void my_serv_button_down_init(BFL_button*);

void my_serv_button_next_init(BFL_button*);
void my_serv_button_prev_init(BFL_button*);


struct CHK_APMT_node;
typedef struct CHK_APMT_node* CHK_APMT_node_ptr;
typedef CHK_APMT_node_ptr CHK_APMT_position;
typedef CHK_APMT_node_ptr CHK_APMT_list;

struct main_linklist_node;
typedef struct main_linklist_node* main_linklist_ptr;
typedef main_linklist_ptr main_linklist_position;
typedef main_linklist_ptr main_linklist_list;

struct main_linklist_node
{
    char ID[20];
    int type;
    char info[30];
    char status[20];
    main_linklist_position next;
    main_linklist_position front;
};

struct CHK_APMT_node
{
    check_appointment check_appointment_node;
    CHK_APMT_position next;
};



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

    int check_appointment_count = 0;
    FILE* check_appointment_file;

    CHK_APMT_list CHK_APMT_head = (CHK_APMT_list)malloc(sizeof(struct CHK_APMT_node));
    CHK_APMT_position CHK_APMT_read_ptr = CHK_APMT_head;
    
    int main_count = 0;
    main_linklist_list main_linklist_head= (main_linklist_list)malloc(sizeof(struct main_linklist_node));
    main_linklist_position main_linklist_read_ptr = main_linklist_head;


    char debug1[50]={'\0'};
    char debug2[50]={'\0'};
    char debug3[50]={'\0'};
    

    
    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX, MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */
    
    //年检预约的文件操作与链表操作
    if(CHK_APMT_head == NULL)
    {
        outtextxy(0,0,"MEMORY ERROR");
    }
    CHK_APMT_head->next = NULL;
    if((check_appointment_file =fopen("./FILE/CHK_APMT.TXT","at+")) == NULL)
    {
        outtextxy(0,0,"FILE ERROR");
    }

    while(!feof(check_appointment_file))
    {
        CHK_APMT_read_ptr->next = malloc(sizeof(struct CHK_APMT_node));
        if(CHK_APMT_read_ptr->next == NULL)
        {
            outtextxy(0,0,"MEMORY ERROR");
        }
        if((fread(&(CHK_APMT_read_ptr->next->check_appointment_node),sizeof(check_appointment),1,check_appointment_file)) == 0)
        {
            free(CHK_APMT_read_ptr->next);
            CHK_APMT_read_ptr->next = NULL;
            break;
        } 
        if(strcmp(CHK_APMT_read_ptr->next->check_appointment_node.user_id,user_ID) == 0)
        {
            CHK_APMT_read_ptr = CHK_APMT_read_ptr->next;
            CHK_APMT_read_ptr->next = NULL;
            check_appointment_count++;
        }
        else
        {
            free(CHK_APMT_read_ptr->next);
            CHK_APMT_read_ptr->next = NULL;
        }
        
    }
    fclose(check_appointment_file);
    
    outtextxy(0,200,CHK_APMT_read_ptr->check_appointment_node.tel);
    //itoa((int)CHK_APMT_read_ptr,debug1,16);// once used in debug
    //itoa((int)CHK_APMT_head->next,debug2,16);
    itoa(check_appointment_count,debug3,10);

    //outtextxy(0,240,debug1);
    //outtextxy(0,280,debug2);
    outtextxy(0,320,debug3);
    
    //主链表的操作 将各个链表读入主链表中
    if(main_linklist_head == NULL)
    {
        outtextxy(0,0,"MEMORY ERROR");
    }
    CHK_APMT_read_ptr = CHK_APMT_head->next;
    main_linklist_head->next = NULL;
    main_linklist_head->front = NULL;

    while(CHK_APMT_read_ptr != NULL)
    {
        main_linklist_read_ptr->next = (main_linklist_position)malloc(sizeof(struct main_linklist_node));
        if(main_linklist_read_ptr->next == NULL)
        {
            outtextxy(0,0,"MEMORY ERROR");
        }
        main_linklist_read_ptr->next->front = main_linklist_read_ptr;//新节点的前向指针指向现在的节点
        main_linklist_read_ptr->next->next = NULL;//新节点的后向指针指向 NULL
        main_linklist_read_ptr = main_linklist_read_ptr->next;

        strcpy(main_linklist_read_ptr->ID,CHK_APMT_read_ptr->check_appointment_node.ID);
        strcpy(main_linklist_read_ptr->info,CHK_APMT_read_ptr->check_appointment_node.car_licence);
        strcpy(main_linklist_read_ptr->status,"正在处理");
        main_linklist_read_ptr->type = 0;

        CHK_APMT_read_ptr = CHK_APMT_read_ptr->next;
        main_count++;
    }
    itoa(main_count,debug3,10);


    my_serv_button_exit_init(&button_exit);
    my_serv_button_delete_init(&button_delete);

    my_serv_button_up_init(&button_up);
    my_serv_button_down_init(&button_down);

    my_serv_button_prev_init(&button_prev);
    my_serv_button_next_init(&button_next);


    /* COMPONENTS INIT END */

    /* DRAW START */
    setfillstyle(1, LIGHTGRAY);
    bar(0, 420, 640, 480);

    CHN_print(22, 21, "我的", 48, DARKGRAY);
    CHN_print(22, 71, "服务", 48, DARKGRAY);

    CHN_print(20, 20, "我的", 48, RED);
    CHN_print(20, 70, "服务", 48, RED);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(150+5,25+5,605+5,380+5);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(150,25,605,55);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(150,55,605,380);

    setfillstyle(SOLID_FILL,WHITE);
    bar(153,28,155,377);
    bar(153,28,602,30);
    bar(600,28,602,377);
    bar(153,375,602,377);
    //setfillstyle(SOLID_FILL,CYAN);
    //bar(150,25,525,380);
    CHN_print(160,35,"服务ID",16,YELLOW);
    CHN_print(240,35,"服务类型",16,YELLOW);
    CHN_print(320,35,"服务信息",16,YELLOW);
    CHN_print(520,35,"服务状态",16,YELLOW);


    /* DRAW END */

    /*WHILE*/
    while (page == _MY_SERV)
    {
        /* REDRAW START */
        BFL_button_draw(&button_exit);
        BFL_button_draw(&button_delete);
        BFL_button_draw(&button_up);
        BFL_button_draw(&button_down);

        BFL_button_draw(&button_prev);
        BFL_button_draw(&button_next);

        BFL_mouse_draw();
        /* REDRAW END */

        /*CODE START*/
        
        if (button_exit.status == PRESS)
        {
            page = _VEH_ADMI;
            break;
        }
        /*CODE END*/

        /* ACTION START */
        BFL_mouse_action();

        BFL_button_action(&button_exit);
        BFL_button_action(&button_delete);
        
        BFL_button_action(&button_up);
        BFL_button_action(&button_down);

        BFL_button_action(&button_prev);
        BFL_button_action(&button_next);
        /* ACTION  END */
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

    buttonPtr->position_left = 160;
    buttonPtr->position_top = 400;
    buttonPtr->position_right = 250;
    buttonPtr->position_bottom = 421;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 27;
    buttonPtr->position_text_top = buttonPtr->position_top +3;
    buttonPtr->text_size = 16;

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

    buttonPtr->position_left = 160;
    buttonPtr->position_top = 429;
    buttonPtr->position_right = 250;
    buttonPtr->position_bottom = 450;

    buttonPtr->is_shadow_enable = SET;
    buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;

    buttonPtr->position_text_left = buttonPtr->position_left + 27;
    buttonPtr->position_text_top = buttonPtr->position_top +3;
    buttonPtr->text_size = 16;

    strcpy(buttonPtr->display_text, "向下");

    buttonPtr->status = REST;
}

void my_serv_button_prev_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
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

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "上一页");

    buttonPtr->status = REST;
}

void my_serv_button_next_init(BFL_button *buttonPtr)
{
    buttonPtr->color_rest = RED;
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

    buttonPtr->position_text_left = buttonPtr->position_left + 2;
    buttonPtr->position_text_top = buttonPtr->position_top + 10;
    buttonPtr->text_size = 32;

    strcpy(buttonPtr->display_text, "下一页");

    buttonPtr->status = REST;
}
/*
page = 0;
item = 1;

void list_draw(my_list* listPtr)
{
    int i=0;
    int page;
    int y_now = listPtr->position_top+5;
    int x_now = listPtr->position_left+5;
    main_linklist_position draw_main_linklist_ptr = listPtr->main_list->next;
    if(draw_main_linklist_ptr == NULL)
    {
	return;
    }
    if(listPtr == RESET)
    {
	return;
    }

    setfillstyle(SOLID_FILL,listPtr->color_box);
    bar(listPtr->position_left,listPtr->position_top,listPtr->position_right,listPtr->position_bottom);

    listPtr->page= (listPtr->item -1) / 10;
    while( i < page * 10)
    {
	draw_main_linklist_ptr = draw_main_linklist_ptr->next;
    }

    while(draw_main_linklist_ptr != listPtr->main_read_ptr)
    {
	outtextxy(x_now,y_now,draw_main_linklist_ptr->ID);

	CHN_print(,35,"服务类型",16,16,YELLOW);
    CHN_print(320,35,"服务信息",16,16,YELLOW);
    CHN_print(520,35,"服务状态",16,16,YELLOW);

    }







}*/