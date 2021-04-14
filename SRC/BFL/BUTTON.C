#include<STDIO.H>
#include<GRAPHICS.H>
#include<STDLIB.H>
#include<DOS.H>
#include"INCLUDE/GENERAL.H"
#include"INCLUDE/BUTTON.H"
#include"INCLUDE/MOUSE.H"
#include"INCLUDE/CHN.H"


void BFL_button_draw(BFL_button* buttonPtr)
{  if(buttonPtr->reDraw_status == RESET)
    {
        return;
    }
    else
    {
        buttonPtr->reDraw_status = RESET;
        
        switch(buttonPtr->status)
        {
            case REST:
                if(buttonPtr->is_shadow_enable == SET)
                {
                    setfillstyle(SOLID_FILL,buttonPtr->color_shadow);
                    bar(buttonPtr->position_shadow_left,buttonPtr->position_shadow_top,buttonPtr->position_shadow_right,buttonPtr->position_shadow_bottom);
                }
                setfillstyle(SOLID_FILL,buttonPtr->color_rest);
    			bar(buttonPtr->position_left,buttonPtr->position_top,buttonPtr->position_right,buttonPtr->position_bottom);
                CHN_print(  buttonPtr->position_text_left,
                            buttonPtr->position_text_top,
                            buttonPtr->display_text,
			                buttonPtr->text_size,
                            buttonPtr->color_text
                        );
                break;
            case HOVER:
               if(buttonPtr->is_shadow_enable == SET)
                {
                    setfillstyle(SOLID_FILL,buttonPtr->color_shadow);
                    bar(buttonPtr->position_shadow_left,buttonPtr->position_shadow_top,buttonPtr->position_shadow_right,buttonPtr->position_shadow_bottom);
                }
                setfillstyle(SOLID_FILL,buttonPtr->color_hover);
    			bar(buttonPtr->position_left,buttonPtr->position_top,buttonPtr->position_right,buttonPtr->position_bottom);
                CHN_print(  buttonPtr->position_text_left,
                            buttonPtr->position_text_top,
                            buttonPtr->display_text,
                            buttonPtr->text_size,
			                buttonPtr->color_text
                        );
                break;
        }
        
        
        
    }
   
}
  

void BFL_button_action(BFL_button* buttonPtr)
{
	if(MouseX > buttonPtr->position_left 
	&&MouseX < buttonPtr->position_right
	&&MouseY > buttonPtr->position_top
	&&MouseY < buttonPtr->position_bottom
	&&press == 1)
	{
		if(buttonPtr->status != PRESS)
        {
            buttonPtr->reDraw_status = SET;
        }
        buttonPtr->status = PRESS;
	}
	
	else if(MouseX > buttonPtr->position_left 
	&&MouseX < buttonPtr->position_right
	&&MouseY > buttonPtr->position_top
	&&MouseY < buttonPtr->position_bottom
	&&press == 0)
	{
        if(buttonPtr->status != HOVER)
        {
            buttonPtr->reDraw_status = SET;
        }
		buttonPtr->status = HOVER;
	}
	
	else
	{
         if(buttonPtr->status != REST)
        {
            buttonPtr->reDraw_status = SET;
        }
		buttonPtr->status = REST;
    }
}

