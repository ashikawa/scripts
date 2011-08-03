/**
 *List 13-6
 */
#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILER 1

#define STATION_NUMBER 6
#define START_STATION 0

char* stations[]
           = {"横浜", "武蔵小杉", "品川", "渋田", "新橋", "溜池山王"};

int current_const[STATION_NUMBER];
int fix[STATION_NUMBER];

int adjacency_matrix[STATION_NUMBER][STATION_NUMBER] = {
		{0, 12, 28, 0, 0, 0},
		{12, 0, 10, 13, 0, 0},
		{28, 10, 0, 11, 7, 0},
		{0, 13, 11, 0, 0, 9},
		{0, 0, 7, 0, 0, 4},
		{0, 0, 0, 9, 4, 0},
	};

int main(int argc, char *argv[])
{
	int i, min_station, min_time, new_time;
	
	for(i=0; i < STATION_NUMBER; i++){
		current_const[i] = -1;
		fix[i] = 0;
	}
	
	current_const[0] = 0;
	
	
	for(;;){
		min_time = -1;
		for( i = 0; i < STATION_NUMBER; i++ ){
			if( fix[i] == 0 && current_const[i] != -1 ){
				if( min_time == -1 || min_time > current_const[i] ){
					min_time	= current_const[i];
					min_station	= i;
				}
			}
		}
		if(min_time == -1){
			break;
		}
		
		for( i=0; i < STATION_NUMBER; i++ ){
			if( fix[i] == 0
					&& adjacency_matrix[min_station][i] ){
				new_time = min_time + adjacency_matrix[min_station][i];
				
				if( current_const[i] == -1 || current_const[i] > new_time ){
					current_const[i] = new_time;
				}
			}
		}
		fix[min_station] = 1;
	}
	
	
	for( i=0; i < STATION_NUMBER; i++ ){
		printf("%s -> %s : %d min\n",
					stations[START_STATION], stations[i], current_const[i]);
	}
	
	return EXIT_SUCCESS;
}
