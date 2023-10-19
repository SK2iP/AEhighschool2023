#include <iostream>
#include <vector> 
using namespace std;
#define N 3

typedef pair<int,int> point;

vector<vector<pair<int,int>>> paths;

vector<vector<char>> board;

void intialize();
void run();
bool check(point a);
bool is_visited(vector <pair<int,int>> path , pair <int,int> new_point);
void print_path();
void dfs(vector <pair<int,int>> path);

int main(void)
{
    run();
}

void intialize()
{
    for(int i =0 ; i<N ; i++)
    {
        vector <char> tmp;
        for (int j = 0 ; j < N ; j++)
        {
            tmp.push_back(' ');
        }
        board.push_back(tmp);
    }
    board[0][0] = 'A';
    board[N-1][N-1] = 'C';

}

void print_map()
{
    for(int i =0 ; i<N ; i++)
    {
        cout<<"|";
        for (int j = 0 ; j < N ; j++)
        {
            cout<<board[i][j]<<"|";
        }
        cout<<endl;
        for (int j = 0 ; j < 2*N ; j++)
        {
            cout<<"-";
        }
        cout<<endl;
    }
}

void run()
{
    intialize();
    print_map();
    vector<pair<int,int>> tmp;
    tmp.push_back({0,0});
    dfs(tmp);
    print_path();
}
bool check(pair<int,int> a){
    if (a.first < 0 || a.first >= N)
    {
        return false;
    }
    if (a.second < 0 || a.second >= N)
    {
        return false;
    }
    return true;
}
bool is_visited(vector <pair<int,int>> path , pair <int,int> new_point)
{
    for (auto point : path)
    {
        if (point == new_point)
            return false;
    }
    return true;
}
void dfs(vector <pair<int,int>> path){
    pair <int,int> point_n = path[path.size() - 1];
    if (board[point_n.first][point_n.second] == 'C')
    {
        paths.push_back(path);
        return;
    }
    pair <int,int> point_next = point_n;
    point_next.second +=1;
    if (check(point_next))
    {
        if(is_visited(path , point_next))
        {
            path.push_back(point_next);
            dfs(path);
            path.pop_back();
        }
    }
    point_next = point_n;
    point_next.second -=1;
    if (check(point_next))
    {
        if(is_visited(path , point_next))
        {
            path.push_back(point_next);
            dfs(path);
            path.pop_back();
        }
    }

    point_next = point_n;
    point_next.first -=1;
    if (check(point_next))
    {
        if(is_visited(path , point_next))
        {
            path.push_back(point_next);
            dfs(path);
            path.pop_back();
        }
    }

    point_next = point_n;
    point_next.first +=1;
    if (check(point_next))
    {
        if(is_visited(path , point_next))
        {
            path.push_back(point_next);
            dfs(path);
            path.pop_back();
        }
    }
}
void print_path()
{
    for(int i =0 ; i<paths.size() ; i++)
    {
        cout<<"Paht_number = "<<i+1<<endl;
        for (int j = 0 ; j < paths[i].size() ; j++)
        {
            cout<<"i = "<<paths[i][j].first<<"j = "<<paths[i][j].second<<endl;
        }
        cout<<endl;
    }
}