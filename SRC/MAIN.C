#include<STDIO.H>
#include<GRAPHICS.H>
#include<STDLIB.H>
#include<DOS.H>

#include"INCLUDE/MOUSE.H"
#include"INCLUDE/BUTTON.H"

#include"INCLUDE/INITIAL.H"
#include"INCLUDE/SIGN_IN.H"
#include"INCLUDE/LOGIN.H"
#include"INCLUDE/MAIN_PAGE.H"
#include"INCLUDE/MY_INFO.H"
#include"INCLUDE/TEST.H"
#include"INCLUDE/CAR_SERV.H"
#include"INCLUDE/CAR_INSU.H"
#include"INCLUDE/VEH_ADMI.H"
#include"INCLUDE/CHK_APMT.H"

#include"INCLUDE/GENERAL.H"

void main()
{
    int page = 0;
    int graphdriver = VGA;
    int graphmode = VGAHI;
     char user_ID[100];
    initgraph(&graphdriver,&graphmode,"../BORLANDC/BGI");
    setviewport(0,0,640,480,0);
    BFL_mouse_init();



    while(1)
    {
        switch (page)
        {
        case _TEST:
            page = TEST(user_ID);
            break;
        case _INITIAL:
            page = INITIAL();
            break;
        case _SIGN_IN:
            page = SIGN_IN();
            break;
        case _LOGIN:
            page = LOGIN(user_ID);
            break; 
        case _MAIN_PAGE:
            page = MAIN_PAGE(user_ID);
            break; 
        case _MY_INFO:
            page = MY_INFO(user_ID);  
            break;
        case _CAR_SERV:
            page = CAR_SERV(user_ID);
            break;
        case _CAR_INSU:
            page = CAR_INSU(user_ID);
            break;
        case _VEH_ADMI:
            page = VEH_ADMI(user_ID);
            break;
        case _CHK_APMT:
            page = CHK_APMT(user_ID);
            break;
        default:
            break;
        }
    }

    closegraph();

}