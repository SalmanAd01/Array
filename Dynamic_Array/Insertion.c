#include <stdio.h>
#include <stdlib.h>
int size;
void take_element(int *arr)
{
    printf("Enter the element in the array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display_element(int *arr)
{
    printf("Elements in the arrays is given by\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element is : %d\n", arr[i]);
    }
}
void inseret_top(int *arr, int num)
{
    size++;
    arr = (int *)realloc(arr, (size) * sizeof(int));
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = num;
}
void inseret_bottom(int *arr, int num)
{
    arr = (int *)realloc(arr, (size) * sizeof(int));
    arr[size] = num;
    size++;
}
void inseret_index(int *arr, int num, int index)
{
    size++;
    arr = (int *)realloc(arr, (size) * sizeof(int));
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = num;
}
int find_pos(int *arr, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}
void inseret_after_num(int *arr, int num, int index)
{
    int temp = find_pos(arr, index);
    if (temp == -1)
    {
        printf("Number Not Found\n");
    }
    else
    {
        inseret_index(arr, num, temp + 1);
    }
}
int main()
{
    int num, choice, index;
    char ch;
    printf("Enter the size of the array\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    take_element(arr);
    display_element(arr);
    do
    {
        printf("Enter 1 to disply the element\nEnter 2 to inseret the element at the top\nEnter 3 to inseret the element at the bottom\nEnter 4 to inseret the element at the given index\nEnter 5 to inseret the element after the given number\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_element(arr);
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d",&num);
            inseret_top(arr, num);
            break;
        case 3:
            printf("Enter the number\n");
            scanf("%d",&num);
            inseret_bottom(arr, num);
            break;
        case 4:
            printf("Enter the number and the index\n");
            scanf("%d %d",&num,&index);
            if (index > size)
            {
                printf("Enter the valid index\n");
            }
            else
            {
            inseret_index(arr,num,index);
            }
            break;
        case 5:
            printf("Enter the number and the Element after which you wanted to inseret the element\n");
            scanf("%d %d", &num,&index);
            inseret_after_num(arr,num,index);
            break;
        default:
            printf("Enter the valid number\n");
            break;
        }
        printf("Enter S to stop\n");
        scanf(" %c",&ch);
    } while (ch != 'S');

    return 0;
}
