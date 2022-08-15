#pragma once
#include <iostream>
#include <string_view>
#include <utility>

using namespace std::literals;

namespace math {

	namespace common {

		class Point
		{
		public:

			// ------------ конструкторы класса -------------

			Point() = default;
			Point(double, double);
			Point(const Point&);
			Point(Point&&) noexcept;

			virtual ~Point() = default;

			// ------------ назначение параметров -----------

			Point& set_x(double);                                // назначение координаты X
			Point& set_y(double);                                // назначение координаты Y
			Point& set_coordinates(double, double);               // назначение координат
			Point& operator=(const Point&);                      // оператор присваивания
			Point& operator=(Point&&) noexcept;                  // оператор перемещения

			// ------------ получение параметров ------------

			double get_x() const;                                // получение координаты X
			double get_y() const;                                // получение координаты Y

			// ------------ математические операции ---------

			Point& operator+(const Point&);                      // координатное сложение двух точек
			Point& operator+=(const Point&);                     // координатное сложение двух точек
			Point& operator-(const Point&);                      // координатное вычитание точки 
			Point& operator-=(const Point&);                     // координатное вычитание точки 
			Point& operator*(const double&);                     // умножение координат точки на скаляр
			Point& operator*=(const double&);                    // умножение координат точки на скаляр
			Point& operator/(const double&);                     // деление координат точки на скаляр
			Point& operator/=(const double&);                    // деление координат точки на скаляр

			// ------------ булевые операции ----------------

			bool operator==(const Point&);                       // координатное равенство с другой точкой
			bool operator!=(const Point&);                       // координатное неравенство с другой точкой

			// ------------ прочие операции -----------------

			Point& swap(Point&);                                 // обмен координат с другой точкой
			Point& swap(Point&&);                                // обмен координат с другой точкой
			Point& clear();                                      // приведение точки к координатам 0:0

		private:
			double x_ = 0.0;
			double y_ = 0.0;
		};

		std::ostream& operator<<(std::ostream&, const Point&);

		class Spot : public Point
		{
		public:
			Spot() = default;

			Spot& set_name(std::string);                          // задать имя точки
			std::string get_name() const;                         // получить имя точки

		private:
			std::string name_ = "";
		};

		std::ostream& operator<<(std::ostream&, const Spot&);
	}

}