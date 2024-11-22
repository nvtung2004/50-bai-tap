#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

class MonHoc {
    private:
        int maMH;
        string tenMH;
        int soTinChi;
        int soTietDaGiangDay;
    public:
        void nhapThongTinMonHoc() {
            cout << "Nhap ma mon hoc: ";
            cin >> this->maMH;
            cout << "Nhap ten mon hoc: ";
            cin.ignore();
            getline(cin, this->tenMH);
            cout << "Nhap so tin chi: ";
            cin >> this->soTinChi;
            cout << "Nhap so tiet da giang day: ";
            cin >> this->soTietDaGiangDay;
        }
        void xuatThongTinMonHoc() const {
            cout << setw(15) << left << this->maMH
                 << setw(30) << left << this->tenMH
                 << setw(15) << left << this->soTinChi
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
        void nhapDanhSach(int n) {
            for (int i = 0; i < n; i++) {
                cout << "Nhap thong tin mon hoc thu " << i + 1 << ":" << endl;
                list[i].nhapThongTinMonHoc();
            }
        }
        void xuatDanhSach(int n) const {
            cout << setw(15) << left << "Ma MH"
                 << setw(30) << left << "Ten MH"
                 << setw(15) << left << "So tin chi"
                 << setw(20) << left << "So tiet da giang day" << endl;
            for (int i = 0; i < n; i++) {
                list[i].xuatThongTinMonHoc();
            }
        }
        //pp sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if(list[i].getSoTietDaGiangDay() > list[j].getSoTietDaGiangDay()){
						swap(list[i], list[j]);
					}
				}
			}
		}
		//pp sx chon truc tiep
		void selectionSort(int n){
			for(int i = 0; i < n-1; i++){
				int tmp = i;
				for(int j = i+1; j < n; j++){
					if(list[tmp].getSoTietDaGiangDay() > list[j].getSoTietDaGiangDay()){
						tmp = j;
					}
				}
				if(tmp != i){
					swap(list[i], list[tmp]);
				}
			}
		}
		//pp sx chen truc tiep
		void insertionSort(int n){
			for(int i = 1; i < n; i++){
				MonHoc tmp = list[i];
				int pos = i-1;
				while(pos>=0 && tmp.getSoTietDaGiangDay() < list[pos].getSoTietDaGiangDay()){
					list[pos+1] = list[pos];
					pos-=1;
				}
				list[pos+1] = tmp;
			}
		}
		//pp sx noi bot
		void bubbleSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = n-1; j>i; j--){
					if(list[j].getSoTietDaGiangDay() < list[j-1].getSoTietDaGiangDay()){
						swap(list[j], list[j-1]);
					}
				}
			}
		}
		//pp sx nhanh
		int partition(int low, int high){
			int pivot = high;
			int i = low-1;
			for(int j = low; j < high; j++){
				if(list[j].getSoTietDaGiangDay() < list[pivot].getSoTietDaGiangDay()){
					i+=1;
					swap(list[i], list[j]);
				}
			}
			swap(list[i+1], list[pivot]);
			return i+1;
		}
		void quickSort(int low, int high){
			if(low < high){
				int x = partition(low, high);
				quickSort(low, x-1);
				quickSort(x+1, high);
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
    cout << "Nhap so luong mon hoc: ";
    n = isValid();
    DanhSachMonHoc* danhSach = new DanhSachMonHoc(n);
    danhSach->nhapDanhSach(n);
    cout << "\nDanh sach mon hoc vua nhap:" << endl;
    danhSach->xuatDanhSach(n);

    cout << "\nSap xep danh sach mon hoc theo so tiet da giang day tang dan:" << endl;
    danhSach->selectionSort(n);
    danhSach->xuatDanhSach(n);

    delete danhSach;
    return 0;
}

