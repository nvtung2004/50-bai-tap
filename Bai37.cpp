#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class DuAn { //checked
private:
    int maDuAn;
    string tenDuAn;
    float tongKinhPhi;

public:
    void nhapThongTinDuAn() {
        cout << "Nhap ma du an: ";                cin >> this->maDuAn;
        cout << "Nhap ten du an: ";               cin.ignore(); getline(cin, this->tenDuAn);
        cout << "Nhap tong kinh phi (ty dong): "; cin >> this->tongKinhPhi;
    }
    
    void xuatThongTinDuAn() const {
        cout << setw(15) << left << this->maDuAn
             << setw(20) << left << this->tenDuAn
             << setw(15) << left << this->tongKinhPhi << endl;
    }
    
    float getTongKinhPhi() const {
        return this->tongKinhPhi;
    }
};

class DanhSachDuAn {
private:
    DuAn* list;

public:
    DanhSachDuAn(int n) {
        list = new DuAn[n];
    }
    
    ~DanhSachDuAn() {
        delete[] list;
    }
    
    void nhapDanhSachDuAn(int n) {
        for (int i = 0; i < n; i++) {
            list[i].nhapThongTinDuAn();
        }
    }
    
    void xuatDanhSachDuAn(int n) const {
        cout << setw(15) << left << "Ma du an"
             << setw(20) << left << "Ten du an"
             << setw(15) << left << "Tong kinh phi" << endl;
        for (int i = 0; i < n; i++) {
            list[i].xuatThongTinDuAn();
        }
    }
    
    void bubbleSort(int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j > i; j--) {
                if (list[j - 1].getTongKinhPhi() > list[j].getTongKinhPhi()) {
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
    
    DanhSachDuAn* list = new DanhSachDuAn(n);
    list->nhapDanhSachDuAn(n);
    cout << "Danh sach du an vua nhap: " << endl;
    list->xuatDanhSachDuAn(n);
    
    list->bubbleSort(n);
    cout << "Danh sach du an sau khi sap xep theo tong kinh phi: " << endl;
    list->xuatDanhSachDuAn(n);

    
    delete list; 
    return 0;
}

