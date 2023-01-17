#include <stdio.h>
#include <string.h>

int count = 0;

int recursion(const char* s, int l, int r) {
    ++count;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    printf("%d ", recursion(s, 0, strlen(s) - 1));

    return count;
}

int main()
{
    int t;
    scanf_s("%d", &t);

    char str[1001];

    for (int i = 0; i < t; ++i)
    {
        count = 0;
        scanf_s("%s", str, sizeof(str));
        int result = isPalindrome(str);
        printf("%d", result);
    }

    return 0;
}