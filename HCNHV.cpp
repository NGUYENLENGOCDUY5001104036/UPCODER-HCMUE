#include <iostream>
#include <string>
#include <vector>

using namespace std;
class HCN {
private:
	double l, w;
public:
	double getL() const { return l; }
	double getW() const { return w; }
	void setL(double x) { l = x; }
	void setW(double x) { w = x; }
	void set(double dai, double rong) { l = dai; w = rong; }

	HCN(double x=1, double y=1) : l(x), w(y) {}
	HCN(const HCN &p) : l(p.l), w(p.w) {}
	~HCN() {}
	double cv() const{
		return (l + w)*2;
	}
	double dt() const{
		return l * w;
	}
	friend istream& operator >> (istream& in, HCN& p) {
		in >> p.l >> p.w;
		return in;
	}
	friend ostream& operator << (ostream& out, const HCN& p) {
		out << p.cv();
		return out;
	}
	bool operator > (const HCN& p) const{
		return cv() > p.cv();
	}
};
class HV : public HCN {
private:
	double canh;
public:
	double getCanh() const { return canh; }
	void setCanh(double x) { canh = x; }
	void set(double _canh = 1) { 
		canh = _canh;
		HCN::set(canh, canh);
	}

	HV(double x=1) : canh(x), HCN(canh,canh) {}
	HV(const HV& p) : canh(p.canh), HCN(canh,canh) {}
	~HV() {}
	double cv() const {
		return HCN::cv();
	}
	double dt() const {
		return HCN::dt();
	}
	friend istream& operator >> (istream& in, HV& p) {
		in >> p.canh;
		p.set(p.canh);
		return in;
	}
	friend ostream& operator << (ostream& out, const HV& p) {
		out << p.cv();
		return out;
	}
	bool operator > (const HV& p) const{
		return cv() > p.cv();
	}
};
int main() {
	string str;
	double max = 0;
	getline(cin, str);
	if (str == "HCN") {
		HCN hcn[100];
		int n = 0;
		while (cin >> hcn[n]) {
			if(hcn[n].cv() > max)
			max = hcn[n].cv();
			n++;
		}
		cout << max;
	}
	else if (str == "HV") {
		HV hv[100];
		int n = 0;
		while (cin >> hv[n]) {
			if (hv[n].cv() > max)
				max = hv[n].cv();
			n++;
		}
		cout << max;
	}
}
