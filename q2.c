#include <stdio.h>

int ropePieces(int rope){
	if(rope == 0) return 0;
	return 1 + ropePieces(rope - 1);
}

int main() {
	int cuts = ropePieces(32);
	printf("%d", cuts);
    return 0;
}