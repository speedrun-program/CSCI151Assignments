
#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

class Item
{
public:
	Item(std::string name, long ID, double price, int initialStock);

	std::string getName() const;
	long getID() const;
	double getPrice() const;
	int getStock() const;

	void setName(std::string name);
	void setPrice(double price);
	void addOrRemoveStock(int amount);

private:
	std::string _name;
	long _ID;
	double _price;
	int _stock = 0;
};

class Order
{
public:
	// default constructor works

	double getTotalPrice(const std::unordered_map<std::string, Item>& storeMap) const;

	std::unordered_map<std::string, int>::const_iterator getOrderMapCBegin() const;

	std::unordered_map<std::string, int>::const_iterator getOrderMapCEnd() const;

	void addOrRemoveItem(std::string name, int amount);

private:
	std::unordered_map<std::string, int> _itemAmounts;
};

class Store
{
public:
	// default constructor works

	Item& getItem(std::string name);

	std::unordered_map<std::string, Item>::const_iterator getItemMapCBegin() const;

	std::unordered_map<std::string, Item>::const_iterator getItemMapCEnd() const;

	const std::unordered_map<std::string, Item>& getItemMap();

	void setItem(std::string name, double price, int initialStock);

	void processOrder(const Order& order);

private:
	std::unordered_map<std::string, Item> _itemMap;
};

std::ostream& operator<<(std::ostream& out, const Item& item);

std::ostream& operator<<(std::ostream& out, const Store& store);

void printOrder(Order& order, Store& store);
