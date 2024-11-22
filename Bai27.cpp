#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;
class VeMayBay{
	private:
		int maVe;
		string khoiHanh, diemDen;
		float giaVe;
	public:
		void nhapThongTinVe(){
			cout<<"Nhap ma ve: ";			cin>>this->maVe;
			cout<<"Nhap diem khoi hanh: ";	cin.ignore(); getline(cin, this->khoiHanh);
			cout<<"Nhap diem den: ";		getline(cin, this->diemDen);
			cout<<"Nhap gia ve: ";			cin>>this->giaVe;
		} 
		void xuatThongTinVe() const{
			cout<<setw(15)<<left<<this->maVe
				<<setw(25)<<left<<this->khoiHanh
				<<setw(25)<<left<<this->diemDen
				<<setw(15)<<left<<this->giaVe<<endl;
		}
		float getGiaVe() const{
			return this->giaVe;
		}
}; 

class DanhSachVeMayBay{
	private:
		VeMayBay* list;
	public:
		DanhSachVeMayBay(int n){
			list = new VeMayBay[n];
		}
		~DanhSachVeMayBay(){
			delete[] list;
		}
		void nhapDanhSach(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinVe();
			}
		}
		void xuatDanhSach(int n){
			cout<<setw(15)<<left<<"Ma ve"
				<<setw(25)<<left<<"Diem khoi hanh"
				<<setw(25)<<left<<"Diem den"
				<<setw(15)<<left<<"Gia ve"<<endl;
			for(int i = 0; i < n; i++){
				list[i].xuatThongTinVe();
			}
		}
		//pp sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if(list[i].getGiaVe() > list[j].getGiaVe()){
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
					if(list[tmp].getGiaVe() > list[j].getGiaVe()){
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
				VeMayBay tmp = list[i];
				int pos = i-1;
				while(pos>=0 && tmp.getGiaVe() < list[pos].getGiaVe()){
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
					if(list[j].getGiaVe() < list[j-1].getGiaVe()){
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
				if(list[j].getGiaVe() < list[pivot].getGiaVe()){
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
	DanhSachVeMayBay* list = new DanhSachVeMayBay(n);
	list->nhapDanhSach(n);
	list->xuatDanhSach(n);
	cout<<"Sap xep danh sach ve may bay tang dan theo gia ve: "<<endl;
	//list->interchangeSort(n);
	//list->selectionSort(n);
	//list->insertionSort(n);
	//list->bubbleSort(n);
	list->quickSort(0, n-1); 
	list->xuatDanhSach(n);
	return 0;
}
