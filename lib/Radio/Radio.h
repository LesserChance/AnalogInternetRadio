#ifndef Radio_H
#define Radio_H

#include "Arduino.h"
#include "Audio.h"
#include "SPIFFS.h"
#include "WiFi.h"

// CONFIGURATION OPTIONS
#define MAX98357A_I2S_DOUT 25
#define MAX98357A_I2S_BCLK 27
#define MAX98357A_I2S_LRC 26
// how many stations are in each frequency band
#define STATIONS 15

#define BAND_FM 0
#define BAND_AM 1

class Radio {
   public:
    Radio();
    void setup();
    void loop();
    void initSPIFFS();

    void setStaticAmt(int _staticAmt);
    void setBand(int _band);
    void setStation(int _station);
    std::string getStationName();
    void setPower(bool _power);

   private:
    bool power = false;
    int staticAmt = 0;
    int band = 0;
    int station = 0;
    std::string stationName = "";

    void connectToStation();

    std::string fmStations[STATIONS][2] = {
        {"http://wwoz-sc.streamguys1.com/wwoz-hi.mp3", "WWOZ"},
        {"http://kexp-mp3-128.streamguys1.com/kexp128.mp3", "KEXP"},
        {"http://current.stream.publicradio.org/kcmp.mp3", "KCMP"},
        {"http://fm939.wnyc.org/wnycfm-web?browser_id=39d5eba987fc0f5a",
         "WNYC"},
        {"http://15093.live.streamtheworld.com/WNPRFM.mp3", "WNPR"},
        {"http://audio.wgbh.org:8000/", "WGBH"},
        {"http://q2stream.wqxr.org/q2", "WQXR"},
        {"http://wbgo.streamguys.net/wbgo128", "WBGO"},
        {"http://14833.live.streamtheworld.com:3690/WNYLFMAAC_SC", "WNYL"},
        {"http://14223.live.streamtheworld.com:3690/WNEWFM_SC", "WHEW"},
        {"http://50.31.186.115/kqedradio.mp3", "KQED"},
        {"http://peridot.streamguys.com:5350/iheartjazz", "WFDU"},
        {"http://wwfm.streamguys1.com/live", "WWFM"},
        {"http://17443.live.streamtheworld.com/WQHTAAC_SC", "WQHT"},
        {"http://rawlco.leanstream.co/CFMCFM?args=tunein_02", "CFMC"},
    };
    std::string amStations[STATIONS][2] = {
        {"http://bbcmedia.ic.llnwd.net/stream/bbcmedia_radio1_mf_p", "BBC1"},
        {"http://bbcmedia.ic.llnwd.net/stream/bbcmedia_radio2_mf_p ", "BBC2"},
        {"http://bbcmedia.ic.llnwd.net/stream/bbcmedia_radio3_mf_p", "BBC3"},
        {"http://bbcmedia.ic.llnwd.net/stream/bbcmedia_radio4fm_mf_p", "BBC4"},
        {"http://bbcmedia.ic.llnwd.net/stream/bbcmedia_radio5live_mf_p",
         "BBC5"},
        {"http://whatradio.macchiatomedia.org:9119/", "WHAT"},
        {"http://181fm-edge1.cdnstream.com/181-breeze_128k.mp3", "Bree"},
        {"http://radiolatina.info:7087/", "123V"},
        {"http://listen.radioking.com/radio/8916/stream/19088", "92.6"},
        {"http://178.33.53.51:8052/;", "Slas"}};
};

#endif