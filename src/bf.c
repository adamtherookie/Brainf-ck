#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char tape[30000] = {0};
unsigned char* ptr = tape;

void interpret(char* input) {
    char current_char;
    size_t i;
    size_t loop;

    for (i = 0; input[i] != 0; i++) {
        current_char = input[i];
        if (current_char == '>') {
            ++ ptr;
        } else if (current_char == '<') {
            -- ptr;
        } else if (current_char == '+') {
            ++ *ptr;
        } else if (current_char == '-') {
            -- *ptr;
        } else if (current_char == '.' ) {
            putchar(*ptr);
        } else if (current_char == ',') {
            *ptr = getchar();
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && *ptr) {
            loop = 1;
            while (loop > 0) {
                current_char = input[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        }
    }
}

int main(void) {
	// Prompt loop
	while(1) {
		char *input = malloc(sizeof(char) * 100);
		printf(">>> ");
		scanf("%s", &(*input));
		
		if (strcmp(input, "exit") == 0) exit(0);

		interpret(input);
		printf("\n");
	}
}
