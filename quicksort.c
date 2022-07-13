#include <stdio.h>

void quicksort(int a[],int low,int high);
int split (int a[],int low,int high);

int main()
{
    int a[10], i;
    printf("Введите 10 чисел: ");
    for (i=0;i<10;i++)
    scanf ("%d",&a[i]);
    
    quicksort (a,0,9);
    
    printf ("В отсортированном порядке: ");
    for (i=0;i<9;i++)
    printf ("%d ", a[i]);
    printf ("\n");
    return 0;
}

void quicksort (int a[],int low,int high) {
    int middle;
    if(low>=high) return;
    middle=split(a,low,high);
    quicksort (a,middle+1,high);
    quicksort (a,low,middle-1);
}

int split (int a[],int low,int high) {
    int part_element=a[low];
    
    for (;;) {
        while (low<high&&part_element<=a[high]) 
            high--;
            if (low>=high) break;
            a[low]=a[high];
        
        while (low<high&&a[low]<=part_element)
            low++;
            if (low>=high) break;
            a[high]=a[low];
    }
    a[low]=part_element;
    return high;
}
