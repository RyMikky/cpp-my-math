#pragma once
#include <cmath>

#include "common_math_struct.h"

namespace math {

	namespace vector {

		using namespace common;

		class Vector
		{
		public:

			// ------------ конструкторы класса -------------

			Vector() = default;
			Vector(const Vector&);                                 // конструктор копирования из другого вектора
			Vector(Vector&&) noexcept;                             // конструктор присваивания из другого вектора
			Vector(const Point&);                                  // конструктор копирования из начала координат
			Vector(Point&&) noexcept;                              // конструктор перемещения из начала координат
			Vector(const Point&, const Point&);                    // конструктор копирования по двум точкам
			Vector(Point&&, Point&&) noexcept;                     // конструктор перемещения по двум точкам

			~Vector() = default;

			// ------------ назначение параметров -----------

			Vector& set_start_point(const Point&);                  // назначение начальной точки вектора
			Vector& set_end_point(const Point&);                    // назначение конечной точки вектора
			Vector& operator=(const Vector&);                       // оператор присваивания lvalue
			Vector& operator=(Vector&&) noexcept;                   // оператор перемещения rvalue

			// ------------ получение параметров ------------

			double get_lenght() const;                              // возвращает длину вектора
			Vector get_normalize();                                 // получить копию нормированного вектора
			Point get_begin_point() const;                          // возвращает точку начала вектора
			Point get_end_point() const;                            // возвращает точку конца вектора

			// ------------ математические операции ---------

			Vector& operator+(const Vector&);                       // сложение с другим вектором
			Vector& operator+=(const Vector&);                      // сложение с другим вектором
			Vector& operator-(const Vector&);                       // вычитание другого вектора
			Vector& operator-=(const Vector&);                      // вычитание другого вектора

			// ------------ булевые операции ----------------

			bool operator==(const Vector&);                         // равенство двух векторов
			bool operator!=(const Vector&);                         // неравенство двух векторов

			// ------------ прочие операции -----------------

			Vector& clear();                                        // обнулить текущий вектор
			Vector& scale(double);                                  // произведение вектора на скаляр
			Vector& set_zero();                                     // обнулить начальную точку
			Vector& normalization();                                // нормировать текущий вектор
			Vector& change_basis(const Vector&, const Vector&);     // преобразить по новым базисным векторам
			bool is_normalize();                                    // возвращает ответ нормирован ли вектор

		private:
			common::Point begin_;
			common::Point end_;
			bool isNormalize_ = false;

			// ------------ приватные методы ----------------

			void PointReconfiguration(Point&, const Point&, const Point&);      // преобразование точки для смены базиса
		};

		std::ostream& operator<<(std::ostream&, const Vector&);
	}

}