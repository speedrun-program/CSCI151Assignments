
#include "online_store.h"

Item::Item(std::string name, long ID, double price, int initialStock)
{
	setName(name);
	_ID = ID;
	setPrice(price);
	addOrRemoveStock(initialStock);
}

std::string Item::getName() const { return _name; }
long Item::getID() const { return _ID; }
double Item::getPrice() const { return _price; }
int Item::getStock() const { return _stock; }

void Item::setName(std::string name) { _name = name; }

void Item::setPrice(double price)
{
	if (price < 0)
	{
		throw (std::invalid_argument("invalid price\n"));
	}
	_price = price;
}

void Item::addOrRemoveStock(int amount)
{
	if (_stock + amount < 0)
	{
		throw (std::invalid_argument("too much stock removed\n"));
	}
	_stock += amount;
}

double Order::getTotalPrice(const std::unordered_map<std::string, Item>& itemMap) const
{
	double totalPrice = 0.0;
	for (auto it : _itemAmounts)
	{
		totalPrice += itemMap.at(it.first).getPrice() * it.second;
	}
	return totalPrice;
}

std::unordered_map<std::string, int>::const_iterator Order::getOrderMapCBegin() const { return _itemAmounts.cbegin(); }

std::unordered_map<std::string, int>::const_iterator Order::getOrderMapCEnd() const { return _itemAmounts.cend(); }

void Order::addOrRemoveItem(std::string name, int amount)
{
	int& currentAmount = _itemAmounts[name];
	if (currentAmount + amount < 0)
	{
		throw (std::invalid_argument("too many items removed from order\n"));
	}
	currentAmount += amount;
}

// _itemArrayPositions.at will throw std::out_of_range if Item isn't found
Item& Store::getItem(std::string name) { return _itemMap.at(name); }

std::unordered_map<std::string, Item>::const_iterator Store::getItemMapCBegin() const { return _itemMap.cbegin(); }

std::unordered_map<std::string, Item>::const_iterator Store::getItemMapCEnd() const { return _itemMap.cend(); }

const std::unordered_map<std::string, Item>& Store::getItemMap() { return _itemMap; }

void Store::setItem(std::string name, double price, int initialStock)
{
	_itemMap.emplace(name, Item{ name, (long)_itemMap.size(), price, initialStock });
}
/*
void Store::processOrder(const Order& order)
{
	auto itEnd = order.getOrderMapCEnd();
	for (auto it = order.getOrderMapCBegin(); it != itEnd; ++it)
	{
		Item& currentItem = _itemMap.at(it->first);
		if (currentItem.getStock() - it->second < 0)
		{
			throw (std::invalid_argument("too many items requested from store\n"));
		}
		currentItem.addOrRemoveStock(it->second * -1);
	}
}
*/
void printOrder(Order& order, Store& store)
{
	std::cout << "\n";
	auto itEnd = order.getOrderMapCEnd();
	for (auto it = order.getOrderMapCBegin(); it != itEnd; ++it)
	{
		std::cout << it->first << " x " << it->second << "\n";
	}
	std::cout << "total price: " << order.getTotalPrice(store.getItemMap()) << "\n";
}

void printStore(Store& store)
{
	auto itEnd = store.getItemMapCEnd();
	std::cout << "\nStore:\n";
	for (auto it = store.getItemMapCBegin(); it != itEnd; ++it)
	{
		std::cout << it->second.getName() << " x " << it->second.getStock() << "\n";
	}
}
