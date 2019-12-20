#ifndef H_SCEPTER_ANIMATIONS
#define H_SCEPTER_ANIMATIONS 1

class PulseAnimation {
  private:
    int m_Brightness = 10;
    int m_Increment = 1;
    long m_LastUpdate = 0;
    Adafruit_NeoPixel* m_Strip;

    void flipIncrement() {
      this->m_Increment *= -1;
    }
  public:
    PulseAnimation(Adafruit_NeoPixel* strip) {
      this->reset(); 
      this->m_Strip = m_Strip;
    }
    
    void reset() {
      this->m_Brightness = 10;
      this->m_Increment = 1;
      this->m_LastUpdate = 0;
    }

    void update(int time) {
      if(time - this->m_LastUpdate > 10) { // run every 10 ms
        this->m_Brightness += this->m_Increment;
        if(this->m_Brightness == 10 || this->m_Brightness == 200) this->flipIncrement();

        this->m_Strip->setBrightness(this->m_Brightness);
        
        this->m_LastUpdate = time; 
      }
    }
};

#endif
