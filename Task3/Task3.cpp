#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* diopters = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> diopters[i];
    }

    int temp;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; j++) {
            if (diopters[j] > diopters[j + 1]) {
                temp = diopters[j + 1];
                diopters[j + 1] = diopters[j];
                diopters[j] = temp;
            }
        }
    }

    int count = N;
    for (int i = 0; i < N - 1; ++i) {
        if (diopters[i + 1] - diopters[i] <= 2) {
            count--;
            i++;
        };
    }

    cout << count;

    delete[] diopters;
}