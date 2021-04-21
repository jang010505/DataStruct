#include <stdio.h>

#define WHITE 0
#define BLACK 1
#define YELLOW 2
#define WIDTH 10
#define HEIGHT 10

int screen[HEIGHT][WIDTH];

int read_screen(int x, int y){
	return screen[x][y];
}

void write_screen(int x, int y, int target){
	screen[x][y] = target;
}

void flood_fill(int x, int y){
	if(0 <= x && x < HEIGHT && 0 <= y && y < WIDTH){
		if(read_screen(x, y) == WHITE){
			write_screen(x, y, BLACK);
			flood_fill(x - 1, y);
			flood_fill(x, y - 1);
			flood_fill(x + 1, y);
			flood_fill(x, y + 1);
		}
	}
}

int main(){
	int x, y;
	flood_fill(0, 0);
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			printf("%d ", read_screen(i, j));
		}
		printf("\n");
	}
	return 0;
}
