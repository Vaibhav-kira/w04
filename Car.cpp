#include<iostream>
#include<cstring>
#include<iomanip>
#include "Car.h"
using namespace std;
using namespace sdds;
namespace sdds {
	Car::Car() {
		rese

	}
	void Car::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_code = 0;
		m_model = nullptr;
		m_price = 0;
		m_year = 0;
	}
	Car::Car(const char* type,
		const char* brand,
		const char* model,
		int year,
		int code,
		double price) {
		resetInfo();
		setInfo(type, brand, model, year , code , price );
	}
	Car& Car::setInfo(const char* type,
		const char* brand,
		const char* model,
		int year,
		int code,
		double price) {
		if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || price < 0) {
			resetInfo();
		}
		else {
			delete[] m_type;
			delete[] m_brand;
			delete[] m_model;
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		return *this;
	}
	bool Car::isValid() const {
		return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_price >= 1;
	}
	void Car::printInfo() const {
		cout << "|" << std::setw(12) << m_type << "|" << std::setw(18) << m_brand << "|" << std::setw(18) << m_model << "|" << std::setw(6) << m_year << "|" << std::setw(6) << m_code << "|" << std::setw(11)<< fixed <<setprecision(2) << m_price << "|" << std::endl;
	}
	void print(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			if (car[i].isValid()) {
				car[i].printInfo();
			}
		}
	}
	bool has_invalid(const Car car[], const int num_cars) {

		for (int i = 0; i < num_cars; i++) {
			if (!car[i].isValid()) {
				return true;
			}
		}
		return false;
	}
	bool Car::isSimilarTo(const Car& car) const {
		return m_year == car.m_year;
	}
	bool has_similar(const Car car[], const int num_cars) {
		bool flag = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					flag = true;
				}
			}
		}
		return flag;
	}
	Car::~Car() {
		delete[] m_type;
		delete[] m_model;
		delete[] m_brand;
	}
}