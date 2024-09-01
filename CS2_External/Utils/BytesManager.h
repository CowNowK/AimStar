#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

class Bytes
{

public:
	std::vector<byte> Data;

	Bytes() {}
	Bytes(const byte* _In, size_t Size);
	Bytes(std::initializer_list<byte> _In);
	Bytes(const int& _In);
	Bytes(const long long& _In);
	Bytes(const std::string& _In);

	bool operator!=(Bytes _In)
	{
		for (int i = 0; i < _In.Length(); i++)
		{
			if (this->Data[i] != _In.Data[i])
				return true;
		}
		return false;
	}
	bool operator==(Bytes _In)
	{
		for (int i = 0; i < _In.Length(); i++)
		{
			if (this->Data[i] != _In.Data[i])
				return false;
		}
		return true;
	}
	void operator=(Bytes _In)
	{
		Data.clear();
		for (int i = 0; i < _In.Length(); i++)
			this->Data.push_back(_In.Data[i]);
	}
	void operator+=(Bytes _In)
	{
		for (int i = 0; i < _In.Length(); i++)
			this->Data.push_back(_In.Data[i]);
	}
	Bytes& operator+(Bytes _In)
	{
		for (int i = 0; i < _In.Length(); i++)
			this->Data.push_back(_In.Data[i]);
		return *this;
	}

	Bytes& Add(const byte _In);
	int Length();
	bool Replace(int Index, int Length, Bytes Source);
	int Find(Bytes Source, int Index = 0);
	Bytes Get(int Index, int Length);
	byte* GetData();
	void Print();
};

