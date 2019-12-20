#ifndef H_STRIP_CONTROLLER
#define H_STRIP_CONTROLLER 1

#define PIXELS  72

class StripController {
  private:
    Adafruit_NeoPixel* m_Strip = new Adafruit_NeoPixel(PIXELS, D5, NEO_GRB + NEO_KHZ800);

  public:
    int length = PIXELS;
    
    Adafruit_NeoPixel* strip() {
      return this->m_Strip;
    }

    void init() {
      this->m_Strip->begin();
      this->clear();
      this->show();
    }

    void show() {
      this->m_Strip->show();
    }

    void clear() {
      this->m_Strip->clear();
    }
};


#endif
