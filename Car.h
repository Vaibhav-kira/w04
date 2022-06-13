#ifndef SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds {
	class Car {
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		Car();
		Car(const char* type,
			const char* brand,
			const char* model,
			int year = 2022,
			int code = 100,
			double price = 1.00);
		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		bool isValid() const;
		void printInfo() const;
		bool isSimilarTo(const Car& car) const;
		~Car();
	};
	void print(const Car car[], const int num_cars);
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
}
#endif // !SDDS_CAR_H
