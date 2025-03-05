#include <iostream>
#include <vector>

using namespace std;

int strStr(string haystack, string needle) {

    int c=0;
    
    for (int i=0; i<haystack.size(); i++) {
        if(haystack[i] == needle[c]) {
            c++;
        } else if(c!=0) {
            i=i-c;
            c=0;

        }

        if (c==needle.size()) return i-c+1;

    }

    return -1;
}


int main(){


    string  haystack = "mississippi", needle = "issip";

    cout << strStr(haystack, needle);

    return 0;
}