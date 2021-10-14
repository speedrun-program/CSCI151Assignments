
#include <iostream>
#include <string>

int main()
{
    for (int n = 1; n <= 100; n++)
    {
        switch ((n % 3 == 0) + ((n % 5 == 0) * 2))
        {
            case 0:
                std::cout << n << "\n";
                break;
            case 1:
                std::cout << "Fizz\n";
                break;
            case 2:
                std::cout << "Buzz\n";
                break;
            case 3:
                std::cout << "FizzBuzz\n";
                break;
        }
    }

    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::string waitForUserToPressEnter = "";
    std::cin >> waitForUserToPressEnter;

    return 0;
}
