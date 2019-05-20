#include <iostream>
#include <vector>

#include "./matrix_chain_recursive.h"
#include "./bottom_up_matrix_chain.h"

int main(void)
{
    std::vector<int> matrixChain({ 30, 35, 15, 5, 10, 20, 25 });
    // std::vector<int> matrixChain({ 30, 35, 15, 5, 10, 20, 25, 40, 60, 30, 35, 10, 15, 30, 35, 15, 20, 30, 40, 55, 20 });
    int left = 1, right = matrixChain.size() - 1;

    // int minCalc = matrixChainRecursive(matrixChain, left, right);
    int minCalc = matrixChainBottomUp(matrixChain);

    std::cout << "Minimum calculations: " << minCalc << std::endl;
}