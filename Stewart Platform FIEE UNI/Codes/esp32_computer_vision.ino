#include "esp_camera.h"
#include <HardwareSerial.h>

// Definir constantes para la configuración de la cámara
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

//HardwareSerial SerialPort(2);

void setup() {
  Serial.begin(115200);
  //SerialPort.begin(115200, SERIAL_8N1, 16, 1);
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

void fotito(){  // Acceder a la información de los píxeles
  int dmax=0;
  int dmin=0;
  uint8_t imax=0;
  uint8_t imin=0;
  int dmax2=0;
  int dmin2=0;
  uint8_t imax2=0;
  uint8_t imin2=0;

  camera_fb_t *fb = esp_camera_fb_get(); // Capturar una imagen
  if (!fb) {
    Serial.println("Error capturing image");
    return;
  }
  // for (int i = 0; i < fb->width; i++) {
  //   for (int j = 0; j < fb->height; j++) {
  //     uint8_t pixel_value = fb->buf[i + j * fb->width];
  //       // Realizar alguna operación con el valor del píxel
  //   }
  // }
  for (int i = 0; i< fb->width-1; i++){ //255 blanco, 0 negro
    uint8_t pixelg = fb -> buf[fb->height/2 * fb->width  +  i]; //seleccionamos la fila a la mitad de la cámara
    uint8_t pixelgs = fb -> buf[fb->height/2 * fb->width  +  i + 1]; //siguiente pixel
    if (dmax < pixelgs-pixelg){ //halla el mayor cambio de color a positivo (representaría un cambio de negro a blanco)
      dmax = pixelgs-pixelg;
      imax = i+1;
    }
    if (dmin > pixelgs-pixelg){ //halla el mayor cambio de color a negativo (de blanco a negro)
      dmin = pixelgs-pixelg;
      imin = i+1;
    }
  }
  for (int j = 0; j< fb->width-1; j++){
    uint8_t pixelg = fb -> buf[fb->height/2 * fb->width  +  j];
    uint8_t pixelgs = fb -> buf[fb->height/2 * fb->width  +  j + 1];
    if (dmax2 < pixelgs-pixelg && dmax2<dmax){ //halla el segundo mayor cambio a postivo, tal vez debería ser <=
      dmax2 = pixelgs-pixelg;
      imax2 = j+1;
    }
    if (dmin2 > pixelgs-pixelg && dmin2>dmin){ //halla el segundo mayor cambio a negativo
      dmin2 = pixelgs-pixelg;
      imin2 = j+1;
    }
  }

  // if ( (imax2+imax) < fb->width){ //está el punto medio entre las 2 líneas al medio?
  //   Serial.println("Gira hacia la izquierda"); //depende de la orientación de la cámara
  // }
  // if ( (imax2+imax) > fb->width){
  //   Serial.println("Gira hacia la derecha");
  // }

  esp_camera_fb_return(fb); // Liberar la memoria de la imagen
  static uint16_t a[4];
  static String b[4];
  a[0] = imin;
  a[1] = imax;
  a[2] = imin2;
  a[3] = imax2;

  // for (int k=0; k<4; k++){
  //   if(a[k]<10) b[k]=String('0')+String('0')+String(a[k]);
  //   else if (a[k]<100)  b[k]=String('0')+String(a[k]);
  //   else b[k]=String(a[k]);
  // }

  // Serial.print(b[0]);
  // Serial.print(b[1]);
  // Serial.print(b[2]);
  // Serial.print(b[3]);
  //Serial.print("a");
  //Serial.write(imin);
  // byte a1 = B10100000;
  // byte b2 = B10100010;
  // byte c3 = B10100001;
  // byte d4 = B10101000;
  //Serial.write(a1);
  // delay(10);
  // //Serial.write(imax);
  // Serial.write(b2);
  // delay(10);
  // //Serial.write(imin2);
  // Serial.write(c3);
  // delay(10);
  // //Serial.write(imax2);
  // Serial.write(d4);
  //Serial.println("");
  // Serial.println("1");
  // Serial.println("2");
  // Serial.println("3");
  Serial.println("4");
  //Serial.write(15);
}

void loop() {
  fotito();
  delay(100); //espera 0.05 segundos hasta tomar otra foto, hay que probar hasta donde aguanta.
}