#ifndef __MY_SERV_H__
#define __MY_SERV_H__
/*
“我的服务”函数
参数：char* user_ID 用户名为值的用户ID
返回：int page 跳转页面值
*/
#include "INCLUDE/CHK_APMT.H"

struct CHK_APMT_NODE;
struct MAIN_LIST_NODE;
struct MY_LIST;
struct DELETE_NODE;

typedef struct CHK_APMT_NODE* CHK_APMT_Position;
typedef struct CHK_APMT_NODE* CHK_APMT_List;
typedef struct DELETE_NODE* Delete_Position;
typedef struct DELETE_NODE* Delete_List;
 
typedef struct MAIN_LIST_NODE* Main_List_Position;
typedef struct MAIN_LIST_NODE* Main_List_List;

typedef struct MY_LIST My_List;
typedef struct DELETE_NODE Delete_Node;

struct CHK_APMT_NODE
{
    check_appointment check_appointment_node;
    CHK_APMT_Position next;
};

struct DELETE_NODE
{
    char service_ID[20];
    Delete_Position next;
};


struct MAIN_LIST_NODE
{
    char ID[20];
    int type;

    char info1[30];
    char info2[30];
    char info3[30];
    char info4[30];

    char status[20];
    Main_List_Position next;
    Main_List_Position front;
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

    int is_delete;
    int redraw;
    //WHEN HAVING ONLY ONE ITEM,THE VALUE OF ITEM IS 1
    int item;//ITEM START FROM 1
    int total_item;

    Main_List_List main_list_head;
    Main_List_Position main_list_ptr;
    
    Delete_List delete_list_head;
    Delete_Position delete_list_ptr;

    CHK_APMT_List chk_apmt_list_head;
    CHK_APMT_Position chk_apmt_list_ptr;
};

int MY_SERV(char* user_ID);
#endif