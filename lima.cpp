#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((double)(x - arr[low]) / (arr[high] - arr[low])) * (high - low);
        
        if (arr[pos] == x)
            return pos;
        
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> kursiTersedia(n);
    for (int i = 0; i < n; i++) {
        cin >> kursiTersedia[i];
    }
    
    int cari;
    cin >> cari;
    
    int hasil = interpolationSearch(kursiTersedia, cari);
    
    cout << "Nomor kursi yang dicari: " << cari << endl;
    
    if (hasil != -1) {
        cout << "Status: TERSEDIA" << endl;
        cout << "Posisi index: " << hasil << endl;
        cout << "Nomor kursi: " << kursiTersedia[hasil] << endl;
    } else {
        cout << "Status: TIDAK TERSEDIA" << endl;
        
        // Cari kursi terdekat
        int terdekat = kursiTersedia[0];
        int selisih = abs(kursiTersedia[0] - cari);
        
        for (int i = 1; i < n; i++) {
            if (abs(kursiTersedia[i] - cari) < selisih) {
                selisih = abs(kursiTersedia[i] - cari);
                terdekat = kursiTersedia[i];
            }
        }
        
        cout << "Kursi terdekat yang tersedia: " << terdekat << endl;
    }
    
    return 0;
}