#include "ArrayDynamic.hpp"

namespace prm{
	namespace ad{
		void input(int *&array, int size){
			if (array != nullptr){
				array = nullptr;
				delete[] array;
			}
			array = new int[size];
			for (int i = 0; i < size; i++){
				cout << "Typing array[" << i << "]: ";
				cin >> array[i];
			}
		}
		void output(int *array, int size){
			for (int i = 0; i < size; i++){
				cout << array[i] << " ";
			}
		}
		//
		void insert(int *&array, int &size, int index, int value){
			int *temp = array;
			array = new int[(size + 1)];
			for (int i = 0; i < index; i++){
				array[i] = temp[i];
			}
			array[index] = value;
			for (int j = (index + 1); j < (size + 1); j++){
				array[j] = temp[(j - 1)];
			}
			size++;
			temp = nullptr;
			delete[] temp;
		}
		void insertHead(int *&array, int &size, int value){
			int *temp = array;
			array = new int[(size + 1)];
			array[0] = value;
			for (int i = 1; i < (size + 1); i++){
				array[i] = temp[(i - 1)];
			}
			size++;
			temp = nullptr;
			delete[] temp;
		}
		void insertTail(int *&array, int &size, int value){
			int *temp = array;
			array = new int[(size + 1)];
			for (int i = 0; i < size; i++){
				array[i] = temp[i];
			}
			array[size] = value;
			size++;
			temp = nullptr;
			delete[] temp;
		}
		void erase(int *&array, int &size, int index){
			int *temp = array;
			array = new int[(size - 1)];
			for (int i = 0; i < index; i++){
				array[i] = temp[i];
			}
			for (int j = index; j < (size - 1); j++){
				array[j] = temp[(j + 1)];
			}
			temp = nullptr;
			delete[] temp;
			size--;
		}
		void eraseHead(int *&array, int &size){
			int *temp = array;
			array = new int[(size - 1)];
			for (int i = 0; i < (size - 1); i++){
				array[i] = temp[(i + 1)];
			}
			temp = nullptr;
			delete[] temp;
			size--;
		}
		void eraseTail(int *&array, int &size){
			int *temp = array;
			array = new int[(size - 1)];
			for (int i = 0; i < (size - 1); i++){
				array[i] = temp[i];
			}
			temp = nullptr;
			delete[] temp;
			size--;

		}
		void update(int *array, int size, int index, int value){
			array[index] = value;
		}
		void updateHead(int *array, int size, int value){
			array[0] = value;
		}
		void updateTail(int *array, int size, int value){
			array[(size - 1)] = value;
		}
		//
		bool search(int *array, int size, int value){
			for (int i = 0; i < size; i++){
				if (array[i] == value){
					return true;
				}
			}
			return false;
		}
		int search(int *array, int size, int value, SearchType searchType){
			if (searchType == SearchType::First){
				for (int i = 0; i < size; i++){
					if (array[i] == value){
						return i;
					}
				}
			}
			else{
				for (int j = (size - 1); j >= 0; j--){
					if (array[j] == value){
						return j;
					}
				}
			}
			return -1;
		}
		void sort(int *array, int size, SortType sortType){
			if (sortType == SortType::Increase){
				for (int i = 0; i < (size - 1); i++){
					for (int j = (i + 1); j < size; j++){
						if (array[i] > array[j]){
							swap(array[i], array[j]);
						}
					}
				}
			}
			else{
				for (int i = 0; i < (size - 1); i++){
					for (int j = (i + 1); j < size; j++){
						if (array[i] < array[j]){
							swap(array[i], array[j]);
						}
					}
				}
			}
		}
		//
		void swap(int &x, int &y){
			int temp = x;
			x = y;
			y = temp;
		}
	}
}