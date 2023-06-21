#include<bits/stdc++.h>
using namespace std;

/*
<aside>
💡 1. **Merge k Sorted Lists**

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

</aside>
*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* solve(ListNode* l1,ListNode* l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    if(l1->val < l2->val){
        l1->next = solve(l1->next,l2);
        return l1;
    }else{
        l2->next = solve(l1,l2->next);
        return l2;
    }
    return NULL;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* node = new ListNode (INT_MIN);
    for(auto &i: lists){
        node = solve(node,i);
    }
    return node->next;
}


/*
<aside>
💡 2. **Count of Smaller Numbers After Self**

Given an integer array `nums`, return *an integer array* `counts` *where* `counts[i]` *is the number of smaller elements to the right of* `nums[i]`.

</aside>
*/

void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right){
    vector<pair<int,int>> temp(right - left + 1);
    int i=left;
    int j=mid+1;
    int k=0;
        
    while(i<=mid && j<=right){
            
        if(v[i].first <= v[j].first){
            temp[k++] = v[j++];
        }
            
        else{
                
            count[v[i].second] += right-j+1;
            temp[k++] = v[i++];
                
        }
            
    }
        
        
    while(i<=mid){
        temp[k++] = v[i++];
    }
        
    while(j<=right){
        temp[k++] = v[j++];
    }
        
    for(int i=left;i<=right;i++){
        v[i] = temp[i-left]; 
    }
        
}
void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right){
        
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid+1, right);
        merge(count, v, left, mid, right);
    }
        
}
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        pair<int, int> p;
        p.first = nums[i];
        p.second = i;
        v[i] = p;
    }
    vector<int> count(n, 0);
    mergeSort(count, v, 0, n-1);
    return count;
}


/*
<aside>
💡 3. **Sort an Array**

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem **without using any built-in** functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

</aside>
*/
vector<int> sortArray(vector<int>& nums) {
    function<void(int, int)> quick_sort = [&](int l, int r) {
        if (l >= r) {
            return;
        }
        int i = l - 1, j = r + 1;
        int x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[++i] < x) {
            }
            while (nums[--j] > x) {
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        quick_sort(l, j);
        quick_sort(j + 1, r);
    };
    quick_sort(0, nums.size() - 1);
    return nums;
}


/*
<aside>
💡 4. **Move all zeroes to end of array**

Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).

</aside>
*/

void shifter(int *a,int size_of_array){
     int j = 0;
    for (int i = 0; i < size_of_array; i++) {
        if (a[i] != 0) {
            swap(a[j], a[i]);//taking two pointers i and j where j only moves forward when a[i]!=0 in this way the element containing zero can be shifted
            j++;
        }
    }
}



/*
<aside>
💡 5. **Rearrange array in alternating positive & negative items with O(1) extra space**

Given an **array of positive** and **negative numbers**, arrange them in an **alternate** fashion such that every positive number is followed by a negative and vice-versa maintaining the **order of appearance**. The number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array.

</aside>
*/
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
 
void rearrange(int arr[], int n)
{
    int outofplace = -1;
 
    for (int index = 0; index < n; index++) {
        if (outofplace >= 0) {
            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0)
                    && (arr[outofplace] >= 0))) {
                rightrotate(arr, n, outofplace, index);
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }

        if (outofplace == -1) {
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    }
}

/*
<aside>
💡 **6. Merge two sorted arrays**

Given two sorted arrays, the task is to merge them in a sorted manner.

</aside>
*/
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         vector<int> nums3(m+n);
        int i=0,j=0,k=0;
        
        
        for(i=0,j=0,k=0;i<m&&j<n;k++)
        {
            if(nums1[i]<nums2[j])
            {
                nums3[k]=nums1[i];
                i++;
            }
            else
            {
                nums3[k]=nums2[j];
                j++;
            }
        }
        while(i<m)
        {
            nums3[k]=nums1[i];
            i++;
            k++;
        }
       while(j<n)
        {
            nums3[k]=nums2[j];
           j++;
           k++;
        }
        for(int x=0;x<(m+n);x++)
        {
            nums1[x]=nums3[x];
        }
       
    }


/*
<aside>
💡 7. **Intersection of Two Arrays**

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

</aside>
*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int l1=nums1.size(),l2=nums2.size(),i=0,j=0;
    vector<int>ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
        
    for( i=0,j=0;i<l1 && j<l2;){
        if(nums1[i]>nums2[j]){
            j++;
        }
        else if(nums2[j]>nums1[i]){
            i++;
        }
        else{
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

/*
<aside>
💡 8. **Intersection of Two Arrays II**

Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

</aside>
*/

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
    vector<int> ans;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i=0;
    int j=0;
    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i]==nums2[j])
        {
            ans.push_back(nums1[i]);
            i++,j++;
        }
        else if(nums1[i]>nums2[j])
            j++;
        else if(nums1[i]<nums2[j])
            i++;
    }
    return ans;
}