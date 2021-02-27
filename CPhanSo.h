#pragma once
#include<iostream>
using namespace std;

class CPhanSo{
private:
	int tuSo;
	int mauSo;
	int timUCLN(int a, int b);
	void rutGon();
	void chuanHoa();
public:
	CPhanSo();
	CPhanSo(int tuSo);
	CPhanSo(int tuSo, int mauSo);
	CPhanSo(CPhanSo const &phanSo);
	friend istream& operator>>(istream& in, CPhanSo &phanSo);
	friend ostream& operator<<(ostream& out, CPhanSo phanSo);
	CPhanSo operator+(CPhanSo phanSo);
	CPhanSo operator-(CPhanSo phanSo);
	CPhanSo operator*(CPhanSo phanSo);
	CPhanSo operator/(CPhanSo phanSo);
	CPhanSo operator++();//không truyền thì this bên phải =>++a
	CPhanSo operator++(int dummy);
	CPhanSo operator--();
	CPhanSo operator--(int dummy);
	bool operator>(CPhanSo phanSo);
	bool operator>=(CPhanSo phanSo);
	bool operator<(CPhanSo phanSo);
	bool operator<=(CPhanSo phanSo);
	bool operator==(CPhanSo phanSo);
	void operator=(CPhanSo phanSo);
	CPhanSo operator+=(CPhanSo phanSo);
	CPhanSo operator-=(CPhanSo phanSo);
	CPhanSo operator*=(CPhanSo phanSo);
	CPhanSo operator/=(CPhanSo phanSo);
};