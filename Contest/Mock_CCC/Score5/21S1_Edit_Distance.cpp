// https://dmoj.ca/problem/nccc8s1
// 02/2021

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define uset unordered_set
#define umap unordered_map
#define priq priority_queue
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

void solve() {

    string alpha, s;
    cin>>alpha>>s;
    uset<string> st;

    // Remove and replace
    for (int i = 0; i<s.size(); ++i) {
        string sub = s;
        for (int j = 0; j<alpha.size(); ++j) {
            sub[i] = alpha[j];
            st.emplace(sub);
            sub[i] = s[i];
        }
        for (int j = 0; j<alpha.size(); ++j) {
            sub += alpha[j];
            st.emplace(sub);
            sub.erase(sub.size()-1, 1);
        }
        sub.erase(i, 1);
        st.emplace(sub);
    }
    // Add
    for (char i:alpha) {
        string sub = s;
        for (int j = 0; j<s.size(); ++j) {
            sub.insert(j, string(1, i));
            st.emplace(sub);
            sub.erase(j, 1);
        }
    }
    st.erase(s);
    vector<string> v(all(st));
    sort(all(v));
    for (string str:v) {
        cout<<str<<'\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 0
    int t; scan(t); while (t--) solve();
#else
    solve();
#endif
    return 0;
}
