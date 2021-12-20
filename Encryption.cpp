#include <bits/stdc++.h>

using namespace std;

// PROBLEM LINK : https://www.hackerrank.com/challenges/encryption/problem

string encryption(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    double L_root = sqrt(s.length());
    int rows, columns;
    rows = columns = L_root;
    
    if (L_root != rows) columns = L_root + 1;
    if (rows * columns < s.length()) rows++;
    
    string tmp_s = "";
    vector<string> str;
    for (int i = 0; i < s.length(); i++){
        tmp_s += s[i];
        if ((i+1) % columns == 0 || i+1 == s.length()){
            str.push_back(tmp_s);
            tmp_s = "";
        }
    }
    
    s = "";
    for (int i = 0; i < columns; i++){
        for (int j = 0; j < rows; j++){
            if (i < str[j].length()) s += str[j][i];
        }
        if (i+1 != columns) s += " ";
    }
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
