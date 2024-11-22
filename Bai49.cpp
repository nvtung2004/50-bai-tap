#include <iostream>
using namespace std;

void nhapMang(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap so nguyen thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void xuatMang(int* arr, int n) {
    cout << "Mang da nhap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool kiemTraTangDan(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool timKiemBinary(int* arr, int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return true;
        }
        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    int* arr = new int[n];

    nhapMang(arr, n);
    xuatMang(arr, n);

    if (!kiemTraTangDan(arr, n)) {
        cout << "Mang chua duoc sap xep tang dan. Dang sap xep lai mang...\n";
        quickSort(arr, 0, n - 1);
        xuatMang(arr, n);
    } else {
        cout << "Mang da duoc sap xep tang dan.\n";
    }

    int x;
    cout << "Nhap so X de tim kiem: ";
    cin >> x;
    if (timKiemBinary(arr, n, x)) {
        cout << "So " << x << " da co trong mang.\n";
    } else {
        cout << "So " << x << " khong co trong mang.\n";
    }

    delete[] arr;

    return 0;
}

