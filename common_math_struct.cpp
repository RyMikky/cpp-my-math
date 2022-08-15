#include "common_math_struct.h"

namespace math {

	namespace common {
		
		// ------------ class Point ---------------------

		// ------------ конструкторы класса -------------

		Point::Point(double x, double y) : x_(x), y_(y) {
		}

		Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {
		}

		Point::Point(Point&& other) noexcept
			: x_(std::exchange(other.x_, 0)), y_(std::exchange(other.y_, 0)) {
		}

		// ------------ назначение параметров -----------

		Point& Point::set_x(double x) {
			x_ = x;
			return *this;
		}

		Point& Point::set_y(double y) {
			y_ = y;
			return *this;
		}

		Point& Point::set_coordinates(double x, double y) {
			x_ = x; y_ = y;
			return *this;
		}

		Point& Point::operator=(const Point& other) {
			if (this == &other)
				return *this;

			x_ = other.x_;
			y_ = other.y_;
			return *this;
		}

		Point& Point::operator=(Point&& other) noexcept {
			if (this == &other)
				return *this;
		
			x_ = std::exchange(other.x_, 0);
			y_ = std::exchange(other.y_, 0);
			return *this;
		}

		// ------------ получение параметров ------------
		
		double Point::get_x() const {
			return x_;
		}

		double Point::get_y() const {
			return y_;
		}

		// ------------ математические операции ---------
		
		Point& Point::operator+(const Point& other) {
			x_ += other.x_;
			y_ += other.y_;
			return *this;
		}

		Point& Point::operator+=(const Point& other) {
			*this + other;
			return *this;
		}

		Point& Point::operator-(const Point& other) {
			x_ -= other.x_;
			y_ -= other.y_;
			return *this;
		}

		Point& Point::operator-=(const Point& other) {
			*this - other;
			return *this;
		}

		Point& Point::operator*(const double& scale) {
			x_ *= scale;
			y_ *= scale;
			return *this;
		}

		Point& Point::operator*=(const double& scale) {
			x_ *= scale;
			y_ *= scale;
			return *this;
		}

		Point& Point::operator/(const double& scale) {
			x_ /= scale;
			y_ /= scale;
			return *this;
		}

		Point& Point::operator/=(const double& scale) {
			x_ /= scale;
			y_ /= scale;
			return *this;
		}

		// ------------ булевые операции ----------------

		bool Point::operator==(const Point& other) {
			return x_ == other.x_
				&& y_ == other.y_;
		}

		bool Point::operator!=(const Point& other) {
			return x_ != other.x_
				&& y_ != other.y_;
		}

		// ------------ прочие операции -----------------

		Point& Point::swap(Point& other) {
			Point tmp(*this);
			*this = other;
			other = tmp;

			return *this;
		}

		Point& Point::swap(Point&& other) {
			Point tmp(*this);
			*this = other;
			other = tmp;

			return *this;
		}

		Point& Point::clear() {
			x_ = 0.0;
			y_ = 0.0;

			return *this;
		}

		// ------------ class Point END -----------------


		// ------------ общие функции -------------------

		std::ostream& operator<<(std::ostream& out, const Point& point) {
			out << "["sv << point.get_x() << ":"sv << point.get_y() << "]"sv;
			return out;
		}


		// ------------ class Spot ----------------------

		Spot& Spot::set_name(std::string name) {
			name_ = name;
			return *this;
		}

		std::string Spot::get_name() const {
			return name_;
		}

		// ------------ class Spot END ------------------


		// ------------ общие функции -------------------

		std::ostream& operator<<(std::ostream& out, const Spot& spot) {
			out << "["sv << spot.get_name() << ", "sv
				<< spot.get_x() << ":"sv << spot.get_y() << "]"sv;
			return out;
		}
	}
}