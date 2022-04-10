#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto s = vi(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	int m;
	cin >> m;
	while (0 < (m--)) {
		int x, q;
		cin >> x >> q;

		if (1 == x) {
			auto j = q;
			while (j <= n) {
				s[j - 1] ^= 1;
				j += q;
			}
		}
		else {
			--q;

			auto c = int{ 1 };
			for (int i = 1; i < n; ++i) {
				auto l = q - i;
				auto r = q + i;
				if (l < 0 || n <= r) {
					break;
				}

				if (s[l] == s[r]) {
					++c;
				}
				else {
					break;
				}
			}

			s[q] ^= 1;
			for (int i = 1; i < c; ++i) {
				s[q - i] ^= 1;
				s[q + i] ^= 1;
			}
		}
	}

	auto c = int{ 0 };
	for (const auto& v : s) {
		cout << v << ' ';
		++c;
		if (20 == c) {
			cout << '\n';
			c -= 20;
		}
	}

	return 0;
}