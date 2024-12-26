#include<bits/stdc++.h>
using namespace std;

int FIFOpageFaults(int page[], int n, int capacity)
{
        unordered_set<int> s;
        queue<int> indexes;
        int page_faults = 0;
        for (int i=0; i<n; i++)
        {
                if (s.size() < capacity)
                {
                        if (s.find(page[i])==s.end())
                        {
                                s.insert(page[i]);
                                page_faults++;
                                indexes.push(page[i]);

                        }
                }
                else
                {
                        if (s.find(page[i]) == s.end())
                        {
                                int val = indexes.front();
                                indexes.pop();
                                s.erase(val);
                                s.insert(page[i]);
                                indexes.push(page[i]);
                                page_faults++;

                                                              }
                }
        }
        return page_faults;
}






int main()
{
            int page[] = {3,1,4,2,5,4,1,3,5,2,0,1,1,0,2,3,4,5,0,1};
                int n = sizeof(page)/sizeof(page[0]);
                    int capacity = 3;
		    	cout << "NUMBER OF MISSES IN FIFO REPLACEMENT :" << endl;
                        cout << FIFOpageFaults(page, n, capacity)<<"\n";
                            return 0;
}


