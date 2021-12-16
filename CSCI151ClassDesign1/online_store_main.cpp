
#include "online_store.h"

int main()
{
    try
    {
        Store store;

        store.setItem("book", 1.00, 12);
        store.setItem("colored pencils", 2.00, 15);
        store.setItem("coloring paper", 3.00, 20);
        store.setItem("markers", 4.00, 50);
        store.setItem("crayons", 4.50, 0);
        store.setItem("staples", 5.00, 10);

        store.getItem("crayons").addOrRemoveStock(3);
        store.getItem("staples").addOrRemoveStock(-3);

        printStore(store);

        Order order;

        order.addOrRemoveItem("book", 1);
        order.addOrRemoveItem("markers", 2);
        order.addOrRemoveItem("crayons", 5);
        order.addOrRemoveItem("crayons", -2);

        printOrder(order, store);

        //store.processOrder(order);

        //printStore(store);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what();
    }
    
    std::string exitInput = "";
    std::cout << "\nType visible character(s) and press Enter to end program.\n";
    std::cin >> exitInput;
}
