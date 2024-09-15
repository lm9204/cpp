#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	public:
		Array() : _size(0), _arr(NULL) {}

		Array(unsigned int n) : _size(n)
		{
			_arr = new T[n];
		}

		Array(const Array& ref) : _arr(NULL)
		{
			*this = ref;
		}

		Array&	operator=(const Array& ref)
		{
			if (this == &ref)
				return *this;
			
			if (_arr)
				delete _arr;

			this->_size = ref._size;
			this->_arr = new T[ref._size];
			for (unsigned int i = 0; i < _size; ++i)
				_arr[i] = ref._arr[i];

			return *this;
		}

		~Array()
		{
			if (_arr)
				delete _arr;
		}

		T&	operator[](unsigned int n)
		{
			if (n >= _size)
				throw std::out_of_range("Wrong Index");
			return _arr[n];
		}

		const T&	operator[](unsigned int n) const
		{
			if (n >= _size)
				throw std::out_of_range("Wrong Index");
			return _arr[n];
		}

		unsigned int	size() const
		{
			return _size;
		}

	private:
		unsigned int	_size;
		T*				_arr;
};

#endif