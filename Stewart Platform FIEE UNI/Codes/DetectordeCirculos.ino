#include "esp_camera.h"
#include "image_util.h" //solo sirve para image_resize_linear
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#define W 104
#define H 64
camera_fb_t *fb = NULL;
uint8_t *gray_buffer, *rgb_buffer, *tmp_buffer, *convolve_buffer;
uint8_t thresh = 0;

void setup() {

}

void loop() {
  fb = esp_camera_fb_get();
  //rgb
  rgb_buffer = (uint8_t *) malloc(fb->width * fb->height * 3);
  fmt2rgb888(fb->buf, fb->len, fb->format, rgb_buffer);
  esp_camera_fb_return(fb);
  //grises
  tmp_buffer = (uint8_t *) malloc(fb->width * fb->height);
  fmt2gray(rgb_buffer, fb->width * fb->height * 3, tmp_buffer);
  free(rgb_buffer);
  gray_buffer = (uint8_t *) malloc(W*H);
  image_resize_linear(gray_buffer, tmp_buffer, W, H, 1, fb->width, fb-> height);
  free(tmp_buffer);
  //bordes
  convolve_buffer = (uint8_t *) malloc(W*H);
  Sobel(gray_buffer, convolve_buffer);
  free(gray_buffer);
  //espera pulso del boton
  if (digitalRead(12) == LOW){//display.clear();display.setFont(ArialMT_Plain_24);display.drawString(0, 0, "Compute...");
    //detección de circulos con hough tranform
    computeHough(convolve_buffer, 1.5, 8, 11); //imagen con los bordes, distancia entre centros, radio minimo a detectar, radio maximo a detectar
    delay(5000);
  }
  else{
    plot_edges(convolve_buffer);
  }
}

void plot_edges (uint8_t *imageIn){}
void computeHough (uint8_t *imageIn, float dist, uint8_t min_r, uint8_t max_r){
  //display.clear();
  uint8_t arr_x[50];
  uint8_t arr_y[50];
  uint16_t indexCircle = 0;
  uint8_t n_Circle = 0;
  for (uint8_t r=min_r; r<max_r; r+=1){
    for (uint8_t y=r; y<H-r; y+=2){
      for (uint8_t x=r; x<W-r; x+=2){
        int acum = 0;
        for (uint16_t i=0; i<360; i+=15){
          float theta = i*PI/180.0;
          uint8_t xc = x + r*cos(theta);
          uint8_t yc = y + r*sin(theta);
          uint32_t pos = yc*W + xc;
          if (imageIn[pos] >= thresh){
            acum++;
          }
        }
        if (acum>14){
          bool newCircle = true;
          if (indexCircle == 0){
            arr_x[indexCircle] = x;
            arr_y[indexCircle] = y;
          }
          else{
            arr_x[indexCircle] = x;
            arr_y[indexCircle] = y;
            for (uint8_t pa=0; pa<indexCircle; pa++){
              int distEuclidian = sqrt(pow(x-arr_x[pa],2)+pow(y-arr_y[pa],2));
              if (distEuclidian < dist*r){
                newCircle = false;
              }
            }
          }
        }
      }
    }
  }
}
void Sobel (uint8_t *imageIn, uint8_t *imageOut){
  int i, grad, deltaX, deltaY;
  thresh = 50;
  for (i=W; i<(H-1)*W; i++){
    deltaX = 2*imageIn[i+1] - 2*imageIn[i-1] + imageIn[i-W+1] + imageIn[i+W+1] - imageIn[i-W-1] - imageIn[i+W-1];
    deltaY = 2*imageIn[i-W] - 2*imageIn[i+W] + imageIn[i-W+1] - imageIn[i+W-1] + imageIn[i-W-1] - imageIn[i+W+1];
    grad = (abs(deltaX) + abs(deltaY))/3;
    if (grad>255) grad = 255;
    imageOut[i] = uint8_t(grad);                                
  }
}
void fmt2gray (uint8_t *imageIn, size_t ImgLen, uint8_t *imageOut){}
bool initCamera (framesize_t frameSize, pixformat_t pixFormat){}