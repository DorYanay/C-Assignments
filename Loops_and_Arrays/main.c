#include <stdio.h>
#include "my_mat.h"

int main()
{
    int mat[SIZE][SIZE];
    char input = 'l';
    int i, j;
    while (input != 'D')
    {
        scanf("%c", &input);
        switch (input)
        {
        case 'A':
            A(mat);
            break;

        case 'B':
            scanf("%d", &i);
            scanf("%d", &j);
            B(mat, i, j);
            break;

        case 'C':
            scanf("%d", &i);
            scanf("%d", &j);
            C(mat, i, j);
            break;
        }
    }
    return 0;
}