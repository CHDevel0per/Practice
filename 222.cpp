#include <iostream>
#include <cstdint>
#include <cstddef>

// Константы
const std::size_t MAX_CARS = 10; // Максимальное количество автомобилей
const std::size_t MAX_BRAND_LENGTH = 20; // Максимальная длина строки марки

// Структура для автомобиля
struct Car {
    char brand[MAX_BRAND_LENGTH];
    uint16_t year;
    uint32_t mileage;
    uint32_t price;
};

// Функция для отображения меню
void displayMenu() {
    std::cout << "\n--- Меню автосалона ---\n";
    std::cout << "1. Добавить автомобиль\n";
    std::cout << "2. Удалить автомобиль\n";
    std::cout << "3. Вывести список всех автомобилей\n";
    std::cout << "4. Найти самый дешевый автомобиль\n";
    std::cout << "5. Найти автомобиль с наименьшим пробегом\n";
    std::cout << "6. Выход\n";
    std::cout << "Ваш выбор: ";
}

// Функция для добавления автомобиля
void addCar(Car cars[], std::size_t &count) {
    if (count >= MAX_CARS) {
        std::cout << "Невозможно добавить больше автомобилей. Массив заполнен.\n";
        return;
    }
    Car newCar;
    std::cout << "Введите марку автомобиля: ";
    std::cin >> newCar.brand;
    std::cout << "Введите год выпуска: ";
    std::cin >> newCar.year;
    std::cout << "Введите пробег: ";
    std::cin >> newCar.mileage;
    std::cout << "Введите цену: ";
    std::cin >> newCar.price;
    cars[count] = newCar;
    ++count;
    std::cout << "Автомобиль успешно добавлен!\n";
}

// Функция для удаления автомобиля
void deleteCar(Car cars[], std::size_t &count, std::size_t index) {
    if (index >= count) {
        std::cout << "Неверный индекс!\n";
        return;
    }
    for (std::size_t i = index; i < count - 1; ++i) {
        cars[i] = cars[i + 1];
    }
    --count;
    std::cout << "Автомобиль удален!\n";
}

// Функция для вывода списка автомобилей
void displayCars(const Car cars[], std::size_t count) {
    if (count == 0) {
        std::cout << "Список автомобилей пуст.\n";
        return;
    }
    for (std::size_t i = 0; i < count; ++i) {
        std::cout << i + 1 << ". Марка: " << cars[i].brand
                  << ", Год: " << cars[i].year
                  << ", Пробег: " << cars[i].mileage << " км"
                  << ", Цена: " << cars[i].price << " руб.\n";
    }
}

// Функция для поиска самого дешевого автомобиля
void findCheapestCar(const Car cars[], std::size_t count) {
    if (count == 0) {
        std::cout << "Список автомобилей пуст.\n";
        return;
    }
    std::size_t cheapestIndex = 0;
    for (std::size_t i = 1; i < count; ++i) {
        if (cars[i].price < cars[cheapestIndex].price) {
            cheapestIndex = i;
        }
    }
    std::cout << "Самый дешевый автомобиль:\n";
    std::cout << "Марка: " << cars[cheapestIndex].brand
              << ", Год: " << cars[cheapestIndex].year
              << ", Пробег: " << cars[cheapestIndex].mileage << " км"
              << ", Цена: " << cars[cheapestIndex].price << " руб.\n";
}

// Функция для поиска автомобиля с наименьшим пробегом
void findLowestMileageCar(const Car cars[], std::size_t count) {
    if (count == 0) {
        std::cout << "Список автомобилей пуст.\n";
        return;
    }
    std::size_t lowestMileageIndex = 0;
    for (std::size_t i = 1; i < count; ++i) {
        if (cars[i].mileage < cars[lowestMileageIndex].mileage) {
            lowestMileageIndex = i;
        }
    }
    std::cout << "Автомобиль с наименьшим пробегом:\n";
    std::cout << "Марка: " << cars[lowestMileageIndex].brand
              << ", Год: " << cars[lowestMileageIndex].year
              << ", Пробег: " << cars[lowestMileageIndex].mileage << " км"
              << ", Цена: " << cars[lowestMileageIndex].price << " руб.\n";
}

// Главная функция


int main() {
    Car cars[MAX_CARS];
    std::size_t carCount = 0;
    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            addCar(cars, carCount);
            break;
        case 2: 
            std::cout << "Введите индекс автомобиля для удаления (начиная с 1) \n";
            std::size_t index;
            std::cin >> index;
            deleteCar(cars, carCount, index - 1);
            break;
        case 3:
            displayCars(cars, carCount);
            break;
        case 4:
            findCheapestCar(cars, carCount);
            break;
        case 5:
            findLowestMileageCar(cars, carCount);
            break;
        case 6:
            std::cout << "Завершение работы! \n";
            break;                                
        default:
            std::cout << "Такого пункта нет! \n";
            break;
        }
    } while (choice != 6);
    
    return 0;
}
