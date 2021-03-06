#pragma once

// Represens constant size array which is allocated in stack, not in a heap
template<class T, UINT Size>
class Array
{
private:
	T arr[Size];

public:
	// Empty constructor
	inline Array();

	// Copies elements from "source"
	inline void operator=(const Array<T, Size> &source);
	// Get element reference by index
	inline const T &operator[](UINT index) const;
	// Get element reference by index
	inline T &operator[](UINT index);

	// Get size of array
	inline UINT GetSize() const;

	// Copy elements to this array from "source"
	inline void CopyFrom(const Array<T, Size> &source);
};


template<class T, UINT Size>
inline Array<T, Size>::Array()
{ }

template<class T, UINT Size>
inline void Array<T, Size>::operator=(const Array<T, Size>& source)
{
	CopyFrom(source);
}

template<class T, UINT Size>
inline const T &Array<T, Size>::operator[](UINT index) const
{
	ASSERT(index >= 0 && index < Size);

	return arr[index];
}

template<class T, UINT Size>
inline T &Array<T, Size>::operator[](UINT index)
{
	ASSERT(index >= 0 && index < Size);

	return arr[index];
}

template<class T, UINT Size>
inline UINT Array<T, Size>::GetSize() const
{
	return Size;
}

template<class T, UINT Size>
inline void Array<T, Size>::CopyFrom(const Array<T, Size>& source)
{
	for (UINT i = 0; i < Size; i++)
	{
		arr[i] = source.arr[i];
	}
}