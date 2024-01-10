
#include <opencv2/opencv.hpp>
#include <iostream>

void demonstrate(const cv::Mat& original, const cv::Mat& blur, const cv::Mat& result) {

    // Отображение исходного изображения
    cv::imshow("Original Image", original);
    cv::waitKey(0);

    // Отображение размытого изображения
    cv::imshow("Blur", blur);
    cv::waitKey(0);

    // Отображение результата
    cv::imshow("Contour Detection", result);
    cv::waitKey(0);
}

void visualize(const cv::Mat& image, const std::string& windowName) {

    std::cout << "Visualizing image in window: " << windowName << std::endl;
}


int main(int argc, char *argv[]) {


    if (argc != 5) {
        std::cerr << "Необходимо ввести путь к изображению, размер ядра для медианного размытия, размер ядра для размытия Гаусса и пороговое значение Canny." << std::endl;
        return -1;
    }

    // Загрузка изображения
    cv::Mat image = cv::imread(argv[1]);

    if (image.empty()) {
        std::cerr << "Не удалось открыть изображение" << std::endl;
        return -1;
    }

    int kernelSize, medianSize, cannyThreshold;

    try {

         kernelSize = std::stoi(argv[2]);
         medianSize = std::stoi(argv[3]);
         cannyThreshold = std::stoi(argv[4]);

         if(medianSize %2 == 0){
             std::cerr << "Ошибка: Размер ядра для медианного размытия должен быть нечетным." << std::endl;
             return -1;
         }

    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: Некорректное значение аргумента. " << e.what() << std::endl;
        return -1;

    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: Значение аргумента вне допустимого диапазона. " << e.what() << std::endl;
        return -1;
    }

    // Применение медианного размытия для размытия фона
    cv::Mat blurImage;
    cv::medianBlur(image, blurImage, medianSize);


    // Преобразование изображения в оттенки серого
    cv::Mat grayImage;
    cv::cvtColor(blurImage, grayImage, cv::COLOR_BGR2GRAY);


    // Применение размытия Гаусса для уменьшения шума и улучшения выделения контуров
    cv::GaussianBlur(blurImage, grayImage, cv::Size(kernelSize, kernelSize), 0);


    // Пороговая обработка для выделения границ
    cv::Mat edges;
    cv::Canny(grayImage, edges, cannyThreshold, cannyThreshold * 2);


    // Поиск контуров в бинарном изображении
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);


    // Отрисовка контуров на исходном изображении
    cv::Mat result = image.clone();
    cv::drawContours(result, contours, -1, cv::Scalar(0, 255, 0), 1);


    // Отображение результатов
    demonstrate(image, blurImage, result);


    // Визуализация отдельных этапов программы
    visualize(image, "Original Image");
    visualize(blurImage, "Blur");
    visualize(result, "Contour Detection");

    return 0;

}










/*#include <opencv2/opencv.hpp>

void demonstrate(cv::Mat& original, cv::Mat& blur, cv::Mat& result) {
    // Отображение исходного изображения
    cv::imshow("Original Image", original);
    cv::waitKey(0);

    // Отображение размытого изображения
    cv::imshow("Blur Image", blur);
    cv::waitKey(0);

    // Отображение результата
    cv::imshow("Contour Detection", result);
    cv::waitKey(0);
}

void visualize(cv::Mat& image, const std::string& windowName) {
    cv::imshow(windowName, image);
    cv::waitKey(0);
}

int main() {
    // Загрузка изображения
    cv::Mat image = cv::imread("/Users/egor/Documents/GitHub/misis2023f-22-03-bobkov-e-e/prj.cw/volo.jpg");

    if (image.empty()) {
        std::cout << "Не удалось открыть изображение" << std::endl;
        return -1;
    }

    // Применение медианного размытия для размытия фона
    cv::Mat blurImage;
    cv::medianBlur(image, blurImage, 9);

    // Преобразование изображения в оттенки серого
    cv::Mat grayImage;
    cv::cvtColor(blurImage, grayImage, cv::COLOR_BGR2GRAY);

    // Применение размытия Гаусса для уменьшения шума и улучшения выделения контуров
    cv::GaussianBlur(blurImage, grayImage, cv::Size(5, 5), 0);

    // Пороговая обработка для выделения границ
    cv::Mat edges;
    cv::Canny(grayImage, edges, 90, 180);

    // Поиск контуров в бинарном изображении
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Отрисовка контуров на исходном изображении
    cv::Mat result = image.clone();
    cv::drawContours(result, contours, -1, cv::Scalar(0, 255, 0), 1);

    // Демонстрация результатов
    demonstrate(image, blurImage, result);

    // Визуализация отдельных этапов программы
    visualize(image, "Original Image");
    visualize(grayImage, "Blur Image");
    visualize(result, "Contour Detection");

    return 0;
}*/




//                                  Мой код!!!!!!!
/*

#include <opencv2/opencv.hpp>

int main () {
    // загрузка изображения
    cv::Mat image = cv::imread ("/Users/egor/Documents/GitHub/misis2023f-22-03-bobkov-e-e/prj.cw/volo.jpg");

    // проверка на загрузку
    if ( image.empty()) {
        std::cout<< "Не удалось загрузить изображение" << std::endl;
        return -1;
    }
// серая картинка
    cv::Mat grayimage;
    cv::cvtColor(image, grayimage, cv::COLOR_BGR2GRAY);

// фильтр Гаусса
    cv::GaussianBlur( grayimage, grayimage, cv::Size (5,5), 1.5,1.5);


// медианная фильтрация
    cv::Mat blurimage;
    cv::medianBlur(grayimage,blurimage,9);

 //



// вывод изображения
    cv::imshow("processed Image", grayimage);
    cv::imshow("Blur image", blurimage);
    cv::waitKey(0);

    return 0;

}

*/




















/*
#include <opencv2/opencv.hpp>

 int main() {
     // Загрузка изображения
     cv::Mat image = cv::imread("/Users/egor/Documents/GitHub/misis2023f-22-03-bobkov-e-e/prj.cw/volo.jpg");

     if (image.empty()) {
         std::cout << "Не удалось открыть изображение" << std::endl;
         return -1;
     }

     // Применение медианного размытия для размытия фона
     cv::Mat blurImage;
     cv::medianBlur(image, blurImage, 9);

     // Преобразование изображения в оттенки серого
     cv::Mat grayImage;
     cv::cvtColor(blurImage, grayImage, cv::COLOR_BGR2GRAY);

     // Применение размытия Гаусса для уменьшения шума и улучшения выделения контуров
     cv::GaussianBlur(grayImage, grayImage, cv::Size(5, 5), 0);

     // Пороговая обработка для выделения границ
     cv::Mat edges;
     cv::Canny(grayImage, edges, 90, 180);

     // Поиск контуров в бинарном изображении
     std::vector<std::vector<cv::Point>> contours;
     cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

     // Отрисовка контуров на исходном изображении
     cv::Mat result = image.clone();
     cv::drawContours(result, contours, -1, cv::Scalar(0, 255, 0), 1);

     // Отображение результатов
     cv::imshow("the original image", image);
     cv::imshow("blur", blurImage);
     cv::imshow("pore allocation", result);
     cv::waitKey(0);

     return 0;
 }*/














