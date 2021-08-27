#include"spec_rule1.h"
#define SPEC_CANDY 100

spec::spec(){
	#undef MOVE
	#define MOVE 100
	x=11;y=5;//initial position
	movement_left = MOVE;//MOVE macro
}
void spec::map_generate(){
	srand(time(NULL));
	for(i=0;i<width;i++)
		for(j=0;j<height;j++)
			map[i][j] = rand()%5+1;//num of color
	for(i=0;i<3;i++)
		map[rand()%width][0] = SPEC_CANDY; // The candy for special rule
return;
}
void spec::grid_print(){
	for(j=0;j<=height*2;j+=2)
		for(i=0;i<=width*2-1;i++)
			mvprintw(j+4, i+10, "-");
	for(j=0;j<=width*2;j+=2)
		for(i=0;i<=height*2-1;i++)
			mvaddstr(i+4, j+10, "|");
}
void spec::map_print(){
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			candy_print(0,map[i][j]);
			//mvprintw(2*j+20,3*i+30,"%d ",map[i][j]);
		}
	}
}
void spec::candy_print(int image, int type){
	if(type == SPEC_CANDY){
		attrset(COLOR_PAIR(12));
		mvprintw(2*j+5,2*i+11,"\u2721");
		attrset(A_REVERSE|COLOR_PAIR(A_NORMAL));
	}
	else if(type > 5){
		attrset(COLOR_PAIR(type-5));
		mvprintw(2*j+5,2*i+11,"\u2720");}
	else{
		attrset(COLOR_PAIR(type));
		mvprintw(2*j+5,2*i+11,"\u2b24");//\u25cf
		}
		attrset(A_NORMAL);
	if(!type)
		mvprintw(2*j+5,2*i+11," ");
return;
}
void spec::eleminate_initial(){//check the map before moving
	int do_eleminate;
	while(do_eleminate = movement_check()){
	score += do_eleminate;
	score_print();
	map_fall();
	map_print();
	mvaddstr(5+2*height,0,"Continue");
	getch();//fill the empty after press something
	mvaddstr(5+2*height,0,"         ");
	map_refill();
	map_print();
	mvaddstr(5+2*height,0,"Continue");
	getch();
	mvaddstr(5+2*height,0,"         ");
	}
}
int spec::movement_check(){
	int local_score=0;
	int n;
	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			if(map[i][j] != SPEC_CANDY)
				local_score += column_eleminating(i);
		}
	}			
	for(j=0;j<height;j++){
		for(i=0;i<width;i++){
			if(map[i][j] != SPEC_CANDY)
				local_score += row_eleminating(j);
		}
	}
	return local_score;	
}
int spec::column_eleminating(int b){
	bool strong_candy=FALSE;
	int col_score = 0;
	int target;
	int m;
	int p;
	static int v = 0;
	if(!(target = map[b][j])) return 0;
	/*if((target == map[b][j+1] && target == map[b][j+2] && j+2<width) || \
	   (target == map[b][j+1] && target == map[b][j-1] && j+1<width && j-1>=0) || \
	   (target == map[b][j-1] && target == map[b][j-2] && j-2>=0)){*/
	if(((target == map[b][j+1] || 5+target == map[b][j+1]) && \
	    (target == map[b][j+2] || 5+target == map[b][j+2]) && j+2<height) || \
	   ((target == map[b][j+1] || 5+target == map[b][j+1]) && \
	    (target == map[b][j-1] || 5+target == map[b][j-1]) && j+1<height && j-1>=0) || \
	   ((target == map[b][j-1] || 5+target == map[b][j-1]) && \
	    (target == map[b][j-2] || 5+target == map[b][j-2]) && j-2>=0)){
		for(m=j;m<height;m++){
			if(map[b][m] == target){
				col_score += SCORE_PER;
				col_score += row_eleminating(m);
				map[b][m]=0;
			}
			else if(map[b][m] == target+5){
				strong_candy = TRUE;
				col_score += 5*SCORE_PER;
				col_score += row_eleminating(m);
				map[b][m]=0;
			}
			else break;
		}
		for(m=j-1;m>=0;m--){
			if(map[b][m] == target){
				col_score += SCORE_PER;
				col_score += row_eleminating(m);
				map[b][m]=0;
			}
			else if(map[b][m] == target+5){
				strong_candy=TRUE;
				col_score += 5*SCORE_PER;
				col_score += row_eleminating(m);
				map[b][m]=0;
			}
			else break;
		}
	}
	if(strong_candy){
		for(p=0;p<height;p++){
			if(map[b][p]){
				if(map[b][p] > 5)
					col_score += 5*SCORE_PER;
				else
					col_score += SCORE_PER;
				col_score += row_eleminating(p);
				map[b][p]=0;
			}
		}
	}
	else if(col_score > 3*SCORE_PER)
		map[b][j] = 5+target;
	return col_score;
}
int spec::row_eleminating(int a){
	bool strong_candy = FALSE;
	int row_score = 0;
	int target;
	int l;
	int p;
	static int v=0;
	if(!(target = map[i][a])) return 0;
	/*if((target == map[i+1][a] && target == map[i+2][a] && i+2<width) || \
	   (target == map[i+1][a] && target == map[i-1][a] && i+1<width && i-1>=0) || \
	   (target == map[i-1][a] && target == map[i-2][a] && i-2>=0)){*/
	if(((target == map[i+1][a] || 5+target == map[i+1][a]) && \
	    (target == map[i+2][a] || 5+target == map[i+2][a]) && i+2<height) || \
	   ((target == map[i-1][a] || 5+target == map[i-1][a]) && \
	    (target == map[i+1][a] || 5+target == map[i+1][a]) && i+1<height && i-1>=0) || \
	   ((target == map[i-1][a] || 5+target == map[i-1][a]) && \
	    (target == map[i-2][a] || 5+target == map[i-2][a]) && i-2>=0)){
		for(l=i;l<width;l++){
			if(map[l][a] == target){
				row_score+=SCORE_PER;
				map[l][a]=0;
			}
			else if(map[l][a] == 5+target){
				strong_candy = TRUE;
				row_score+=5*SCORE_PER;
				map[l][a]=0;
			}
			else break;
		}
		for(l=i-1;l>=0;l--){
			if(map[l][a] == target){
				row_score+=SCORE_PER;
				map[l][a]=0;
			}
			else if(map[l][a] == 5+target){
				strong_candy = TRUE;
				row_score+=5*SCORE_PER;
				map[l][a]=0;
			}
			else break;
		}
	}
	if(strong_candy){
		for(p=0;p<width;p++){
			if(map[p][a]){
				if(map[p][a] > 5)
					row_score += 5*SCORE_PER;
				else
					row_score += SCORE_PER;
				map[p][a]=0;
			}
		}
	}
	else if(row_score > 3*SCORE_PER)
		map[i][a] = 5+target;
	return row_score;
}
void spec::map_fall(){
	int n,m;
	int memo[height] = {0};
	for(i=0;i<width;i++){
		n = height-1;
		for(j=height-1;j>=0;j--){
			if(map[i][j])
				memo[n--] = map[i][j];	
		}
		for(n=0;n<height;n++){
			map[i][n] = memo[n];
			memo[n] = 0;
		}
	}
}
void spec::map_refill(){
	for(i=0;i<width;i++)
		for(j=0;j<height;j++)
			if(!map[i][j])
				map[i][j] = rand()%5+1;
}
void spec::score_print(){
	int m;
	int n=score/100;
	if(score > SCORE_WIN) n = SCORE_WIN/100;
	for(m=4;m<2*height+4;m++)
		mvaddstr(m,6,"[ ]");
	attrset(A_REVERSE|COLOR_PAIR(3));
	for(m=2*height+3;m>(23-n);m--)
		mvaddstr(m,7," ");
	attrset(A_NORMAL);
	mvprintw(3,6,"Score:%3d/%d",score,SCORE_WIN);
	mvprintw(2,5,"Move left:%3d", movement_left);
	mvprintw(5,24,"Still %d   exist", spec_search("all"));
	attrset(COLOR_PAIR(12));
	mvprintw(5,32,"\u2721");
	attrset(A_NORMAL);
	mvprintw(6,24,"Drop them to the ground or eliminate them with \u2720");
	mvprintw(7,24,"You can NOT move them or eliminate them in other ways");
	attrset(A_NORMAL);
	mvprintw(12,24,"Press F to select");
	mvprintw(13,24,"Press E to quit");
}
int spec::control(){
	static bool Hold;
	static int hold_x,hold_y;
	int do_eleminate;
	int c;
	bool go_on = TRUE;
	bool validation = FALSE;
	while(go_on){
		move(y,x);
		c = getch();
		switch(c){
			case KEY_LEFT:  if(y!=hold_y-2 && y!=hold_y+2)x-=2;break;
			case KEY_RIGHT: if(y!=hold_y-2 && y!=hold_y+2)x+=2;break;
			case KEY_UP:    if(x!=hold_x-2 && x!=hold_x+2)y-=2;break;
			case KEY_DOWN:  if(x!=hold_x-2 && x!=hold_x+2)y+=2;break;
			case 'd': grid_print();map_print();break;
			case 'e': go_on=FALSE;break;
			case 'r': map_generate();
				  movement_left=MOVE;
				  score=0;
				  score_print();
				  map_print();
				  mvprintw(5+2*height,0,"Restart");
				  getch();
				  eleminate_initial();
				  break;
			case 'f': if(!Hold && map[(x-11)/2][(y-5)/2] != SPEC_CANDY){
				 	hold_x=x;
				  	hold_y=y;
				  	Hold=TRUE;
					attrset(A_REVERSE|A_BLINK|COLOR_PAIR(map[(x-11)/2][(y-5)/2]));
					if(map[(x-11)/2][(y-5)/2] > 5)
						mvprintw(y,x,"\u2720");
					else
						mvprintw(y,x,"\u2b24");
					attrset(A_NORMAL);
				}	
				else if(x == hold_x && y == hold_y){
					hold_x=0;hold_y=0;
					Hold=FALSE;
					map_print();
				}
				else{
					k = map[(x-11)/2][(y-5)/2];
					if(k == SPEC_CANDY){
						mvaddstr(5+2*height,0,"You can't move that");
						getch();
						mvaddstr(5+2*height,0,"                   ");
						break;
					}
			  		map[(x-11)/2][(y-5)/2] = map[(hold_x-11)/2][(hold_y-5)/2];
					map[(hold_x-11)/2][(hold_y-5)/2] = k;
					Hold = FALSE;
					map_print();
					while(do_eleminate = movement_check()){
					validation = TRUE;
					score += do_eleminate;
					score_print();
					map_fall();
					map_print();
					mvaddstr(5+2*height,0,"Continue");
					getch();//fill the empty after press something
					mvaddstr(5+2*height,0,"         ");
					map_refill();
					map_print();
					mvaddstr(5+2*height,0,"Continue");
					getch();
					mvaddstr(5+2*height,0,"         ");
					}
					if(validation){//valid move
						movement_left--;
						score_print();
						validation = FALSE;
					}
					else if(!validation){//invalid
						mvaddstr(5+2*height,0,"invalid movement!");
						getch();
						mvaddstr(5+2*height,0,"                 ");
						map[(hold_x-11)/2][(hold_y-5)/2] = map[(x-11)/2][(y-5)/2];
						map[(x-11)/2][(y-5)/2] = k;
						map_print();
					}
					hold_x=0;hold_y=0;
				}
				 	//mvprintw(5,30,"HOLD coord (%d,%d)", hold_x,hold_y);
				  	//mvprintw(6,30,"HOLD value %d", map[(hold_x-11)/2][(hold_y-6)/2]);
				break;
		}
		if(x<10) x+=2;
		if(x>=10+width*2) x-=2;
		if(y<5) y+=2;
		if(y>=5+height*2) y-=2;
		if(Hold && x>hold_x+2) x-=2;
		if(Hold && x<hold_x-2) x+=2;
		if(Hold && y>hold_y+2) y-=2;
		if(Hold && y<hold_y-2) y+=2;
		if(score >= SCORE_WIN && spec_search("bott") == spec_search("all")) return 1;//win
		else if(movement_left <= 0) return 2;//lose
	}
}
int spec::spec_search(string a){//bott or all
	int n;
	if(a == "bott"){
		for(i=0;i<width;i++)
			if(map[i][height-1] == SPEC_CANDY)
				n++;
	}
	if(a == "all"){
		for(i=0;i<width;i++)
			for(j=0;j<height;j++)
				if(map[i][j] == SPEC_CANDY)
					n++;
	}
	return n;
}
		
