# Greenhouse

My Mother grows her own food as a hobby and is very passionate about it. I usually benefit a lot from this hobby since as a vegetarian I get basically all my food from my mother&#39;s garden during the summer months. On top of that, organic home-grown food is not only much richer in nutrients and free of pesticides, it also tastes a lot better in my experience. Since I will be moving out and will no longer be able to help water the plants, I decided to use my engineering skills to build her an automated gardening system which takes care of her greenhouse and the three 5 m² raised bed fields.

# User Requirements

After talking to my mother about her needs with the system, I came up with the following user requirements.

| **ID** | **Description** |
| --- | --- |
| UREQ-001 | Must Deliver water to 4 separate fields with an average of 20L per day on a dry, sunny day and 0-5L on a cloudy or rainy day |
| UREQ-002 | Could keep the soil at a configured moisture level between 0-100% |
| UREQ-003 | Must ventilate when the temperature in the green house reaches a user set temperature |
| UREQ-004 | Must heat actively when the temperature in the green house drops below a user set temperature |
| UREQ-005 | Should fend of snails effectively |
| UREQ-006 | Should not kill snails so as not to attract more snails |
| UREQ-007 | Must Monitor minimum and maximum temperatures over the day |
| UREQ-008 | Must be powered by solar since no grid connection is available in the garden |
| UREQ-009 | Must be low-cost |
| UREQ-010 | Must operate during 3 cloudy summer days in a row |
| UREQ-011 | Monitor must be easily readable from 50cm |
| UREQ-012 | Must be repairable |
| UREQ-013 | Must be safe |
| UREQ-014 | Must not break down in the first year |
| UREQ-015 | Should be low noise |

# System Diagram

The first thing I usually do is to define the different functional elements of a system together with inputs and outputs. I like to do that in a system diagram because it is intuitive and easy to read. I could use standardized symbols, but since I want this project to be accessible to hobbyists, I&#39;ll keep it simple and visual.

![](RackMultipart20220512-1-oz3st0_html_ee1c1d96afde8f27.png)

# System Requirements

Next, I thought about what parts my system would need to consist of and what each of these parts must fulfill to cover the user requirements. I did not take this too seriously and did not go into all the detailed module requirements like the behavior requirements of the software. This was just to document my thinking process and practice my product requirements skills a little.

| **ID** | **Description** | **Trace** |
| --- | --- | --- |
|
 | **Wiring** |
 |
| REQ-001 | All cables need to be detachable with little effort for maintenance purposes | \&gt; UREQ-011 |
| REQ-002 | All wires must exceed the standard diameters based on the rated amperage of the attached utility | \&gt; UREQ-013 |
|
 | **Water Distribution** |
 |
| REQ-011 | Must have a pump that delivers a set amount of water up to 40 Liter per day to four different locations based on user input | \&gt; UREQ-001 |
| REQ-012 | Could deliver separate amounts of water up to 40 Liter per day to four different locations based on moisture readings | \&gt; UREQ-002 |
| REQ-013 | Could have hygrometers in each field | \&gt; REQ-012 |
| REQ-014 | Must have a flowmeter with a measuring range compatible to the selected pump | \&gt; REQ-011 |
| REQ-015 | Must take the water from a water tank with potentially dirty water | \&gt; UREQ-001 |
| REQ-016 | Pump must not run dry | \&gt; UREQ-014 |
|
 | **User Interface** |
 |
| REQ-021 | Display must be at least 1.3&quot; | \&gt; UREQ-010 |
| REQ-022 | Must have a means to set the water/humidity for each field | \&gt; UREQ-001 |
| REQ-023 | Must have a means to configure the internal clock | \&gt; UREQ-001 |
| REQ-024 | Must display the minimum and maximum temperature and humidity over the day | \&gt; UREQ-007 |
| REQ-025 | Must allow to set a minimum temperature at which heating is turned on | \&gt; UREQ-004 |
| REQ-026 | Must allow to set a maximum temperature at which ventilation is turned on | \&gt; UREQ-003 |
|
 | **Control Board** |
 |
| REQ-031 | Must be protected from rain and/or condensation | \&gt; UREQ-014 |
|
 | **Snail Fence** |
 |
| REQ-041 | Must surround each of the three 1m x 5m raised beds with two copper tapes attached to a 9V power supply | \&gt; UREQ-005 \&gt; UREQ-006 |
| REQ-042 | should have a switch to turn off | \&gt; UREQ-006 |
|
 | **Greenhouse Ambient Regulation** |
 |
| REQ-051 | Must have a 12V fan | \&gt; REQ-061 \&gt; UREQ-003 |
| REQ-052 | Must have a 12V heater | \&gt; REQ-061 \&gt; UREQ-004 |
| REQ-053 | Must have a temperature and humidity sensor | \&gt; UREQ-004 |
|
 | **Power Supply** |
 |
| REQ-061 | Must have a battery with twice the capacity to power the controller module and operate the pump long enough to deliver a total of 80L per day for three days in a row. | \&gt; UREQ-001 \&gt; UREQ-008 |
| REQ-062 | Battery must be a 12V lead acid battery for cost effectiveness (because we had an old one laying around) | \&gt; UREQ-009 |
| REQ-063 | Must have a solar panel that generates enough electricity to charge the battery on an average sunny day in germany through a charge controller as constrained by\&gt; REQ-061 | \&gt; UREQ-010 \&gt; UREQ-008 |
| REQ-064 | Must provide enough power for the fan | \&gt; UREQ-003 |
| REQ-065 | Must provide enough power for the heater | \&gt; UREQ-004 |
| REQ-066 | Must provide enough power for the water distribution system | \&gt; UREQ-001 |
| REQ-067 | Must provide enough power for the snail fence | \&gt; UREQ-005 |

# System Design

Next, I started looking for parts and thinking about how I may build it cost-effectively with the parts on the market. There is no point in designing the perfect system if you can&#39;t build it because you can&#39;t find the right parts. For example, I had to get multiple adapters between thread sizes and a pressure regulator because the pump would deliver more pressure than the drip hose could endure. I made a more detailed module diagram of the water distribution since this one was the most complicated and I wanted to visualize what adaptors I needed and how everything fits together.

![](RackMultipart20220512-1-oz3st0_html_586a2cf621e89302.png)

I thought about making diagrams for the electronics and software as well. but I feel like the code and electronic schematics are pretty self-explanatory, and since I am a busy man, I will leave it at that. If you have any questions, please create a github issue and I will try to answer it.

# Parts

Since my mother did not want me to spend much money, I ordered most parts from AliExpress which arrived within 2-4 weeks. Since I did not write down all requirements, traceability kind of loses its purpose so I&#39;ll leave it out.

| **ID** | **Description** | **Properties** | **Requirements** | **Quantity** | **Price €** | **Buy** |
| --- | --- | --- | --- | --- | --- | --- |
| PART-001 | Hose | 20m, 12mm inner diameter | low-cost, tolerate pressure of pump | 1 | 10 | get locally |
| PART-002 | Dripping Hose | 20m length 4/9mm, minimum of 1-2 bar working pressure, maximum of 4 bar |
 | 4 | 11,43 | [Link](https://www.aliexpress.com/item/32929487096.html?spm=a2g0o.order_detail.0.0.442df19cQ0YDjF) |
| PART-003 | Hose Clamp | 3/4&quot;, 5pc per pack | 3/4&quot; | 2 | 0,86 | [Link](https://www.aliexpress.com/item/4000954734119.html?spm=a2g0o.order_detail.0.0.442df19cQ0YDjF) |
| PART-004 | Pump | 5 Bar, 3.5 L/min | Flow Rate, Pressure | 1 | 8,46 | [Link](https://www.aliexpress.com/item/1005001612894964.html?spm=a2g0o.order_detail.0.0.5879f19cBlBGBz) |
| PART-005 | Flow Meter | 1-30L/min, 17.5 Bar, 1/2&quot; threads | 12V, can handle the pressure | 1 | 1,60 | [Link](https://www.aliexpress.com/item/4000074968315.html?spm=a2g0o.order_detail.0.0.5e16f19cs0yNR7) |
| PART-006 | Inlet Filter | Double Net | Easy to clean, hang into water | 1 | 2,64 | [Link](https://www.aliexpress.com/item/33054351075.html?spm=a2g0o.order_detail.0.0.1003f19cVZCf1I) |
| PART-007 | Pre-pump Filter | 3/4&quot; threads | connectors on both ends | 1 | 6,34 | [Link](https://www.aliexpress.com/item/32906764639.html?spm=a2g0o.order_detail.0.0.442df19cQ0YDjF) |
| PART-008 | Pressure Regulator | 3 Bar, 3/4&quot; in female, 3/4&quot; out male, | less than 4 bar PART-002 | 1 | 1,58 | [Link](https://www.aliexpress.com/item/32917089441.html?spm=a2g0o.order_detail.0.0.442df19cQ0YDjF) |
| PART-009 | 1/2&quot; to 3/4&quot; adapter |
 | low cost UREQ-009 | 4 | 0,45 | [Link](https://www.aliexpress.com/item/4000177787641.html?spm=a2g0o.order_list.0.0.21ef1802ucAw6e) |
| PART-010 | Adaptor 1/2&quot;to hose |
 | 1/2&quot; internal thread12mm barbed connector (PART-001) | 5 | 0,43 | [Link](https://www.aliexpress.com/item/32917141441.html?spm=a2g0o.order_detail.0.0.10a3f19cB1McZV) |
| PART-011 | Adaptor 3/4&quot;to hose |
 | 3/4&quot; internal thread12mm barbed connector (PART-001) | 2 | 0,43 | [Link](https://www.aliexpress.com/item/32917141441.html?spm=a2g0o.order_detail.0.0.10a3f19cB1McZV) |
| PART-012 | Fan |
 | 12Vlow noise | 2 | 3,27 | [Link](https://www.aliexpress.com/item/4001007637782.html?spm=a2g0o.order_list.0.0.14751802i02e6V) |
| PART-013 | 4 Way hose splitter |
 | can screw into solenoid | 1 | 5,51 | [Link](https://www.aliexpress.com/item/32923580377.html?spm=a2g0o.order_detail.0.0.442df19cQ0YDjF) |
| PART-014 | Soaking hose connector |
 | 4mm outside3/4&quot; splitter | 4 | 1,86 | [Link](https://www.aliexpress.com/item/32936271677.html?spm=a2g0o.order_detail.0.0.442df19cMCg4OG) |
| PART-015 | Solenoid Valve | 1/2&quot; threads, 0.2-8 bar | runs at 12V, normally closed | 4 | 1,36 | [Link](https://www.aliexpress.com/item/33007085127.html?spm=a2g0o.order_detail.0.0.5e16f19cs0yNR7) |
| PART-016 | Float Switch |
 | mounts to side of the tank | 2 | 0,64 | [Link](https://www.aliexpress.com/item/4001061701102.html?spm=a2g0o.order_detail.0.0.5e16f19cs0yNR7) |
| PART-017 | Solar Panel | 20W | \&gt;= 4x battery capacity | 1 | 22,17 | [Link](https://www.aliexpress.com/item/32847502994.html?spm=a2g0o.order_list.0.0.14751802i02e6V) |
| PART-018 | Solar Charge Controller | 10A | for lead acid batteries, | 1 | 3,66 | [Link](https://www.aliexpress.com/item/33007101009.html?spm=a2g0o.order_detail.0.0.5e16f19cs0yNR7) |
| PART-019 | Battery | 60Wh | low-cost, \&gt;= 60 Wh | 1 | 18 | get locally |
| PART-020 | Heater |
 | 100W, 12V | 1 | 10,59 | [Link](https://www.aliexpress.com/item/32967951841.html) |
| PART-021 | ESP32 |
 | low-cost, I2C interface, USB flashing, | 1 | 4,62 | [Link](https://www.aliexpress.com/item/32834130422.html?spm=a2g0o.productlist.0.0.22ba51a1cVx5Tk&amp;algo_pvid=d6e10e8c-95cd-4f96-bed8-ae0a6d282c16&amp;algo_exp_id=d6e10e8c-95cd-4f96-bed8-ae0a6d282c16-8&amp;pdp_ext_f=%7B%22sku_id%22%3A%2212000028367307855%22%7D&amp;pdp_npi=2%40dis%21EUR%21%214.62%21%21%21%21%21%400b0a119a16521050946161144ed3e0%2112000028367307855%21sea) |
| PART-022 | Real Time Clock module | I2C, Battery mount | I2C, Battery mount | 1 | 0,32 | [Link](https://www.aliexpress.com/item/33003227226.html?spm=a2g0o.order_detail.0.0.5e16f19cs0yNR7) |
| PART-023 | Hygrometer | Analog reading | 3.3V, low-cost | 8 | 0,23 | [Link](https://www.aliexpress.com/item/33048567290.html?spm=a2g0o.order_detail.0.0.5e16f19cs0yNR7) |
| PART-024 | Copper Tape | 50mx5mm | low-cost, stable enough not to rip too easily | 3 | 2,40 | [Link](https://www.aliexpress.com/item/4000308076266.html?spm=a2g0o.order_detail.0.0.5d49f19crDv0wy) |
| PART-025 | 5V Regulator | 2A, 10pc per lot | input 12V, output \&gt; 1A | 1 | 2,18 | [Link](https://www.aliexpress.com/item/4000830180460.html?spm=a2g0o.productlist.0.0.468758619MU2ay&amp;algo_pvid=70af16be-82de-40aa-9254-8427a1b18ad6&amp;algo_exp_id=70af16be-82de-40aa-9254-8427a1b18ad6-0&amp;pdp_ext_f=%7B%22sku_id%22%3A%2210000008680758020%22%7D&amp;pdp_npi=2%40dis%21EUR%21%212.18%21%21%21%21%21%402100bde316521065479014467ef391%2110000008680758020%21sea) |
| PART-026 | 3.3V Regulator | 2A, 10pc per lot | input 12V, output \&gt; 1A | 1 | 1,69 | [Link](https://www.aliexpress.com/item/4000184190884.html?spm=a2g0o.productlist.0.0.4c6cc8a3phDkZt&amp;algo_pvid=b860fb45-c95d-4de3-b16e-2176006a25b0&amp;algo_exp_id=b860fb45-c95d-4de3-b16e-2176006a25b0-1&amp;pdp_ext_f=%7B%22sku_id%22%3A%2210000000676904737%22%7D&amp;pdp_npi=2%40dis%21EUR%21%211.69%21%21%21%21%21%400b0a01f816521063912872306e82e0%2110000000676904737%21sea) |
| PART-027 | IRF3708 MOSFET to run solenoid valves | Note, should have used a relay here as I had some issues with creeping currents and heat | Fully open at Logic Levels (3.3V), 12V range, 10A | 6 | 2,31 | [Link](https://www.aliexpress.com/item/32873147996.html?spm=a2g0o.productlist.0.0.29247fb5A5oe6Y&amp;algo_pvid=6f61a903-fb08-413e-8446-6806683b2d53&amp;algo_exp_id=6f61a903-fb08-413e-8446-6806683b2d53-1&amp;pdp_ext_f=%7B%22sku_id%22%3A%2212000024568308110%22%7D&amp;pdp_npi=2%40dis%21EUR%21%212.11%21%21%21%21%21%400b0a187b16521066441732290e9b77%2112000024568308110%21sea) |
| PART-028 | I2C Display | 1.3&quot;, OLED | I2C communication | 1 | 3,15 | [Link](https://www.aliexpress.com/item/4001145494936.html?spm=a2g0o.productlist.0.0.387f39e04knEdU&amp;algo_pvid=88f457cf-9efd-439c-98f4-184f69913d6b&amp;algo_exp_id=88f457cf-9efd-439c-98f4-184f69913d6b-1&amp;pdp_ext_f=%7B%22sku_id%22%3A%2210000014888634895%22%7D&amp;pdp_npi=2%40dis%21EUR%21%213.15%21%21%21%21%21%402100bde116521055145145237e7895%2110000014888634895%21sea) |
| PART-029 | HTU31D Humidity &amp; Temperature Sensor | 0-100% humidity, -40 to +125 C | 0-100% humidity, -10 to +60 C, resistant to condensation | 1 | 2,57 | [Link](https://www.aliexpress.com/item/1005003128666097.html) |
| PART-030 | Connectors |
 | 2,3,4 pin connectors, suitable for selected wire diameter | 1 | 1,52 | [Link](https://www.aliexpress.com/item/32836912971.html?spm=a2g0o.order_list.0.0.21ef1802ucAw6e) |
| PART-031 | Buttons, Switches, Resistors, cables, etc. | I am too busy to make a detailed list here. Have a look at the electrical schematic and adjust to your use case |
 | 1 | 10 |
 |
| PART-032 | Barbed Connector adaptor | I 3D printed this from TPU because I realized later that I was missing this part | flexible, convert 9mm outer diameter to 12mm outer diameter | 1 | 0,05 |
 |
|
 | **Total** |
 |
 |
 | **200,95** |
 |

Things from China have gotten significantly more expensive since I bought these so you might come up with a different price. Also, the soaking hose was the most expensive part. You can choose to use less hose or a different, cheaper kind if you want to save money.

# Pictures

Me assembling the box.
![](photos\box.jpg)
I did not have any hinges so I 3D printed some with my resin printer
![](photos\hinges.jpg) 
They work!
![](photos\box-open.jpg) 
Assembling the electronics
![](photos\electronics.jpg) 
the fans
![](photos\fans.jpg) 
this is where the fans get their air from
![](photos\intake.jpg) 
solar panel
![](photos\solar.jpg) 
battery at full charge!
![](photos\solar-charge.jpg) 
This is where the water is taken in
![](photos\water-intake.jpg)
Here the pump is distributing it
![](photos\water-distribution.jpg)
The hoses and wiring of the snail fence and hygrometers (we will install the snail fence later)
![](photos\water-distribution-2.jpg) 

# Conclusion

This was a fun project and I had a chance to apply my skills in engineering and product design on a small, low risk scale which made this very enjoyable. The system is fully functional and my mom is delighted, but I will share any design improvements I come up with.


And as a final treat my mothers beautiful garden
![](photos\flowers.jpg) 