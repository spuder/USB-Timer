# USB-Timer

Control 4 USB ports with a microcontroller

![](https://imgur.com/A2CsYek.png)
![](https://imgur.com/ROunWd5.png)

![](https://imgur.com/yNPN8Ie.png)
![](https://i.imgur.com/fN3Y8YD.png)
![](https://imgur.com/tp0hgIG.png)


Buy your own:   
<a href="https://www.tindie.com/stores/spuder/?ref=offsite_badges&utm_source=sellers_spuder&utm_medium=badges&utm_campaign=badge_medium"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a>
## Hardware

USB-Timer is based on a Wemos D1 Mini. It uses 4 N Channel Mosfets to control multiple USB ports

| **Microcontroller**: | Count | 
| --- | --- |
| [Wemos D1 Mini](https://www.amazon.com/MakerFocus-NodeMcu-Development-ESP8266-Compatible/dp/B07KW54YSK) | 1x | 


| **Mosfets**: | Type | Count | 
| --- | --- | --- | 
| [IRLZ34N N Channel Mosfet ](https://www.amazon.com/BOJACK-IRLZ34N-IRLZ34NPBF-N-Channel-transistors/dp/B08L8S3154) |Through Hole| 4x|
| [NTR4501NT1G N Channel Mosfet](https://www.mouser.com/ProductDetail/863-NTR4501NT1G) |SMD | 4x |

Use either through hole _or_ SMD mosfet, not both!
*Any TTL N Channel Mosfet should work as long as it has a VGO < 3.3. volts*


| **Resitors**  | Count | 
| ---  | --- | 
| [10K - 1/4 watt](https://www.mouser.com/ProductDetail/Vishay-Beyschlag/MBA02040C1002FC100?qs=nlQjf3QnJCoHnMMMaOw%2FFA%3D%3D) | 8x | 

| **USB** | Website | Count |
| --- | --- | --- |
| [USB Type A Connector](https://www.amazon.com/gp/product/B00H51E7B0/ref=ewc_pr_img_3?smid=ATVPDKIKX0DER&psc=1) | Amazon | 4x | 
| [USB mini](https://www.mouser.com/ProductDetail/798-ZX62D-B-5PA830) | Mouser | 1x | 
| [USB Mini Easy Solder](https://www.amazon.com/Micro-Interface-Adapter-Breakout-Module/dp/B07B5ZDLJY/ref=sr_1_5?crid=1STON25BNGX2E&keywords=micro+usb+header&qid=1658890928&sprefix=micro+usb+header%2Caps%2C181&sr=8-5) | Amazon | 1x | 


| **Buttons (optional)** | Website | Count | 
| --- | --- | --- |
| [8mm metal buttons](https://www.aliexpress.com/item/3256801677651364.html?spm=a2g0o.productlist.0.0.169c62f1N2n2FT&algo_pvid=c18aeb60-fc17-4477-b9e9-b930d34a5b91&algo_exp_id=c18aeb60-fc17-4477-b9e9-b930d34a5b91-5&pdp_ext_f=%7B%22sku_id%22%3A%2212000017904710697%22%7D&pdp_npi=2%40dis%21USD%210.91%210.68%21%21%21%21%21%402101d8b516622380113308192e6a4d%2112000017904710697%21sea&curPageLogUid=412udmnHGEBC) | Aliexpress | 4
| [Rubber Feet](https://www.amazon.com/gp/product/B07G86DL1L/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1) | Amazon | 100| 

See [PCB/BOM](./PCB/BOM) for full Bill of Materials

### Schematic

![](https://imgur.com/e69g4XU.png)

![](https://imgur.com/ZkSwsCX.png)


Board was designed with [Easy EDA](https://easyeda.com/)

View project on [OSHWLab.com/owenspencer/USB-Timer](https://oshwlab.com/owenspencer/USB-Timer)

![](https://i.imgur.com/y102LIr.png)

![](https://i.imgur.com/PML6dVw.png)

### Building

Order the PCB from your favorite PCB Manufacture. Cost of boards will be about $27 for 5

Popular Choices: 
- [OshPark](https://oshpark.com/)
- [JLCPCB](https://jlcpcb.com/)
- [PCBWay](https://www.pcbway.com/)


The board can be built with either surface mount or through hole components (but not both). 

For the micro USB ports, you can solder the ports directly (if you are skilled), or you can use [these through hole kits](https://www.amazon.com/gp/product/B07KS1RPMP/ref=ewc_pr_img_2?smid=AB5D7200EYCEL&psc=1)

![](https://m.media-amazon.com/images/I/512k+5LeVmL._AC_SX679_.jpg)


### PinOut

```sh
USB 1 => D8 
USB 2 => D7
USB 3 => D6
USB 4 => D5
Button 1 => D1 and GND (PullUp)
Button 2 => D2 and GND (PullUp)
Button 3 => D3 and GND (PullUp)
Button 4 => D0 and 3.3v (PullDown)
```
![](https://imgur.com/kfg2NW0.png)

Once the board is built, see the [Firmware/arduino/blink/README.md](Firmware/arduino/blink/README.md]) for a sketch to blink the leds. Or get started with ESPHome configuration. 


[Setup D1 Mini with arduino](https://www.instructables.com/Programming-the-WeMos-Using-Arduino-SoftwareIDE/)  


## Configuration

Configuration can be done in one of several ways

1. ESPHome / ESPHome + Home Assistant (recomended)
2. Arudino programming (advanced)
3. Mobile app (advanced/ work in progress)

![](https://imgur.com/lSZCWdr.png)

### Config[ESPHome]

#### Home Assistant

Setting up with HomeAssistant is easy, just install the esphome extension, then click 'add device'. 

See [./Firmware/esphome](./Firmware/esphome/) directory for example configurations

Most of the configuration is abstracted away so you don't need to worry about it. 

Just add an 'include' into your esphome config that references this git repo and esphome should set everything up automatically including your timezone.

```yaml
dashboard_import:
  package_import_url: github://spuder/usb-timer/esphome/common.yaml@main
```

Copy the api key from the HA gui and then go to 'Settings' -> 'Integrations' and you should see a new device named usb-timer1 (or whatever you named it). Paste in your api key and everything should work. 

---

#### ESPHome Stand Alone (non home assistant)

A `Makefile` is provided that will generate `firmware.bin` file which you can manually upload to your USB-Timer. 

Make sure you have `esphome` installed. OSX Users with homebrew can run `brew install esphome`. 

```bash
make clean
make build
```

This will generate 2 firmware files in the root directory

```bash
firmware.bin
firmware.elf
```

Use a tool like [esphome/esphome-flasher](https://github.com/esphome/esphome-flasher) to upload the .bin to the wemos d1 mini

If you didn't specify a wireless network, the wemos will boot up into AP mode. Join the network named 'USB-Timer Fallback Hotspot' with password `12345678`. 

A captive portal will popup which will allow you to reconfigure the device to your wifi network. 

![](https://imgur.com/fE1KLrj.png)


### Config[Firmware/arduino]


Code examples located in the arduino folder

- [Firmware/arduino](./Firmware/arduino)  
- [Firmware/arduino/blink/README.md](arduino/blink/README.md])  
- [Firmware/arduino/wifi_manager/README.md](arduino/wifi_manager/README.md])  



## Case

STL files for a 3d printable case are located in the [CAD](./CAD/) folder

![](https://media.giphy.com/media/WjviqmvAURGXarPrWy/giphy.gif)


## License

This is released under the [GNU license](https://choosealicense.com/licenses/gpl-3.0/). 
You may modify and even sell comercial products, as long as it remains open source (closed source derivitives are prohibited). 
