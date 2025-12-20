#include "Shake.h"
void ShakeSort(std::vector<Key>& vec) {
	int Lt = 0, Rt = vec.size() - 1;
	bool no_swap;
	while (Lt < Rt) {
		no_swap = true;
		for (int i = Lt;i <= Rt - 1;i++) {
			if (Bigger(vec[i], vec[i + 1])) { std::swap(vec[i], vec[i + 1]); no_swap = false; }
		}
		if (no_swap) { break; }

		no_swap = true;
		Rt--;
		for (int i = Rt;i >= Lt + 1;i--) {
			if (Bigger(vec[i - 1], vec[i])) { std::swap(vec[i - 1], vec[i]); no_swap = false; }
		}
		if (no_swap) { break; }
		Lt++;

	}
}
