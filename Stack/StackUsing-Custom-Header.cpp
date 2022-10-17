#include <bits/stdc++.h>

#include "Masum_Stack.h"

using namespace std;

int main() {
    Stack st;
    int n;
    cout << "Enter the the number of inputs: ";
    cin >> n;
    cout << "Enter " << n << " integers: ";
    while (n--) {
        int x;
        cin >> x;
        st.Push(x);
    }

    cout << st.mid() << endl;

    return 0;
}