#include <iostream>
#include <string>
using namespace std;

struct MonHoc {
    int maMonHoc;          
    string tenMonHoc;     
    int soTinChi;          
    int soTietDaGiangDay;  
};

struct Node {
    MonHoc data;  
	Node* left;        
    Node* right;           
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(MonHoc mh) {
    Node* newNode = new Node;
    newNode->data = mh;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, MonHoc mh) {
    if (root == nullptr) {
        return taoNode(mh);
    }

    if (mh.maMonHoc < root->data.maMonHoc) {
        root->left = chenNode(root->left, mh);
    } else {
        root->right = chenNode(root->right, mh);
    }

    return root;
}

Node* timKiem(Node* root, int maMonHoc) {
    if (root == nullptr || root->data.maMonHoc == maMonHoc) {
        return root;
    }

    if (maMonHoc < root->data.maMonHoc) {
        return timKiem(root->left, maMonHoc);
    } else {
        return timKiem(root->right, maMonHoc);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma Mon Hoc: " << root->data.maMonHoc << ", Ten Mon Hoc: " << root->data.tenMonHoc
             << ", So Tin Chi: " << root->data.soTinChi << ", So Tiet Da Giang Day: " << root->data.soTietDaGiangDay << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        MonHoc mh;
        cout << "Nhap thong tin Mon Hoc thu " << i + 1 << endl;
        cout << "Ma Mon Hoc: ";
        cin >> mh.maMonHoc;
        cin.ignore();
        cout << "Ten Mon Hoc: ";
        getline(cin, mh.tenMonHoc);
        cout << "So Tin Chi: ";
        cin >> mh.soTinChi;
        cout << "So Tiet Da Giang Day: ";
        cin >> mh.soTietDaGiangDay;
        cin.ignore();

        root = chenNode(root, mh);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timMonHoc(Node* root, int maMonHoc) {
    Node* result = timKiem(root, maMonHoc);
    if (result != nullptr) {
        cout << "Mon Hoc tim thay: " << endl;
        cout << "Ma Mon Hoc: " << result->data.maMonHoc << ", Ten Mon Hoc: " << result->data.tenMonHoc
             << ", So Tin Chi: " << result->data.soTinChi << ", So Tiet Da Giang Day: " << result->data.soTietDaGiangDay << endl;
    } else {
        cout << "Khong tim thay Mon Hoc co ma so " << maMonHoc << endl;
    }
}

int main() {
    Node* root = khoiTaoCay();  

    int n;
    cout << "Nhap so luong Mon Hoc: ";
    cin >> n;
    cin.ignore();

    nhapCay(root, n);

    cout << "\nDanh sach Mon Hoc trong cay:\n";
    hienThiDanhSach(root);

    int maMonHoc;
    cout << "\nNhap ma Mon Hoc can tim: ";
    cin >> maMonHoc;
    timMonHoc(root, maMonHoc);

    return 0;
}

