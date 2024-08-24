#include "profile.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <future>
//#include <execution>  //C++17

using namespace std;


// template <typename ContainerOfVectors>
// void GenerateSingleThread(ContainerOfVectors& result, size_t first_row, size_t column_size) {
//     for_each (execution::par,  //C++17
//              begin(result),
//              end(result),
//              [&first_row, column_size](vector<int>& row) {
//         row.reserve(column_size);
//         for (size_t column = 0; column < column_size; ++column) {
//             row.push_back(first_row ^ column);
//         }
//         ++first_row;
//     });
// }

template <typename ContainerOfVectors>
void GenerateSingleThread(ContainerOfVectors& result, size_t first_row, size_t column_size) {
    for (auto& row : result) {
        row.reserve(column_size);
        for (size_t column = 0; column < column_size; ++column) {
            row.push_back(first_row ^ column);
        }
        ++first_row;
    }
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

template <typename C>
struct Subrange {
    C& collection;
    size_t first_index, last_index;

    auto begin() const { return collection.begin() + first_index; };
    auto end() const { return collection.begin() + last_index; };

    size_t size() const {
        return last_index - first_index;
    }
};

template<typename Container>
class Paginator {
private:
    vector<Subrange<Container>> pages;

public:
    Paginator(Container& c, size_t page_size) {
        for (size_t i = 0; i < c.size(); i += page_size) {
            pages.push_back({ c, i, min(i + page_size, c.size()) });
        }
    }

    auto begin() const {
        return pages.begin();
    }

    auto end() const {
        return pages.end();
    }

    size_t size() const {
        return pages.size();
    }
};


template <typename C>
Paginator<C> Paginate(C& c, size_t page_size) {
    return Paginator<C>(c, page_size);
}

vector<vector<int>> GenerateSingleThread(size_t size) {
    vector<vector<int>> result(size);
    GenerateSingleThread(result, 0, size);
    return result;
}

vector<vector<int>> GenerateMultiThread(size_t size, size_t page_size) {
    vector<vector<int>> result(size);
    vector<future<void>> futures;
    size_t first_row = 0;
    for (auto page : Paginate(result, page_size)) {
        futures.push_back(
            async([page, first_row, size] {
                GenerateSingleThread(page, first_row, size);
            })
            );
        first_row += page_size;
    }

    return result;
}



int main() {
    LOG_DURATION("Total ");
    const size_t matrix_size = 15000;

    vector<vector<int>> matrix;
    {
        LOG_DURATION("Single thread generation ");
        matrix = GenerateSingleThread(matrix_size);
    }
    {
        //TODO: DEBUG
        LOG_DURATION("Multi thread generation ");
        matrix = GenerateMultiThread(matrix_size, 700);
    }
    {
        LOG_DURATION("Single thread sum ");
        cout << SumSingleThread(matrix) << endl;
    }
}
