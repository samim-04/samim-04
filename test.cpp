#include <iostream>
#include <vector>

using namespace std;

// Function to check if Abhimanyu can cross the Chakravyuha
bool canAbhimanyuCross(vector<int> &k, int p, int a, int b) {
    int n = k.size();  // Total number of circles
    
    for (int i = 0; i < n; i++) {
        // Special handling for enemies at positions 3 (index 2) and 7 (index 6)
        if ((i == 2 || i == 6) && k[i] > 0) {
            // Regeneration logic: these enemies regenerate with half power if alive
            int regeneratedPower = k[i] / 2;
            if (p > regeneratedPower) {
                p -= regeneratedPower;  // Abhimanyu defeats the regenerated enemy
                k[i] = 0;  // Enemy defeated
            } else if (a > 0) {
                a--;  // Use skip
                k[i] = 0;  // Mark enemy defeated
            } else if (b > 0) {
                p += 20;  // Recharge (arbitrary recharge value)
                b--;  // Use recharge
                p -= regeneratedPower;  // Abhimanyu defeats the regenerated enemy
                k[i] = 0;
            } else {
                return false;  // Abhimanyu loses
            }
        }

        // If Abhimanyu's power is greater than or equal to the enemy's power in the current circle
        if (p >= k[i]) {
            p -= k[i];  // Abhimanyu defeats the enemy
        } else if (a > 0) {
            a--;  // Use skip if Abhimanyu's power is less than the enemy's power
        } else if (b > 0) {
            p += 20;  // Recharge (arbitrary recharge value)
            b--;  // Use recharge
            if (p >= k[i]) {
                p -= k[i];  // Abhimanyu defeats the enemy after recharging
            } else {
                return false;  // Abhimanyu loses
            }
        } else {
            return false;  // Abhimanyu loses due to insufficient power
        }
    }
    return true;  // Abhimanyu successfully crosses all circles
}

// Test cases
int main() {
    vector<int> k1 = {5, 10, 20, 8, 12, 15, 25, 18, 30, 35, 40};  // Enemy powers in each circle
    int p1 = 100, a1 = 2, b1 = 1;  // Test case 1
    if (canAbhimanyuCross(k1, p1, a1, b1))
        cout << "Abhimanyu successfully crossed the Chakravyuha in test case 1!" << endl;
    else
        cout << "Abhimanyu failed to cross the Chakravyuha in test case 1!" << endl;

    vector<int> k2 = {8, 5, 15, 25, 10, 20, 35, 10, 22, 30, 45};  // Test case 2
    int p2 = 80, a2 = 1, b2 = 2;  // Test case 2
    if (canAbhimanyuCross(k2, p2, a2, b2))
        cout << "Abhimanyu successfully crossed the Chakravyuha in test case 2!" << endl;
    else
        cout << "Abhimanyu failed to cross the Chakravyuha in test case 2!" << endl;

    return 0;
}
