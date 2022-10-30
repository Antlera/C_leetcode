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

```C++
    int reverse(int x){
        int r = 0;
        while(x){
            if(r > 0 && r > (INT_MAX - x % 10) / 10)
                return 0;
            if(r < 0 && r < (INT_MIN - x % 10) / 10)
                return 0;
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
```

## 8.字符串转换整数(atoi)

题目关键：模拟题

**`Tag:`** `math` `string`

```C++
    int myAtoi(string s){
        int k = 0;
        while(k < s.size() && s[k] == ' ') k ++;
        if(k == s.size()) return 0;
        int minus = 1;//用整数1表示正负号
        if(s[k] == '-') minus = -1 , k++;
        else if(s[k] == '+') k++;

        long long res = 0;
        while(k < s.size() && s[k] >= '0' && s[k] <= '9')
        {
            int x = s[k] - '0';
            if(minus > 0 && res > (INT_MAX - x) / 10) return INT_MAX;
            if(minus < 0 && -res < (INT_MIN + x) / 10) return INT_MIN;
            res = res * 10 + x;
            k ++;
            if(res > INT_MAX) break;
        }
        res *= minus;
        return res;
    }
```

## 9.回文数

题目关键：模拟题，将数字处理倒转即可，可以字符串处理也可数字处理

**`Tag:`** `math` `string`

```C++
    bool isPalindrome(int x){
        if(x < 0) return false;
        long long res = 0;
        int t = x;
        while(x){
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == t;
    }
```

## 10.正则表达式匹配

题目关键：动态规划，根据结尾的字符划分集合。即 . ,* ,字符，匹配的转移即可得出

**`Tag:`** `dynamic-progamming` `string`

```C++
    bool isMatch(string s,string p){
        int n = s.size(),m = s.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n+1,vector<bool>(m+1));
        f[0][0] = true;
        for(int i = 0;i <= n;i++) //能够匹配字符的个数从0到n
            for(int j = 1;j <= m;j++)
            {
                if(j + 1 <= m && p[j + 1] == '*') continue;
                if(i && p[j] != '*')
                    f[i][j] = f[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                else if (p[j] == '*')
                {
                    for(int k = 0;k <= i;k ++){
                        //若能匹配较长串肯定能匹配较短串，因此从长串开始匹配，直到匹配到一个能匹配的，但是较短串能匹配较长串不一定能匹配
                        f[i][j] = (f[i][j] || f[i - 1][j - 2]);
                        if(f[i][j])
                            for(int l = 0;l < k;l++)
                                f[i][j] = f[i][j] && (s[i - l] == p[j - 1] || p[j - 1] == '.');
                    }
                }
            }
        return f[n][m]; 
    }
```

## 11.盛最多水的容器

题目关键：如果暴力求解是循环遍历两遍数组，是O(n^2)的复杂度。利用双指针可以减到O(n)的复杂度，双指针的移动搜索需要单调性，在这里的单调性是若较大边想内移动一定是不能找到更大的容器的，因此在移动较小边的搜索空间中进行搜索

**`Tag:`** `two-pointer`

```C++
    int maxArea(vector<int> &h){
        int res=0;
        for(int i = 0,j = h.size() - 1;i < j;)
        {
            res = max(res,(j - i) * min(h[i],h[j]));
            if(h[i] > h[j]) j --;
            else i ++;
        }
        return res;
    }
```

## 12.整数转罗马数字

题目关键：由于罗马数字实际上可以视作一个一个字符块单位组成的相加组合，因此在分解时只需要按照从大到小去分解成对应单位块即可

**`Tag:`** `math` `string`

```C++
    string intToRoman(int num){
        int values[] = {
            1000,
            900,500,400,100,
            90,50,40,10,
            9,5,4,1
        };
        string unit[] = {
            "M",
            "CM","D","CD","C",
            "XC","L","XL","X",
            "IX","V","IV","I"
        };
        string res;
        for(int i = 0;i <= 12;i++){
            while(num >= values[i]){
                res += unit[i];
                num -= values[i];
            }
        }
        return res;
    }
```

## 13.罗马数字转整数

题目关键：与整数转罗马数字相同，罗马数字转整数可以通过字母累加值来完成，遇到下一个比前一个大的减去对应值即可

**`Tag:`** `math` `string`

```C++
    int romanToInt(string s){
        unordered_map<char,int> hash;
        hash['I'] = 1,hash['V'] = 5,
        hash['X'] = 10,hash['L'] = 50,
        hash['C'] = 100,hash['D'] = 500,
        hash['M'] = 1000;
        int res = 0;
        for(int i = 0;i < s.size();i++){
            if(i + 1 < s.size() && hash[s[i]] < hash[s[i+1]]) res -= hash[s[i]];
            else res += hash[s[i]];
        }
        return res;
    }
```

## 14.最长公共前缀

题目关键：简单模拟题，每次取出第一个字符串的字符与后面的字符进行比较

**`Tag:`** `string`

```C++
    string longestCommonPrefix(vector<string> & strs){
        string res;
        if(strs.empty())return res;
        for(int i = 0;;i++){
            char c = strs[0][i];
            for(auto str: strs){
                if(i >= str.size() || str[i] != c) return res;
            }
            res += c;
        }
    }
```

## 15.三数之和

题目关键：双指针算法，由于实际上有三数，其中一个数是简单遍历，注意去重。注意k-1的探测，而不是判断k当前位置

**`Tag:`** `two-pointer`

```C++
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++)
        {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1,k = nums.size() - 1;j < k;j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                while(j < k - 1 && nums[i] + nums[j] + nums[k-1] >= 0) k--;//右指针移动法则，找到第一个大于等于的，即收缩搜索范围
                if(nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return res;
    }
```

## 16.最接近的三数之和

题目关键：与三数之和相同也是双指针算法，不过这次是要判断接近程度，也就是说，找到的组合会在target的右边(>=)也有可能在左边，找到大于等于的第一个往右边看看即可

**`Tag:`** `two-pointer`

```C++
    int threeSumClosest(vector<int>& nums,int target){
        sort(nums.begin(),nums.end());
        pair<int,int> res(INT_MAX,INT_MAX);
        for(int i = 0;i < nums.size();i++)
            for(int j = i + 1,k = nums.size() - 1;j < k;j++)
            {
                while(k - 1 > j && nums[i] + nums[j] + nums[k-1] >= target) k --;
                int s = nums[i] + nums[j] + nums[k] ;
                res = min(res,make_pair(abs(target - s),s));
                if(k - 1 > j) s = nums[i] + nums[j] + nums[k - 1],
                res = min(res,make_pair(abs(target - s),s));
            }
        return res.second;
    }
```

## 17.电话号码的字母组合

题目关键：dfs暴搜，注意模拟处理按键，用数组下标对应对应数字

**`Tag:`** `string` `backtracking`

```C++
    string strs[10] = {
        "","","abc","def",
        "ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };
    void dfs(string& digits,int u,string path){
        if(u == digits.size()) res.push_back(path);
        else
            for(auto c: strs[digits[u] - '0']){
                dfs(digits,u+1,path+c);
            }
    }
    vector<string> letterCombination(string digits){
        if(string.empty()) return res;
        dfs(digits,0,"");
        return res;
    }
```

## 18.四数之和

题目关键：参考三数之和，前两重循环遍历，后部双指针移动

**`Tag:`** `two-pointer`

```C++
    vector<vector<int>> fourSum(vector<int>& nums,int target){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++)
        {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1;j < nums.size();j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                for(int k = j + 1,u = nums.size() - 1;k < u;k ++) 
                {
                    if(k > j + 1 && nums[k] == nums[k - 1]) continue;
                    while(u - 1 > k && (long)nums[i] + nums[j] + nums[k] + nums[u - 1] >= target) u --;
                    if((long)nums[i]+ nums[j] + nums[k] + nums[u] == target) res.push_back({nums[i], nums[j], nums[k], nums[u]});
                }
            }
        }
        return res;
    }
```

## 19. 删除链表的倒数第N个结点

题目关键：遍历链表用指针数组添加下标，则可以直接找到倒数第N个结点

**`Tag:`** `linked-list`

```C++
    ListNode* removeNthFromEnd(ListNode* head,int n)
    {
        ListNode* Nodes[35];
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy,Nodes[0] = dummy,int k = 1;
        while(p->next)
        {
            Nodes[k++] = p->next;
            p = p->next;
        }
        Nodes[(k - 1) - n]->next = Nodes[k - n]->next;//此时k - 1才是结点的数量
        return dummy->next;
    }
```

## 20.有效的括号

题目关键：利用栈的栈顶配对

**`Tag:`** `string` `stack`

```C++
    bool isValid(string s){
        stack<char> stk;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '[') stk.push(c);
            else
            {
                if(stk.size() && abs(c - stk.top()) <= 2) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
```

## 21.合并两个有序链表

题目关键：就是归并算法的后一步，同时循环两个链表共有长度部分，然后处理剩余部分即可

**`Tag:`** `linked-list`

```C++
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while( l1 && l2){
            if(l1->val < l2->val){
               cur->next = l1;
               l1 = l1->next;
               cur = cur->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return dummy->next;
    }
```

## 22.括号生成

题目关键：一个规则：左右括号序列中，任意前缀中左括号数量一定要大于等于右括号数量，可以证明这是括号序列有效的充要条件。利用该条件剪枝，dfs即可

**`Tag:`** `backtracking`

```C++
    vector<string> ans;
    void dfs(int n,int lc,int rc,string path){
        if(lc == rc && lc == n) ans.push_back(path);
        if(lc < n) dfs(n,lc + 1,rc,path+'(');//可以添加左括号的情况
        if(rc < n && lc > rc) dfs(n,lc,rc+1,path+')');//可以添加右括号的情况
    }
    vector<string> generateParenthesis(int n){
        dfs(n,0,0,"");
        return ans;
    }
```

## 23.合并K个升序链表

题目关键：构建一个优先队列，将每次的链表头插入进行比较，相对于循环遍历k条链表的比较大小，可以将复杂度降至O(logk),总的时间复杂度即为O(length * logk)

**`Tag:`** `linked-list`

```C++
    struct Cmp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeLists(vector<ListNode*>& lists){
        priority_queue<ListNode*,vector<ListNode*>,Cmp> heap;
        for(auto l: lists)if(l) heap.push(l);
        auto dummy = new ListNode(-1),tail=dummy;
        while(heap.size())
        {
            auto t = heap.top();//临时保存出堆的头结点，便于之后找到它的后继结点
            heap.pop();
            tail = tail->next = t;
            if(t->next)heap.push(t->next);//若后继结点还存在，就继续进入堆比较
        }
        return dummy->next;
    }
```


