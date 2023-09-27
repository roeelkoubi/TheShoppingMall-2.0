#include "StoreFactory.h"

Store* StoreFactory::createStore(int type)
{
    Store* pTemp = nullptr;
    cleanBuffer();
    switch (type)
    {
    case eRestaurant:
    {
        cout << "--> Please enter Restaurant name:\n";
        string name;
        getline(cin, name);

        cout << "--> Please enter food type:\n";
        string foodType;
        getline(cin, foodType);

        pTemp = new Restaurant(name, foodType);
        break;
    }
    case eEntertainment:
    {
        cout << "--> Please enter Entertainment store name:\n";
        string name;
        getline(cin, name);

        cout << "--> Please enter Entertainment type:\n";
        string entertainmentType;
        getline(cin, entertainmentType);

        pTemp = new Entertainment(name, entertainmentType);
        break;
    }
    case eSpecialty:
    {
        cout << "--> Please enter Specialty store name:\n";
        string name;
        getline(cin, name);

        cout << "--> Please enter merchandise type:\n";
        string merchandiseType;
        getline(cin, merchandiseType);

        pTemp = new SpecialtyStore(name, merchandiseType);
        break;
    }
    default:
        cout << "Store type does not exists." << endl;
        break;
    }
    return pTemp;
}