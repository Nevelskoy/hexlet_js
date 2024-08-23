#include "profile.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <future>

using namespace std;


template <typename ContainerOfVectors>
void GenerateSingleThread(
	ContainerOfVectors& result,
	size_t first_row,
	size_t column_size
) {
	for (auto& row : result) {
		row.reserve(column_size);
		for (size_t column = 0; column < column_size; ++column) {
			row.push_back(first_row ^ column);
		}
		++first_row;
	}
}


vector<vector<int>> GenerateSingleThread(size_t size) {
	vector<vector<int>> result(size);
	GenerateSingleThread(result, 0, size);
	return result;
}


template <typename ContainerOfVectors>
int64_t SumSingleThread(const ContainerOfVectors& matrix) {
	int64_t sum = 0;
	for (const auto& row : matrix) {
		for (auto item : row) {
			sum += item;
		}
	}
	return sum;
}

//
//template <typename C>
//struct Subrange {
//	C& collection;
//	size_t first_index, last_index;
//
//	auto begin() const { return collection.begin() + first_index };
//	auto end() const { return collection.begin() + last_index };
//
//	size_t size() const {
//		return last_index - first_index;T
//	}
//};


int main() {
	LOG_DURATION("Total");
	const size_t matrix_size = 500;

	vector<vector<int>> matrix;
	{
		LOG_DURATION("Single thread generation ");
		matrix = GenerateSingleThread(matrix_size);
	}
	{
		LOG_DURATION("Single thread sum ");
		cout << SumSingleThread(matrix) << endl;
	}
}