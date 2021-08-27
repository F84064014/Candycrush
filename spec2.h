#include<iostream>
#include<vector>
#include<time.h>
#include<ncurses.h>
#include<unistd.h>
#include<string>
#define width 5
#define height 10
#define SCORE_PER 10
#define MOVE 20
#define SCORE_WIN 2000
using namespace std;

class spec2{
	public:
		spec2();
		void map_generate();
		void grid_print();
		void map_print();
		void candy_print(int image, int type);
		void eleminate_initial();//check the map before moving
		int movement_check();
		int column_eleminating(int b);
		int row_eleminating(int a);
		void map_refill();
		void map_fall();
		void score_print();
		int control();
	private:
		int map[20][20]={0};
		int i,j,k;
		int score;
		int x,y;
		int movement_left;
};
