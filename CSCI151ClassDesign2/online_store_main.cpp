
#include "online_store.h"

int main()
{
    try
    {
        Store store;

        store.setItem("book", 1.23, 12);
        store.setItem("colored pencils", 2.34, 15);
        store.setItem("coloring paper", 3.45, 20);
        store.setItem("markers", 4.56, 50);
        store.setItem("crayons", 5.67, 0);
        store.setItem("staples", 6.78, 10);

        store.getItem("crayons").addOrRemoveStock(3);
        store.getItem("staples").addOrRemoveStock(-3);

        std::cout << store.getItem("markers");

        std::cout << store;

        Order order;

        order.addOrRemoveItem("book", 1);
        order.addOrRemoveItem("markers", 2);
        order.addOrRemoveItem("crayons", 5);
        order.addOrRemoveItem("crayons", -2);

        printOrder(order, store);

        store.processOrder(order);

        std::cout << store;
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what();
    }

    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}
