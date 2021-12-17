
#include <iostream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include "Utility.h"
#include "Car.h"

std::vector<int> createElevationMap();

int main() {
    std::vector<int> range = createElevationMap();
    std::cout << "Elevation Map: " << range << "\n";

    int amountTrapped = 0;
    if (!range.empty())
    {
        int rangeSize = range.size() - 1;
        int frontPosition = 0;
        int backPosition = 0;
        int highestWallSeen = 0;
        int currentStartWall = 0;
        if (range[frontPosition] >= range[rangeSize])
        {
            highestWallSeen = range[frontPosition];
            currentStartWall = range[rangeSize];
        }
        else
        {
            highestWallSeen = range[rangeSize];
            currentStartWall = range[frontPosition];
        }
        for (int n : range)
        {
            if (frontPosition + backPosition >= rangeSize)
            {
                break;
            }
            else if (n >= highestWallSeen)
            {
                highestWallSeen = n;
                currentStartWall = range[rangeSize - backPosition];
                std::any_of(
                    range.rbegin() + backPosition + 1,
                    range.rend() - frontPosition,
                    [&rangeSize, &frontPosition, &backPosition, &highestWallSeen, &amountTrapped, &currentStartWall](int n)
                    {
                        backPosition++;
                        if (frontPosition + backPosition >= rangeSize || n >= highestWallSeen)
                        {
                            highestWallSeen = n;
                            return true;
                        }
                        else if (n >= currentStartWall)
                        {
                            currentStartWall = n;
                        }
                        else
                        {
                            amountTrapped += currentStartWall - n;
                        }
                        return false;
                    }
                );
                currentStartWall = range[frontPosition];
            }
            else
            {
                if (n >= currentStartWall)
                {
                    currentStartWall = n;
                }
                else
                {
                    amountTrapped += currentStartWall - n;
                }
            }
            frontPosition++;
        }
    }
    std::cout << "amount trapped: " << amountTrapped << "\n";

    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}

std::vector<int> createElevationMap() {
    // generate elevation data
    std::mt19937 generator{ std::random_device{}() };
    std::exponential_distribution<> elevationDist{ 0.5 };
    auto elevationCreator = [&generator, &elevationDist]() {
        return static_cast<int>(elevationDist(generator));
    };
    auto elevationMap = randomVectorOfObjects<int, decltype(elevationCreator)>(elevationCreator);

    // ensure there is only one highest peak
    auto firstMaxPeakIt = std::max_element(elevationMap.begin(), elevationMap.end());
    *firstMaxPeakIt += 1;

    return elevationMap;
}
