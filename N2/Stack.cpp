#include <iostream>
#include <locale>
#include <conio.h>


	class MyStack
	{
	private:
		unsigned int NumberOfElements, MaxSize;
		int* Elements;

	public:
		MyStack(unsigned int Size)//Конструктор
		{
			NumberOfElements = 0;
			MaxSize = Size;
			Elements = new int[Size];
		}

		~MyStack()//Деструктор
		{
			delete[] Elements;
		}

		void Push(int NewElement)//Добавление элемента в стек
		{
			if (NumberOfElements == MaxSize)
				std::cout << "Стек переполнен!" << std::endl;
			else
			{
				Elements[NumberOfElements] = NewElement;
				NumberOfElements++;
			}
		}

		int Pop()//Удаление элемента стека
		{
			if (IsEmpty())
			{
				std::cout << "Стек Пуст!" << std::endl;
				return 0;
			}
			else
			{
				int LastElement = Elements[NumberOfElements - 1];
				NumberOfElements--;
				int* NewArr = new int[NumberOfElements];
				for (unsigned int i = 0; i < NumberOfElements; i++)
				{
					NewArr[i] = Elements[i];
				}
				delete[] Elements;
				Elements = NewArr;
				return LastElement;
			}
		}

		bool IsEmpty()//Проверка на пустоту
		{
			if (NumberOfElements == 0)
				return true;
			else
				return false;
		}

		int Peek()//Получение верхнего элемента стека без удаления
		{

			if (IsEmpty())
			{
				std::cout << "Стек Пуст!" << std::endl;
				return 0;
			}
			else
			{
				return Elements[NumberOfElements - 1];
			}
		}

		unsigned int GetSize()//Получение размера
		{
			return NumberOfElements;
		}

		void PeekAll()//Вывод всех элементов на консооль
		{
			if (IsEmpty())
				std::cout << "Стек пуст!" << std::endl;
			else
			{
				for (unsigned int i = NumberOfElements; i > 0; i--)
				{
					std::cout << Elements[i - 1] << " ";
				}
				std::cout << std::endl;
			}
		}
	};

	int main()
	{
		setlocale(LC_ALL, "Russian");
		unsigned int StackSize;
		std::cout << "Введите размер стека!" << std::endl;
		std::cin >> StackSize;
		MyStack stack1(StackSize);
		std::cout << "Добавляем элементы в стек" << std::endl;
		int buff;
		for (unsigned int i = 0; i < StackSize; i++)
		{
			std::cin >> buff;
			stack1.Push(buff);
		}
		std::cout << "Весь стек:" << std::endl;
		stack1.PeekAll();
		std::cout << "Размер стека = " << stack1.GetSize() << std::endl;
		std::cout << "Просмотрим последний элемент без удаления" << std::endl;
		std::cout << "Последний элемент = " << stack1.Peek() << std::endl;
		std::cout << "Размер стека не изменился и = " << stack1.GetSize() << std::endl;
		std::cout << "Удалим последний элемент = " << stack1.Pop() << std::endl;
		std::cout << "Весь стек:" << std::endl;
		stack1.PeekAll();
		std::cout << "Размер стека изменился и равен = " << stack1.GetSize() << std::endl;
		std::cout << "Удалим все элементы" << std::endl;
		StackSize = stack1.GetSize();
		for (unsigned int i = 0; i < StackSize; i++)
		{
			stack1.Pop();
		}
		std::cout << "Проверим стек на наличие элементов" << std::endl;
		if (stack1.IsEmpty())
			std::cout << "Стек пуст!" << std::endl;
		char s = _getch();
		return 1;
	}

