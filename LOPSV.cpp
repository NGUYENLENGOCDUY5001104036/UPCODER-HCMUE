#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Nguoi {
private:
	string hoten;
	int nam;
	string quequan;
public:
	string getHoten() { return hoten; }
	int getNam() { return nam; }
	string getQuequan() { return quequan; }
	void setHoten(string h) { hoten = h; }
	void setNam(int n) { nam = n; }
	void setQuequan(string q) { quequan = q; }

	Nguoi(string h = "hoten", int n=2000, string q ="quequan") : hoten(h), nam(n), quequan(q) {}
	Nguoi(const Nguoi &p) : hoten(p.hoten), nam(p.nam), quequan(p.quequan) {}
	~Nguoi() {}
	void set(string h = "hoten", int n = 2000, string q = "quequan") {
		hoten = h;
		nam = n;
		quequan = q;
	}

	friend istream& operator >> (istream& in, Nguoi& p) {
		getline(in, p.hoten);
		in >> p.nam;
		in.ignore();
		getline(in, p.quequan);
		return in;
	}
	friend ostream& operator << (ostream& out, const Nguoi& p) {
		out << "Ho Ten: " << p.hoten << endl;
		out << "Nam Sinh: " << p.nam << endl;
		out << "Que Quan: " << p.quequan << endl;
		return out;
	}
};
class SinhVien : public Nguoi{
private :
	string khoa;
	double diem[10];
	int n;
public:
	string getKhoa() { return khoa; }
	void setKhoa(string k) { khoa = k; }
	double& operator[](int i) { return diem[i]; }

	SinhVien(string h = "hoten", int n = 2000, string q = "quequan", string k="CNTT", double _diem[] = new double[1], int _n=0) : Nguoi(h, n, q) {
		khoa = k;
		n = _n;
		for (int i = 0; i < n; i++) {
			diem[i] = _diem[i];
		}
	}
	SinhVien(const SinhVien& p) : Nguoi(p) {
		khoa = p.khoa;
		n = p.n;
		for (int i = 0; i < n; i++) {
			diem[i] = p.diem[i];
		}
	}
	~SinhVien() {}

	friend istream &operator >> (istream &in, SinhVien &p) {
		in >> (Nguoi&)p;
		getline(in, p.khoa);
		p.n = 0;
		while (in >> p.diem[p.n]) p.n++;
		return in;
	}
	friend ostream& operator << (ostream& out, const SinhVien& p) {
		out << (Nguoi&)p;
		out << "Khoa: " << p.khoa << endl;
		out << "Diem cac mon: ";
		for (int i = 0; i < p.n; i++) {
			out << p.diem[i] << " ";
		}
		out << endl << "Diem trung binh: " << fixed << setprecision(2) << p.dtb() << endl;
	}
	double dtb() const{
		double kq = 0;
		for (int i = 0; i < n; i++) {
			kq += diem[i];
		}
		return kq / n;
	}
};
int main() {
	SinhVien p;
	cin >> p;
	cout << p;
}