#include "myselect.h"

/*
 * Precondition: At least one element exists
 * Postcondition: The elements are pritned to the screen
 */

void show_elems(){
	int i;
	int x = 0;
	int y = 0;
	int max = 0;

	ioctl(0, TIOCGWINSZ, &(gl_env.win));
	gl_env.flag = 0;
	term_clear();

	for(i = 0; i < gl_env.nbelems; i++){
		if(y >= gl_env.win.ws_row){
			y = 0;
			x += max + 5;
			max = 0;
		}
		if(max < gl_env.elements[i].size){
			max = gl_env.elements[i].size;
		}
		if(x + max >= gl_env.win.ws_col){
			term_clear();
			my_str("Window too small, Please resize!");
			gl_env.flag = 1;
			break;
		}
		gl_env.elements[i].x = x;
		gl_env.elements[i].y = y;
		refreshout(i);
		if(!gl_env.flag)
		{
			refreshin();
		}
		y++;
	}
}