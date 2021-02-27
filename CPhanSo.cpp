#include"CPhanSo.h"

int CPhanSo::timUCLN(int a, int b){
	int temp;
	while (b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}
void CPhanSo::rutGon(){
	int temp = timUCLN(this->tuSo, this->mauSo);
	this->tuSo /= temp;
	this->mauSo /= temp;
}
void CPhanSo::chuanHoa(){
	if (this->tuSo == 0){
		this->mauSo = 1;
	}
	else{
		if (this->tuSo < 0 && this->mauSo < 0){
			this->tuSo = abs(this->tuSo);
			this->mauSo = abs(this->mauSo);
		}
		if (this->mauSo < 0){
			this->tuSo = -abs(this->tuSo);
			this->mauSo = abs(this->mauSo);
		}
	}
}
CPhanSo::CPhanSo(){
	this->tuSo = 0;
	this->mauSo = 1;
}
CPhanSo::CPhanSo(int tuSo){
	this->tuSo;
	this->mauSo = 1;
}
CPhanSo::CPhanSo(int tuSo, int mauSo){
	this->tuSo = tuSo;
	this->mauSo = mauSo;
}
CPhanSo::CPhanSo(CPhanSo const &phanSo){
	this->tuSo = phanSo.tuSo;
	this->mauSo = phanSo.mauSo;
}
istream& operator>>(istream& in, CPhanSo &phanSo){
	cout << "Nhap tu: ";
	cin >> phanSo.tuSo;
	cout << "Nhap mau: ";
	cin >> phanSo.mauSo;
	if (phanSo.mauSo == 0){
		exit(1);
	}
	else{
		return in;
	}
}
ostream& operator<<(ostream& out, CPhanSo phanSo){
	cout << phanSo.tuSo << "/" << phanSo.mauSo;
	return out;
}
CPhanSo CPhanSo::operator+(CPhanSo phanSo){
	CPhanSo kq;
	kq.tuSo = this->tuSo * phanSo.mauSo + this->mauSo *phanSo.tuSo;
	kq.mauSo *=this->mauSo*phanSo.mauSo;
	kq.chuanHoa();
	kq.rutGon();
	return kq;
}
CPhanSo CPhanSo::operator-(CPhanSo phanSo){
	CPhanSo kq;
	kq.tuSo = this->tuSo * phanSo.mauSo - this->mauSo *phanSo.tuSo;
	kq.mauSo *=phanSo.mauSo;
	kq.chuanHoa();
	kq.rutGon();
	return kq;
}
CPhanSo CPhanSo::operator*(CPhanSo phanSo){
	CPhanSo kq;
	kq.tuSo = this->tuSo * phanSo.tuSo;
	kq.mauSo = this->mauSo*phanSo.mauSo;
	kq.chuanHoa();
	kq.rutGon();
	return kq;
}
CPhanSo CPhanSo::operator/(CPhanSo phanSo){
	CPhanSo kq;
	kq.tuSo = this->tuSo * phanSo.mauSo;
	kq.mauSo = this->mauSo*phanSo.tuSo;
	kq.chuanHoa();
	kq.rutGon();
	return kq;
}
CPhanSo CPhanSo::operator++(){//không truyền thì this bên phải =>++a
	this->tuSo += 1;
	this->chuanHoa();
	this->rutGon();
	return *this;
}
CPhanSo CPhanSo::operator++(int dummy){//a++
	CPhanSo kq;
	kq.tuSo = this->tuSo;
	kq.mauSo = this->mauSo;
	this->tuSo += 1;
	kq.chuanHoa();
	kq.rutGon();
	return kq;
}
CPhanSo CPhanSo::operator--(){//--a
	this->tuSo -= 1;
	this->chuanHoa();
	this->rutGon();
	return *this;
}
CPhanSo CPhanSo::operator--(int dummy){//a--
	CPhanSo kq;
	kq.tuSo = this->tuSo;
	kq.mauSo = this->mauSo;
	this->tuSo -= 1;
	kq.chuanHoa();
	kq.rutGon();
	return kq;
}
bool CPhanSo::operator>(CPhanSo phanSo){
	phanSo.chuanHoa();
	phanSo.rutGon();
	if (this->tuSo*phanSo.mauSo > this->mauSo*phanSo.tuSo){
		return true;
	}
	return false;
}
bool CPhanSo::operator>=(CPhanSo phanSo){
	phanSo.chuanHoa();
	phanSo.rutGon();
	if (this->tuSo*phanSo.mauSo >= this->mauSo*phanSo.tuSo){
		return true;
	}
	return false;
}
bool CPhanSo::operator<(CPhanSo phanSo){
	phanSo.chuanHoa();
	phanSo.rutGon();
	if (this->tuSo*phanSo.mauSo < this->mauSo*phanSo.tuSo){
		return true;
	}
	return false;
}
bool CPhanSo::operator<=(CPhanSo phanSo){
	phanSo.chuanHoa();
	phanSo.rutGon();
	if (this->tuSo*phanSo.mauSo <= this->mauSo*phanSo.tuSo){
		return true;
	}
	return false;
}
bool CPhanSo::operator==(CPhanSo phanSo){
	phanSo.chuanHoa();
	phanSo.rutGon();
	if (this->tuSo == phanSo.tuSo && this->mauSo*phanSo.mauSo){
		return true;
	}
	return false;
}
void CPhanSo::operator=(CPhanSo phanSo){
	this->tuSo = phanSo.tuSo;
	this->mauSo = phanSo.mauSo;
}
CPhanSo CPhanSo::operator+=(CPhanSo phanSo){
	this->tuSo = this->tuSo * phanSo.mauSo + this->mauSo * phanSo.tuSo;
	this->mauSo *= phanSo.mauSo;
	this->chuanHoa();
	this->rutGon();
	return *this;
}
CPhanSo CPhanSo::operator-=(CPhanSo phanSo){
	this->tuSo = this->tuSo * phanSo.mauSo - this->mauSo * phanSo.tuSo;
	this->mauSo *= phanSo.mauSo;
	this->chuanHoa();
	this->rutGon();
	return *this;
}
CPhanSo CPhanSo::operator*=(CPhanSo phanSo){
	this->tuSo *= phanSo.tuSo;
	this->mauSo *= phanSo.mauSo;
	this->chuanHoa();
	this->rutGon();
	return *this;
}
CPhanSo CPhanSo::operator/=(CPhanSo phanSo){
	this->tuSo *= phanSo.mauSo;
	this->mauSo *= phanSo.tuSo;
	this->chuanHoa();
	this->rutGon();
	return *this;
}