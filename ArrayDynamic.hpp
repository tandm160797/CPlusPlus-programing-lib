#ifndef ArrayDynamic_hpp
#define ArrayDynamic_hpp

#include <iostream>
using namespace std;

namespace prm{
	namespace ad{
		enum SearchType{
			First, Final
		};
		enum SortType{
			Increase, Decrease
		};
		/////////////
		void input(int *&array, int size);
		void output(int *array, int size);
		//
		void insert(int *&array, int &size, int index, int value);
		void insertHead(int *&array, int &size, int value);
		void insertTail(int *&array, int &size, int value);
		void erase(int *&array, int &size, int index);
		void eraseHead(int *&array, int &size);
		void eraseTail(int *&array, int &size);
		void update(int *array, int size, int index, int value);
		void updateHead(int *array, int size, int value);
		void updateTail(int *array, int size, int value);
		//
		bool search(int *array, int size, int value);
		int search(int *array, int size, int value, SearchType searchType);
		void sort(int *array, int size, SortType sortType);
		//
		void swap(int &x, int &y);
	}
}

#endif //ArrayDynami.hpp