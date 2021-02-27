#include "ArrayStatic.hpp"

namespace prm{
	namespace as{
		void input(int array[], int size){
			for (int i = 0; i < size; i++){
				cout << "Typing array[" << i << "]: ";
				cin >> array[i];
			}
		}
		void output(int array[], int size){
			for (int i = 0; i < size; i++){
				cout << array[i] << " ";
			}
		}
		//
		void insert(int array[], int &size, int index, int value){
			for (int i = size; i > index; i--){
				array[i] = array[i - 1];
			}
			array[index] = value;
			size++;
		}
		void insertHead(int array[], int &size, int value){
			for (int i = size; i > 0; i--){
				array[i] = array[i - 1];
			}
			array[0] = value;
			size++;
		}
		void insertTail(int array[], int &size, int value){
			array[size] = value;
			size++;
		}
		void erase(int array[], int &size, int index){
			for (int i = index; i < (size - 1); i++){
				array[i] = array[i + 1];
			}
			size--;
		}
		void eraseHead(int array[], int &size){
			for (int i = 0; i < (size - 1); i++){
				array[i] = array[i + 1];
			}
			size--;
		}
		void eraseTail(int array[], int &size){
			size--;
		}
		void update(int array[], int size, int index, int value){
			array[index] = value;
		}
		void updateHead(int array[], int size, int value){
			array[0] = value;
		}
		void updateTail(int array[], int size, int value){
			array[(size - 1)] = value;
		}
		//
		bool search(int array[], int size, int value){
			for (int i = 0; i < size; i++){
				if (array[i] == value){
					return true;
				}
			}
			return false;
		}
		int search(int array[], int size, int value, SearchType searchType){
			if (searchType == SearchType::First){
				for (int i = 0; i < size; i++){
					if (array[i] == value){
						return i;
					}
				}
			}
			else{
				for (int i = (size - 1); i >= 0; i--){
					if (array[i] == value){
						return i;
					}
				}
			}
			return -1;
		}
		void sort(int array[], int size, SortType sortType){
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