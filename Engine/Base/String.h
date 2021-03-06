#pragma once

// Null terminated string allocated in a heap
class String
{
private:
	char *string;
	UINT length;	// string length without '\0'
					// memory allocated for string is (length+1)

private:
	// Allocates new string
	static char				*AllocateString(const char* orig);

public:
	// Creates empty string ("")
	String();
	// Creates copy of orig
	String(const String &orig);
	// Creates copy from orig
	String(const char* orig);
	// Destructor
	~String();

	char					&operator[](int i);
	char					operator[](int i) const;

	bool					operator==(const String &b) const;
	bool					operator==(const char *b) const;
	bool					operator!=(const String &b) const;
	bool					operator!=(const char *b) const;

	String					&operator=(const String &b);
	String					&operator=(const char *b);

	// Overloaded cast to const char*
	operator const char * () const;

	// Concatenate
	String					operator+(const String &b) const;
	// Concatenate
	String					operator+(const char *b) const;
	// Concatenate
	String					&operator+=(const String &b);
	// Concatenate
	String					&operator+=(const char *b);

	static bool				Compare(const char *a, const char *b);

	// Returns length of this string
	UINT					Length() const;

	// Makes string empty
	void					Clear();

	static bool				ToBool(const char *str);
	static int				ToInt(const char *str);
	static float			ToFloat(const char *str);
	static Vector3			ToVector3(const char *str);
	static Quaternion		ToQuaternion(const char *str);
	static Color4			ToColor4(const char *str);

	bool					ToBool() const;
	int						ToInt() const;
	float					ToFloat() const;
	Vector3					ToVector3() const;
	Quaternion				ToQuaternion() const;
	Color4					ToColor4() const;

	const char				*GetCharPtr() const;

	// Hash function for a string
	static UINT				StringHash(String toHash);

	// Free string memory
	void					Delete();
};

inline String::String() : String("")
{ }

inline String::String(const String &orig) : String(orig.string)
{ }

inline char &String::operator[](int i)
{
	ASSERT(i >= 0 && i <= (int)length); // == to allow to read '\0'
	return string[i];
}

inline char String::operator[](int i) const
{
	ASSERT(i >=0 && i <= (int)length); // == to allow to read '\0'
	return string[i];
}

inline bool String::operator==(const String &b) const
{
	return *this == b.string;
}

inline bool String::operator!=(const String &b) const
{
	return !(*this == b.string);
}

inline bool String::operator!=(const char * b) const
{
	return !(*this == b);
}

inline bool String::operator==(const char * b) const
{
	return Compare(this->string, b);
}

inline String &String::operator=(const String &b)
{
	*this = b.string;
	return *this;
}

inline String::operator const char*() const
{
	return string;
}

inline String String::operator+(const String &b) const
{
	return (*this + b.string);
}

inline String &String::operator+=(const String &b)
{
	*this += b.string;
	return *this;
}

inline UINT String::Length() const
{
	return length;
}

inline void String::Clear()
{
	*this = "";
}

inline bool String::ToBool() const
{
	return ToBool(string);
}

inline int String::ToInt() const
{
	return ToInt(string);
}

inline float String::ToFloat() const
{
	return ToFloat(string);
}

inline const char * String::GetCharPtr() const
{
	return string;
}

inline UINT String::StringHash(String toHash)
{
	// djb2
	// modified: using UINT

	unsigned char *str = (unsigned char*)toHash.string;

	UINT hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return hash;
}