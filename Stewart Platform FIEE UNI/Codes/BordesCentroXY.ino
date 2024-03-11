#include "esp_camera.h"
#include "image_util.h" //solo sirve para image_resize_linear
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#define W 104
#define H 64
camera_fb_t *fb = NULL;
uint8_t *gray_buffer, *rgb_buffer, *tmp_buffer, *convolve_buffer;
uint8_t thresh = 0;

#define CAMERA_MODEL_AI_THINKER
#define PWDN_GPIO_NUM    32 //-1
#define RESET_GPIO_NUM   -1
#define XCLK_GPIO_NUM    0  //21
#define SIOD_GPIO_NUM    26
#define SIOC_GPIO_NUM    27
#define Y9_GPIO_NUM      35
#define Y8_GPIO_NUM      34
#define Y7_GPIO_NUM      39
#define Y6_GPIO_NUM      36
#define Y5_GPIO_NUM      21  //19
#define Y4_GPIO_NUM      19  //18
#define Y3_GPIO_NUM      18  //5
#define Y2_GPIO_NUM       5  //4
#define VSYNC_GPIO_NUM   25
#define HREF_GPIO_NUM    23
#define PCLK_GPIO_NUM    22
// Inicializar la cámara
camera_config_t config;

void setup() {
  Serial.begin(115200);

  // Inicializar la cámara
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_GRAYSCALE;
  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 10;
  config.fb_count = 1;

  // Inicializar la cámara
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Error initializing camera: %d\n", err);
    return;
  }
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
  //creo que este código es general para cualquier tipo de image por eso usa fb->format y aquí lo pasa a gris, podría solo usar el gris que ya se obtiene de la cámara de frente
  gray_buffer = (uint8_t *) malloc(W*H);
  image_resize_linear(gray_buffer, tmp_buffer, W, H, 1, fb->width, fb-> height);
  free(tmp_buffer);
  //bordes
  convolve_buffer = (uint8_t *) malloc(W*H);
  Sobel(gray_buffer, convolve_buffer);
  free(gray_buffer);

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
void fmt2gray (uint8_t *imageIn, size_t ImgLen, uint8_t *imageOut){
  for (size_t i = 0; i < ImgLen; i += 3) {// Iterar sobre cada píxel en la imagen de entrada
    uint8_t r = imageIn[i];// Obtener los componentes de color RGB
    uint8_t g = imageIn[i + 1];
    uint8_t b = imageIn[i + 2];
    // Calcular el valor de luminancia (escala de grises). Fórmula de luminancia: Y = 0.299*R + 0.587*G + 0.114*B. Para simplificar, usaremos la aproximación: Y = (R + G + B) / 3
    uint8_t gray = (0.299*r + 0.587*g + 0.114*b) / 3;
    imageOut[i/3] = gray;
  }
}