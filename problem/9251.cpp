#include <iostream>
#include <string>

using namespace std;

int main() {
    int LCS_length = 0, max;
    int** table; 

    string str1, str2;

    cin >> str1;
    cin >> str2;

    str1 = "0" + str1;
    str2 = "0" + str2;

    int len1, len2;
    len1 = str1.length();
    len2 = str2.length();

    table = new int* [len2];
    for (int i = 0; i < len2; i++) {
        table[i] = new int[len1];
    }

    for (int i = 0; i < len1; i++) {
        table[0][i] = 0;
    }
    for (int i = 1; i < len2; i++) {
        max = 0;
        table[i][0] = 0;
        for (int j = 1; j < len1; j++) {
            if (str2[i] == str1[j]) {
                max = table[i - 1][j - 1] + 1;
                table[i][j] = max;
            }
            else {
                if (table[i][j - 1] > table[i - 1][j])
                    table[i][j] = table[i][j - 1];
                else
                    table[i][j] = table[i - 1][j];
            }
        }
        if (LCS_length < max)
            LCS_length = max;
    }
    cout << LCS_length;
    return 0;
}