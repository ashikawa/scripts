#include <stdio.h>
#include <string.h>

#define FLAG_START	'S'
#define FLAG_GOAL		'G'
#define FLAG_WALL		'*'
#define FLAG_SPACE	' '
#define FLAG_STAMP	'+'

#define MAP_HEIGHT	255
#define MAP_WIDTH		255

char	map[MAP_HEIGHT][MAP_WIDTH];
unsigned int	lineNum = 0;
unsigned int	minStep = 0;

void	map_loader();
void	print_map();
void	run();
void	search(int x,int y,int step);


/**
 * 経路探索問題
 * @see http://okajima.air-nifty.com/b/2010/01/post-abc6.html
 */
int main(int argc, char *argv[])
{
	map_loader();
	run();
	return 0;
}

void run()
{
	int x = 0, y = 0;
	
	while( map[y][x] != EOF ){
		if( map[y][x] == '\n'){
			x = 0;
			y++;
		}
		
		if( map[y][x] == FLAG_START )	break;
		x++;
	}
	
	search(x, y, 0);
}

void search(int x, int y, int step)
{
	map[y][x] = FLAG_STAMP;
	
	if( (map[y+1][x] == FLAG_GOAL)
			|| (map[y-1][x] == FLAG_GOAL)
			|| (map[y][x+1] == FLAG_GOAL)
			|| (map[y][x-1] == FLAG_GOAL) ){
		
		if(minStep == 0){
			minStep = step;
			print_map();
		}else if( step < minStep ){
			minStep = step;
			print_map();
		}
		
		map[y][x] = FLAG_SPACE;
		return ;
	}
	
	if(minStep != 0){
		if( step > minStep ){
			map[y][x] = FLAG_SPACE;
			return ;
		}
	}
	
	if( map[y+1][x] == FLAG_SPACE ){
		search(x, y+1, step+1);
	}
	
	if( map[y-1][x] == FLAG_SPACE ){
		search(x, y-1, step+1);
	}
	
	if( map[y][x+1] == FLAG_SPACE ){
		search(x+1, y, step+1);
	}
	
	if( map[y][x-1] == FLAG_SPACE ){
		search(x-1, y, step+1);
	}
	
	map[y][x] = FLAG_SPACE;
}

void map_loader()
{
	int i=0;
	
	while( fgets(map[i++], sizeof map[i], stdin) );
	lineNum = i;
}


void print_map()
{
	int i = 0;
	while( i < lineNum ) printf("%s", map[i++]);
	printf("step %d,\n\n", minStep);
}

