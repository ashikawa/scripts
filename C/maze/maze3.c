#include <stdio.h>

#define FLAG_START	'S'
#define FLAG_GOAL		'G'
#define FLAG_WALL		'*'
#define FLAG_SPACE	' '
#define FLAG_STAMP	'+'

#define MAP_HEIGHT	255
#define MAP_WIDTH		255

#define MAX_STEP		1000

char	map[MAP_HEIGHT][MAP_WIDTH];
int	stepMap[MAP_HEIGHT][MAP_WIDTH];

unsigned int	lineNum = 0;
unsigned int	minStep = MAX_STEP;

void	map_loader();
void	print_map();
void	search(int x,int y,int step);


/**
 * 経路探索問題
 * @see http://okajima.air-nifty.com/b/2010/01/post-abc6.html
 */
int main(int argc, char *argv[])
{
	map_loader();
	
	int i,j;
	for( i = 0; i < MAP_HEIGHT; i++ ){
		for( j = 0; j < MAP_WIDTH; j++ ){
			stepMap[i][j]	= -1;
		}
	}
	
	int x = 0, y = 0;
	 
	while( map[y][x] != EOF ){
		if( map[y][x] == '\n'){
			x = 0;
			y++;
		}
		
		if( map[y][x] == FLAG_START ) break;
		x++;
   }
	
	map[y][x] = FLAG_SPACE;
	search(x, y, 0);

	return 0;
}

void search(int x, int y, int step)
{

	if( stepMap[y][x] < 0){
		stepMap[y][x]	= step;
	}else if( stepMap[y][x] > step){
		stepMap[y][x]	= step;
	}else{
		return;
	}
	
	if( (map[y][x] == FLAG_GOAL) ){
		
		if( step < minStep ){
			minStep = step;
			print_map();
		}
		
		return ;
	}
	if( map[y][x] == FLAG_SPACE ){
		
		step++;

//		printf("\033[2J");
//		print_map();
//		sleep(1);
		
		if( step >= minStep ){
			return ;
		}
		
		map[y][x] = FLAG_STAMP;
		
		search(x, y+1, step);
		search(x+1, y, step);
		search(x, y-1, step);
		search(x-1, y, step);
		
		map[y][x] = FLAG_SPACE;
	}
}

void map_loader()
{
	int i = 0;
	while( fgets(map[i++], sizeof map[i], stdin) );
	lineNum = i;
}

void print_map()
{
	int i = 0;
	while( i < lineNum ) printf("%s", map[i++]);
	printf("step %d,\n\n", minStep);
}

