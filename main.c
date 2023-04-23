#include "main.h"
#include <stdio.h>

int main(void)
{
    int len;

    len = _printf("Hello, world!\n");
    printf("Length: %d\n", len);

    len = _printf("Character: %c\n", 'H');
    printf("Length: %d\n", len);

    len = _printf("String: %s\n", "Hello");
    printf("Length: %d\n", len);

    len = _printf("Percent sign: %%\n");
    printf("Length: %d\n", len);

    return (0);
}
