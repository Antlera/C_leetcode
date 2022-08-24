/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start


int mySqrt(int x){
    if (!x)
{
    return 0;
}
if(x==1){
    return 1;
}
double high = x;
double low = 0;
double middle;
while (low <= high)
{
    middle = low + (high - low) / 2;
    if (middle*middle>x)
    {
        high = middle;
    }
    else if (middle*middle<x)
    {
        low = middle;
    }
    if (fabs(middle*middle-x)<0.05)
    {
        return (int)middle;
    }
}
return -1;
}
// @lc code=end


//tpye1
/*if (!x)
{
    return 0;
}
double high = x;
double low = 0;
double last = x;
double result = x;
while (1)
{
    if ((result * result) < x)
    {
        low = result;
        result = ((low + high) / 2);
    }
    else if ((result * result) > x)
    {
        high = result;
        result = ((low + high) / 2);
    }
    else
    {
        return (int)result;
    }

    if (fabs(result * result - x) < 0.05)
    {
        return (int)result;
    }
}
return;*/
