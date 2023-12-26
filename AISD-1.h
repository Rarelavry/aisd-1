// AISD-1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <stdexcept>
#include <random>
#include <complex>
#include <math.h>

template <typename T>
class Vector {
	int _dimension;
	T* _values;
public:
	int getDimension() const{
		return _dimension;
	}

	Vector perpen() const {
		T x = _values[0];
		T y = _values[1];
		for (int i = 0; i < _dimension; i++) {
			_values[i] = 0;
		}
		_values[0] = y;
		_values[1] = x*(-1);
		return *this;
	}

	Vector(const Vector& v) {
		_dimension = v._dimension;
		_values = new T[_dimension];
		for (int i = 0; i < _dimension; i++) {
			_values[i] = v._values[i];
		}
	}

	Vector& operator=(const Vector& v) {
		for (int i = 0; i < _dimension; i++) {
			_values[i] = v._values[i];
		}
		return *this;
	}
	
	Vector() = delete;

	Vector(int dimension) {
		_dimension = dimension;
		_values = new T[dimension];
		for (int i = 0; i < dimension; i++) {
			_values[i] = 0;
		}
	}

	Vector(int dimension, T values[]) {
		_dimension = dimension;
		_values = new T[dimension];
		for (int i = 0; i < dimension; i++) {
			_values[i] = values[i];
		}
	}

	Vector(int dimension, double minValue, double maxValue) { 
		random_device rd;
		mt19937 e{ rd() }; // or std::default_random_engine e{rd()};
		uniform_real_distribution<double> dist{ minValue, maxValue };

		_dimension = dimension;
		_values = new T[dimension];
		for (int i = 0; i < dimension; i++) {
			_values[i] = dist(e);
		}
	}
	
	~Vector() {
		delete[] _values;
	}

	T& operator[](int i) {
		return _values[i];
	}

	const T& operator[](int i) const {
		return _values[i];
	}

	Vector operator+(const Vector& rhs) const {
		if (_dimension == rhs._dimension)
		{
			Vector v(_dimension);
			for (int i = 0; i < _dimension; i++) {
				v[i] = _values[i] + rhs[i];
			}
			return v;
		}
		else
		{
			throw invalid_argument("Vectors have diffrent dimensions");
		}
	}

	Vector operator-(const Vector& rhs) const {
		if (_dimension == rhs._dimension)
		{
			Vector v(_dimension);
			for (int i = 0; i < _dimension; i++) {
				v[i] = _values[i] - rhs[i];
			}
			return v;
		}
		else
		{
			throw invalid_argument("Vectors have diffrent dimensions");
		}
	}

	T operator*(const Vector& rhs) const {
		if (_dimension == rhs._dimension)
		{
			T sum = 0;
			for (int i = 0; i < _dimension; i++) {
				sum += _values[i] * rhs[i];
			}
			return sum;
		}
		else
		{
			throw invalid_argument("Vectors have diffrent dimensions");
		}
	}

	Vector operator*(const T& rhs) const {
		Vector v = Vector(*this);
		for (int i = 0; i < _dimension; i++) {
			v._values[i] *= rhs;
		}
		return v;
	}

	friend Vector operator*(const float& lhs, const Vector& rhs) {
		Vector v = Vector(rhs);
		for (int i = 0; i < v._dimension; i++) {
			v._values[i] *= lhs;
		}
		return v;
	}

	Vector operator/(const T& rhs) const {
		Vector v = Vector(this);
		for (int i = 0; i < _dimension; i++) {
			v._values[i] /= rhs;
		}
		return v;
	}

	bool operator==(const T& v) {
		for (int i = 0; i < _dimension; i++) {
			if (_values[i] - v._values[i] <0)
				if ((_values[i] - v._values[i])*(-1)>exp(1.0))
					return false;
			else 
				if (_values[i] - v._values[i] > exp(1.0))
					return false;
		}
		return true;
	}

};