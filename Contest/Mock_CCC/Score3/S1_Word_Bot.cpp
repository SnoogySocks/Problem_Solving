// https://dmoj.ca/problem/rccc1s1
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
#define vec vector
#define all(x) begin(x), end(x)

template<class T, class U> static inline void amax (T& a, U b) { if (a<b) a = b; }
template<class T, class U> static inline void amin (T& a, U b) { if (a>b) a = b; }
template<class T> void scan (T& n) { n = 0; bool neg = 0; char c = getchar(); if (c=='-') neg = 1, c = getchar(); for (; c<'0'||'9'<c; c = getchar()); for (; '0'<=c&&c<='9'; c = getchar()) n = (n<<3)+(n<<1)+(c&15); if (neg) n *= -1; }
template<class T> void scan (T begin, T end) { while (begin!=end) scan(*begin++); }
void scan (vector<char>& c, const char&& escape = ' ') { c.clear(); char buf; do buf = getchar(); while (buf<'!'||'~'<buf); for (; buf!='\n'&&buf!=escape; buf = getchar()) c.push_back(buf); c.push_back('\0'); }
template<class T> void print (T n, char&& end = '\n') { bool neg = 0; if (n<0) neg = 1, n *= -1; char snum[65]; int i = 0; do { snum[i++] = n%10+'0'; n /= 10; } while (n); i--; if (neg) putchar('-'); while (i>=0) putchar(snum[i--]); putchar(end); }
template<class T> void print (T begin, T end) { while (begin!=end) print(*begin++, ' '); putchar('\n'); }

void solve() {

    int n, c, v; scan(n); scan(c); scan(v);
    vec<char> s; s.reserve(n); scan(s);
    vec<bool> isvowel(26);
    string vowels = "aeiouy";
    for (char c:vowels) {
        isvowel[c-'a'] = true;
    }

    pair<int, bool> cnt(0, false);
    pair<int, bool> ys(0, false);
    for (int i = 0; i<n; ++i) {
        if (cnt.second==isvowel[s[i]-'a']||s[i]=='y') {
            ++cnt.first;
        } else {
            cnt = make_pair(1, !cnt.second);
            if (ys.second) {
                cnt.first += ys.first;
            }
        }
        if (s[i]=='y') {
            ys.second = true;
            ++ys.first;
        } else {
            ys = make_pair(0, false);
        }
        if (cnt.second==false&&cnt.first>c||cnt.second==true&&cnt.first>v||ys.first>c||ys.first>v) {
            puts("NO");
            return;
        }
    }
    puts("YES");
    
}
/*
7 2 3
omuyymi
*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#if 0
    int t; scan(t); while(t--) solve();
#else
    solve();
#endif
    return 0; 
}
