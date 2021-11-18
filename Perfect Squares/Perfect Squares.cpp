// Perfect Squares.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int numSquares(int n) {
    int range = floor(pow(n, 0.5));
    vector<int> dptable(n + 1, 0);
    for (int i = 0; i < dptable.size(); i++) {
        if (dptable[i] != 0 || i==0) { // the current cell is not null -> means unpossible
            for (int j = 1; j <= range; j++) {
                int val = j * j;
                if (i + val < dptable.size()) {
                    if (i == 0) {
                        dptable[val] = 1;
                    }
                    else {
                        if (dptable[i + val] == 0) { // prevent min(1,0)
                            dptable[i + val] = dptable[i]+1;
                        }
                        else {
                            dptable[i + val] = min(dptable[i] + 1, dptable[i+val]);
                        }

                    }
                }
            }
        }
    }
    return dptable[n];
}

int main()
{
    int n = 15;
    cout<<numSquares(n)<<endl;
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
