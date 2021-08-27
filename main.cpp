#include<iostream>
#include<ncurses.h>
#include"candy_crush.h"
#include"cool_map.h"
#include"spec_rule1.h"
#include"spec2.h"
#include"spec3.h"
#define levels_num 5
using namespace std;

int main(){
int option = 0;
int select;
bool go_on = TRUE;
	setlocale(LC_ALL, "");//allow unicode
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(10,COLOR_RED,COLOR_BLACK);
	init_pair(11,COLOR_BLACK,COLOR_WHITE);
	init_pair(1,COLOR_YELLOW,COLOR_BLACK);
	init_pair(2,COLOR_BLUE,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	init_pair(4,COLOR_RED,COLOR_BLACK);
	init_pair(5,COLOR_WHITE,COLOR_BLACK);
	init_pair(12,COLOR_BLUE,COLOR_WHITE);
	init_pair(14,COLOR_YELLOW,COLOR_RED);
	attrset(A_BOLD|COLOR_PAIR(10));
	mvaddstr(0,0,"Select map(Press up or down)");
	attrset(COLOR_PAIR(0));
	mvaddstr(1,0,"normal");
	mvaddstr(2,0,"tower");
	mvaddstr(3,0,"spec1");
	mvaddstr(4,0,"spec2");
	mvaddstr(5,0,"spec3");
	//add new map

	while(go_on){
		select = getch();
		switch(select){
			case KEY_UP: --option;
				if(option < 1) option = levels_num;
				 break;
			case KEY_DOWN: ++option;
				if(option > levels_num) option =1;
				break;
			case '\n':go_on=0;
				continue;
			default:continue; 
		}//switch
		mvaddstr(1,0,"normal  ");
		mvaddstr(2,0,"tower   ");
		mvaddstr(3,0,"spec1   ");
		mvaddstr(4,0,"spec2   ");
		mvaddstr(5,0,"spec3   ");
		//add new map
		attrset(COLOR_PAIR(11));
		mvaddstr(option,0,"Enter  ");
		attrset(A_NORMAL);
	}//while go_on==FALSE
	
	if(option == 1){
		erase();
		Game game_A;
		curs_set(2);
		game_A.map_generate();
		game_A.map_print();
		game_A.score_print();
		game_A.grid_print();
		mvaddstr(5+2*height,0,"Continue");
		getch();
		mvaddstr(5+2*height,0,"         ");
		game_A.eleminate_initial();
		if(game_A.control() == 1)
			mvaddstr(0,0,"WIN");
		else
			mvaddstr(0,0,"LOSE");
		getch();
		erase();
		endwin();
		return 0;
	}
	else if(option == 2){
		erase();
		COOL game_A;
		curs_set(2);
		game_A.map_generate();
		game_A.map_print();
		game_A.score_print();
		game_A.grid_print();
		mvaddstr(5+2*height,0,"Continue");
		getch();
		mvaddstr(5+2*height,0,"         ");
		game_A.eleminate_initial();
		if(game_A.control() == 1)
			mvaddstr(0,0,"WIN");
		else
			mvaddstr(0,0,"LOSE");
		getch();
		erase();
		endwin();
		return 0;
	}
	else if(option == 3){
		erase();
		spec game_A;
		curs_set(2);
		game_A.map_generate();
		game_A.map_print();
		game_A.score_print();
		game_A.grid_print();
		mvaddstr(5+2*height,0,"Continue");
		getch();
		mvaddstr(5+2*height,0,"         ");
		game_A.eleminate_initial();
		if(game_A.control() == 1)
			mvaddstr(0,0,"WIN");
		else
			mvaddstr(0,0,"LOSE");
		getch();
		erase();
		endwin();
		return 0;
	}
	else if(option == 4){
		erase();
		spec2 game_A;
		curs_set(2);
		game_A.map_generate();
		game_A.map_print();
		game_A.score_print();
		game_A.grid_print();
		mvaddstr(5+2*height,0,"Continue");
		getch();
		mvaddstr(5+2*height,0,"         ");
		game_A.eleminate_initial();
		if(game_A.control() == 1)
			mvaddstr(0,0,"WIN");
		else
			mvaddstr(0,0,"LOSE");
		getch();
		erase();
		endwin();
		return 0;
	}
	else if(option == 5){
		erase();
		spec3 game_A;
		curs_set(2);
		game_A.map_generate();
		game_A.map_print();
		game_A.score_print();
		game_A.grid_print();
		mvaddstr(5+2*height,0,"Continue");
		getch();
		mvaddstr(5+2*height,0,"         ");
		game_A.eleminate_initial();
		if(game_A.control() == 1)
			mvaddstr(0,0,"WIN");
		else
			mvaddstr(0,0,"LOSE");
		getch();
		erase();
		endwin();
		return 0;
	}
}
