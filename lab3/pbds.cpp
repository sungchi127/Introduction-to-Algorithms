#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

int data, n;

char opt[10];

int main()
{
    __gnu_pbds::priority_queue<int, less<int>, pairing_heap_tag> que;
    while(~scanf("%d ", &n)) {
        que.clear();
        while(!que.empty()) {
            que.pop();
        }
        for(int i = 1; i <= n; i ++ ) {
            scanf("%s", opt);
            if(opt[1] == 'u') {
                scanf("%d", &data);
                que.push(data);
            } else {
                if(que.empty()) {
                    puts("Empty");
                } else {
                    printf("%d\n", que.top());
                    que.pop();
                }
            }
        }
    }
    return 0;
}