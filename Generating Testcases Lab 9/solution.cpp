#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 5005;
long long narr[MAX_N], suma[MAX_N], dp[MAX_N][MAX_N];

int main() {
    for (int file_num = 1; file_num <= 25; ++file_num) {
        string input_filename = "./hard1/input/input" + to_string(file_num) + ".txt";
        string output_filename = "./hard1/output/output" + to_string(file_num) + ".txt";

        ifstream infile(input_filename);
        ofstream outfile(output_filename);

        if (!infile.is_open()) {
            cerr << "Error opening file: " << input_filename << endl;
            continue;
        }

        int t;
        infile >> t;

        while (t--) {
            int n, m, k;
            infile >> n >> m >> k;

            memset(narr, 0, sizeof(narr));  
            memset(suma, 0, sizeof(suma));  
            memset(dp, 0, sizeof(dp));      

            for (int i = 0; i < n; ++i) {
                infile >> narr[i];
            }

            long long temp = 0;
            for (int i = n - 1; i >= n - m; --i) {
                temp += narr[i];
            }
            suma[n - m] = temp;

            for (int i = n - m - 1; i >= 0; --i) {
                suma[i] = suma[i + 1] + narr[i] - narr[i + m];
            }

            dp[n - m][1] = suma[n - m];

            for (int i = n - m - 1; i >= 0; --i) {
                for (int j = 1; j <= k; ++j) {
                    long long temp = dp[i + m][j - 1] + suma[i];
                    dp[i][j] = max(dp[i + 1][j], temp);
                }
            }

            outfile << dp[0][k] << endl;
        }

        infile.close();
        outfile.close();
    }

    return 0;
}
