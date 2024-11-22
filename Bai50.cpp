#include <iostream>
using namespace std;

void inputArray(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap so thuc thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void outputArray(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(float* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int partition(float* arr, int low, int high) {
    float pivot = arr[high];
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

void quickSort(float* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(float* arr, int low, int high, float x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;
    
    float* arr = new float[n];
    inputArray(arr, n);
    
    cout << "Mang ban dau: ";
    outputArray(arr, n);

    if (isSorted(arr, n)) {
        cout << "Mang da duoc sap xep theo thu tu tang dan." << endl;
    }
    else {
        cout << "Mang chua duoc sap xep." << endl;
        quickSort(arr, 0, n - 1);
        cout << "Mang sau khi sap xep: ";
        outputArray(arr, n);
    }

    float x;
    cout << "Nhap so thuc X de tim: ";
    cin >> x;

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        cout << "So thuc " << x << " duoc tim thay tai chi so: " << result << endl;
    }
    else {
        cout << "So thuc " << x << " khong ton tai trong mang." << endl;
    }

    delete[] arr;
    return 0;
}

