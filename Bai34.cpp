#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class Date{ //checked
	private:
		int ngay, thang, nam;
	
	public:
		void nhapNgay(){
			cout<<"Nhap ngay: ";	cin>>this->ngay;
			cout<<"Nhap thang: ";	cin>>this->thang;
			cout<<"Nhap nam: ";		cin>>this->nam;
		}
		string hienThiNgay() const{ // ham nay k lam thay doi du lieu attribute
			return to_string(ngay)+"/"+to_string(thang)+"/"+to_string(nam);
		}
};

class NhanVien {
    private:
        int maNV;
        string hoTen;
        Date ngaySinh;
        float luong;
    public:
        void nhapThongTinNhanVien() {
            cout << "Nhap ma nhan vien: ";
            cin >> this->maNV;
            cout << "Nhap ho ten nhan vien: ";
            cin.ignore();
            getline(cin, this->hoTen);
            this->ngaySinh.nhapNgay();
            cout << "Nhap luong (trieu dong): ";
            cin >> this->luong;
        }

        void xuatThongTinNhanVien() const {
            cout << setw(15) << left << this->maNV
                 << setw(30) << left << this->hoTen
                 << setw(15) << left << this->ngaySinh.hienThiNgay()
                 << setw(15) << left << this->luong << endl;
        }

        float getLuong() const {
            return this->luong;
        }
};

class DanhSachNhanVien {
    private:
        NhanVien* list;
    public:
        DanhSachNhanVien(int n) {
            list = new NhanVien[n];
        }
        
        ~DanhSachNhanVien() {
            delete[] list;
        }

        void nhapDanhSach(int n) {
            for (int i = 0; i < n; i++) {
                cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
                list[i].nhapThongTinNhanVien();
            }
        }

        void xuatDanhSach(int n) const {
            cout << setw(15) << left << "Ma NV"
                 << setw(30) << left << "Ho Ten"
                 << setw(15) << left << "Ngay Sinh"
                 << setw(15) << left << "Luong" << endl;
            for (int i = 0; i < n; i++) {
                list[i].xuatThongTinNhanVien();
            }
        }

        // Phuong phap sap xep noi bot (Bubble sort) theo luong
        void bubbleSort(int n) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = n - 1; j > i; j--) {
                    if (list[j].getLuong() < list[j - 1].getLuong()) {
                        swap(list[j], list[j - 1]);
                    }
                }
            }
        }
};

int isValid() {
    int n;
    while (true) {
        try {
            cin >> n;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Kieu du lieu khong hop le. Yeu cau nhap lai.");
            }
            if (n <= 0) {
                throw invalid_argument("Vui long nhap so nguyen duong. Yeu cau nhap lai.");
            }
            break;
        } catch (const exception& ex) {
            cout << ex.what() << endl;
        }
    }
    return n;
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    n = isValid();
    DanhSachNhanVien* danhSach = new DanhSachNhanVien(n);
    danhSach->nhapDanhSach(n);

    cout << "\nDanh sach nhan vien vua nhap:" << endl;
    danhSach->xuatDanhSach(n);

    cout << "\nSap xep danh sach nhan vien theo luong tang dan:" << endl;
    danhSach->bubbleSort(n);
    danhSach->xuatDanhSach(n);

    delete danhSach;
    return 0;
}

