#include <stdio.h>
#include <stdlib.h>

struct human {
    char name[20];
    float weight;
    int height;
};

int main()
{
    struct human list[5];
    for(int i = 0; i < 5; i++)
    {
        scanf("%s", list[i].name);
    }


    for(int i = 0; i < 5; i++)
    {
        printf("%s", list[i].name);
    }

    return 0;
}
