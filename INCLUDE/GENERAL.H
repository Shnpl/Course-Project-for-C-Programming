#ifndef __GENERAL_H__
#define __GENERAL_H__
/*GENERAL.H
用于一些通用的宏定义与结构体定义
*/
#define SET 1
#define RESET 0

#define REST 0
#define HOVER 1
#define PRESS 2
/* 登录与注册 user 结构 */
typedef struct user_struct
{
    char name[30]; 
    char code[30];
    char codeRepeat[30];
} user;

#endif
