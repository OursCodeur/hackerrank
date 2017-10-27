#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using Cell = int;
using Row = std::vector<Cell>;
using Matrix = std::vector<Row>;

void move_sq(Matrix& matrix, int start_row, int start_col, std::function<void(Cell&)> action) {

	auto rows = matrix.size(), cols = matrix[0].size();
	auto r = start_row, c = start_col;

	for (; c < cols - start_col - 1; ++c)	{ action(matrix[r][c]); }
	for (; r < rows - start_row - 1; ++r)	{ action(matrix[r][c]); }
	for (; c > start_col; --c)		{ action(matrix[r][c]); }
	for (; r > start_row; --r)		{ action(matrix[r][c]); }
}

int main() {
	int rows, cols, rot;
	std::cin >> rows >> cols >> rot;

	Matrix matrix(rows, Row(cols));

	for (auto& row : matrix)
		for (auto& cell : row)
			std::cin >> cell;

	for (int r = 0, c = 0; r < rows / 2 && c < cols / 2; ++c, ++r) {
		std::vector<Cell> vec;

		move_sq(matrix, r, c, [&vec](Cell& cell) { vec.push_back(cell); });
		std::rotate(begin(vec), begin(vec) + rot % vec.size(), end(vec));

		move_sq(matrix, r, c, [&vec, i = 0](Cell& cell) mutable {
			cell = vec[i];
			i++;
		});
	}

	for (const auto& row : matrix) {
		for (const auto& cell : row)
			std::cout << cell << ' ';
		std::cout << std::endl;
	}

	return 0;
}
