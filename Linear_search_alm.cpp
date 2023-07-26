#include <iostream>
using namespace std;

int linearSearch(int L[], int N, int Key) {
    int k = 0;
    int Loc = -1; // -1 indicates that the key was not found

    while (k < N) {
        if (L[k] == Key) {
            Loc = k;
            break;
        }
        k++;
    }

    return Loc;
}

int main() {
    int N, Key;

    cout << "Enter the number of items in the list: ";
    cin >> N;

    int *L = new int[N];

    cout << "Enter the list items: ";
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    cout << "Enter the item to be searched: ";
    cin >> Key;

    int result = linearSearch(L, N, Key);

    if (result != -1) {
        cout << "Item found at index: " << result << endl;
    } else {
        cout << "Item is not in the list." << endl;
    }

    delete[] L; // Free the dynamically allocated memory for the list
    return 0;
}

