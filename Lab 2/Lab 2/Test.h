#pragma once
#include "Struct.h"
#include <vector>
#include <sstream>
#include <fstream>
#include "Shell.h"
#include "Shake.h"
#include <chrono>
std::vector<Key> Read(const std::string& filename);
void Write(std::vector<Key> arr, const std::string& filename);
void TestShell(const std::string& out, const std::string& in);
void TestShake(const std::string& out, const std::string& in);