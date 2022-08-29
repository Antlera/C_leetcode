#include<stdio.h>

int mySqrt(int x)
{
    if (!x)
    {
        return 0;
    }
    double high = x;
    double low = 0;
    double middle;
    while (low <= high)
    {
        middle = low + (high - low) / 2;
        if (middle * middle > x)
        {
            high = middle;
        }
        else if (middle * middle < x)
        {
            low = middle;
        }
        if (fabs(middle * middle - x) < 0.05)
        {
            return (int)middle;
        }
    }
    return;
}
int main(){
    printf("%d", mySqrt(1));
}