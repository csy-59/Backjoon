#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char num[10] = "";
	while (1){
		scanf("%s", num);
		if (num[0] == '0')
			break;
		bool isPallindrom = true;
		for (int i = 0; i < strlen(num) / 2; ++i) {
			if (num[i] != num[strlen(num) - i - 1]) {
				isPallindrom = false;
				break;
			}
		}

		if (isPallindrom)
			printf("yes\n");
		else
			printf("no\n");
	}
}