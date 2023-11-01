#include <iostream>
#include <locale>
#include <conio.h>

	class MyQueue
	{
	private:
		unsigned int NumberOfElements, MaxSize;
		int* Elements;

	public:
		MyQueue(unsigned int Size)//Конструктор
		{
			NumberOfElements = 0;
			MaxSize = Size;
			Elements = new int[Size];
		}

		~MyQueue()//Деструктор
		{
			delete[] Elements;
		}

		void Push(int NewElement)//Добавление элемента в очередь
		{
			if (NumberOfElements == MaxSize)
				std::cout << "Очередь переполнена!" << std::endl;
			else
			{
				Elements[NumberOfElements] = NewElement;
				NumberOfElements++;
			}
		}

		int Pop()//Удаление элемента из очереди
		{
			if (IsEmpty())
			{
				std::cout << "Очередь Пуста!" << std::endl;
				return 0;
			}
			else
			{
				int FirstElement = Elements[0];
				NumberOfElements--;
				int* NewArr = new int[NumberOfElements];
				for (unsigned int i = 0; i < NumberOfElements; i++)
				{
					NewArr[i] = Elements[i+1];
				}
				delete[] Elements;
				Elements = NewArr;
				return FirstElement;
			}
		}

		bool IsEmpty()//Проверка на пустоту
		{
			if (NumberOfElements == 0)
				return true;
			else
				return false;
		}

		int Peek()//Получение нижнего элемента очереди без удаления
		{

			if (IsEmpty())
			{
				std::cout << "Очередь Пуста!" << std::endl;
				return 0;
			}
			else
			{
				return Elements[0];
			}
		}

		unsigned int GetSize()//Получение размера
		{
			return NumberOfElements;
		}

		void PeekAll()//Вывод всех элементов на консооль
		{
			if (IsEmpty())
				std::cout << "Очередь пуста!" << std::endl;
			else
			{
				for (unsigned int i = 0; i < NumberOfElements; i++)
				{
					std::cout << Elements[i] << " ";
				}
				std::cout << std::endl;
			}
		}
	};

	int main()
	{
		setlocale(LC_ALL, "Russian");
		unsigned int QueueSize;
		std::cout << "Введите размер очереди!" << std::endl;
		std::cin >> QueueSize;
		MyQueue queue1(QueueSize);
		std::cout << "Добавляем элементы в очередь" << std::endl;
		int buff;
		for (unsigned int i = 0; i < QueueSize; i++)
		{
			std::cin >> buff;
			queue1.Push(buff);
		}
		std::cout << "Вся очередь:" << std::endl;
		queue1.PeekAll();
		std::cout << "Размер очереди = " << queue1.GetSize() << std::endl;
		std::cout << "Просмотрим последний элемент без удаления" << std::endl;
		std::cout << "Последний элемент = " << queue1.Peek() << std::endl;
		std::cout << "Размер очереди не изменился и = " << queue1.GetSize() << std::endl;
		std::cout << "Удалим первый элемент = " << queue1.Pop() << std::endl;
		std::cout << "Вся очередь:" << std::endl;
		queue1.PeekAll();
		std::cout << "Размер очереди изменился и = " << queue1.GetSize() << std::endl;
		std::cout << "Удалим все элементы" << std::endl;
		QueueSize = queue1.GetSize();
		for (unsigned int i = 0; i < QueueSize; i++)
		{
			queue1.Pop();
		}
		std::cout << "Проверим стек на наличие элементов" << std::endl;
		if (queue1.IsEmpty())
			std::cout << "Очередь пуста!" << std::endl;
		char s = _getch();
		return 1;
	}
