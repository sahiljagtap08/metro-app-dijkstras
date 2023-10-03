#include <iostream>
#include<vector>
#include<unordered_map>

template <typename T>
class Heap
{
private:
	std::
		vector<T>
			data;
	std::unordered_map<T, int> map;

	void upHeapify(int ci)
	{
		int pi = (ci - 1) / 2;
		if (isLarger(data[ci], data[pi]) > 0)
		{
			swap(ci, pi);
			upHeapify(pi);
		}
	}

	void downHeapify(int pi)
	{
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		int largest = pi;

		if (lci < static_cast<int>(data.size()) && isLarger(data[lci], data[largest]) > 0)
		{
			largest = lci;
		}

		if (rci < static_cast<int>(data.size()) && isLarger(data[rci], data[largest]) > 0)
		{
			largest = rci;
		}

		if (largest != pi)
		{
			swap(pi, largest);
			downHeapify(largest);
		}
	}

	void swap(int i, int j)
	{
		T ith = data[i];
		T jth = data[j];

		data[i] = jth;
		data[j] = ith;

		map[ith] = j;
		map[jth] = i;
	}

public:
	void add(T item)
	{
		data.push_back(item);
		map[item] = data.size() - 1;
		upHeapify(data.size() - 1);
	}

	void display()
	{
		for (const T &item : data)
		{
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}

	int size()
	{
		return data.size();
	}

	bool isEmpty()
	{
		return size() == 0;
	}

	T remove()
	{
		swap(0, data.size() - 1);
		T rv = data.back();
		data.pop_back();
		downHeapify(0);

		map.erase(rv);
		return rv;
	}

	T get()
	{
		return data[0];
	}

	int isLarger(T t, T o)
	{
		if (t < o)
			return -1;
		if (t == o)
			return 0;
		return 1;
	}

	void updatePriority(T pair)
	{
		int index = map[pair];
		upHeapify(index);
	}
};
