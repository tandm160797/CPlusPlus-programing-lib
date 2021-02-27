#include "Utility.hpp"

namespace prm{
	int uocChungLonNhat(int a, int b){
		int r;
		while (b != 0){
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
	int boiChungNhoNhat(int a, int b){
		return (a * b) / uocChungLonNhat(a, b);
	}
	int soCoMayChuSo(int n){
		int dem = 0;
		while (n != 0){
			dem++;
			n /= 10;
		}
		return dem;
	}
	//
	bool kiemTraNamNhuan(int nam){
		return ((nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0)));
	}
	bool kiemTraSoNguyenTo(int n){
		if (n < 2){
			return false;
		}
		if (n == 2){
			return true;
		}
		if (n % 2 == 0){
			return false;
		}
		for (int i = 2; i <= sqrt(n); i++){
			if (n%i == 0){
				return false;
			}
		}
		return true;
	}
	bool kiemTraSoSieuNguyenTo(int n){
		if (n < 2){
			return false;
		}
		while (n != 0){
			if (!kiemTraSoNguyenTo(n)){
				return false;
			}
			n /= 10;
		}
		return true;
	}
	bool kiemTraSoChinhPhuong(int n){
		if (n < 1){
			return false;
		}
		int temp = sqrt(n);
		return ((temp * temp) == n);
	}
	bool kiemTraSoHoanThien(int n){
		if (n < 6){
			return false;
		}
		int tongUoc = 0;
		for (int i = 1; i < n; i++){
			if (n % i == 0){
				tongUoc += i;
			}
		}
		return (tongUoc == n);
	}
	bool kiemTraSoDoiXung(int n){
		int soDao = 0, tam = n, soMu = soCoMayChuSo(n) - 1;
		while (tam != 0){
			soDao += (tam % 10) * pow(10, soMu);
			soMu--;
			tam /= 10;
		}
		return (soDao == n);
	}
	bool kiemTraSoTuMan(int n){
		if (n < 0){
			return false;
		}
		int tong = 0, tam = n, soMu = soCoMayChuSo(n);
		while (tam != 0){
			tong += pow((tam % 10), soMu);
			tam /= 10;
		}
		return (tong == n);
	}
}
