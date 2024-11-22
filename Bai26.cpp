#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;

class TaiLieu{
	private:
		int maTL;
		string tenTL;
		int namXB;
		float giaBan;
	public:
		void nhapThongTinTaiLieu(){
			cout<<"Nhap ma tai lieu: ";		cin>>this->maTL; 
			cout<<"Nhap ten tai lieu: ";	cin.ignore(); getline(cin, this->tenTL); 
			cout<<"Nhap nam xuat ban: ";	cin>>this->namXB;
			cout<<"Nhap gia ban: ";	cin>>this->giaBan;
		} 
		void xuatThongTinTaiLieu() const{
			cout<<setw(15)<<left<<this->maTL
				<<setw(20)<<left<<this->tenTL
				<<setw(15)<<left<<this->namXB
				<<setw(15)<<left<<this->giaBan<<endl;
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
		void nhapDanhSach(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinTaiLieu();
			}
		}
		void xuatDanhSach(int n){
			cout<<setw(15)<<left<<"Ma tai lieu"
				<<setw(20)<<left<<"Ten tai lieu"
				<<setw(15)<<left<<"Nam xuat ban"
				<<setw(15)<<left<<"Gia ban"<<endl;
			for(int i = 0; i < n; i++){
				list[i].xuatThongTinTaiLieu();
			}
		}
		//pp sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if(list[i].getGiaBan() > list[j].getGiaBan()){
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
					if(list[tmp].getGiaBan() > list[j].getGiaBan()){
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
				TaiLieu tmp = list[i];
				int pos = i-1;
				while(pos>=0 && tmp.getGiaBan() < list[pos].getGiaBan()){
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
					if(list[j].getGiaBan() < list[j-1].getGiaBan()){
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
				if(list[j].getGiaBan() < list[pivot].getGiaBan()){
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

int isValid(){ // checked
	int n;
	while(true){
		try{
			cin>>n;
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
			cout<<ex.what()<<endl;
		}
	}
	return n;
}

int main(){
	int n;
	cout<<"Nhap n: ";
	n = isValid();
	DanhSachTaiLieu* list = new DanhSachTaiLieu(n);
	list->nhapDanhSach(n);
	list->xuatDanhSach(n);
	cout<<"Sap xep danh sach tai lieu tang dan theo gia ban: "<<endl;
	list->interchangeSort(n);
	//list->selectionSort(n);
	//list->insertionSort(n);
	//list->bubbleSort(n);
	//list->quickSort(0, n-1); 
	list->xuatDanhSach(n);
	return 0;
}
