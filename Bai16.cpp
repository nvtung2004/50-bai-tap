#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct date{
	int day, month, year;
};
struct NhanVien{
	int maNV;
	string hoTen;
	date ngaySinh;
	float luong;
};

void nhapThonTin(NhanVien* nv){
	cout<<"Nhap ma nhan vien: ";					cin>>nv->maNV;
	cout<<"Nhap ho ten nhan vien: ";				cin.ignore();	getline(cin, nv->hoTen);
	cout<<"Nhap ngay sinh (d/m/y): ";				cin>>nv->ngaySinh.day>>nv->ngaySinh.month>>nv->ngaySinh.year;
	cout<<"Nhap luong (dong vi la trieu dong): ";	cin>>nv->luong;
}

NhanVien* nhapMang(int n){
	NhanVien* array = new NhanVien[n];
	if(array == NULL){
		return NULL;
	}
	else{
		cout<<"Nhap thong tin: "<<endl;
		for(int i = 0; i < n; i++){
			nhapThonTin(&array[i]);
		}
		return array;
	}
}

void xuatThongTin(NhanVien* nv){
	string ngaySinh = to_string(nv->ngaySinh.day)+"/"+to_string(nv->ngaySinh.month)+"/"+to_string(nv->ngaySinh.year);
	cout<<setw(20)<<left<<nv->maNV
		<<setw(30)<<left<<nv->hoTen
		<<setw(20)<<left<<ngaySinh
		<<setw(30)<<left<<nv->luong<<endl;
}

void xuatMang(NhanVien* array, int n){
	cout<<"Xuat thong tin: "<<endl;
	cout<<setw(20)<<left<<"Ma nhan vien"
		<<setw(30)<<left<<"Ho va ten"
		<<setw(20)<<left<<"Ngay sinh"
		<<setw(30)<<left<<"Luong(don vi trieu dong)"<<endl;
	for(int i = 0; i < n; i++){
		xuatThongTin(&array[i]);
	}
}

//đổi chỗ trực tiếp
void interchangeSort(NhanVien* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i].luong > arr[j].luong){
				swap(arr[i], arr[j]);
			}
		}
	}
}

//chọn trực tiếp
void selectionSort(NhanVien* arr, int n){
	for(int i = 0; i < n-1; i++){
		int tmp = i;
		for(int j = i+1; j < n; j++){
			if(arr[tmp].luong > arr[j].luong){
				tmp = j;
			}
		}
		if(tmp != i){
			swap(arr[i], arr[tmp]);
		}
	}
}

//nổi bọt
void bubbleSort(NhanVien* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j].luong > arr[j+1].luong){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

//chèn trực tiếp
void insertionSort_luong(NhanVien* array, int n){
	for(int i = 1; i < n; i++){
		int j = i-1;
		NhanVien tmp = array[i];
		while(j >= 0 && array[j].luong>tmp.luong){
			array[j+1] = array[j];
			j-=1;
		}
		array[j+1]=tmp;
	}
}

int main(){
	int n;
	do{
		cout<<"Nhap so luong nhan vien: ";
		cin>>n;
	}while(n <= 0);
	NhanVien* dsNhanVien = nhapMang(n);
	xuatMang(dsNhanVien, n);
	insertionSort_luong(dsNhanVien, n);
	cout<<"Sau khi sap xep: "<<endl;
	//xuatMang(dsNhanVien, n);
	
	delete[] dsNhanVien;
	return 0;
		
}
