# Chapter 04: Divide-and-Conquer

## 4.1. The Maximum-Subarray Problem
This problem is the case to maximize the benefits of stock trading, within a given range and price data of specific period.

### A Brute-Force Solution
Just try every pair, doing $C(n, 2)$ trials. This requires time complexity of $O(n^2)$.

### A Transformation
* 모든 가능한 경우의 수를 시도해 보는 대신, 각 날짜의 가격을 전일로부터의 변화량으로 변환한다. 이후, 연속된 sequence의 합이 가장 큰 것을 고른다.
* 최댓값을 갖는 부분집합은 여러 개가 될 수 있으므로, 하나를 특정하여 말하는 것이 아니라 최댓값을 가지는 부분집합 중 하나를 찾는 문제로 생각한다.
* 모든 변화량 값이 양수일 경우 array 전체의 합이 최댓값이므로, 변화량 중 음수가 포함되어 있을 때 비로소 의미가 있는 문제이다.

### A Solution Using Divide-and-Conquer
* 부분집합 A[low, high] 중에서 합이 최대힌 부분집합을 찾는다.
* Divide-and-Conquer 방법은 가능한 한 균일한 크기로 부분집합을 분할한다.
* 부분집합 중 최대합을 갖는 부분집합은 다음 세 가지 경우 중 하나에 해당한다.
  * 중간값보다 작다.
  * 중간값보다 크다.
  * 중간값을 중심으로 걸쳐 있다.
* 여기서, 중간값보다 작거나 큰 경우 다음 번 재귀함수 루프에서 다룰 수 있으므로, 실제로 해야 할 일은 중간값을 중심으로 최대 부분집합이 걸쳐 있는지 찾는 것이다.