#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<climits> // chua INT_MAX & INT_MIN
#include<fstream>

using namespace std;

void getData(int &V, int &src, int &dest, int** &G){
	//ifstream là 1 class chi cho phep mo và doc  du lieu tu file
	//ios::in là input mode chi co the doc du lieu tu tiep
	ifstream graph("D:\\C++\\CauTrucDuLieu&GiaiThuatNangCao\\Cac phuong phap sap xep co ban\\graph\\Bai10.txt", ios::in);
	if(!graph.is_open()){
		cout<<"Loi mo file."<<endl;
		return;
	}
	/*
	Moi lan ban su dung toan tu >> de doc mot gia tri con tro trong tep se di chuyen den vi tri ngay sau gia tri vua doc 
	Gia tri da duoc doc se khong duoc doc lai trong cac lan doc tiep theo tru khi ban dat lai con tro ve vi tri truoc do hoac mo lai tep
	*/
	
	// doc so dinh - Vertices 
	graph >> V;
	
	// doc dinh nguon - source va dinh dich - destination
	graph >> src >> dest;
	
	// cap phat bo nho cho mang 2 chieu
	G = new int*[V]; 
	for (int i = 0; i < V; i++) {
		G[i] = new int[V]; 
	}
	
	// doc du lieu do thi -graph
	for(int i=0; i < V; i++){
		for(int j = 0; j < V; j++){
			graph>>G[i][j];
			if(G[i][j] == 0){
				G[i][j]=INT_MAX;
			}
		}
	}
	graph.close();
}

void hienThiGraph(int** G, int V){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if (G[i][j] == INT_MAX) {
				cout << "INF" << "    "; // Hien thi INF thay vì INT_MAX
			} else {
				cout << G[i][j] << "    ";
			}
		}
		cout << endl;;
	}
}
// Hàm tìm dinh có do dài duong di nho nhat chua duac duyet
int getMin(int dist[], bool visited[], int V){
    int key = -1;
    int min = INT_MAX; 
    for(int i = 0; i < V; i++){
        if (!visited[i] && dist[i] < min){
            min = dist[i];
            key = i; 
        }
    }
    return key; 
}

void display(int dist[], int par[], int src, int dest){
    if (dist[dest] == INT_MAX) {
        cout << "Khong có duong di tu dinh " << src << " den dinh " << dest << endl;
        return;
    }

    cout << "Doan duong tu dinh " << src << " den dinh " << dest << ": ";
    
    // In duong di
    int temp = dest;
    string path = to_string(dest);
    while (par[temp] != -1) {
        path = to_string(par[temp]) + " -> " + path;
        temp = par[temp];
    }
    
    cout << path << endl;
    cout << "Tong trong so: " << dist[dest] << endl; 
}

// Thuat toán Dijkstra
void dijkstra(int src, int V, int** G, int dest){
    int par[100], dist[100]; 
    bool visited[100] = {0}; 
    fill(dist, dist + V, INT_MAX); 

    dist[src] = 0; 
    par[src] = -1;
    
    for(int g = 0; g < V - 1; g++){
        int u = getMin(dist, visited, V); 
        visited[u] = true;
        for(int v = 0; v < V; v++){
            if(!visited[v] && dist[u] + G[u][v] < dist[v] && G[u][v] != INT_MAX) {
                par[v] = u; 
                dist[v] = dist[u] + G[u][v]; 
            }
        }
    }
    
    display(dist, par, src, dest);  // Hi?n th? k?t qu? ch? cho d?nh ngu?n và d?nh dích
}
int main(){
	
	int V;	// so dinh cua do thi
	int src, dest; // dinh nguon-source & dinh dich-destination
	int** G;  // khai bao 1 con tro cap 2 de luu date mang 2 chieu 
	getData(V, src, dest, G);
	
	cout<<"So dinh cua do thi: "<<V<<endl
		<<"Dinh nguon: "<<src<<endl
		<<"Dinh dich: "<<dest<<endl;
	// hien thi do thi 
	cout<<"Thong tin do thi bieu dien duoi dang ma tran ke co trong so: "<<endl;
	hienThiGraph(G, V);
	
	cout << "Chay thuat toan Dijkstra tu dinh " << src << ":\n";
	dijkstra(src, V, G, dest);

	for (int i = 0; i < V; i++) {
		delete[] G[i]; 
	}
	delete[] G;  
	return 0;

}
