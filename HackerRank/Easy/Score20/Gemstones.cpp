// 08/2020
// https://www.hackerrank.com/challenges/gem-stones/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {

    int alpha[26]{};
    int* c;
    for (int i = 0; i<arr.size(); i++) {
        for (int j = 0; j<arr[i].size(); j++) {
            c = &alpha[arr[i][j]-'a'];
            *c += i==*c;
        }
    }
    int ans = 0;
    for (int i : alpha) {
        ans += i==arr.size();
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
