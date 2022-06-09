#pragma once
#include <cmath>

namespace Jogo
{
	template <typename T>
	class Vector2D
	{
	public:
		T x, y;

		Vector2D<T>(T x = 0.0, T y = 0.0);
		~Vector2D();
		Vector2D<T> operator +(Vector2D v);
		Vector2D<T> operator - (Vector2D v);
		Vector2D<T> operator * (int i);
		Vector2D<T> operator * (float f);
		Vector2D<T> operator * (double d);
		void operator += (Vector2D<T> v);

		T operator * (Vector2D v);
		T modulo();
		Vector2D<T> versor();

		/*este vetor na direção de v*/
		Vector2D<T> projOrtogonal(Vector2D v){/*a fazer*/ }

	};

	template<typename T>
	inline Vector2D<T>::Vector2D(T x, T y):
		x(x),
		y(y)
	{
	}

	template<typename T>
	inline Vector2D<T>::~Vector2D()
	{
	}

	template<typename T>
	inline Vector2D<T> Vector2D<T>::operator+(Vector2D v)
	{
		return Vector2D<T>(x + v.x, y + v.y);
	}

	template<typename T>
	inline Vector2D<T> Vector2D<T>::operator-(Vector2D v)
	{
		return Vector2D<T>(x - v.x, y - v.y);
	}

	template<typename T>
	inline Vector2D<T> Vector2D<T>::operator*(int i)
	{
		return Vector2D<T>(x * i, y * i);
	}

	template<typename T>
	inline Vector2D<T> Vector2D<T>::operator*(float f)
	{
		return Vector2D<T>(x * f, y * f);
	}

	template<typename T>
	inline Vector2D<T> Vector2D<T>::operator*(double d)
	{
		return Vector2D<T>(x * d, y * d);
	}

	template<typename T>
	inline void Vector2D<T>::operator+=(Vector2D<T> v)
	{
		x += v.x;
		y += v.y;
	}


	template<typename T>
	inline T Vector2D<T>::operator*(Vector2D v)
	{
		return T(x * v.x + y * v.y);
	}

	template<typename T>
	inline T Vector2D<T>::modulo()
	{
		return sqrt(x*x + y*y);
	}

	template<typename T>
	inline Vector2D<T> Vector2D<T>::versor()
	{
		return Vector2D<T>(x / this->modulo(), y / this->modulo());
	}

	typedef Vector2D<float> Vector2F;
	typedef Vector2D<unsigned int> Vector2U;
}

