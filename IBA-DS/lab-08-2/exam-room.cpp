#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class ExamRoom {
private:
    int n;
    std::set<int> seats;

public:
    explicit ExamRoom(const int n) : n(n) {}

    int seat() {
        // If no seats are taken, take seat 0
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int maxDist = *seats.begin(); // Distance to the first seat
        int prev = -1;  // Previous seat index
        int bestSeat = 0;  // Best seat to take

        for (int seat : seats) {
            if (prev == -1) {
                // If this is the first seat, check distance from the start
                if (seat > maxDist) {
                    maxDist = seat;
                    bestSeat = 0;
                }
            } else {
                // Calculate the distance to the previous seat
                int dist = (seat - prev) / 2;
                // Update maxDist and bestSeat if this distance is greater
                if (dist > maxDist) {
                    maxDist = dist;
                    bestSeat = prev + dist;
                }
            }
            prev = seat;  // Update previous seat
        }

        // Check the distance from the last seat to the end
        if (n - 1 - *seats.rbegin() > maxDist) {
            bestSeat = n - 1;
        }

        seats.insert(bestSeat);
        return bestSeat;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

// Example usage
int main() {
    ExamRoom examRoom(10);
    std::cout << examRoom.seat() << std::endl;  // return 0
    std::cout << examRoom.seat() << std::endl;  // return 9
    std::cout << examRoom.seat() << std::endl;  // return 4
    std::cout << examRoom.seat() << std::endl;  // return 2
    examRoom.leave(4);
    std::cout << examRoom.seat() << std::endl;  // return 5
    return 0;
}