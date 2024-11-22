#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class SinhVien {
    private:
        int maSV;
        string tenSV;
        string lop;
        float tongKet;
    public:
        void nhapThongTinSinhVien() {
            cout << "Nhap ma sinh vien: ";
            cin >> this->maSV;
            cout << "Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin, this->tenSV);
            cout << "Nhap lop: ";
            getline(cin, this->lop);
            cout << "Nhap tong ket: ";
            cin >> this->tongKet;
        }
        void xuatThongTinSinhVien() const {
            cout << setw(10) << left << this->maSV
                 << setw(20) << left << this->tenSV
                 << setw(10) << left << this->lop
                 << setw(10) << left << this->tongKet << endl;
        }
        float getTongKet() const {
            return this->tongKet;
        }
};

class DanhSachSinhVien {
    private:
        SinhVien* list;
    public:
        DanhSachSinhVien(int n) {
            list = new SinhVien[n];
        }
        ~DanhSachSinhVien() {
            delete[] list;
        }
        void nhapDanhSach(int n) {
            for (int i = 0; i < n; i++) {
                cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
                list[i].nhapThongTinSinhVien();
            }
        }
        void xuatDanhSach(int n) const {
            cout << setw(10) << left << "Ma SV"
                 << setw(20) << left << "Ten SV"
                 << setw(10) << left << "Lop"
                 << setw(10) << left << "Tong ket" << endl;
            for (int i = 0; i < n; i++) {
                list[i].xuatThongTinSinhVien();
            }
        }
        // Phuong phap sap xep noi bot theo tong ket
        void bubbleSort(int n) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = n - 1; j > i; j--) {
                    if (list[j].getTongKet() < list[j - 1].getTongKet()) {
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
    cout << "Nhap so luong sinh vien: ";
    n = isValid();
    DanhSachSinhVien* danhSach = new DanhSachSinhVien(n);
    danhSach->nhapDanhSach(n);
    cout << "\nDanh sach sinh vien vua nhap:" << endl;
    danhSach->xuatDanhSach(n);

    cout << "\nSap xep danh sach sinh vien theo tong ket tang dan:" << endl;
    danhSach->bubbleSort(n);
    danhSach->xuatDanhSach(n);

    delete danhSach;
    return 0;
}

