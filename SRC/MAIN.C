#include<STDIO.H>
#include<GRAPHICS.H>
#include<STDLIB.H>
#include<DOS.H>

#include"./INCLUDE/MOUSE.H"
#include"./INCLUDE/BUTTON.H"

#include"./INCLUDE/INITIAL.H"
#include"./INCLUDE/SIGN_IN.H"
#include"./INCLUDE/LOGIN.H"
#include"./INCLUDE/MAIN_PAGE.H"
#include"./INCLUDE/MY_INFO.H"

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
        case 0:
            page = INITIAL();
            break;
        case 1:
            page = SIGN_IN();
            break;
        case 2:
            page = LOGIN(user_ID);
            break; 
        case 3:
            page = MAIN_PAGE(user_ID);
            break; 
        case 4:
            page = MY_INFO(user_ID);  
            break;
        default:
            break;
        }
    }

    closegraph();

}