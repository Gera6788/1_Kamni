
#include <iostream>
#include <iomanip>
#include <sstream>
#include <random>
#include <ctime>

int main() {
	int min_kamni = 10;
	int max_kamni = 20;
	int count, a = 1, c = 3, b ;

	std::minstd_rand gen(time(nullptr));
	count = min_kamni + gen() % (max_kamni - min_kamni + 1);
	std::cout << "Начальное количество камней: " << count << std::endl;

	while (count != 0) {
		if (count >= 3) {
			for (int i=1; i<=3; i++)
			if (((count-1)-i)%4==0)
			{a=i; }
			if (count==3)
			{a=2; }
		} else {
			if (count==2)
			{a=1; }
		}
		std::cout << "Компьютер взял камней: " << a << std::endl;
		count = count - a;
		if (count <= 0) {
			goto ex;
		}
		std::cout << "Оставшееся количество камней: " << count << std::endl;
		std::cin >> b;
		if (b >= 4 || b <= 0) {
			std::cout << "Нельзя брать больше 3 камней, укажите количество меньше!" << std::endl;
			while (b >= 4 || b <= 0) {
				std::cin >> b;
			}
			count -= b;
		} else {
			count = count - b;
			if (count <= 0) {
				c = 0;
				goto ex;
			}
		}

	}
	ex:

	if (c == 0)
		std::cout << "Компьютер ПОБЕДИЛ, пользователь ПРОИГРАЛ!" << std::endl;
	else

		std::cout << "Пользователь ПОБЕДИЛ, компьютер ПРОИГРАЛ!" << std::endl;

	return 0;
}
