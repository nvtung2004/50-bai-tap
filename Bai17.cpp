#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct TaiLieu{
	int maTL, namXB;
	string tenTL;
	float giaBan;
};

void nhapThongTin(TaiLieu& tl){
	cout<<"Nhap ma tai lieu: ";		cin>>tl.maTL;
	cout<<"Nhap ten tai lieu: ";	cin.ignore();	getline(cin, tl.tenTL);
	cout<<"Nhap nam xuat ban: ";	cin>>tl.namXB;
	cout<<"Nhap gia ban: ";			cin>>tl.giaBan;
}

TaiLieu* nhapMang(int n){
	TaiLieu* array = new TaiLieu[n];
	if(array == NULL){
		exit(1);
	}
	else{
		cout<<"Nhap thong tin: "<<endl;
		for(int i = 0; i < n; i++){
			cout<<"Nhap thong tin tai lieu thu "<<i+1<<endl;
			nhapThongTin(array[i]);
		}
		return array;
	}
}

void xuatThongTin(TaiLieu tl){
	cout<<setw(20)<<left<<tl.maTL
		<<setw(30)<<left<<tl.tenTL
		<<setw(20)<<left<<tl.namXB
		<<setw(20)<<left<<tl.giaBan<<endl;
}

void xuatMang(TaiLieu* array, int n){
	cout<<"Xuat thong tin: "<<endl;
	cout<<setw(20)<<left<<"Ma tai lieu"
		<<setw(30)<<left<<"Ten tai lieu"
		<<setw(20)<<left<<"Nam xuat ban"
		<<setw(20)<<left<<"Gia ban(vnd)"<<endl;
	for(int i = 0; i < n; i++){
		xuatThongTin(array[i]);
	}
}

// đổi chỗ trực tiếp
void interchangeSort(TaiLieu* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j< n; j++){
			if(arr[i].giaBan > arr[j].giaBan){
				swap(arr[i], arr[j]);
			}
		}
	}
}

//chọn trực tiếp
void selectionSort(TaiLieu* arr, int n){
	for(int i = 0; i < n-1; i++){
		int tmp = i;
		for(int j = i+1; j < n; j++){
			if(arr[tmp].giaBan > arr[j].giaBan){
				tmp = j;
			}
		}
		if(tmp != i){
			swap(arr[i], arr[tmp]);
		}
	}
}

//nổi bọt
void bubbleSort(TaiLieu* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j].giaBan > arr[j+1].giaBan){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

// chèn trực tiếp
void insertionSort_giaBan(TaiLieu* array, int n){
	for(int i = 1; i < n ;i++){
		int j = i-1;
		TaiLieu tmp = array[i];
		while(j >= 0 && array[j].giaBan>tmp.giaBan){
			array[j+1] = array[j];
			j-=1;
		}
		array[j+1] = tmp;
	}
}

int main(){
	int n;
	do{
		cout<<"Nhap so luong tai lieu: ";
		cin>>n;
	}while(n<=0);
	TaiLieu* dsTaiLieu = nhapMang(n);
	xuatMang(dsTaiLieu, n);
	insertionSort_giaBan(dsTaiLieu, n);
	xuatMang(dsTaiLieu, n);
	delete[] dsTaiLieu;
	return 0;
}
