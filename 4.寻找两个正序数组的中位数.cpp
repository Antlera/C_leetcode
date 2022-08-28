/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();//统计两个数组总数k
        if(tot%2 == 0){
            //若为偶数，则中位数为两数的平均数
            int left = find(nums1,0,nums2,0,tot/2);//找到k/2位置的数
            int right = find(nums1,0,nums2,0,tot/2+1);//找到k/2+1位置的数
            return (left+right)/2.0;//返回平均数
        }
        else{
            return find(nums1,0,nums2,0,tot/2+1);
        }
    }
    int find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)//i和j是消除指针,即现在数组的头从何处开始
    {
        if(nums1.size()-i > nums2.size()-j)return find(nums2,j,nums1,i,k);
        if(k == 1){//特判，已经是第一个数了
            if(nums1.size()==i)return nums2[j];//若第一个数组为空，则为第二个数组的首元素
            else return min(nums1[i],nums2[j]);//否则是按顺序两个数组中较小的
        }
        if(nums1.size()==i)return nums2[j + k - 1];
        int si = min((int)nums1.size(),i + k / 2),sj = j + k - k / 2;//指向k/2的下一个位置
        if(nums1[si-1] > nums2[sj-1])//小于较小的中位数一定不是中位数，因此可以消除
            return find(nums1,i,nums2,sj,k - (sj - j));//消去sj之前的数
        else 
            return find(nums1,si,nums2,j,k - (si - i));//消去si之前的数

    }
};
// @lc code=end

