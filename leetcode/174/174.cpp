class Solution {
public:
    int ans = 0x3f3f3f3f;
    int rowLimit, colLimit;
    int d[2][2] = {-1, 0, 0, -1};
    bool OK(int x, int y)
    {
        if (x < 0 || x >= rowLimit || y < 0 || y >= colLimit) return false;
        return true;
    }
    typedef struct Node
    {
        int x, y, tmpAns;//health means the health you need at least in the area.
        Node () {}
        Node(int _x, int _y, int _tmpAns) : x(_x), y(_y), tmpAns(_tmpAns) {}
    }Node;
    int minTmpAns[1007][1007];
    void solve(vector<vector<int>>& dungeon)
    {
        queue<Node> que;
        if (dungeon[rowLimit-1][colLimit-1] < 0) 
        {
            minTmpAns[rowLimit-1][colLimit-1] = dungeon[rowLimit-1][colLimit-1]*(-1);
            que.push(Node(rowLimit-1, colLimit-1, minTmpAns[rowLimit-1][colLimit-1]));
        }
        else 
        {
            minTmpAns[rowLimit-1][colLimit-1] = 0;
            que.push(Node(rowLimit-1, colLimit-1, minTmpAns[rowLimit-1][colLimit-1]));
        }   
        //cout << rowLimit << " " << colLimit << " " << minTmpAns[0][1] << endl;
        while (!que.empty())
        {
            Node now = que.front();
            //cout << now.x << " " << now.y << " " << now.tmpAns << " " << now.health << endl;
            que.pop();
            for (int i = 0; i < 2; i++)
            {
                int nx = now.x + d[i][0];
                int ny = now.y + d[i][1];
                if (!OK(nx, ny)) continue;
                int tmpAns = now.tmpAns;
                tmpAns = max(0, tmpAns - dungeon[nx][ny]); 
                //cout << nx << " " << ny << " " << tmpAns << endl;
                if (tmpAns < minTmpAns[nx][ny])
                {
                    minTmpAns[nx][ny] = tmpAns;
                    que.push(Node(nx, ny, tmpAns));
                }
            }
        }
        ans = min(ans, minTmpAns[0][0]+1);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rowLimit = dungeon.size();
        colLimit = dungeon[0].size();
        memset(minTmpAns, 0x3f, sizeof(minTmpAns));
        solve(dungeon);
        //dfs(0, 0, dungeon, 0, 0);
        return ans;
    }
};