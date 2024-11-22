#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
using namespace std;
class VanDongVien{
    private:
        int maVDV;
        string tenVDV;
        int tuoi;
        float luong;
    public:
        void nhapThongTin(){
            cout<<"Nhap ma van dong vien: ";
            cin>>this->maVDV;
            cout<<"Nhap ten van dong vien: ";
            cin.ignore();
            getline(cin, this->tenVDV);
            cout<<"Nhap tuoi: ";
            cin>>this->tuoi;
            cout<<"Nhap luong: ";
            cin>>this->luong;
        }
        void hienThiThongTin(){
            cout<<setw(20)<<left<<this->maVDV
                <<setw(30)<<left<<this->tenVDV
                <<setw(10)<<left<<this->tuoi
                <<setw(20)<<left<<this->luong<<endl;
        }
        float getLuong(){
        	return this->luong;
		}
};

VanDongVien* nhapMang(int n){
	VanDongVien* arr = new VanDongVien[n];
	if(arr == NULL){
		cout<<"Khong du bo nho de cap phat.";
		exit(1);
	} else {
		for(int i = 0; i < n; i++){
			arr[i].nhapThongTin();
		}
		return arr;
	}
}

void hienThiMang(VanDongVien* arr, int n){
	for(int i = 0; i < n; i++){
		arr[i].hienThiThongTin();
	}
}

//pp sx doi cho truc tiep
void interchangeSort(VanDongVien* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i].getLuong() > arr[j].getLuong()){
				swap(arr[i], arr[j]);
			}
		}
	}
}

//pp sx chon truc tiep
void selectionSort(VanDongVien* arr, int n){
	for(int i = 0; i < n-1; i++){
		int tmp = i;
		for(int j = i+1; j < n; j++){
			if(arr[tmp].getLuong()>arr[j].getLuong()){
				tmp = j;
			}
		}
		if(tmp != i){
			swap(arr[i], arr[tmp]);
		}
	}
}

//pp sx chen truc tiep
void insertionSort(VanDongVien* arr, int n){
	for(int i = 1; i < n; i++){
		VanDongVien tmp = arr[i];
		int pos = i-1;
		while(pos >= 0 && tmp.getLuong()<arr[pos].getLuong()){
			arr[pos+1] = arr[pos];
			pos -= 1;
		}
		arr[pos+1] = tmp;
	}
}

//pp sx noi bot
void bubbleSort(VanDongVien* arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j<n-1-i; j++){
			if(arr[j].getLuong()>arr[j+1].getLuong()){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int phanVung(VanDongVien* arr, int low, int high){
	int pivot = high;
	int i = low -1;
	for(int j = low; j<high-1; j++){
		if(arr[j].getLuong()<arr[pivot].getLuong()){
			i+=1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[pivot], arr[i+1]);
	return i+1;
}

void quickSort(VanDongVien* arr, int low, int high){
	if(low<high){
		int x = phanVung(arr, low, high);
		quickSort(arr, low, x-1);
		quickSort(arr, x+1, high);
	}
}




int main(){
	
	//nhap so luong van dong vien
    int n;
    do{
    	cout<<"Nhap so nguyen duong n: ";
    	cin>>n;
	}while(n<=0);
	
	//nhap thong tin cho van dong vien
	cout<<"Nhap mang: \n";
	VanDongVien* arr = nhapMang(n);
	
	//hien thi mang vua nhap
	cout<<"Mang vua nhap la: \n";
	cout<<setw(20)<<left<<"Ma VDV"
                <<setw(30)<<left<<"Ten VDV"
                <<setw(10)<<left<<"Tuoi"
                <<setw(20)<<left<<"Luong"<<endl;
    hienThiMang(arr, n);
	//cout<<"Phuong phap sap xep interchange sort: \n";
	//interchangeSort(arr, n);
	//cout<<"Phuong phap sap xep selection sort: \n";
	//selectionSort(arr, n);
	//cout<<"Phuong phap sap xep insertion sort:\n";
	//insertionSort(arr, n);
	//cout<<"Phuong phap sap xep bubble sort: \n";
	//bubbleSort(arr, n);
	cout<<"Phuong phap sap xep quick sort: \n";
	quickSort(arr, 0, n-1);
	cout<<setw(20)<<left<<"Ma VDV"
                <<setw(30)<<left<<"Ten VDV"
                <<setw(10)<<left<<"Tuoi"
                <<setw(20)<<left<<"Luong"<<endl;
    hienThiMang(arr, n);
	
	delete[] arr;
	return 0;
}
