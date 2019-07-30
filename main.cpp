/*
 * make by chogahui05
 * https://www.acmicpc.net/source/share/f44596b18d0b41d098cdf25f6918cf35
 */

#include <stdio.h>
#include <stdlib.h>
int arr[1000000];
void merge_sort(int *arr,int le,int ri);
void insert_sort(int *arr,int le,int ri);
void conquer(int *arr,int left_s,int left_e,int right_s,int right_e);
int main(void)
{
    int n; scanf("%d\n",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&(arr[i]));
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    return 0;
}
void merge_sort(int *arr,int le,int ri)
{
    int mid = (le+ri)/2;
    if(le == ri)
        return;
    if(ri-le<=31)
    {
        insert_sort(arr,le,ri);
        return;
    }
    merge_sort(arr,le,mid);
    merge_sort(arr,mid+1,ri);
    conquer(arr,le,mid,mid+1,ri);
}
void insert_sort(int *arr,int le,int ri)
{
    for(int i=le+1;i<=ri;i++)
    {
        for(int j=i-1;j>=le;j--)
        {
            if(arr[j]<=arr[j+1])
                break;
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
void conquer(int *arr,int left_s,int left_e,int right_s,int right_e)
{
    int *brr = (int *)malloc(sizeof(int)*(right_e-left_s+1));
    int le = left_s; int ri = right_s; int p = 0;
    for(;le<=left_e&&ri<=right_e;)
    {
        if(arr[le]<=arr[ri])
            brr[p++] = arr[le++];
        else
            brr[p++] = arr[ri++];
    }
    while(le<=left_e)
        brr[p++] = arr[le++];
    while(ri<=right_e)
        brr[p++] = arr[ri++];
    for(int i=0;i<p;i++)
        arr[i+left_s] = brr[i];
    free(brr);
}