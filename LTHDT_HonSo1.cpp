#include <iostream>
#include <algorithm>

using namespace std;
class PhanSo {
private:
	int tu, mau;
public:
	int getTu() const{ return tu; }
	void setTu(int x) { tu = x; }
	int getMau() const{ return mau; }
	void getMau(int y) { mau = y; }

	PhanSo(int x=1, int y=1) : tu(x), mau(y) {}
	PhanSo(const PhanSo &p) : tu(p.tu), mau(p.mau) {}
	~PhanSo() {}
	void set(int x = 1, int y = 1) {
		tu = x; mau = y;
	}

	friend istream& operator >> (istream& in, PhanSo& p) {
		in >> p.tu >> p.mau;
		return in;
	}
	friend ostream& operator << (ostream& out, const PhanSo& p) {
		out << p.tu << "/" << p.mau;
		return out;
	}
	PhanSo operator + (const PhanSo& p) const{
		return PhanSo(tu * p.mau + mau * p.tu, mau*p.mau);
	}
};
class HonSo : public PhanSo{
private:
	int nguyen;
public:
	int getNguyen() const { return nguyen; }
	void setNguyen(int n) { nguyen = n; }

	HonSo(int n = 1, int x=1, int y=1) : nguyen(n) ,PhanSo(x,y) {}
	HonSo(const HonSo &p) : nguyen(p.nguyen), PhanSo(p) {}
	~HonSo() {}

	friend istream& operator >> (istream& in, HonSo& p) {
		in >> p.nguyen >> (PhanSo&)p;
		return in;
	}
	friend ostream& operator << (ostream & out, const HonSo & p) {
		out << p.nguyen << " " << (PhanSo&)p;
		return out;
	}

	HonSo operator + (const HonSo& p) const{
		return HonSo(nguyen + p.nguyen, getTu() * p.getMau() + getMau() * p.getTu(), getMau()*p.getMau() );
	}
};
int main() {
	HonSo a, b;
	cin >> a >> b;
	cout << (a + b);
}