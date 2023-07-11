#include<bits/stdc++.h>
using namespace std;

void printFrameState(vector<int>frames)
{
    int n = frames.size();
    for(int i=0; i<n; i++)
    {
        if(frames[i]==-1) continue;
        cout << frames[i] << " ";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int frame_size;
    cin >> frame_size;

    vector<int>frames(frame_size, -1);
    map<int, int>mp;

    int miss = 0;
    int current_time = 0;

    int page;
    while(cin >> page)
    {
        mp[page]++;
        // checking if the page is found or not
        bool found = false;
        for(int i=0; i<frames.size(); i++)
        {
            if(frames[i]==page)
            {
                cout << page << " => " << endl;
                found = true;
                break;
            }
        }
        if(found) continue;

        // if not found then the following code executed
        miss++;
        int victim = frames[0];
        // remove victim
        for(int i=0; i<frames.size(); i++)
        {
            if(frames[i]==-1) {
                victim = frames[i];
                break;
            }
            if(mp[frames[i]]<mp[victim]) victim = frames[i];
        }

        // store new page
        for(int i=0; i<frames.size(); i++)
        {
            if(frames[i]==victim)
            {
                frames[i] = page;
                break;
            }
        }

        // print frame state
        cout << page << " => ";
        printFrameState(frames);
        cout << endl;

    }

    cout << "Total page fault : " << miss << endl;

    return 0;
}