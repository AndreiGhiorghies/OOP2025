#include <exception>
#include <iostream>

using namespace std;

class out_of_bounds : public exception
{
	virtual const char* what() const throw()
	{
		return "Index out of bounds";
	}
};

class division_by_zero : public exception
{
	virtual const char* what() const throw()
	{
		return "Division by zero";
	}
};

class empty_array : public exception {
	const char* what() const throw() {
		return "Operation on empty array";
	}
};


template<typename T>
class Array {
private:
	T* data;
	int size, count;
	out_of_bounds out_of_bounds_exception;

	void resize() {
		size *= 2;
		T* temp = new T[size];
		for (int i = 0; i < count; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
	}
	
public:
	Array() {
		size = 2;
		count = 0;
		data = new T[size];
	}
	Array(int length) {
		size = length;
		count = 0;
		data = new T[size];
	}
	Array(int length, const T vals[]) {
		size = length;
		count = length;
		data = new T[size];
		for (int i = 0; i < length; i++)
			data[i] = vals[i];
	}

	Array(const Array& from) {
		delete[] data;
		size = from.size;
		count = from.count;
		data = new T[size];

		for (int i = 0; i < count; i++)
			data[i] = from.data[i];
	}
	Array(Array&& from) {
		size = from.size;
		count = from.count;
		delete[] data;
		data = from.data;
		delete[] from.data;
		from.data = nullptr;
	}

	Array& operator=(const Array& other) {
		if (this == &other) 
			return *this;
		delete[] data;
		size = other.size;
		count = other.count;
		data = new T[size];
		for (int i = 0; i < count; ++i) 
			data[i] = other.data[i];
		return *this;
	}

	Array& operator=(Array&& other) {
		if (this == &other) 
			return *this;
		delete[] data;
		data = other.data;
		size = other.size;
		count = other.count;
		other.data = nullptr;
		other.size = 0;
		other.count = 0;
		return *this;
	}

	~Array() {
		delete[] data;
		data = nullptr;
		size = 0;
		count = 0;
	}
	
	Array& operator+(const Array& other) {
		Array<T> ans(size + other.size);
		ans.count = count;
		for (int i = 0; i < count; i++) {
			ans.data[i] = data[i];
		}
		for (int i = 0; i < other.count; i++)
			if (!find(other.data[i])) {
				ans[ans.count] = other.data[i];
				ans.count++;
			}
		return ans;
				
	}

	Array& operator-(const Array& other) {
		Array<T> ans(size + other.size);
		ans.count = 0;
		for (int i = 0; i < count; i++) {
			if (!find(other.data[i])) {
				ans.data[ans.count] = data[i];
				ans.count++;
			}
		}
		return ans;
	}

	Array& operator*(const int& val) {
		Array<T> ans(size);
		ans.count = count;
		for (int i = 0; i < count; i++) {
			ans.data[i] = data[i] * val;
		}
		return ans;
	}

	Array& operator/(const int& val) {
		if (val == 0)
			throw division_by_zero();
		Array<T> ans(size);
		ans.count = count;
		for (int i = 0; i < count; i++) {
			ans.data[i] = data[i] / val;
		}
		return ans;
	}

	T& operator[](int index) {
		if (index < 0 || index >= count)
			throw out_of_bounds();
		return data[index];
	}

	bool find(const T& val) {
		for (int i = 0; i < count; i++)
			if (data[i] == val)
				return true;
		return false;
	}
	
	void Sort() {
		if (count == 0)
			throw empty_array();

		for(int i = 0; i < count - 1; i++)
			for(int j = i + 1; j < count; j++)
				if (data[i] > data[j]) {
					T temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
	}

	void Sort(bool(*compare)(const T& a, const T& b)) {
		if (count == 0)
			throw empty_array();

		for (int i = 0; i < count - 1; i++)
			for (int j = i + 1; j < count; j++)
				if (compare(data[i], data[j])) {
					T temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
	}
	void Insert(int index, const T& val) {
		if (index < 0 || index > count)
			throw out_of_bounds();
		if (count == size)
			resize();
		for (int i = count; i > index; i--)
			data[i] = data[i - 1];
		data[index] = val;
	}
	void Erase(int index) {
		if (index < 0 || index > count)
			throw out_of_bounds();
		while (index < count - 1)
			data[index] = data[index + 1];
		count--;
	}
	void Delete() {
		delete[] data;
		size = 2;
		count = 0;
		data = new T[size];
	}

	class iterator_array {
	private:
		T *idx;
	public:
		void SetVal(T* val) {
			idx = val;
		}
		iterator_array& operator++(int) {
			idx++;
			return *this;
		}iterator_array& operator++() {
			idx++;
			return *this;
		}
		bool operator!=(const iterator_array& other) {
			return idx != other.idx;
		}
		T& operator*() {
			return *idx;
		}
	};

	iterator_array begin() {
		iterator_array it;
		it.SetVal(data);
		return it;
	}
	iterator_array end() {
		iterator_array it;
		it.SetVal(data + count);
		return it;
	}
};

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	Array<int> v(5, arr);
	Array<int>::iterator_array it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << ' ';
	cout << endl;
	try {
		cout << v[1] << endl;
	}
	catch (exception& e) {
		cout << e.what();
	}
	v[2] = 10;
	for (auto i : v)
		cout << i << ' ';
}

