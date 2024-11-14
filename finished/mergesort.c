#include <stdio.h>
void merge(int arr[], int l, int m, int h)
{
    int i = l;
    int j = m + 1;
    int k = 0;

    int tempa[h - l + 1];

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            tempa[k] = arr[i];
            i++;
        }
        else
        {
            tempa[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        tempa[k] = arr[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        tempa[k] = arr[j];
        j++;
        k++;
    }

    for (int i = l; i <= h; i++)
    {
        arr[i] = tempa[i - l];
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int n;
    printf("ENTER THE SIZE OF ARRAY : ");
    scanf("%d", &n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF ARRAY : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("SORTED ARRAY : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}