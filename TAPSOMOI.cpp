#include <iostream>
using namespace std;

class TapSoMoi {
private:
	int x, y, z, t;
public:
	TapSoMoi() {
		x = 0; y = 0; z = 0; t = 0;
	}
	TapSoMoi(int a, int b, int c, int d) : x(a), y(b), z(c), t(d) {}
	TapSoMoi(const TapSoMoi& p) : x(p.x), y(p.y), z(p.z), t(p.t) {}
	int tong() {
		return x + y + z + t;
	}
	friend istream& operator >> (istream& in, TapSoMoi& p) {
		in >> p.x >> p.y >> p.z >> p.t;
		return in;
	}
	friend ostream& operator << (ostream& out, const TapSoMoi& p) {
		out << "[TapSoMoi] " << p.x << ";" << p.y << ";" << p.z << ";" << p.t << endl;
		return out;
	}
	TapSoMoi operator + (const TapSoMoi& p) const {
		return TapSoMoi(x + p.x, y + p.y, z + p.z, t + p.t);
	}
	bool operator < (const TapSoMoi& p) const {
		return x+y+z+t < p.x + p.y+p.z+p.t;
	}
	TapSoMoi& operator = (const TapSoMoi& p) {
		if (this != &p) {
			x = p.x;
			y = p.y;
			z = p.z;
			t = p.t;
		}
		return *this;
	}
	TapSoMoi& operator ++() {
		x = x + 1;
		t = t + 1;
		return *this;
	}
};
int main() {
	TapSoMoi a, b;
	cin >> a >> b;
	cout << a << b;
	if (a < b) cout << "true";
	else cout << "false";
	cout << endl;
	cout << a + b;
	++a;
	cout << a;
}