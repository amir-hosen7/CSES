#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll num, n, a;
    cin >> num >> n;
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    ll res = 0;
    while (1) {
        ll x = pq.top();
        pq.pop();
        res += x;
        if (pq.empty()) break;
        ll y = pq.top();
        pq.pop();
        res += y;
        if (pq.empty()) break;
        pq.push(x + y);
    }
    cout << res << "\n";
    return 0;
}

