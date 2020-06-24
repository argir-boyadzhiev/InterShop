#pragma once
class Property
{
private:
	char* name;
	char* value;
public:
	Property();
	Property(const char* newName, const char* newValue);
	~Property();
	void operator=(const Property& rhs);

	const char* getName() const;
	const char* getValue() const;
};

