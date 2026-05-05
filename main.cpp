#include <iostream>
using namespace std;

// 🔹 Function to calculate fragmentation
void calculateFragmentation(int temp[], int m) {
    int total = 0;
    for (int i = 0; i < m; i++) {
        total += temp[i];
    }
    cout << "Total Fragmentation: " << total << endl;
}

// 🔹 First Fit
void firstFit(int blocks[], int m, int processes[], int n) {
    int temp[m];
    for (int i = 0; i < m; i++)
        temp[i] = blocks[i];

    cout << "\n--- First Fit Allocation ---\n";

    for (int i = 0; i < n; i++) {
        bool allocated = false;

        for (int j = 0; j < m; j++) {
            if (temp[j] >= processes[i]) {
                cout << "Process " << processes[i]
                     << " -> Block " << j + 1 << endl;

                temp[j] -= processes[i];
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            cout << "Process " << processes[i]
                 << " -> Not Allocated" << endl;
        }
    }

    calculateFragmentation(temp, m);
}

// 🔹 Best Fit
void bestFit(int blocks[], int m, int processes[], int n) {
    int temp[m];
    for (int i = 0; i < m; i++)
        temp[i] = blocks[i];

    cout << "\n--- Best Fit Allocation ---\n";

    for (int i = 0; i < n; i++) {
        int bestIndex = -1;

        for (int j = 0; j < m; j++) {
            if (temp[j] >= processes[i]) {
                if (bestIndex == -1 || temp[j] < temp[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            cout << "Process " << processes[i]
                 << " -> Block " << bestIndex + 1 << endl;

            temp[bestIndex] -= processes[i];
        } else {
            cout << "Process " << processes[i]
                 << " -> Not Allocated" << endl;
        }
    }

    calculateFragmentation(temp, m);
}

// 🔹 Worst Fit
void worstFit(int blocks[], int m, int processes[], int n) {
    int temp[m];
    for (int i = 0; i < m; i++)
        temp[i] = blocks[i];

    cout << "\n--- Worst Fit Allocation ---\n";

    for (int i = 0; i < n; i++) {
        int worstIndex = -1;

        for (int j = 0; j < m; j++) {
            if (temp[j] >= processes[i]) {
                if (worstIndex == -1 || temp[j] > temp[worstIndex]) {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) {
            cout << "Process " << processes[i]
                 << " -> Block " << worstIndex + 1 << endl;

            temp[worstIndex] -= processes[i];
        } else {
            cout << "Process " << processes[i]
                 << " -> Not Allocated" << endl;
        }
    }

    calculateFragmentation(temp, m);
}

// 🔹 Menu System
int main() {
    int m, n, choice;

    cout << "Enter number of memory blocks: ";
    cin >> m;

    int blocks[m];
    cout << "Enter sizes of memory blocks:\n";
    for (int i = 0; i < m; i++) {
        cin >> blocks[i];
    }

    cout << "Enter number of processes: ";
    cin >> n;

    int processes[n];
    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i];
    }

    do {
        cout << "\n===== Memory Allocation Menu =====\n";
        cout << "1. First Fit\n";
        cout << "2. Best Fit\n";
        cout << "3. Worst Fit\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                firstFit(blocks, m, processes, n);
                break;
            case 2:
                bestFit(blocks, m, processes, n);
                break;
            case 3:
                worstFit(blocks, m, processes, n);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}