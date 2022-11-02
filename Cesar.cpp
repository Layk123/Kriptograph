#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using ld = long double;
using ll = long long;

std::vector<ll> cnt_al(std::string s) {
    std::vector<ll> cnt(26, 0);
    for (char i: s)
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) {
            i = tolower(i);
            cnt[i - 'a']++;
        }
    return cnt;
}

std::vector<ld> func(std::vector<ll> cnt, std::string s) {
    std::vector<ld> cnti(26);
    for (int i = 0; i < 26; ++i) {
        ld x = std::abs((ld) cnt[i] / (ld) s.size() * 100);
        cnti[i] = x;
        cnti[i] = x;
    }
    return cnti;
}

signed main() {
    std::string s;
    getline(std::cin, s);
    std::string ans = "s";
    ld min = 1e9;
    std::string s1;
    for (int i = 0; i < 26; ++i) {
        s1.clear();
        for (unsigned char symbol: s) {
            if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
                symbol = std::tolower(symbol);
                symbol += i;
                if (symbol > 'z')
                    symbol = symbol - 26;
            }
            s1 += symbol;
        }
        std::vector<ld> cntik = {8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75,
                                 7.51, 1.93, 0.10, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};
        std::vector<ll> cnt_letter(26);
        cnt_letter = cnt_al(s1);
        std::vector<ld> cnt_proc_letter(26);
        cnt_proc_letter = func(cnt_letter, s1);
        ld num = 0;
        for (ll j = 0; j < 26; j++) num += std::abs(cnt_proc_letter[j] - cntik[j]);
        if (num < min) {
            min = num;
            ans = s1;
        }
    }
    std::cout << ans;
}
//code created by _s1nmeee_ and Layk