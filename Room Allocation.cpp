#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, a, d;
    cin >> n;
    vector<vector<ll>> v;
    for (ll i = 0; i < n; i++) {
        cin >> a >> d;
        v.push_back({a, d, i});
    }
    sort(v.begin(), v.end());
    ll currRoom = 0;
    vector<ll> res(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll i = 0; i < n; i++) {
        if (!pq.empty() and pq.top().first < v[i][0]) {
            ll roomNo = pq.top().second;
            res[v[i][2]] = roomNo;
            pq.pop();
            pq.push({v[i][1], roomNo});
        }
        else {
            pq.push({v[i][1], ++currRoom});
            res[v[i][2]] = currRoom;
        }
    }
    cout << currRoom << "\n";
    for (ll i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}

