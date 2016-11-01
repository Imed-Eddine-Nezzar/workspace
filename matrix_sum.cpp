#include <iostream>

namespace matrix {
    template <size_t N>
    int diagonal_sum(int mat[][N]) {
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += mat[i][i];
        return sum;
    }

    template <size_t N>
    int upperhalf_sum(int mat[][N]) {
        int sum = 0;
        for (int i = 0; i < N - 1; ++i)
            for (int j = i + 1; j < N; ++j)
                sum += mat[i][j];
        return sum;
    }

    template <size_t N>
    int lowerhalf_sum(int mat[][N]) {
        int sum = 0;
        for (int i = 1; i < N; ++i)
            for (int j = 0; j < i; ++j)
                sum += mat[i][j];
        return sum;
    }
}

int main(void) {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {2, 3, 4, 3},
        {3, 4, 3, 2},
        {4, 3, 2, 1}
    };

    std::cout << "diagonal sum: "
              << matrix::diagonal_sum<4>(arr) << "\n";
    std::cout << "upper half sum: "
              << matrix::upperhalf_sum<4>(arr) << "\n";
    std::cout << "lower half sum: "
              << matrix::lowerhalf_sum<4>(arr) << "\n";
}
