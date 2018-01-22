/*
ID: omar.se1
LANG: C++11
TASK: castle
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

template<class T>
inline T next()
{
    T x;
    std::cin >> x;
    return x;
}

struct node
{
    bool up, down;
    bool left, right;
    int x, y;
    bool visited;
    int size;
    int component;

    node(): visited(false)
    {
    }

    node(int _x, int _y, int n):
        up((n & 2) == 0),
        down((n & 8) == 0),
        left((n & 1) == 0),
        right((n & 4) == 0),
        x(_x), y(_y),
        visited(false)
    {
    }

    vector<node*> dfs(vector<vector<node>>& grid)
    {
        if (visited) return {};
        visited = true;
        vector<node*> cur = {this};
        vector<pair<int, int>> adj = {{x - up, y}, {x + down, y}, {x, y - left}, {x, y + right}};
        for (const auto& p : adj) {
            vector<node*> next = grid[p.first][p.second].dfs(grid);
            cur.insert(end(cur), begin(next), end(next));
        }
        return cur;
    }

    bool connected_to(const node& other) const
    {
        return component == other.component;
    }

    int merge_size(const node& other) const
    {
        return size + other.size;
    }
};

struct room_data
{
    int x, y;
    int merge_size;
    char removed_wall_direction;

    room_data():
        x(-1), y(-1),
        merge_size(numeric_limits<int>::min()),
        removed_wall_direction('A')
    {
    }

    room_data(int _x, int _y, int size, char direction):
        x(_x),  y(_y), merge_size(size), removed_wall_direction(direction)
    {
    }

    friend ostream& operator << (ostream& ostr, const room_data& room)
    {
        ostr << room.merge_size << '\n';
        ostr << room.x << ' ' << room.y << ' ' << room.removed_wall_direction;
        return ostr;
    }
};

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector<vector<node>> grid(n, vector<node>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = node(i, j, next<int>());
        }
    }
    int rooms_count = 0;
    int max_size = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            node& room = grid[i][j];
            if (!room.visited) {
                vector<node*> component = room.dfs(grid);
                for (node* cn : component) {
                    cn->size = SIZE(component);
                    cn->component = rooms_count;
                }
                max_size = max(max_size, SIZE(component));
                rooms_count++;
            }
        }
    }
    room_data room;
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            const node& cur_node = grid[i][j];
            if (i - 1 >= 0 && !cur_node.connected_to(grid[i - 1][j])) {
                int value = cur_node.merge_size(grid[i - 1][j]);
                if (value > room.merge_size) {
                    room = room_data(i + 1, j + 1, value, 'N');
                }
            }
            if (j + 1 < m && !cur_node.connected_to(grid[i][j + 1])) {
                int value = cur_node.merge_size(grid[i][j + 1]);
                if (value > room.merge_size) {
                    room = room_data(i + 1, j + 1, value, 'E');
                }
            }
        }
    }
    cout << rooms_count << '\n';
    cout << max_size << '\n';
    cout << room << '\n';
}
