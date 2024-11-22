#include <iostream>
#include <string>
using namespace std;

struct KhachHang {
    int maKH;          
    string tenKH;      
    string soDienThoai; 
    float tongTienThanhToan; 
};

struct Node {
    KhachHang data;
    Node* left;
    Node* right;
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(KhachHang kh) {
    Node* newNode = new Node;
    newNode->data = kh;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, KhachHang kh) {
    if (root == nullptr) {
        return taoNode(kh);
    }

    if (kh.maKH < root->data.maKH) {
        root->left = chenNode(root->left, kh);
    } else {
        root->right = chenNode(root->right, kh);
    }

    return root;
}

Node* timKiem(Node* root, int maKH) {
    if (root == nullptr || root->data.maKH == maKH) {
        return root;
    }

    if (maKH < root->data.maKH) {
        return timKiem(root->left, maKH);
    } else {
        return timKiem(root->right, maKH);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma KH: " << root->data.maKH << ", Ten: " << root->data.tenKH
             << ", So dien thoai: " << root->data.soDienThoai << ", Tong tien thanh toan: " 
             << root->data.tongTienThanhToan << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        KhachHang kh;
        cout << "Nhap thong tin khach hang thu " << i + 1 << endl;
        cout << "Ma khach hang: ";
        cin >> kh.maKH;
        cin.ignore();
        cout << "Ten khach hang: ";
        getline(cin, kh.tenKH);
        cout << "So dien thoai: ";
        getline(cin, kh.soDienThoai);
        cout << "Tong tien thanh toan: ";
        cin >> kh.tongTienThanhToan;
        cin.ignore();

        root = chenNode(root, kh);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timKhachHang(Node* root, int maKH) {
    Node* result = timKiem(root, maKH);
    if (result != nullptr) {
        cout << "Khach hang tim thay: " << endl;
        cout << "Ma KH: " << result->data.maKH << ", Ten: " << result->data.tenKH
             << ", So dien thoai: " << result->data.soDienThoai << ", Tong tien thanh toan: " 
             << result->data.tongTienThanhToan << endl;
    } else {
        cout << "Khong tim thay khach hang co ma so " << maKH << endl;
    }
}

int main() {
    Node* root = khoiTaoCay();  

    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    cin.ignore();

    nhapCay(root, n);

    cout << "\nDanh sach khach hang trong cay:\n";
    hienThiDanhSach(root);

    int maKH;
    cout << "\nNhap ma khach hang can tim: ";
    cin >> maKH;
    timKhachHang(root, maKH);

    return 0;
}

