#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"
#include "StoreEmployee.h"
#include "MallEmployee.h"
#include "MaintenanceEmployee.h"
#include "StoreMaintenanceEmployee.h"
#include "GeneralFunctions.h"


typedef enum {
	eStoreEmployee = 1,
	eMallEmployee,
	eMaintenanceEmployee,
	eStoreMaintenanceEmployee,
} EMPLOYEE_TYPE;

class EmployeeFactory
{
public:
	static Employee* createEmployee(int type, Store* store = nullptr);
};