#include <iostream>
#include <algorithm>
using namespace std;

double binary_search(
    vector<int>n1, 
    vector<int>n2, 
    int l1, 
    int r1,
    int tot //tot/2
) {
    int p = l1; 
    int q =  tot-(p+1)-1;
    if(l1<0) {
        p=l1;
        q=tot-1;
    }

    int a = p<0?INT16_MIN:n1[p];
    int b = p+1>=n1.size()?INT16_MAX:n1[p+1];

    int c = q<0?INT16_MIN:n2[q];
    int d = q+1>=n2.size()?INT16_MAX:n2[q+1];

    if(a <= d && c <= b) {
        if((n1.size()+n2.size())%2!=0) {
            return min(b, d);
        } else {
            return (max(a,c) + min(b,d))/2.;
        }
    }

    if(a > d) {
        return binary_search(n1,n2,p-1,r1,tot);
    } 
    
    return binary_search(n1,n2,p+1,r1,tot);
    

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size(), n=nums2.size();

    if(m==0 && n==0) return 0;
    if(m==0 && n!=0) return n%2==0? (nums2[n/2]+nums2[n/2-1])/2.:nums2[n/2];
    if(m!=0 && n==0) return m%2==0? (nums1[m/2]+nums1[m/2-1])/2.:nums1[m/2];
    if(m==1 && n==1) return (nums1[0]+nums2[0])/2.;
    
    int tot = m+n;
    int mid = floor(tot/2);

    if(nums1.size()>=nums2.size()) {
        return binary_search(nums2,nums1,(nums2.size()-1)/2,nums2.size()-1,mid);
    } else {
        return binary_search(nums1,nums2,(nums1.size()-1)/2,nums1.size()-1,mid);
    }

}

int main(){

    vector<int> v1 = {};
    vector<int> v2 = {};
    // cout << findMedianSortedArrays(v1, v2)<<endl;

    // v1 = {3}; v2 = {1,2,4,5};
    // cout << findMedianSortedArrays(v2, v1)<<endl;

    // v1 = {1,7,18,20}; v2 = {10,23,30,35,40};
    // cout << findMedianSortedArrays(v2, v1)<<endl;

    // v1 = {1,12,17,20}; v2 = {5,6,8,23,25};
    // cout << findMedianSortedArrays(v1, v2)<<endl;
    
    // v1 = {1,2,3,4}; v2 = {8,9,10,11};
    // cout << findMedianSortedArrays(v2, v1)<<endl;

    v1 = {1,2,4}; v2 = {3};
    cout << findMedianSortedArrays(v2, v1)<<endl;

    v1 = {2,3,4}; v2 = {1};
    cout << findMedianSortedArrays(v2, v1)<<endl;

    return 0;
}