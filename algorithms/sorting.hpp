#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using vvi = vector<vi>;

int left(int i) {
    return 2*i+1;
}

int right(int i) {
    return 2*i+2;
}

void max_heapify(vi &v, int i, int n) {
    int l = left(i);
    int r = right(i);
    int largest = INT32_MAX;

    if(l<n && v[l]>v[i]) largest = l;
    else largest = i;

    if(r<n && v[r]>v[largest]) largest = r;

    if(largest!=i) {
        swap(v[i], v[largest]);
        max_heapify(v, largest, n);
    }
} 

void build_max_heap(vi &v, int n) {
    for(int i=n/2; i>=0; i--) {
        max_heapify(v, i, n);
    }
}

void heapsort(vi &v) {
    int n = v.size();
    build_max_heap(v, n);
    for(int i=n-1; i>0; i--) {
        swap(v[i], v[0]);
        n--;
        max_heapify(v, 0, n);
    }
}

int partition(vi& A, int p, int r) {
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++) {
        if(A[j]<=x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1; 
}

void quicksort(vi& A, int p, int r) {
    if(p<r) {
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, p+1, r);
    }
}

void merge(vi& v, int p, int q, int r) {
    int nl = q-p+1;
    int nr = r-q;
    vi l(nl,0), R(nr, 0);
    for(int i=0; i<nl; i++)
        l[i] = v[p+i];
    for(int j=0; j<nr; j++)
        R[j] = v[q+j+1];

    int i=0, j=0, k=p;
    while(i<nl && j<nr) {
        if(l[i] <= R[j])
            v[k] = l[i++];
        else 
            v[k] = R[j++];
        k++;
    }
    while (i<nl) 
        v[k++] = l[i++];
    while (j<nr) 
        v[k++] = R[j++];    
    
}

void merge_sort(vi& v, int p, int r) {
    if(p>=r) return;
    int q = floor((p+r)/2);
    merge_sort(v, p, q);
    merge_sort(v, q+1, r);
    merge(v, p, q, r);
    print(v);

}

void selection_sort(vi &v) {
    int n=v.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i]>v[j]) {
                swap(v[i], v[j]);
            }
        }
    }
}
