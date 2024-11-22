#include <iostream>
#include <string>
using namespace std;

struct TaiLieu {
    int maTaiLieu;        
    string tenTaiLieu;    
    int namXuatBan;      
    float giaBan;        
};

struct Node {
    TaiLieu data;
    Node* left;
    Node* right;
};


Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(TaiLieu tl) {
    Node* newNode = new Node;
    newNode->data = tl;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* chenNode(Node* root, TaiLieu tl) {
    if (root == nullptr) {
        return taoNode(tl);
    }

    if (tl.maTaiLieu < root->data.maTaiLieu) {
        root->left = chenNode(root->left, tl);
    } else {
        root->right = chenNode(root->right, tl);
    }

    return root;
}

Node* timKiem(Node* root, int maTaiLieu) {
    if (root == nullptr || root->data.maTaiLieu == maTaiLieu) {
        return root;
    }

    if (maTaiLieu < root->data.maTaiLieu) {
        return timKiem(root->left, maTaiLieu);
    } else {
        return timKiem(root->right, maTaiLieu);
    }
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma tai lieu: " << root->data.maTaiLieu << ", Ten tai lieu: " << root->data.tenTaiLieu
             << ", Nam xuat ban: " << root->data.namXuatBan << ", Gia ban: " << root->data.giaBan << " VND" << endl;
        duyetCay(root->right);
    }
}

void nhapCay(Node*& root, int n) {
    for (int i = 0; i < n; i++) {
        TaiLieu tl;
        cout << "Nhap thong tin tai lieu thu " << i + 1 << endl;
        cout << "Ma tai lieu: ";
        cin >> tl.maTaiLieu;
        cin.ignore();
        cout << "Ten tai lieu: ";
        getline(cin, tl.tenTaiLieu);
        cout << "Nam xuat ban: ";
        cin >> tl.namXuatBan;
        cout << "Gia ban (VND): ";
        cin >> tl.giaBan;
        cin.ignore();

        root = chenNode(root, tl);
    }
}

void hienThiDanhSach(Node* root) {
    duyetCay(root);
}

void timTaiLieu(Node* root, int maTaiLieu) {
    Node* result = timKiem(root, maTaiLieu);
    if (result != nullptr) {
        cout << "Tai lieu tim thay: " << endl;
        cout << "Ma tai lieu: " << result->data.maTaiLieu << ", Ten tai lieu: " << result->data.tenTaiLieu
             << ", Nam xuat ban: " << result->data.namXuatBan << ", Gia ban: " << result->data.giaBan << " VND" << endl;
    } else {
        cout << "Khong tim thay tai lieu co ma so " << maTaiLieu << endl;
    }
}

int main() {
    Node* root = khoiTaoCay();  

    int n;
    cout << "Nhap so luong tai lieu: ";
    cin >> n;
    cin.ignore();

    nhapCay(root, n);

    cout << "\nDanh sach tai lieu trong cay:\n";
    hienThiDanhSach(root);

    int maTaiLieu;
    cout << "\nNhap ma tai lieu can tim: ";
    cin >> maTaiLieu;
    timTaiLieu(root, maTaiLieu);

    return 0;
}

