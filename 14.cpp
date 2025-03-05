#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    
    string temp = "";
    
    int c=0;
    bool conf=false;
    while (1) {

        for(int i=0; i<strs.size();i++) {
            cout << strs[i] << endl;

            if(strs[i].size()<=c && i!=0) {
                conf=true;
                temp = (temp==""? "":temp.substr(0,temp.size()-1));
                break;
            }

            if(strs[i].size()<=c && i==0) {
                conf=true;
                break;
            }

            if (i==0)
                temp = temp + strs[i][c];
            else if (temp[temp.size()-1] == strs[i][c])
                continue;
            else {
                conf=true;
                temp = (temp==""? "":temp.substr(0,temp.size()-1));
                break;
            }
        } 
        if (conf)
            break;
        c++;

    }

    return temp;

}

int main() {

    vector<string> vec = {"flower","flow","flight"};

    cout << " aaa" << longestCommonPrefix(vec);



    return 0;
}