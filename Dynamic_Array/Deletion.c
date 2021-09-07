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
int delete_top(int *arr){
    int val = arr[0];
    for (int i = 0; i < size -1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    arr=(int *)realloc(arr,size*sizeof(int));
    return val;
}
int delete_bottom(int *arr){
    int val=arr[size];
    size--;
    arr=(int *)realloc(arr,size*sizeof(int));
    return val;
}
int delete_index(int *arr,int index){
    int val = arr[index];
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    arr=(int *)realloc(arr,size*sizeof(int));
    return val;
}
int find_pos(int *arr,int num){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}
int delete_num(int *arr,int num){
    int temp = find_pos(arr,num);
    if (temp == -1)
    {
        printf("Number Not Found");
        return -1;
    }
    else{
        return delete_index(arr,temp);
    }
}
int main(){
    int num,index,choice;
    char ch;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    int *arr = (int *)malloc(size*sizeof(int));
    take_element(arr);
    do
    {
        printf("Enter 1 to display the element\nEnter 2 to  delete the element at the top\nEnter 3 to  delete the element at the bottom\nEnter 4 to  delete the element at the index\nEnter 5 to delete the element\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_element(arr);
            break;
        case 2:
            printf("Number deleted is %d\n",delete_top(arr));
            break;
        case 3:
            printf("Number deleted is %d\n",delete_bottom(arr));
            break;
        case 4:
            printf("Enter the index\n");
            scanf("%d",&index);
            if (index > size)
            {
                printf("Enter the valid index\n");
            }
            else
            {
                printf("Number deleted is %d\n",delete_index(arr ,index));
            }
            break;
        case 5:
            printf("Enter the number which you wanted to delete\n");
            scanf("%d", &num);
            printf("Number deleted is %d\n",delete_num(arr, num));
            break;
        default:
            printf("Enter the valid number\n");
            break;
        }
        printf("Enter S to stop\n");
        scanf(" %c", &ch);
    } while (ch != 'S');

    return 0;
}
