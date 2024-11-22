#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class VeMayBay{
	private:
		int maVe;
		string diemKhoiHanh, diemDen;
		float giaVe;
	public:
		void nhapThongTin(){
			cout<<"Nhap ma ve: ";			cin>>this->maVe;
			cout<<"Nhap diem khoi hanh: ";	cin.ignore(); getline(cin, this->diemKhoiHanh);
			cout<<"Nhap diem den: ";		getline(cin, this->diemDen);
			cout<<"Nhap gia ve: ";			cin>>this->giaVe;
		}
		void xuatThongTin(){
			cout<<setw(20)<<left<<this->maVe
				<<setw(30)<<left<<this->diemKhoiHanh
				<<setw(30)<<left<<this->diemDen
				<<setw(20)<<left<<this->giaVe<<endl;
		}
		float getGiaVe(){
			return giaVe;
		}
};

VeMayBay* nhapMang(int n){
	VeMayBay* array = new VeMayBay[n];
	if(array == NULL){
		exit(01);
	}
	else{
		cout<<"Nhap thong tin: "<<endl;
		for(int i = 0; i < n; i++){
			array[i].nhapThongTin();
		}
		return array;
	}
}

void xuatMang(int n, VeMayBay* array){
	for(int i = 0; i < n; i++){
		array[i].xuatThongTin();
	}
}

int partition(VeMayBay* arr, int low, int high) {
    int pivot = high;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].getGiaVe() < arr[pivot].getGiaVe()) {
            i++; 
            swap(arr[i], arr[j]); 
    	}
	}
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(VeMayBay* arr, int low, int high);
int main(){
	int n;
	do{
		cout<<"Nhap so nguyen duong n: ";
		cin>>n;
	}while(n<=0);
	VeMayBay* dsVeMayBay = nhapMang(n);
	cout<<"Mang gom "<<n<<" ve may bay vua nhap la: \n";
	xuatMang(n, dsVeMayBay);
	cout<<"Sap xep theo pp quick sort: \n";
	quickSort(dsVeMayBay, 0, n-1);
	xuatMang(n, dsVeMayBay);
	delete[] dsVeMayBay;
}

void quickSort(VeMayBay* arr, int low, int high) { 
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}