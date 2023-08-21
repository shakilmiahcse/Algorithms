#include <iostream>
using namespace std;
int binarySearch(int L[], int N, int Key) {
    int Loc = -1;
    int Beg = 0;
    int End = N - 1;
    int Mid;
    while (Beg <= End) {
        Mid = (Beg + End) / 2;
// for descending order: if (Key > L[Mid]), else if (Key < L[Mid])
        if (Key < L[Mid]) {
            End = Mid - 1;
        } else if (Key > L[Mid]) {
            Beg = Mid + 1;
        } else if (Key == L[Mid]) {
            Loc = Mid;
            return Loc;
        }
    }
    return Loc;
}
int main() {
    int N;
    cout << "Enter the number of elements in the list: ";
    cin >> N;
    int L[N];
    cout << "Enter the elements in the list in ascending order: ";
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    int Key;
    cout << "Enter the item to be searched: ";
    cin >> Key;
    int result = binarySearch(L, N, Key);
    if (result != -1) {
        cout << "Item found at index: " << result << endl;
    } else {
        cout << "Item is not in the list." << endl;
    }
    return 0;
}

