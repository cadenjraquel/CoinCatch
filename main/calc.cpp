#include <iostream>

enum Coin { NONE = 0, Penny = 1, Nickel = 5, Dime = 10, Quarter = 25 };
const Coin coins[] = {Quarter, Dime, Nickel, Penny};

Coin getCoin(int n) {
  switch (n) {
    case 1:
      return Penny;
    case 5:
      return Nickel;
    case 10:
      return Dime;
    case 25:
      return Quarter;
    default:
      return NONE;
  }
}

int* coinCheck(int target, int* count) {
  int* ret_counts = new int[4];
  for(int i = 0; i < 4; i++) {
    ret_counts[i] = std::min(target / coins[i], count[i]);
    target -= ret_counts[i] * coins[i];
  }
  return target == 0 ? ret_counts : NULL;
}

int main() {
  int* count = new int[4]{3, 1, 2, 5}; // Count of coins (Ordered Quarters, Dimes, Nickels, Pennies)
  int target = 23; // Target in cents
  std::cout << "Target: $0." << target << std::endl;
  int* result = coinCheck(target, count);
  if (result == NULL) {
    std::cout << "SUM IMPOSSIBLE" << std::endl;
    return 1;
  }
  std::cout << "Coins (Q/D/N/P):";
  for(int i = 0; i < 4; i++) {
    std::cout << " " << *result++;
  }
  std::cout << std::endl;
  return 0;
}
