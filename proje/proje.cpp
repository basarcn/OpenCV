#include <opencv2/opencv.hpp>          // OpenCV'nin temel fonksiyonları
#include <opencv2/highgui.hpp>        // Görüntü gösterimi için gerekli fonksiyonlar
#include <opencv2/imgproc.hpp>        // Görüntü işleme işlevleri
#include <opencv2/core.hpp>           // Temel veri yapılarını içerir
#include <opencv2/imgcodecs.hpp>      // Görüntü dosyalarını yükleme/kaydetme

using namespace std;
using namespace cv;
void resimkopyala(Mat resim, Mat& kopyaresim) {
    kopyaresim = Mat(resim.cols, resim.rows, CV_8UC3);
    uchar m, ye, k;
    namedWindow("kopyalama süreci", WINDOW_NORMAL);
    for (int x = 0; x < kopyaresim.cols; x++) {
        for (int y = 0; y < kopyaresim.rows; y++) {
            m = resim.at<Vec3b>(Point(x, y))[0];
            ye = resim.at<Vec3b>(Point(x, y))[1];
            k = resim.at<Vec3b>(Point(x, y))[2];
            kopyaresim.at<Vec3b>(Point(x, y))[0] = m;
            kopyaresim.at<Vec3b>(Point(x, y))[1] = ye;
            kopyaresim.at<Vec3b>(Point(x, y))[2] = k;

            imshow("kopyalama süreci", kopyaresim);
            waitKey(1);




        }
    }
    cout << "islem tamamladı" << endl;
}

int main() {
    string dosya_yolu = "C:/deneme/test1.jpg";
    Mat resim = imread(dosya_yolu);
    Mat kopyaresim;

    resimkopyala(resim, kopyaresim);
    imshow("pencere1", kopyaresim);
    waitKey();



    return 0;
}
