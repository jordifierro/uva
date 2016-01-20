#include <iostream>

using namespace std;

bool p[1000001];

void create_cribe() {

    for (int i = 3; i <= sizeof(p)/2 + 1; i += 2)
        if (!p[i])
            for (int j = i+i; j < sizeof(p); j += i) p[j] = true;
}

bool is_prime (int n) {

    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n&0x01)) return false;
    return !p[n];
}

int main(){

    create_cribe();

    int n;
    cin >> n;
    while (n) {

        int i = 2;
        int j = n - 2;
        bool found = false;
        for(; !found and i <= j;){
            if(is_prime(i) and is_prime(j)) found = true;
            else { i++; j--; }
        }

        if(found) cout << n << " = " << i << " + " << j << endl;
        else cout << "Goldbach's conjecture is wrong." << endl;

        cin >> n;
    }
}
