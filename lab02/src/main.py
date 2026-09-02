import time

def calculate(x):
    return x**2 - x**2 + x * 4 - x * 5 + x + x

def main():
    while True:
        try:
            n = int(input("Введите количество итераций (или букву для выхода): "))
        except ValueError:
            print("Введено не число. Завершение программы.")
            break

        if n <= 0:
            print("Введите положительное число!")
            continue

        start = time.perf_counter()

        result = 0
        for _ in range(n):
            result = calculate(2.0)

        end = time.perf_counter()
        duration_ms = (end - start) * 1000

        print(f"Выполнено итераций: {n}")
        print(f"Время выполнения: {duration_ms:.2f} мс")
        print("-" * 40)

if __name__ == "__main__":
    main()
