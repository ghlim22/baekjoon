//
//  main.c
//  2750
//  https://www.acmicpc.net/problem/2750
//  수 정렬하기.
//  Created by 임규현 on 2022/07/08.
//

#include <stdio.h>

void sort(int arr[], int len);
void sort_recursive(int arr[], int temp[], int len, int start, int end);
void merge(int arr[], int temp[], int len, int start, int mid, int end);

int main(void)
{
    int n; // 수의 개수.
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, n);
    
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}

void sort(int arr[], int len)
{
    int temp[len];
    sort_recursive(arr, temp, len, 0, len - 1);
}

void sort_recursive(int arr[], int temp[], int len, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        sort_recursive(arr, temp, len, start, mid);
        sort_recursive(arr, temp, len, mid + 1, end);
        merge(arr, temp, len, start, mid, end);
    }
}

void merge(int arr[], int temp[], int len, int start, int mid, int end)
{
    for (int i = 0; i <= end; ++i)
    {
        temp[i] = arr[i];
    }
    
    int p_left = start;
    int p_right = mid + 1;
    int index = start;
    
    while (p_left <= mid && p_right <= end)
    {
        if (temp[p_left] < temp[p_right])
        {
            arr[index] = temp[p_left];
            p_left++;
        }
        else
        {
            arr[index] = temp[p_right];
            p_right++;
        }
        index++;
    }
    
    for (int i = 0; i <= mid - p_left; ++i)
    {
        arr[index + i] = temp[p_left + i];
    }
}


