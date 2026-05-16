#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

using vi = vector<int>;
bool debug = 0;

int main() {
	int k, m; cin>>k>>m;
    unordered_map<int, int> hash;
    for (int i=0; i<m; i++) {
        int t; cin>> t;
        hash[t]++;
        if (t>k && hash[t] > 2){
            cout << "*" << endl;
            return 0;
        }

    }
    if (debug) cout << "ajsnas" << endl;
    
    unordered_map<int, unordered_set<int>> rev;

    for (auto e:hash) {
        rev[e.second].insert(e.first);
    } 

    if (rev.size()>3) {
        cout << "*" << endl;
        return 0;
    }

    // 1 no existe
    int x=-1, y=-1, z=-1;
    int c_x=0, c_y=0, c_z=0; 
    int maxi = -1, mini=-1;

    if (rev.size()==3) {

        if (debug) cout << "size 3" << endl;


        auto it = rev.begin();

        // longitud : cuantos tienen esa longitud

        x = it->first; c_x = it->second.size(); it++;
        y = it->first; c_y = it->second.size(); it++;
        z = it->first; c_z = it->second.size();

        if (debug) cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl;;


        if (c_x != c_y || c_x != c_z) {
            cout << "*" << endl;
            return 0;
        }

        if (abs(x-y) > 2 || abs(x-z)>2 || abs(y-z) >2) {
            cout << "*" << endl;
            return 0;
        }

        // maxima longitud

        it = rev.begin();
        
        if (x>y && x>z) {maxi = *it->second.begin();}
        else if (y>x && y>z) {it++; maxi = *it->second.begin();;}
        else if (z>x && z>y) {it++; it++; maxi = *it->second.begin();}

        // minima longitud
        it = rev.begin();

        if (x<y && x<z) {mini = *it->second.begin();}
        else if (y<x && y<z) {it++; mini = *it->second.begin();;}
        else if (z<x && z<y)  {it++; it++; mini = *it->second.begin();}

        if (debug) cout << "mini: " << mini << " " << "max: " << maxi << endl;

        
        cout << "-"  << maxi << " +" << mini << endl;
        return 0;
    }

    if (rev.size()==2) {

        if (debug) cout << "size 2" << endl;

        auto it = rev.begin();

        // longitud : cuantos tienen esa longitud
        x = it->first; c_x = it->second.size(); it++;
        y = it->first; c_y = it->second.size();

        if (debug) cout << "x: " << x << " y: " << y << endl;
        if (debug) cout << "cx: " << c_x << " cy: " << c_y << endl;

        if (abs(x - y) > 1){
        
            cout << "*" << endl;
            return 0;
        }

        if (rev.count(1) && rev[1].size() == 1) {
            if (debug) {cout << "base case" << endl;}
            cout << "-" << *rev[1].begin() << endl;
            return 0;
        }

        char minc = 'x';
        it = rev.begin();
        if (x>y) {maxi = *it->second.begin(); it++; mini=*it->second.begin(); minc = 'y';}
        else {mini=*it->second.begin(); it++; maxi =*it->second.begin(); minc = 'x';}

        if (debug) cout << "mini: " << mini << endl << "max: " << maxi << endl;

        if (x < y && c_x > c_y) {
            cout << "-" << maxi << endl;
        } else {
            cout << "+" << mini << endl;
        }
        
    }


    return 0;


}
