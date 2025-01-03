#include<bits/stdc++.h>
using namespace std;
int LRUpageFaults(int pages[], int n, int capacity)
{
        unordered_set<int> M;
        unordered_map<int, int> indexes;
        int page_faults = 0;
        for (int i=0; i<n; i++)
        {
                if (M.size() < capacity)
                {
                        if (M.find(pages[i])==M.end())
                        {
                                M.insert(pages[i]);
                                page_faults++;
                         }
                        indexes[pages[i]] = i;
                }
                else
                {
                        if (M.find(pages[i]) == M.end())
                        {
                                int lru = INT_MAX, val;
                                for (auto it=M.begin(); it!=M.end(); it++)
                                                {
                                                if (indexes[*it] < lru)
                                                {
                                                lru = indexes[*it];
                                                val = *it;
                                                }
                                                }
                                                M.erase(val);                                                                                                                                       M.insert(pages[i]);
                        page_faults++;
                        }
                        indexes[pages[i]] = i;
                        }
                        }


                            return page_faults;
}
int main()
{
            int pages[] = {3,1,4,2,5,4,1,3,5,2,0,1,1,0,2,3,4,5,0,1};
                int n = sizeof(pages)/sizeof(pages[0]);
                    int capacity = 3;
                cout << LRUpageFaults(pages, n, capacity)<<"\n";
                            return 0;
}
