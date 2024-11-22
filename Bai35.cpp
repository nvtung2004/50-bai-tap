#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;

class TaiLieu{ 
	private:
		int maTaiLieu;
		string tenTaiLieu;
		int namXuatBan;
		float giaBan;
	
	public:
		void nhapThongTinTaiLieu(){
			cout << "Nhap ma tai lieu: ";           cin >> this->maTaiLieu;
			cout << "Nhap ten tai lieu: ";          cin.ignore(); getline(cin, this->tenTaiLieu);
			cout << "Nhap nam xuat ban: ";          cin >> this->namXuatBan;
			cout << "Nhap gia ban: ";                cin >> this->giaBan;
		}
		void xuatThongTinTaiLieu() const{
			cout << setw(15) << left << this->maTaiLieu
				<< setw(20) << left << this->tenTaiLieu
				<< setw(15) << left << this->namXuatBan
				<< setw(15) << left << this->giaBan << endl;
		}
		float getGiaBan() const{
			return this->giaBan;
		}
};

class DanhSachTaiLieu{
	private:
		TaiLieu* list;
	public:
		DanhSachTaiLieu(int n){
			list = new TaiLieu[n];
		}
		~DanhSachTaiLieu(){
			delete[] list;
		}
		void nhapDanhSachTaiLieu(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinTaiLieu();
			}
		}
		void xuatDanhSachTaiLieu(int n) const{
			cout << setw(15) << left << "Ma tai lieu"
				<< setw(20) << left << "Ten tai lieu"
				<< setw(15) << left << "Nam xuat ban"
				<< setw(15) << left << "Gia ban" << endl;
			for(int i = 0; i < n; i++){
				list[i].xuatThongTinTaiLieu();
			}
		}
		void bubbleSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = n-1; j > i; j--){
					if(list[j-1].getGiaBan() > list[j].getGiaBan()){
						swap(list[j-1], list[j]);
					} 
				}
			}
		}
};

int isValid(){ //checked
	int n;
	while(true){
		try{
			cin >> n;
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Kieu du lieu khong hop le. Yeu cau nhap lai.");
			}
			if(n <= 0){
				throw invalid_argument("Vui long nhap so nguyen duong. Yeu cau nhap lai.");
			}
			break;
		} catch(const exception& ex){
			cout << ex.what() << endl;
		}
	}
	return n;
}

int main(){
	int n;
	cout << "Nhap n: ";
	n = isValid();
	DanhSachTaiLieu* list = new DanhSachTaiLieu(n);
	list->nhapDanhSachTaiLieu(n);
	cout << "Danh sach tai lieu vua nhap: " << endl;
	list->xuatDanhSachTaiLieu(n);
	
	list->bubbleSort(n);
	cout << "Danh sach tai lieu sau khi sap xep theo gia ban: " << endl;
	list->xuatDanhSachTaiLieu(n);
	
	delete list; 
	return 0;
}

