#include <stdio.h>

int binary(int *ary, int value, int start, int end)
{
    printf("start=%d  end=%d\n", start, end);
    if(start>end)
        return -1;
    int tmid = (start+end)/2;
    if(ary[tmid] == value) 
        return tmid;
    else if(ary[tmid] < value)
        return binary(ary, value, tmid+1, end);
    else if(ary[tmid] > value)
        return binary(ary, value, start, tmid-1);
}

int searchBin(int *ary, int value, int start, int end)
{
    int index = -1;
    int mid = (start+end)/2;
    int left = start;
    int right = end;

    while(left <= right) {
        mid = (left + right)/2;
        if(ary[mid] == value)
            return mid;
        else if(ary[mid] < value){
            left = mid + 1;
        } else if(ary[mid] > value) {
            right = mid - 1;
        }
    }

    return index;
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int index = binary(array, 9, 0, 9);
    printf("index=%d\n", index);

    index = searchBin(array, 1, 0, 9);
    printf("index=%d\n", index);
    return 0;
}
