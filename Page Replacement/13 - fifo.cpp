#include<bits/stdc++.h>
using namespace std;

void printState(vector<int>frames)
{
    for(int x : frames)
    {
        cout << " ";
        if(x==-1) continue;
        else cout << x ;
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int size; // frame size
    cin >> size;
    vector<int>frames(size, -1);
    int miss = 0, page;

    int index = 0;
    while(cin >> page)
    {
        bool found = false;
        for(int x : frames)
        {
            if(x==page)
            {
                found = true;
                break;
            }
        }

        // page found in frames
        if(found)
        {
            cout << page << " => " << endl;
            continue;
        }

        // page not found in frames
        miss++;
        frames[index] = page;
        index = (index+1)%size;
        cout << page << " => ";
        printState(frames);
    }
    cout << "Total page fault : " << miss << endl;
    return 0;
}