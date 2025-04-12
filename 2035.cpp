// meet in the middle

#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

void print(unordered_map<int, vector<int>> h) {
    for(auto e:h) {
        cout << e.first << " ";
        for(auto a:e.second) {
            cout << a << " ";
        } cout << endl;
    }cout << endl;
}
int solve(vector<int>& sum1,vector<int>& sum2,int tot){

    int m = sum1.size(),n = sum2.size();
    int min_dif = INT_MAX;

    for(int i=0;i<m;++i){ // iterando en todas las sumas de 1

        int target = tot/2-sum1[i];
        int lb = lower_bound(sum2.begin(),sum2.end(),target)-sum2.begin();

        if(lb==sum2.size())
            min_dif = min(min_dif,abs(tot-2*(sum1[i]+sum2[lb-1]))); // cuando el target es mayor al maximo del vector;
        else if(lb==0)
            minDiff = min(min_dif,abs(tot-2*(sum1[i]+sum2[lb]))); // cuando el target es el primer elemento del array
        else
            min_dif = min({min_dif,
                           abs(tot-2*(sum1[i]+sum2[lb-1])),
                           abs(tot-2*(sum1[i]+sum2[lb]))}); // se verifica con el lb, pero tmb con el anterior pq puede tener una mejor rpta
    }
    return min_dif;
}

int minimumDifference(vector<int>& nums) {

    int n=nums.size()/2;
    int tot = 0;//Sum of array
    vector<int> nums1,nums2;

    // dividir el arrray de 2n en n, n
    for(int i=0;i<n;++i){
        nums1.push_back(nums[i]);
        nums2.push_back(nums[i+n]);
        tot += nums[i]+nums[i+n];
    }
    
    int power_set = 1<<n;
    vector<int> sum1[n+1],sum2[n+1]; // array de vectores que almacenan las sumas
    for(int mask = 0; mask < power_set; mask++){
            int tot1 = 0,tot2 = 0,count = 0;
            for(int j=0;j<n;++j)
                if(mask & (1<<j)){
                    tot1 += nums1[j];
                    tot2 += nums2[j];
                    count += 1;
                }
            sum1[count].push_back(tot1);
            sum2[count].push_back(tot2);
        }

    // ordenar el segundo array segun la usma
    for(int i=0;i<=n;++i)
        sort(sum2[i].begin(),sum2[i].end());
    
    int min_dif = INT_MAX;
    for(int i=0;i<=n;i++)
        min_dif = min( 
                        min_dif,
                        solve(sum1[i],sum2[n-i],tot) // pasarle las sumas con i items en a y n-i items en b
                    );
    return miin_dif;
}

/*
int minimumDifference(vector<int>& nums) {

    int target=nums.size()/2;
    int power_set = 1<<target;
    int total_sum =0;

    unordered_map<int, vector<int>> hash1, hash2;

    for(int i=0; i<power_set; i++) { // iterando en todos los elementos de un conjunto potencia
        int sum1=0, sum2=0, cont1=0, cont2=0;
        for(int j=0; j<target; j++) {
            if (i & (1<<j)) {
                sum1=nums[j]+sum1;
                cont1++; cont2++;
                sum2=nums[j+target]+sum2;
            }
        }
        hash1[cont1].push_back(sum1);
        hash2[cont2].push_back(sum2);
    }

    for(auto &[_,e2]:hash2) {
        sort(e2.begin(), e2.end());
    }

    total_sum = hash1[target][0] + hash2[target][0];

    // print(hash1);
    // print(hash2);
    int c=0;
    // if(total_sum%2!=0) {
    //     c=1;
    //     total_sum--;
    // }

    int min_dif = INT32_MAX;
    int target_sum = total_sum/2;

    for(int i=0; i<=target; i++) {
        int item1 = i, item2 = target-i;

        for(auto sum:hash1[i]) {
            int new_target = target_sum - sum;
            auto& vec = hash2[item2];
            int lb = std::lower_bound(vec.begin(), vec.end(), new_target) - vec.begin();
            if (lb == vec.size()) {
                int sep = 2 * (sum + vec[lb - 1] - target_sum);
                min_dif = min(min_dif, abs(sep));
            } else if (lb == 0) {
                int sep = 2 * (sum + vec[lb] - target_sum);
                min_dif = min(min_dif, abs(sep));
            } else {
                int sep1 = 2 * (sum + vec[lb - 1] - target_sum);
                int sep2 = 2 * (sum + vec[lb] - target_sum);
                min_dif = min({min_dif, abs(sep1), abs(sep2)});
            }
        }
    }

 return abs(min_dif)-c;   
}
*/

int main(){

    vector<int> v = {-68,55,-23,13,-20,-14};
    v = {42,41,59,43,69,67};
    v = {91,14,16,82,32,2,38,94};
    cout << "min: " << minimumDifference(v);


    return 0;
}