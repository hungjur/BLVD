#include "Test.h"

std::vector<Key> Read(const std::string& filename) {
	std::ifstream file(filename);
	std::vector<Key> vec;
	int i = 0;
	std::string s;
	while (std::getline(file, s)) {
		Key k;
		std::string w;
		std::stringstream ss(s);
		ss >> w;
		k.date.d = std::stoi(w);
		ss >> w;
		k.date.m = std::stoi(w);
		ss >> w;
		k.date.y = std::stoi(w);
		ss >> w;
		k.fio.f = w;
		ss >> w;
		k.fio.i = w;
		ss >> w;
		k.fio.o = w;
		k.No = i;
		i++;
		vec.push_back(k);
	}return vec;
}
void Write(std::vector<Key> arr ,const std::string& filename) {
	std::ofstream file(filename);
	for(Key a:arr){
		file << a.date.d << " " << a.date.m << " " << a.date.y << " " << a.fio.f << " " << a.fio.i << " " << a.fio.o << " " << a.No << std::endl;
	}
}
void TestShell(const std::string& out, const std::string& in) {
	std::vector<Key> z=Read(in);
	auto start = std::chrono::high_resolution_clock::now();
	ShellSort(z);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	Write(z, out);
	std::ofstream file(out,std::ios::app);
	file << duration.count();
}
void TestShake(const std::string& out, const std::string& in) {
	std::vector<Key> z = Read(in);
	auto start = std::chrono::high_resolution_clock::now();
	ShakeSort(z);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	Write(z, out);
	std::ofstream file(out, std::ios::app);
	file << duration.count();
}
int main() {
	TestShell("OutputShell_1^4.txt", "input_10000.txt");
	TestShake("OutputShake_1^4.txt", "input_10000.txt");
	TestShell("OutputShell_1^5.txt", "input_100000.txt");
	TestShake("OutputShake_1^5.txt", "input_100000.txt");

}