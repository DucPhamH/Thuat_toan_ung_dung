#include <bits/stdc++.h>
using namespace std;

int countpair(int N[], int length)
{
    unordered_map<int,int> temp;

    for(int i = 0; i < length; i++) temp[N[i]] += 1;
     
    int count = 0;

    for(auto j=temp.begin();j!=temp.end();j++) if(j->second > 1) count += (j->second) - 1;

    return count;
}
 
int main()
{
    int N[] = { 6, 3, 2, 3, 5, 4, 4, 2 };
    int length = sizeof(N) / sizeof(N[0]);

    cout << countpair(N, length);
 
    return 0;
}