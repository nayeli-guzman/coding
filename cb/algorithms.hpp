void bfs(vvi grid, pii beg, pii end, int n, int m) {

    vpii dir = {{-1, 0},{0,-1},{0,1},{1,0}};

    vvb visited(n, vb(m,false));
    qpii queue;

    queue.push(beg);
    visited[beg.first][beg.second] = true;


    while (!queue.empty()) {

        pii curr = queue.front();
        queue.pop();
        int i = curr.first, j=curr.second;

        for(auto [dx, dy]:dir) {
            int x =i+dx, y=j+dy;
            if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==false) {
                visited[x][y] = true;
                queue.push({x,y});
            }

    }

}