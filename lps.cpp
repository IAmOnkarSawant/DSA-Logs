#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Solution {
public:
    void lps_helper(std::string& s, std::vector<int>& lps) {
        int n = s.size();
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < n) {
            if (s[len] == s[i]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    std::string longestPrefix(std::string s) {
        std::vector<int> lps(s.size());
        lps_helper(s, lps);
        return s.substr(0, lps[s.size() - 1]);
    }
};

int main() {
    Solution solution;
    std::string inputDir = "./test";
    std::string outputDir = "./output";

    // Number of test cases
    int numCases = 10;

    for (int i = 1; i <= numCases; ++i) {
        std::string inputFile = inputDir + "/input" + std::to_string(i) + ".txt";
        std::string outputFile = outputDir + "/output" + std::to_string(i) + ".txt";

        // Read input string
        std::ifstream infile(inputFile);
        std::string s;
        if (infile.is_open()) {
            std::getline(infile, s);
            infile.close();
        } else {
            std::cerr << "Unable to open input file: " << inputFile << std::endl;
            continue;
        }

        // Find the longest prefix which is also a suffix
        std::string result = solution.longestPrefix(s);

        // Write the output to the corresponding file
        std::ofstream outfile(outputFile);
        if (outfile.is_open()) {
            outfile << result;
            outfile.close();
        } else {
            std::cerr << "Unable to open output file: " << outputFile << std::endl;
        }
    }

    return 0;
}
