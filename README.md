# LEETCODE刷题笔记

## 1.两数之和

题目关键：找到目标和为target的两个整数，即找出**是否存在**已经在集合中的配对数

**`Tag:`** `Hash`

```C++
    vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> hash;
        for(int i = 0;i < nums.size();i ++){
            int r = target - nums[i];//计算配对数 
            if(hash[r]) return {hash[r] - 1,i};//存在则返回
            else hash[nums[i]] = i + 1;
        }
        return {};
    }
```

## 2.两数相加

题目关键：如何去遍历两个数以及处理进位

**`Tag:`** `Linked-list`

```C++
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        auto dummy = new ListNode(-1),cur = dummy;
        int t = 0;
        while(l1 || l2 || t){
            if(l1) t += l1->val, l1 = l1->next;
            if(l2) t += l2->val, l2 = l2->next;
            cur = cur->next = new ListNode(t%10);
            t / 10;
        }
        return dummy->next;
    }
```

## 3.无重复的最长字串

题目关键：滑动窗口，即双指针一边前进一边统计，最长的长度不断更新，**强调无重复**

**`Tag:`** `sliding-window`

```C++
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> hash;
        int res = 0;
        for(int i = 0,j = 0;i < s.size();i++){
            hash[s[i]]++;//进入窗口
            while(hash[s[i]] > 1) hash[s[j++]]--;
            res = max(res,i - j + 1);
        }
        return res;
    }
```

## 4.寻找两个正序数组

题目关键：二分每次的数组为小于两个中位数中较小的数的，以及大于该数。因为小于该数的一定不是中位数，因此在搜索空间中去除，更新剩余的总数，并重新搜索

**`Tag:`** `binary-search` `divide-and-conquer`

```C++
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums)
    {
        int tot = nums1.size() + nums2.size();
        if(tot % 2 == 0){
            int left = find(nums1,0,nums2,0,tot/2);
            int right = find(nums,0,nums2,0,tot/2 + 1);
            return (left + right) / 2.0;
        }

    }
    int find(vector<int> &nums1,int i, vector<int> &nums2,int j,int k){
        if(nums1.size() - i > nums2.size() - j) return find(nums2,j,nums1,i,k);//保证前一个数组是较小的，便于判断哪个数组会是空的
        if(k == 1){
            if(nums1.size()==i)return nums2[j];
            else return min(nums1[i],nums2[j]);
        }
        if(nums1.size()==i) return nums2[j + k - 1];
        
        int si = min((int)nums1.size(),i + k / 2),sj = j + k/2;//指向中位数的前一个数
        if(nums1[si-1] > nums2[sj-1])//小于较小的中位数的数一定不是中位数
            return find(nums1,i,nums2,sj,k - (sj - j));//消去sj之前的数
        else 
            return find(nums1,si,nums2,j,k - (si - i));//消去si之前的数
    }
```

## 5.最长回文字符串

题目关键：定义题，按中心分类向两边探测即可

**`Tag:`** `string`

```C++
    string longestPalindrome(string s){
        string res;
        for(int i = 0;i < s.size();i++){
            int l = i - 1,r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++;
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);

            l = i ,r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++;
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
```

## 6.Z字形变换

题目关键：模拟题，在纸面上用下标模拟出来，找出规律即可，注意相同间隔同时循环的写法

**`Tag:`** `string`

```C++
    string convert(string s,int n){
        string res;
        if(n == 1) return s;
        for(int i  = 0;i < n;i ++ ){
            if(i == 0 || i == n - 1){//第一行后者最后一行
                for(int j = i;j < s.size();j += 2 * n - 2)
                    res += s[j];
            }
            else{
                for(int j = i,k = 2 * n - i - 2;j < s.size() || k < s.size();j += 2 * n - 2,k += 2 * n - 2)
                {
                    if(j < s.size()) res += s[j];
                    if(k < s.size()) res += s[k];
                }
            }
        }
        return res;
    }
```

## 7.整数反转

题目关键：取x的末尾的运算为%，消除x末尾的运算为/，将一个数x加到十进制的末尾的运算为r = r * 10 + x

**`Tag:`** `math`