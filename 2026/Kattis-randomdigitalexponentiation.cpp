#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using vi = vector<int>;
using ll = long long;

bool debug=0;

ll a,b;
string a_str, b_str;


bool back(int idx, ll expe, ll temp, vi &ans) {

    if (idx < 0) {
        return temp == 0;
    }

    int n = a_str[idx] - '0';
    ll powi = 1 * expe / 10;
    ll comp;


    if (idx==0) {
        if (debug) cout<<"ENTRÉ "<<"n:"<<n<<" temp:"<<temp<<" powi:"<<powi<<endl<<endl;

        for(int i=0; ;i++) {
            comp = temp - powi;
            if (debug) cout<<"comp"<<comp<<endl;
            if (comp<0) break;
            if (comp  == 0) {
                ans.push_back(i);
                return true;
            }
            powi = powi * n;
        } 
        return false;
    }

    if (debug) cout<<endl<<"n:"<<n<<" temp:"<<temp<<" powi:"<<powi<<endl<<endl;

    // ll expe = 10;
    for(int i=0; ;i++) {
        comp = temp - powi;
        if(debug) cout <<"comp:"<<comp<<endl;
        if (comp<0) return false;
        if (comp % expe == 0) {
            if (debug) cout<<"n:"<<n<<" temp:"<<temp<<" powi:"<<powi<<endl;

            ans.push_back(i);
            bool d = back(idx-1, expe*10, comp, ans);
            if (d) return d;
            ans.pop_back();
        }
        powi = powi * n;
        // if (n == 0 || n == 1) break;
    } 
}

int main() {

    vi ans;

    cin>>a>>b;
    a_str = to_string(a);
    b_str = to_string(b);

    back(a_str.size()-1, 10, b, ans);

    for (int i=ans.size()-1; i>=0; i--) {
        if (i!=ans.size()-1) cout<<" ";
        cout<<ans[i];
    }
    cout << endl;

    /*
    if(debug) cout <<" b:"<<b<<endl;

    int expo = 1;

    for (int i=a_str.size()-1; i>=0; i--) {
        ll p1 = a_str[i] - '0';
        ll e1=1;
        ll powi = p1*expo;
        ll temp = b-powi;
        expo=expo*10;
        if(debug) cout<<"powi:"<<powi<<" e1:"<<e1<<" a:"<<a<<" expo:"<<expo<<" temp:"<<temp<<endl;


        while (temp % expo != 0) {
            
            e1++;
            powi = powi*p1;
            temp =b-powi;

            if(debug)cout << "temp:"<<temp<<" powi:"<<powi<<endl;

        }

        ans.push_back(e1);
        b = temp;
        b_str = to_string(b);
        if(debug) cout << "powi:"<<powi<<" e1:"<<e1<<" a:"<<a<<" expo:"<<expo<<" temp:"<<temp<<endl;

    }

    for (int i=ans.size()-1; i>=0; i--) {
        if (i!=ans.size()-1) cout<<" ";
        cout<<ans[i];
    }
    cout << endl;

*/

    return 0;
}





