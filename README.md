# Лабораторная работа 15–16

**Контрольная точка 6.**  
Работа с библиотеками для матричных и векторных вычислений.  
Инструменты для производительности и оптимизации кода на C++.

---

## Структура репозитория

```
lab15-16/
├── CMakeLists.txt
├── task1_stl/
│   └── main.cpp                       # Задание 1: STL
├── task2_eigen/
│   ├── task2_1_matrix_multiply.cpp    # 2.1 Умножение матриц 500×500
│   ├── task2_2_solve_ax_b.cpp         # 2.2 Решение Ax = B
│   ├── task2_3_vectors.cpp            # 2.3 Скалярное произведение, норма
│   ├── task2_4_norm.cpp               # 2.4 Норма вектора и матрицы
│   ├── task2_5_transpose.cpp          # 2.5 Транспонирование
│   └── task2_6_inverse.cpp            # 2.6 Обратная матрица
└── task3_opencv/
    └── main.cpp                       # Задание 3: OpenCV
```

---

## Зависимости

| Библиотека | Версия | Установка (Ubuntu/Debian) |
|---|---|---|
| Eigen3 | ≥ 3.3 | `sudo apt install libeigen3-dev` |
| OpenCV | ≥ 4.0 | `sudo apt install libopencv-dev` |
| CMake  | ≥ 3.16 | `sudo apt install cmake` |
| GCC    | ≥ 9 (C++17) | `sudo apt install g++` |

**Windows (Visual Studio + vcpkg):**
```powershell
vcpkg install eigen3 opencv4
```
Добавить в VS: `Свойства проекта → VC++ Directories → Include/Library Directories`.

---

## Сборка через CMake

```bash
git clone <repo-url> && cd lab15-16
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

---

## Сборка вручную (g++)

```bash
# Задание 1
g++ -std=c++17 -O2 task1_stl/main.cpp -o task1

# Задание 2.x (замените <N> на 1–6)
g++ -std=c++17 -O2 -I/usr/include/eigen3 task2_eigen/task2_<N>_*.cpp -o task2_<N>

# Задание 3
g++ -std=c++17 task3_opencv/main.cpp $(pkg-config --cflags --libs opencv4) -o task3
```

---

## Запуск

```bash
./task1
./task2_1_matrix_multiply
./task2_2_solve_ax_b
./task2_3_vectors
./task2_4_norm
./task2_5_transpose
./task2_6_inverse

# Задание 3: передать путь к изображению
./task3_opencv path/to/image.jpg
```

---

## Краткое описание задач

### Задание 1 — STL

| Функция | Реализация |
|---|---|
| `sortVector` | `std::sort` |
| `reverseVector` | `std::reverse` |
| `sum` | `std::accumulate` |
| `findFrequency` | `std::count` |

### Задание 2 — Eigen

| Файл | Описание |
|---|---|
| `task2_1` | Умножение матриц 500×500: Eigen vs тройной цикл; замер времени через `chrono` |
| `task2_2` | Решение `Ax = B` через `colPivHouseholderQr().solve()` и LU |
| `task2_3` | Скалярное произведение (`dot`), евклидова норма (`norm`) vs ручной цикл |
| `task2_4` | Евклидова норма вектора и норма Фробениуса матрицы |
| `task2_5` | Транспонирование (`transpose()`, `transposeInPlace()`) |
| `task2_6` | Обратная матрица (`inverse()`), верификация `A * A⁻¹ = I` |

### Задание 3 — OpenCV

Загрузка изображения → перевод в градации серого (`cvtColor`) → гауссово размытие (`GaussianBlur 5×5`) → отображение в окне и сохранение `output_gray.jpg`, `output_blurred.jpg`.

---

## Замечания по измерению времени

Все замеры выполнены через `std::chrono::high_resolution_clock`. Для корректного сравнения компилировать с `-O2`. Для профилировки памяти использовать Visual Studio: `Отладка → Профилировщик производительности → Использование памяти`.

