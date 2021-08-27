#include<iostream>
#include<ncurses.h>
using namespace std;

int main(){
	setlocale(LC_ALL,"");
	initscr();
	start_color();
	init_pair(2,COLOR_RED,COLOR_BLACK);
	//cout << "Hellow \u25CF!\n";
	//printf("Hellow \u25CF!\n");
	int n=2;
	attrset(COLOR_PAIR(n));
	mvprintw(2,0,"Hellow \u270c!\n");
	getch();
	endwin();
	return 0;
}
