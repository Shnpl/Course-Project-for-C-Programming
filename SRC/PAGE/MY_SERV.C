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

void my_serv_button_confirm_init(BFL_button*);

void list_draw(My_List* listPtr);
void list_action(My_List* listPtr);
void list_save(My_List* listPtr);




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

    FILE* check_appointment_file;

    My_List main_list;

    char debug1[50]={'\0'};
    char debug2[50]={'\0'};
    char debug3[50]={'\0'};
    int  y=60; 

    
    /* DEFINITION END */

    /* DEVICE AND MOUSE INIT START */
    clrmous(MouseX, MouseY);
    cleardevice();
    setbkcolor(YELLOW);

    /* DEVICE AND MOUSE INIT END */

    /* COMPONENTS INIT START */


    //main_list 初始化 

    main_list.main_list_head = (main_linklist_list)malloc(sizeof(struct main_linklist_node));
    main_list.main_list_read_ptr=main_list.main_list_head;
    
    main_list.delete_list_head = (Delete_List)malloc(sizeof(struct DELETE_NODE));

    main_list.chk_apmt_list_head = (CHK_APMT_list)malloc(sizeof(struct CHK_APMT_node));
    main_list.chk_apmt_list_read_ptr = main_list.chk_apmt_list_head;
    
    main_list.position_left =155;
    main_list.position_top = 55;
    main_list.position_right = 600;
    main_list.position_bottom = 375;
    main_list.color_box = LIGHTGRAY;
    main_list.color_text =YELLOW;
    main_list.color_lightened = LIGHTRED;
    // main_list.is_next_page =RESET;
    // main_list.is_prev_page = RESET;
    main_list.is_next_item = RESET;
    main_list.is_prev_item = RESET;

    main_list.is_delete = RESET;
    main_list.redraw = SET;

    main_list.delete_count = 0;
    main_list.total_chk_apmt_count =0;
    
    main_list.item = 1;
    main_list.total_item = 0;
    //delete list 初始化
    if(main_list.delete_list_head == NULL)
    {
         outtextxy(0,0,"MEMORY ERROR");
    }
    main_list.delete_list_head->next = NULL;
    main_list.delete_list_read_ptr = main_list.delete_list_head;

    //年检预约的文件操作与链表操作
    if(main_list.chk_apmt_list_head == NULL)
    {
        outtextxy(0,0,"MEMORY ERROR");
    }
    main_list.chk_apmt_list_head->next = NULL;
    if((check_appointment_file =fopen("./FILE/CHK_APMT.TXT","at+")) == NULL)
    {
        outtextxy(0,0,"FILE ERROR");
    }

    while(!feof(check_appointment_file))
    {
        main_list.chk_apmt_list_read_ptr->next = malloc(sizeof(struct CHK_APMT_node));
        if(main_list.chk_apmt_list_read_ptr->next == NULL)
        {
            outtextxy(0,0,"MEMORY ERROR");
        }
        if((fread(&(main_list.chk_apmt_list_read_ptr->next->check_appointment_node),sizeof(check_appointment),1,check_appointment_file)) == 0)
        {
            free(main_list.chk_apmt_list_read_ptr->next);
            main_list.chk_apmt_list_read_ptr->next = NULL;
            break;
        } 
        // if(strcmp(main_list.chk_apmt_list_read_ptr->next->check_appointment_node.user_id,user_ID) == 0)
        // {
        main_list.chk_apmt_list_read_ptr = main_list.chk_apmt_list_read_ptr->next;
        main_list.chk_apmt_list_read_ptr->next = NULL;
        // }
        // else
        // {
        //     free(main_list.chk_apmt_list_read_ptr->next);
        //     main_list.chk_apmt_list_read_ptr->next = NULL;
        // }
        
    }
    fclose(check_appointment_file);
    
    //outtextxy(0,200,CHK_APMT_read_ptr->check_appointment_node.tel);
    //itoa((int)CHK_APMT_read_ptr,debug1,16);// once used in debug
    //itoa((int)CHK_APMT_head->next,debug2,16);
    //itoa(check_appointment_count,debug3,10);

    //outtextxy(0,240,debug1);
    //outtextxy(0,280,debug2);
    
    
    //主链表的操作 将各个链表读入主链表中
    if(main_list.main_list_head == NULL)
    {
        outtextxy(0,0,"MEMORY ERROR");
    }
    
    main_list.main_list_head->next = NULL;
    main_list.main_list_head->front = NULL;
    main_list.chk_apmt_list_read_ptr = main_list.chk_apmt_list_head->next;
    while(main_list.chk_apmt_list_read_ptr != NULL)
    {
        if(strcmp(main_list.chk_apmt_list_read_ptr->check_appointment_node.user_id,user_ID) == 0)
        {
            main_list.main_list_read_ptr->next = (main_linklist_position)malloc(sizeof(struct main_linklist_node));
            if(main_list.main_list_read_ptr->next == NULL)
            {
                outtextxy(0,0,"MEMORY ERROR");
            }
            main_list.main_list_read_ptr->next->front = main_list.main_list_read_ptr;//新节点的前向指针指向现在的节点
            main_list.main_list_read_ptr->next->next = NULL;//新节点的后向指针指向 NULL
            main_list.main_list_read_ptr = main_list.main_list_read_ptr->next;
       
            strcpy(main_list.main_list_read_ptr->ID,main_list.chk_apmt_list_read_ptr->check_appointment_node.ID);
            strcpy(main_list.main_list_read_ptr->info,main_list.chk_apmt_list_read_ptr->check_appointment_node.car_licence);
            strcpy(main_list.main_list_read_ptr->status,"正在处理");
            main_list.main_list_read_ptr->type = 0;
            main_list.total_item++;
        }
        main_list.total_chk_apmt_count++;
        main_list.chk_apmt_list_read_ptr = main_list.chk_apmt_list_read_ptr->next;
        
    }
    main_list.main_list_read_ptr->next = NULL;
    itoa(main_list.total_item,debug3,10);
    outtextxy(0,320,debug3);
    my_serv_button_exit_init(&button_exit);
    my_serv_button_delete_init(&button_delete);

    my_serv_button_up_init(&button_up);
    my_serv_button_down_init(&button_down);

    my_serv_button_confirm_init(&button_confirm);
    // my_serv_button_prev_init(&button_prev);
    // my_serv_button_next_init(&button_next);


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
    CHN_print(245,35,"服务类型",16,YELLOW);
    CHN_print(320,35,"服务信息",16,YELLOW);
    CHN_print(520,35,"服务状态",16,YELLOW);

    main_list.main_list_read_ptr = main_list.main_list_head->next;

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
        // BFL_button_draw(&button_prev);
        // BFL_button_draw(&button_next);
        list_draw(&main_list);
        BFL_mouse_draw();
        /* REDRAW END */
        /*CODE START*/
        
        if (button_exit.status == PRESS)
        {
            page = _MAIN_PAGE;
            break;//还需要做内存的释放工作
        }
        if(button_down.status == PRESS)
        {
            main_list.is_next_item = SET;
            
            delay(150);
	        
        }
        if(button_up.status == PRESS)
        {
            main_list.is_prev_item = SET;
            //CHN_print(0,0,"OK",16,RED);
            delay(150);
        }
        if(button_delete.status == PRESS)
        {
            main_list.is_delete = SET;
            delay(150);
        }
        if(button_confirm.status == PRESS)
        {
            list_save(&main_list);
            page = _MY_INFO;
            break;//链表已经被删除
        }
        // if(button_next.status == PRESS)//下一页
        // {
        //     main_list.is_next_page = SET;
        //     CHN_print(0,0,"OK",16,RED);
        //     delay(150);
        // }
        // if(button_prev.status == PRESS)//下一页
        // {
        //     main_list.is_prev_page = SET;
        //     CHN_print(0,0,"OK",16,RED);
        //     delay(150);
        // }
        /*CODE END*/
      

        /* ACTION START */
        BFL_mouse_action();

        BFL_button_action(&button_exit);
        BFL_button_action(&button_delete);
        
        BFL_button_action(&button_up);
        BFL_button_action(&button_down);
        BFL_button_action(&button_confirm);

        // BFL_button_action(&button_prev);
        // BFL_button_action(&button_next);

        list_action(&main_list);
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
    buttonPtr->position_text_top = buttonPtr->position_top +10;
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
    buttonPtr->position_text_top = buttonPtr->position_top +10;
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

    // void my_serv_button_prev_init(BFL_button *buttonPtr)
    // {
    //     buttonPtr->color_rest = RED;
    //     buttonPtr->color_hover = LIGHTRED;
    //     buttonPtr->color_text = YELLOW;
    //     buttonPtr->color_shadow = DARKGRAY;
    //     buttonPtr->reDraw_status = SET;
    //     buttonPtr->position_left = 270;
    //     buttonPtr->position_top = 400;
    //     buttonPtr->position_right = 375;
    //     buttonPtr->position_bottom = 450;
    //     buttonPtr->is_shadow_enable = SET;
    //     buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    //     buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    //     buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    //     buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;
    //     buttonPtr->position_text_left = buttonPtr->position_left + 2;
    //     buttonPtr->position_text_top = buttonPtr->position_top + 10;
    //     buttonPtr->text_size = 32;
    //     strcpy(buttonPtr->display_text, "上一页");
    //     buttonPtr->status = REST;
    // }

    // void my_serv_button_next_init(BFL_button *buttonPtr)
    // {
    //     buttonPtr->color_rest = RED;
    //     buttonPtr->color_hover = LIGHTRED;
    //     buttonPtr->color_text = YELLOW;
    //     buttonPtr->color_shadow = DARKGRAY;
    //     buttonPtr->reDraw_status = SET;
    //     buttonPtr->position_left = 390;
    //     buttonPtr->position_top = 400;
    //     buttonPtr->position_right = 495;
    //     buttonPtr->position_bottom = 450;
    //     buttonPtr->is_shadow_enable = SET;
    //     buttonPtr->position_shadow_left = buttonPtr->position_left + 5;
    //     buttonPtr->position_shadow_top = buttonPtr->position_top + 5;
    //     buttonPtr->position_shadow_right = buttonPtr->position_right + 5;
    //     buttonPtr->position_shadow_bottom = buttonPtr->position_bottom + 5;
    //     buttonPtr->position_text_left = buttonPtr->position_left + 2;
    //     buttonPtr->position_text_top = buttonPtr->position_top + 10;
    //     buttonPtr->text_size = 32;
    //     strcpy(buttonPtr->display_text, "下一页");
    //     buttonPtr->status = REST;
    // }
void list_action(My_List* listPtr)
{
    main_linklist_position temp_ptr=NULL;
    if(listPtr->is_next_item == SET)
    {
	    if(listPtr->item<listPtr->total_item)
        {
            (listPtr->item)++;
            listPtr->is_next_item =RESET;
            listPtr->main_list_read_ptr=listPtr->main_list_read_ptr->next;
            listPtr->redraw = SET;
        }
    }
    if(listPtr->is_prev_item == SET)
    {
	    if(listPtr->item > 1)
        {
            (listPtr->item)--;
            listPtr->is_prev_item =RESET;
            listPtr->main_list_read_ptr=listPtr->main_list_read_ptr->front;
            listPtr->redraw = SET;
        }
    }
    if(listPtr->is_delete == SET)
    {
        
        if(listPtr->main_list_head->next == NULL)
        {
            return;
        }
        if(listPtr->main_list_read_ptr->next == NULL)
        {
            //保存ID到删除链表
            listPtr->delete_list_read_ptr->next=(Delete_Position)malloc(sizeof(struct DELETE_NODE));
            if(listPtr->delete_list_read_ptr->next == NULL)
            {
                    outtextxy(0,0,"MEMORY ERROR");
            }
            listPtr->delete_list_read_ptr =listPtr->delete_list_read_ptr->next;
            listPtr->delete_list_read_ptr->next =NULL;
            strcpy(listPtr->delete_list_read_ptr->service_ID,listPtr->main_list_read_ptr->ID);
            listPtr->delete_count++;

            if(listPtr->main_list_read_ptr->front == listPtr->main_list_head)
            {

                
                temp_ptr = listPtr->main_list_read_ptr->front;
                listPtr->main_list_head->next=NULL;

                free(listPtr->main_list_read_ptr);
                listPtr->main_list_read_ptr=listPtr->main_list_head;
                (listPtr->item)--;
            }
            else
            {
                temp_ptr = listPtr->main_list_read_ptr->front;
                listPtr->main_list_read_ptr->front->next=listPtr->main_list_read_ptr->next;
                free(listPtr->main_list_read_ptr);
                listPtr->main_list_read_ptr = temp_ptr;
                (listPtr->item)--;
            }
            
        }
        else
        {
            //保存ID到删除链表
            listPtr->delete_list_read_ptr->next=(Delete_Position)malloc(sizeof(struct DELETE_NODE));
            if(listPtr->delete_list_read_ptr->next == NULL)
            {
                    outtextxy(0,0,"MEMORY ERROR");
            }
            listPtr->delete_list_read_ptr =listPtr->delete_list_read_ptr->next;
            listPtr->delete_list_read_ptr->next =NULL;
            strcpy(listPtr->delete_list_read_ptr->service_ID,listPtr->main_list_read_ptr->ID);
            listPtr->delete_count++;

            temp_ptr = listPtr->main_list_read_ptr->next;
            listPtr->main_list_read_ptr->front->next=listPtr->main_list_read_ptr->next;
            listPtr->main_list_read_ptr->next->front=listPtr->main_list_read_ptr->front;
            
            free(listPtr->main_list_read_ptr);
            listPtr->main_list_read_ptr = temp_ptr;
        }
        
        
        (listPtr->total_item)--;
        listPtr->is_delete = RESET;
        listPtr->redraw= SET;
    }
    
}

void list_draw(My_List* listPtr)
{
    int i=0;
    int page_count = 0;
    int item_count=0;
    int y_now = listPtr->position_top+5;
    int x_now = listPtr->position_left+5;
    main_linklist_position draw_main_linklist_ptr = listPtr->main_list_head->next;
    char debug4[20] ={'\0'};
    char debug5[20] ={'\0'};
    char debug6[20] ={'\0'};
    char debug7[20] ={'\0'};
    if(listPtr->redraw == SET)
    { 
        setfillstyle(SOLID_FILL,YELLOW);
        bar(0,0,200,20);
        
        

        setfillstyle(SOLID_FILL,listPtr->color_box);
        bar(listPtr->position_left,listPtr->position_top,listPtr->position_right,listPtr->position_bottom);
        
       

        page_count= ((listPtr->item) -1) / 10;

        itoa(listPtr->total_item,debug4,10);
        itoa(listPtr->item,debug5,10);
        itoa(listPtr->delete_count,debug6,10);
        itoa(listPtr->total_chk_apmt_count,debug7,10);
        CHN_print(0,0,debug4,16,RED);
        CHN_print(50,0,debug5,16,RED);
        CHN_print(100,0,debug6,16,RED); 
        CHN_print(150,0,debug7,16,RED); 
        if(draw_main_linklist_ptr == NULL)
        {
            listPtr->redraw = RESET;
            return;
        }
        while( i < page_count * 10)
        {
            draw_main_linklist_ptr = draw_main_linklist_ptr->next;
            i++;
        }
        //该页选中项之前的
        while(item_count+10*page_count<listPtr->item-1)
        {
            CHN_print(160,y_now,draw_main_linklist_ptr->ID,16,YELLOW);
            if(draw_main_linklist_ptr->type == 0)
            {
            CHN_print(245,y_now,"年检预约",16,YELLOW);
            }
            CHN_print(320,y_now,draw_main_linklist_ptr->info,16,YELLOW);
            CHN_print(520,y_now,draw_main_linklist_ptr->status,16,YELLOW);
            draw_main_linklist_ptr = draw_main_linklist_ptr->next;
            item_count++;
            y_now += 30;
        }
        //选中项
        setfillstyle(SOLID_FILL,listPtr->color_lightened);
        bar(listPtr->position_left,y_now-2,listPtr->position_right,y_now+25-2);
        CHN_print(160,y_now,draw_main_linklist_ptr->ID,16,YELLOW);
        if(draw_main_linklist_ptr->type == 0)
        {
            CHN_print(245,y_now,"年检预约",16,YELLOW);
        }
        CHN_print(320,y_now,draw_main_linklist_ptr->info,16,YELLOW);
        CHN_print(520,y_now,draw_main_linklist_ptr->status,16,YELLOW);
        draw_main_linklist_ptr = draw_main_linklist_ptr->next;
        item_count++;
        y_now+= 30;
        //该页剩余的项
        while(item_count+10*page_count < listPtr->total_item && item_count < (page_count+1)*10)
        {
            CHN_print(160,y_now,draw_main_linklist_ptr->ID,16,YELLOW);
            if(draw_main_linklist_ptr->type == 0)
            {
                CHN_print(245,y_now,"年检预约",16,YELLOW);
            }
            CHN_print(320,y_now,draw_main_linklist_ptr->info,16,YELLOW);
            CHN_print(520,y_now,draw_main_linklist_ptr->status,16,YELLOW);
            draw_main_linklist_ptr = draw_main_linklist_ptr->next;
            item_count++;
            y_now += 30;
        }
        
    }
    listPtr->redraw = RESET;
}

void list_save(My_List* listPtr)
{
    FILE* check_appointment_file;

    listPtr->delete_list_read_ptr = listPtr->delete_list_head->next;//删除链表指针移至表头
    while (listPtr->delete_list_read_ptr != NULL)
    {
        listPtr->chk_apmt_list_read_ptr = listPtr->chk_apmt_list_head;//chk_apmt链表指针移至表头
        while(listPtr->chk_apmt_list_read_ptr->next != NULL)
        {
            if(strcmp(listPtr->chk_apmt_list_read_ptr->next->check_appointment_node.ID,listPtr->delete_list_read_ptr->service_ID) == 0)
            {
                free(listPtr->chk_apmt_list_read_ptr->next);
                listPtr->chk_apmt_list_read_ptr->next = listPtr->chk_apmt_list_read_ptr->next->next;
            }
            listPtr->chk_apmt_list_read_ptr = listPtr->chk_apmt_list_read_ptr->next;
        }
        listPtr->delete_list_read_ptr = listPtr->delete_list_read_ptr->next;
    }
    
    listPtr->chk_apmt_list_read_ptr = listPtr->chk_apmt_list_head->next;
    if((check_appointment_file =fopen("./FILE/CHK_APMT.TXT","wt")) == NULL)
    {
        outtextxy(0,0,"FILE ERROR");
    }
    while(listPtr->chk_apmt_list_read_ptr != NULL)
    {
        fwrite(&(listPtr->chk_apmt_list_read_ptr->check_appointment_node),sizeof(check_appointment),1,check_appointment_file);
        listPtr->chk_apmt_list_read_ptr =listPtr->chk_apmt_list_read_ptr->next;
    }
    fclose(check_appointment_file);

    //chk_apmt_list 释放内存
    listPtr->chk_apmt_list_read_ptr = listPtr->chk_apmt_list_head->next;
    while(listPtr->chk_apmt_list_read_ptr != NULL)
    {
        listPtr->chk_apmt_list_head->next = listPtr->chk_apmt_list_read_ptr->next;
        free(listPtr->chk_apmt_list_read_ptr);
        listPtr->chk_apmt_list_read_ptr = listPtr->chk_apmt_list_head->next;
    }
    free(listPtr->chk_apmt_list_head);
    listPtr->chk_apmt_list_head = NULL;

    //main_list 释放内存
    listPtr->main_list_read_ptr = listPtr->main_list_head->next;
    while(listPtr->main_list_read_ptr != NULL)
    {
        listPtr->main_list_head->next = listPtr->main_list_read_ptr->next;
        free(listPtr->main_list_read_ptr);
        listPtr->main_list_read_ptr = listPtr->main_list_head->next;
    }
    free(listPtr->main_list_head);
    listPtr->main_list_head = NULL;
    
    

}