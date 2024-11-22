#include <iostream>
#include <string>
using namespace std;

struct DuAn {
    int maDuAn;         
    string tenDuAn;     
    float tongKinhPhi;  
};

struct Node {
    DuAn data;           
    Node* left;          
    Node* right;         
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(DuAn da) {
    Node* newNode = new Node;
    newNode->data = da;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, DuAn da) {
    if (root == nullptr) {
        return taoNode(da);
    }

    if (da.maDuAn < root->data.maDuAn) {
        root->left = chenNode(root->left, da);
    } else {
        root->right = chenNode(root->right, da);
    }

    return root;
}

Node* timKiem(Node* root, int maDuAn) {
    if (root == nullptr || root->data.maDuAn == maDuAn) {
        return root;
    }

    if (maDuAn < root->data.maDuAn) {
        return timKiem(root->left, maDuAn);
    } else {
        return timKiem(root->right, maDuAn);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma du an: " << root->data.maDuAn << ", Ten du an: " << root->data.tenDuAn
             << ", Tong kinh phi: " << root->data.tongKinhPhi << " ty dong" << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        DuAn da;
        cout << "Nhap thong tin du an thu " << i + 1 << endl;
        cout << "Ma du an: ";
        cin >> da.maDuAn;
        cin.ignore();
        cout << "Ten du an: ";
        getline(cin, da.tenDuAn);
        cout << "Tong kinh phi (ty dong): ";
        cin >> da.tongKinhPhi;
        cin.ignore();

        root = chenNode(root, da);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timDuAn(Node* root, int maDuAn) {
    Node* result = timKiem(root, maDuAn);
    if (result != nullptr) {
        cout << "Du an tim thay: " << endl;
        cout << "Ma du an: " << result->data.maDuAn << ", Ten du an: " << result->data.tenDuAn
             << ", Tong kinh phi: " << result->data.tongKinhPhi << " ty dong" << endl;
    } else {
        cout << "Khong tim thay du an co ma so " << maDuAn << endl;
    }
}

int main() {
    Node* root = khoiTaoCay();  

    int n;
    cout << "Nhap so luong du an: ";
    cin >> n;
    cin.ignore();

    nhapCay(root, n);

    cout << "\nDanh sach du an trong cay:\n";
    hienThiDanhSach(root);

    int maDuAn;
    cout << "\nNhap ma du an can tim: ";
    cin >> maDuAn;
    timDuAn(root, maDuAn);

    return 0;
}

