#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int arr[50];

int main(void) {
  char *line = NULL;
  size_t size = 0;

  size_t read = getline(&line, &size, stdin);
  char *nptr = line;
  char *endptr;
  char preceding_operator = '\0';
  int arr_size = 0;

  while (nptr < line + read) {
	int num = strtol(nptr, &endptr, 10);
	switch (preceding_operator) {
		case '\0':
		case '-':
			arr[arr_size++] = num;
			break;
		case '+':
			arr[arr_size - 1] += num;
			break;
	}
	preceding_operator = *endptr;
	nptr = endptr + 1;
  }

  int answer = arr[0];
  for (int i = 1; i < arr_size; ++i) {
    answer -= arr[i];
  }

  printf("%d\n", answer);

  free(line);

  return 0;
}