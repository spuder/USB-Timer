# USB-Timer

Control 4 USB ports with a microcontroller

![](https://i.imgur.com/fN3Y8YD.png)


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

See [./BOM](./BOM) for full Bill of Materials

### Schematic

![](https://imgur.com/FSzB65R.png)

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


Once the board is built, see the [arduino/blink/README.md](arduino/blink/README.md]) for a sketch to blink the leds. Or get started with ESPHome configuration. 


[Setup D1 Mini with arduino](https://www.instructables.com/Programming-the-WeMos-Using-Arduino-SoftwareIDE/)  


## Configuration

Configuration can be done in one of several ways

1. ESPHome / ESPHome + Home Assistant (recomended)
2. Arudino programming (advanced)
3. Mobile app (advanced/ work in progress)

### Config[ESPHome]

See [./esphome](./esphome/) directory for example configurations

- esphome/home-assistant.yaml (recomended for home assistant users)
- esphome/stand-alone.yaml (recomended for users familiar with esphome and not using home assistant)

### Config[Arduino]


Code examples located in the arduino folder

- [./arduino](./arduino)  
- [arduino/blink/README.md](arduino/blink/README.md])  
- [arduino/wifi_manager/README.md](arduino/wifi_manager/README.md])  



## Case

STL files for a 3d printable case are located in the [CAD](./CAD/) folder

![](https://media.giphy.com/media/WjviqmvAURGXarPrWy/giphy.gif)

## Resources

- Add USB C to your usb 2.0 projects https://idyl.io/how-to-add-usb-type-c-micro-usb-replacement/

- [Alternative USB Micro Kit](https://www.amazon.com/Teansic-24Models-Connector-Connectors-Samsung/dp/B089Q99ZHS/ref=rvi_sccl_9/143-4724926-0549058?pd_rd_w=4MUv2&content-id=amzn1.sym.f5690a4d-f2bb-45d9-9d1b-736fee412437&pf_rd_p=f5690a4d-f2bb-45d9-9d1b-736fee412437&pf_rd_r=SZ5G8YWDVHCMYY0A08T3&pd_rd_wg=fNmXg&pd_rd_r=b785f370-4089-4836-be14-47600cf287e0&pd_rd_i=B089Q99ZHS&psc=1)


## License

This is released under the [GNU license](https://choosealicense.com/licenses/gpl-3.0/). 
You may modify and even sell comercial products, as long as it remains open source (closed source derivitives are prohibited). 
