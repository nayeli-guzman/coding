#include<iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
}

void print(vector<vector<int>> v) {
    for(auto e:v) {
        for(auto a:e) {
            cout << a << " ";
        } cout << endl;
    } cout << endl;
}

bool bfs(std::vector<std::vector<int>> matrix, 
    //std::pair<int, int> node,
    int r,
    int c
) {

    vector<pair<int,int>> neigh = 
    {       {-1,0},
    {0,-1},          {0,1},
            {1,0}           };
    
    unordered_set<pair<int,int>> visited;
    queue<pair<int,int>> queue;

    //visited.insert(node);

    for(int i=0; i<c; i++) {
        if(matrix[0][i]==0) {
            queue.push({0,i});
            if(visited.empty()) visited.insert({0,i});
        }
    }
    //queue.push(node);

    while (!queue.empty()){
        pair<int, int> head = queue.front();
        // cout << head.first << " " <<head.second << endl;
        queue.pop();

        for(int i=0; i<neigh.size(); i++) {
            int x = head.first + neigh[i].first;
            int y = head.second + neigh[i].second;

            if(x>=0 && x<r && y>=0 && y<c) {
                if(matrix[x][y]==1) continue;
                if(visited.find({x,y})==visited.end()) {
                    if(x==r-1) return true;
                    visited.insert({x,y});
                    queue.push({x,y});
                }
            }
        }

    }

    return false;
    
    
}

/*
int binary_searc(vector<vector<int>> cells
    //, vector<vector<int>> matrix
    , int r
    , int c
    , int left
    , int right
    , bool w1
    ) {

    if (left > right) return right+1; //+1 día más reciente en el que aún puedes cruzar
    int mid = ((left+right)/2);

    vector<vector<int>> matrix(r, vector<int>(c, 0));
    for (int i = 0; i <= mid; i++) {
        matrix[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }


    cout << "mid: " << mid << endl;

    // if(w1) {
    //     // cout << "camibando por 1" << endl;
    //     for(int i=left; i<=mid; i++) {
    //         // cout << i << endl;
    //         // |   cout << cells[i][0]<<endl;
    //             matrix[cells[i][0]-1][cells[i][1]-1] = 1;
    //         }
    // } else {
    //     // cout << "camibando por 0" << endl;
    //     for(int i=mid+1; i<=right+1; i++) {
    //             // cout << cells[i][0]<<endl;
    //             // cout << i << endl;
    //             matrix[cells[i][0]-1][cells[i][1]-1] = 0;
    //     }
    // }

    
    // print(matrix);
    bool conf = false;
    for(int i=0; i<c; i++) {
        // cout << "pass" << endl;
        if(matrix[0][i]==0 && bfs(matrix, {0,i}, r, c)) {
            conf = true;
            break;
        }
    }

    if(conf) {
        cout << "IMIN" << endl;
        return binary_searc(cells, r,c, mid+1, right, true);
    } 
    cout << "IMNOTIN" << endl;

    return binary_searc(cells, r,c, left, mid-1, false);

}
*/

int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    //return binary_searc(cells, row,col, 0, cells.size()-1,true);

    int left = 0, right = cells.size()-1;
    int response = -1;

    while(left<=right) {

        int mid=(left+right)/2;
        vector<vector<int>> matrix(row, vector<int>(col, 0));
        for (int i = 0; i <= mid; i++) {
            matrix[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        print(matrix);

        if (bfs(matrix,row,col)) {
            cout << "bfs" << endl;
            response = mid;
            left = mid+1;
        } else {
            cout << "no bfs" << endl;
            right = mid-1;
        }
    }
    return response+1;

}


int main(){

    vector<vector<int>> matrix = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 1},
        //{0, 0, 1, 1}
    };

    pair<int, int> start = {0, 2};  // Empezar desde (0, 0)
    int r = 3;
    int c = 3;
//    cout << bfs(matrix, start, r, c);  

    vector<vector<int>> cells = {
        {1, 2},
        {2, 1},
        {3, 3},
        {2, 2},
        {1, 1},
        {1, 3},
        {2, 3},
        {3, 2},
        {3, 1}
    };

    cout << latestDayToCross(r, c, cells);
    
    

    return 0;
}