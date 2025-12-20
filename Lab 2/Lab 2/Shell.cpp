#include "Shell.h"
void ShellSort(std::vector<Key>& vec) {
    int n = vec.size();
    std::vector<int> Sendj;
    for (int i = 0; ; i++) {
        int s = 9 * pow(4, (2 * i) / 2) - 9 * pow(2, (2 * i) / 2) + 1;
        if (s > n) break;
        Sendj.push_back(s);

        s = pow(2, (2 * i + 3) / 2) * (pow(2, (2 * i + 3) / 2) - 3) + 1;
        if (s > n) break;
        Sendj.push_back(s);
    }

    for (int g = Sendj.size() - 1; g >= 0; g--) {

        for (int start = 0; start < Sendj[g]; start++) {
            for (int i = start + Sendj[g]; i < n; i += Sendj[g]) {
                Key temp = vec[i];
                int j = i;

                while (j - Sendj[g] >= start && Bigger(vec[j - Sendj[g]], temp)) {
                    vec[j] = vec[j - Sendj[g]];
                    j -= Sendj[g];
                }
                vec[j] = temp;
            }
        }
    }
}