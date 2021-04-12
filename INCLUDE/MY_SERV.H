#ifndef __MY_SERV_H__
#define __MY_SERV_H__
/*
“我的服务”函数
参数：char* user_ID 用户名为值的用户ID
返回：int page 跳转页面值
*/
#include "INCLUDE/CHK_APMT.H"

struct CHK_APMT_node;
struct main_linklist_node;
struct MY_LIST;
struct DELETE_NODE;

typedef struct CHK_APMT_node* CHK_APMT_position;
typedef struct CHK_APMT_node* CHK_APMT_list;
typedef struct DELETE_NODE* Delete_Position;
typedef struct DELETE_NODE* Delete_List;
 
typedef struct main_linklist_node* main_linklist_position;
typedef struct main_linklist_node* main_linklist_list;

typedef struct MY_LIST My_List;
typedef struct DELETE_NODE Delete_Node;

struct CHK_APMT_node
{
    check_appointment check_appointment_node;
    CHK_APMT_position next;
};

struct DELETE_NODE
{
    char service_ID[20];
    Delete_Position next;
};


struct main_linklist_node
{
    char ID[20];
    int type;
    char info[30];
    char status[20];
    main_linklist_position next;
    main_linklist_position front;
};

struct MY_LIST
{
    int position_left;
    int position_top;
    int position_right;
    int position_bottom;

    int color_box;
    int color_text;
    int color_lightened;



    int is_next_item;
    int is_prev_item;

    // int is_next_page;
    // int is_prev_page;

    int is_delete;
    int redraw;

    int item;
    int total_item;
    int total_chk_apmt_count;//debug 
    main_linklist_list main_list_head;
    main_linklist_position main_list_read_ptr;
    
    Delete_List delete_list_head;
    Delete_Position delete_list_read_ptr;
    int delete_count;//debug 
    CHK_APMT_list chk_apmt_list_head;
    CHK_APMT_position chk_apmt_list_read_ptr;
};

int MY_SERV(char* user_ID);
#endif