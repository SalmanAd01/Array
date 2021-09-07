#include <stdio.h>
#define MAX_SIZE 100
int size;
void take_element(int arr[])
{
    printf("Enter the element in the array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display_element(int arr[])
{
    printf("Enter the element in the array is given by\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element is given by : %d\n", arr[i]);
    }
}
void insert_top(int arr[], int num)
{
    size++;
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = num;
}
void insert_bottom(int arr[], int num)
{
    arr[size] = num;
    size++;
}
void insert_index(int arr[], int index, int num)
{
    size++;
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = num;
}
int find_pos(int arr[], int num)
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
void insert_after_num(int arr[], int index, int num)
{
    int pos = find_pos(arr, index);
    if (pos == -1)
    {
        printf("Element not found");
    }
    else
    {
        insert_index(arr, pos + 1, num);
    }
}
int main()
{
    int choice;
    char ch;
    int arr[MAX_SIZE];
    int num, index;
    printf("Enter the size of the array\n");
    scanf("%d", &size);
    take_element(arr);
    do
    {
        printf("Enter 1 to display the element\nEnter 2 to insert the element at the top\nEnter 3 to insert the element at the bottom\nEnter 4 to insert the element at the index\nEnter 5 to insert the element after number\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_element(arr);
            break;
        case 2:
            printf("Enter the element\n");
            scanf("%d", &num);
            insert_top(arr, num);
            break;
        case 3:
            printf("Enter the element\n");
            scanf("%d", &num);
            insert_bottom(arr, num);
            break;
        case 4:
            printf("Enter the element and the index\n");
            scanf("%d %d", &num, &index);
            if(index > size){
                printf("Enter Valid Index\n");
            }
            else{
            insert_index(arr, index, num);
            }
            break;
        case 5:
            printf("Enter the element and the number\n");
            scanf("%d %d", &num, &index);
            insert_after_num(arr, index, num);
            break;
        default:
            printf("Enter the Valid number\n");
            break;
        }
        printf("Enter S to stop\n");
        scanf(" %c", &ch);
    } while (ch != 'S');

    return 0;
}
