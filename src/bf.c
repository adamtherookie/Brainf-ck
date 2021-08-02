#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	// Prompt loop
	while(1) {
		char *input = malloc(sizeof(char) * 100);
		printf(">>> ");
		scanf("%s", &(*input));
		
		if (strcmp(input, "exit") == 0) exit(0);
	}
}
