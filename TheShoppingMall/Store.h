#pragma once
#include <iostream>
#include <vector>
#include "StoreEmployee.h"
#include "Product.h"
#include "Client.h"
#include "MallExceptions.h"
using namespace std;

class Client;
class Product;
class StoreEmployee;

class Store
{
protected:
	string						name;
	vector<Client*>				clientList;			
	vector<StoreEmployee*>		employeeList;		
	vector<Product*>			productList;		
	Sorter*						sortStrategy;		// Strategy

public:
	Store(string name_a);
	virtual ~Store();

	string						getName() const { return name; }
	vector<StoreEmployee*>		getEmployeeList() const { return employeeList; }
	vector<Product*>			getProductList() const { return productList; }
	vector<Client*>				getClientList() const { return clientList; }
	bool						addProduct(Product* prod);
	bool						checkPID(int id);
	void						showAllEmployeesInStore() const;
	void						showAllProducts() const;
	void						showAllClients(bool nameOnly) const;
	bool						addClient(Client* client);
	void						setName(string name_a);
	bool						addEmployee(StoreEmployee* emp);
	bool						clientBuyProduct(int client, int product);
	void						setSortStrategy(Sorter* strategy);
	void						sort() { sortStrategy->sort(productList); }
	virtual void				show(ostream& out) const = 0;
	virtual void				specialEvent() const = 0;
};