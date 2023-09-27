#pragma once
#include <vector>
#include "Product.h"

class Sorter
{
public:
	virtual void sort(vector<Product*>& products) const = 0;
};

class PriceSort : public Sorter
{
public:
    virtual void sort(vector<Product*>& products) const override
    {
        size_t n = products.size();
        bool swapped;

        for (size_t i = 0; i < n - 1; i++) {
            swapped = false;

            for (size_t j = 0; j < n - i - 1; j++) {
                if (products[j]->getPrice() <= products[j + 1]->getPrice()) {
                    Product* temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped) {
                // If no swap occurred in the inner loop, the vector is already sorted
                break;
            }
        }
    }
};

class IdSort : public Sorter
{
public:
    virtual void sort(vector<Product*>& products) const override
    {
        size_t n = products.size();
        bool swapped;

        for (size_t i = 0; i < n - 1; i++) {
            swapped = false;

            for (size_t j = 0; j < n - i - 1; j++) {
                if (products[j]->getPID() >= products[j + 1]->getPID()) {
                    Product* temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped) {
                // If no swap occurred in the inner loop, the vector is already sorted
                break;
            }
        }
    }
};