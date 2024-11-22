#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<limits>

using namespace std;

class DuAn{
	private:
		int maDA;
		string tenDA;
		float tongKinhPhi;
	public:
		void nhapThongTinDuAn(){
			cout<<"Nhap ma du an: ";
			cin>>this->maDA;
			cout<<"Nhap ten du an: ";
			cin.ignore();
			getline(cin, this->tenDA);
			cout<<"Nhap tong kinh phi: ";
			cin>>this->tongKinhPhi; 
		}
		void xuatThongTinDuAn() const{
			cout<<setw(15)<<left<<this->maDA
				<<setw(30)<<left<<this->tenDA
				<<setw(30)<<left<<this->tongKinhPhi<<endl;
		}
		float getTongKinhPhi() const{
			return this->tongKinhPhi;
		}
};

class DanhSachDuAn{
	private:
		DuAn* list;
	public:
		DanhSachDuAn(int n){
			list = new DuAn[n];
		}
		~DanhSachDuAn(){
			delete[] list;
		}
		void nhapDanhSach(int n){
			for(int i = 0; i < n; i++){
				list[i].nhapThongTinDuAn();
			}
		}
		void xuatDanhSach(int n){
			cout<<setw(15)<<left<<"Ma du an"
				<<setw(30)<<left<<"Ten du an"
				<<setw(30)<<left<<"Tong kinh phi"<<endl;
			for(int i = 0; i < n; i++){
				list[i].xuatThongTinDuAn();
			}
		}
		//pp sx doi cho truc tiep
		void interchangeSort(int n){
			for(int i = 0; i < n-1; i++){
				for(int j = i+1; j < n; j++){
					if(list[i].getTongKinhPhi() > list[j].getTongKinhPhi()){
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
					if(list[tmp].getTongKinhPhi() > list[j].getTongKinhPhi()){
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
				DuAn tmp = list[i];
				int pos = i-1;
				while(pos>=0 && tmp.getTongKinhPhi() < list[pos].getTongKinhPhi()){
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
					if(list[j].getTongKinhPhi() < list[j-1].getTongKinhPhi()){
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
				if(list[j].getTongKinhPhi() < list[pivot].getTongKinhPhi()){
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
	DanhSachDuAn* list = new DanhSachDuAn(n);
	list->nhapDanhSach(n);
	list->xuatDanhSach(n);
	cout<<"Sap xep danh sach du an tang dan theo tong kinh phi: "<<endl;
	list->interchangeSort(n);
	//list->selectionSort(n);
	//list->insertionSort(n);
	//list->bubbleSort(n);
	//list->quickSort(0, n-1); 
	list->xuatDanhSach(n);
	return 0;
}
