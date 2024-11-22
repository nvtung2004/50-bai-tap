#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

class MonHoc { //checked
private:
    int maMonHoc;
    string tenMonHoc;
    int soTinChi;
    int soTietDaGiangDay;

public:
    void nhapThongTinMonHoc() {
        cout << "Nhap ma mon hoc: ";            cin >> this->maMonHoc;
        cout << "Nhap ten mon hoc: ";           cin.ignore(); getline(cin, this->tenMonHoc);
        cout << "Nhap so tin chi: ";             cin >> this->soTinChi;
        cout << "Nhap so tiet da giang day: ";   cin >> this->soTietDaGiangDay;
    }
    
    void xuatThongTinMonHoc() const {
        cout << setw(15) << left << this->maMonHoc
             << setw(20) << left << this->tenMonHoc
             << setw(10) << left << this->soTinChi
             << setw(20) << left << this->soTietDaGiangDay << endl;
    }
    
    int getSoTietDaGiangDay() const {
        return this->soTietDaGiangDay;
    }
};

class DanhSachMonHoc {
private:
    MonHoc* list;

public:
    DanhSachMonHoc(int n) {
        list = new MonHoc[n];
    }
    
    ~DanhSachMonHoc() {
        delete[] list;
    }
    
    void nhapDanhSachMonHoc(int n) {
        for (int i = 0; i < n; i++) {
            list[i].nhapThongTinMonHoc();
        }
    }
    
    void xuatDanhSachMonHoc(int n) const {
        cout << setw(15) << left << "Ma MH"
             << setw(20) << left << "Ten MH"
             << setw(10) << left << "So TC"
             << setw(20) << left << "So tiet giang" << endl;
        for (int i = 0; i < n; i++) {
            list[i].xuatThongTinMonHoc();
        }
    }
    
    void bubbleSort(int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j > i; j--) {
                if (list[j - 1].getSoTietDaGiangDay() > list[j].getSoTietDaGiangDay()) {
                    swap(list[j - 1], list[j]);
                }
            }
        }
    }
    
};

int isValid() { //checked
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
    cout << "Nhap n: ";
    n = isValid();
    
    DanhSachMonHoc* list = new DanhSachMonHoc(n);
    list->nhapDanhSachMonHoc(n);
    cout << "Danh sach mon hoc vua nhap: " << endl;
    list->xuatDanhSachMonHoc(n);
    
    list->bubbleSort(n);
    cout << "Danh sach mon hoc sau khi sap xep theo so tiet da giang: " << endl;
    list->xuatDanhSachMonHoc(n);
    

    delete list;
    return 0;
}

