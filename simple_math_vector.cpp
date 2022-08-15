#include "simple_math_vector.h"

namespace math {

	namespace vector {
	
		using namespace common;

		// ------------ class Vector --------------------

		// ------------ конструкторы класса -------------

		Vector::Vector(const Vector& other)
			: begin_(other.begin_), end_(other.end_), isNormalize_(other.isNormalize_) {
		}

		Vector::Vector(Vector&& other) noexcept
			: begin_(std::move(other.begin_))
			, end_(std::move(other.end_))
			, isNormalize_(std::move(other.isNormalize_)) {
		}

		Vector::Vector(const Point& end) : end_(end) {
		}

		Vector::Vector(Point&& end) noexcept
			:  end_(std::move(end)) {
		}

		Vector::Vector(const Point& begin, const Point& end) : begin_(begin), end_(end) {
		}
		
		Vector::Vector(Point&& begin, Point&& end) noexcept
			: begin_(std::move(begin)), end_(std::move(end)) {
		}

		// ------------ назначение параметров -----------

		Vector& Vector::set_start_point(const Point& begin) {
			begin_.set_x(begin.get_x());
			begin_.set_y(begin.get_y());
			return *this;
		}

		Vector& Vector::set_end_point(const Point& end) {
			end_.set_x(end.get_x());
			end_.set_y(end.get_y());
			return *this;
		}

		Vector& Vector::operator=(const Vector& other) {
			if (this == &other)
				return *this;

			Vector tmp(other);
			std::swap(*this, tmp);
			return *this;
		}

		Vector& Vector::operator=(Vector&& other) noexcept {
			if (this == &other)
				return *this;

			//std::swap(*this, other);

			begin_ = std::move(other.begin_);
			end_ = std::move(other.end_);
			return *this;
		}

		// ------------ получение параметров ------------

		double Vector::get_lenght() const {
			// используем теорему пифагора для прямоугольного треугольника
			double sq_x = std::pow((end_.get_x() - begin_.get_x()), 2);
			double sq_y = std::pow((end_.get_y() - begin_.get_y()), 2);

			return std::sqrt(sq_x + sq_y);
		}

		Vector Vector::get_normalize() {
			Vector result(*this);
			result.normalization();
			return result;
		}

		Point Vector::get_begin_point() const {
			return static_cast<common::Point>(begin_);
		}

		Point Vector::get_end_point() const {
			return static_cast<common::Point>(end_);
		}

		// ------------ математические операции ---------

		Vector& Vector::operator+(const Vector& other) {
			if (this->begin_ == other.begin_) {
				this->end_ += other.end_;
			}
			return *this;
		}

		Vector& Vector::operator+=(const Vector& other) {
			*this + other;
			return *this;
		}

		Vector& Vector::operator-(const Vector& other) {
			if (this->begin_ == other.begin_) {
				this->begin_ = other.end_;
			}
			return *this;
		}

		Vector& Vector::operator-=(const Vector& other) {
			*this - other;
			return *this;
		}

		// ------------ булевые операции ----------------

		bool Vector::operator==(const Vector& other) {
			return begin_ == other.begin_ && end_ == other.end_;
		}

		bool Vector::operator!=(const Vector& other) {
			return begin_ != other.begin_ || end_ != other.end_;
		}

		// ------------ прочие операции -----------------

		Vector& Vector::clear() {
			begin_.set_coordinates(0, 0);
			end_.set_coordinates(0, 0);
			isNormalize_ = false;
			return *this;
		}

		Vector& Vector::scale(double scale) {
			end_ *= scale;
			return *this;
		}

		Vector& Vector::set_zero() {
			begin_.set_coordinates(0, 0);
			return *this;
		}

		Vector& Vector::normalization() {
			this->scale(1 / this->get_lenght());
			this->isNormalize_ = true;
			return *this;
		}

		Vector& Vector::change_basis(const Vector& new_x, const Vector& new_y) {
			if (new_x.get_begin_point() != new_y.get_begin_point()) {
				throw std::logic_error("the starting points of the vectors are different");
			}

			if (begin_ == new_x.get_begin_point() && begin_ == new_y.get_begin_point()) {
				PointReconfiguration(end_, new_x.get_end_point(), new_y.get_end_point());
			}
			else {
				PointReconfiguration(begin_, new_x.get_begin_point(), new_y.get_begin_point());
				PointReconfiguration(end_, new_x.get_end_point(), new_y.get_end_point());
			}
			/*double end_x = end_.GetX();
			double end_y = end_.GetY();
			end_.SetX((end_x * new_x.GetEnd().GetX()) + (end_x * new_y.GetEnd().GetX()));
			end_.SetY((end_y * new_x.GetEnd().GetY()) + (end_y * new_y.GetEnd().GetY()));*/
			return *this;
		}

		bool Vector::is_normalize() {
			return isNormalize_;
		}

		// ------------ приватные методы ----------------

		void Vector::PointReconfiguration(Point& this_point, const Point& new_x_point, const Point& new_y_point) {
			double this_x = this_point.get_x();
			double this_y = this_point.get_y();
			this_point.set_x((this_x * new_x_point.get_x()) + (this_x * new_y_point.get_x()));
			this_point.set_y((this_y * new_x_point.get_y()) + (this_y * new_y_point.get_y()));
		}
		
		// ------------ class Vector END ----------------


		// ------------ общие функции -------------------

		std::ostream& operator<<(std::ostream& out, const Vector& vector) {
			out << "{ "sv << vector.get_begin_point() << "->"sv << vector.get_end_point() << " }"sv;
			return out;
		}
	
	}
}