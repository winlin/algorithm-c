#include <stdio.h>

void quickSort(int *ary, int left, int right)
{
    if(left >= right) return;

    int hold = ary[left];
    int l = left;
    int r = right;
    while(l<r){
        while(l < r && ary[r]>=hold) --r;
        if(l<r)
            ary[l++] = ary[r];
        while(l < r && ary[l]<hold) ++l;
        if(l<r)
            ary[r--] = ary[l];

        ary[l] = hold;
    }
    quickSort(ary, left, l-1);
    quickSort(ary, l+1, right);
}

int main(void)
{
    int ary[] = {1,3,2,5,4,8,6,7,9,10};
    quickSort(ary, 0, 9);
    for(int i=0; i<10; ++i)
        printf("%d ", ary[i]);
    
    puts("");
    
    return 0;
}

