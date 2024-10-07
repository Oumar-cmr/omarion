def calculate_tax():
    # 1. Тип покрытия
    print("Выберите тип покрытия земельного участка:")
    print("1 - Крыша (5000 руб/м²)")
    print("2 - Без крыши (3000 руб/м²)")
    print("3 - Сад (1000 руб/м²)")
    
    coverage_type = int(input("Введите номер покрытия: "))
    
    if coverage_type == 1:
        base_rate = 5000
    elif coverage_type == 2:
        base_rate = 3000
    elif coverage_type == 3:
        base_rate = 1000
    else:
        print("Некорректный выбор типа покрытия.")
        return

    area = float(input("Введите площадь участка (в квадратных метрах): "))

    # 2. Тип материала
    print("\nВыберите тип материала:")
    print("1 - Высококачественный материал (добавляет 15%)")
    print("2 - Саман (добавляет 10%)")
    print("3 - Другой материал (добавляет 5%)")
    
    material_type = int(input("Введите номер типа материала: "))

    if material_type == 1:
        material_increase = 0.15
    elif material_type == 2:
        material_increase = 0.10
    elif material_type == 3:
        material_increase = 0.05
    else:
        print("Некорректный выбор типа материала.")
        return

    # 3. Наличие базовых услуг
    print("\nЕсть ли на участке вода и канализация?")
    print("1 - Да")
    print("2 - Нет")

    utilities = int(input("Введите номер ответа: "))

    if utilities == 1:
        utilities_increase = 2500
    elif utilities == 2:
        utilities_increase = 0
    else:
        print("Некорректный выбор наличия услуг.")
        return

    # 4. Этажность здания
    print("\nВыберите этажность здания:")
    print("1 - 1 этаж")
    print("2 - 2 этажа (добавляет 10%)")
    print("3 - 3 этажа (добавляет 15%)")
    print("4 - 4 этажа (добавляет 15%)")
    print("5 - Более 4 этажей (добавляет 20%)")

    floors = int(input("Введите номер этажа: "))

    if floors == 1:
        floor_increase = 0
    elif floors == 2:
        floor_increase = 0.10
    elif floors == 3:
        floor_increase = 0.15
    elif floors == 4:
        floor_increase = 0.15
    elif floors == 5:
        floor_increase = 0.20
    else:
        print("Некорректный выбор этажности.")
        return

    # Расчет базовой стоимости
    base_tax = base_rate * area

    # Применение увеличений
    tax_with_material = base_tax * (1 + material_increase)
    tax_with_utilities = tax_with_material + utilities_increase
    final_tax = tax_with_utilities * (1 + floor_increase)

    # Вывод результата
    print(f"\nОбщая сумма налога на имущество: {final_tax:.2f} тысяч рублей")


# Запуск программы
calculate_tax()
