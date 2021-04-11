#ifndef __MY_SERV_H__
#define __MY_SERV_H__
/*
“我的服务”函数
参数：char* user_ID 用户名为值的用户ID
返回：int page 跳转页面值
*/
int MY_SERV(char* user_ID);
/*
typedef struct MY_LIST
{
    int position_left;
    int position_top;
    int position_right;
    int position_bottom;

    int color_box;
    int color_text;
    int color_lightened;

    int is_next_page;
    int is_prev_page;


    int is_next_item;
    int is_prev_item;

    int is_delete;
    int redraw;

    int item;
    int total_item;
    main_linklist_list main_list;
    CHK_APMT_list chk_apmt_list;

    main_linklist_position main_read_ptr;



}my_list;                       */

#endif