#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    cv::Mat image = cv::imread("lena.jpg");
    if (image.empty()) {
        cerr << "Ошибка: не удалось загрузить изображение." << endl;
        return -1;
    }

    // Создаём окна для отображения
    cv::namedWindow("Исходное изображение",    cv::WINDOW_NORMAL);
    cv::namedWindow("Обработанное изображение", cv::WINDOW_NORMAL);

    // Конвертируем в оттенки серого
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Применяем размытие по Гауссу
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(5, 5), 0);

    // Отображаем результаты
    cv::imshow("Исходное изображение",    image);
    cv::imshow("Обработанное изображение", blurredImage);

    // Ждём нажатия клавиши
    cv::waitKey(0);

    return 0;
}
