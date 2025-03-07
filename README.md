# The Southerly - Split Keeb

![Final Keeb](<images/Final 2.jpg>)

<img src="images/Final 1.jpg" width="600" alt="Logo"/>

<img src="images/cold-wind.svg" width="200" height="200" alt="Logo"/>

**Brrrr is it cold down here in New Zealand winters!**

## Intro

In 2024 I was getting some serious wrist pain issues from typing all day at my job as a programmer, so I ventured into the world of split keyboards.

Initially I was just curious, but as time went on I really enjoyed the idea of having two keyboard halves an was quite keen on the staggered column. This quickly turned into a purchase of my first split keyboard, the [ZSA Voyager](https://www.zsa.io/voyager). I quickly fell in love with the keyboard and how it felt with my hands.
Alongside also purchasing a Logitech MX Ergo trackball mouse.

I had quite a tough learning experience to switching to the Voyager strictly due to the fact that whilst I changed keyboard layouts, I switched from traditional mice to trackball mice, **and** started learning the ColemakDH keyboard layout.

Switching to the new layer system, getting rid of the numpad, F-keys, moving spaces, tabs and enters; whilst incredibly fun, was quite intensive switch over. But now sitting here a few months after my mission to improve desk ergonomics; I'm feeling a hell of a lot better with all my pain, voila, gone!

## Layout Printouts/Design - ErgoGen

I came across ErgoGen when researching about split keyboards, this piece of software is marvelous... complex but marvelous. It took me quite a while to figure out how to use ErgoGen and their official docs are still a WIP meaning I was initially going blind with this software.

I came across this youtube video [ErgoGen Tutorial](https://www.youtube.com/watch?v=7UXsD7nSfDY) which dramatically helped me start with the design of my keyboard.

Another great guide I came across was this one, which in my honest opinion, **is the best ErgoGen doc set I have found to date**; [ErgoGen Full Guide](https://flatfootfox.com/ergogen-part1-units-points/)

As an initial design process I decided to create a few models, drill holes and tried them out on my fingers. With my owned Voyager, I was able to replicate quite easily the positioning I wanted all the keys in, with the addition of a couple more thumb keys.

![ErgoGen Layout](<images/ErgoGen Layout.png>)

There was going to be three layers to the case design which I'll get into later. But the brief is a bottom plate which becomes the surrounding case, a top plate which sits just under the switches (they click into the top layer) and the circuit board which will be centered below the top layer by a few millimeters.

### Prototyping

I made **lots** of prototypes for my board as I went through multiple designs. Starting with a basic layout to see what worked well with my hands with the original Voyager as reference.

![Prototyping](<images/Prototyping.jpg>)

## PCB Design - KiCad

Once I sorted out the prototyping of the board I moved on to the wiring of the circuit board. The PCB was designed with the idea of being reversible, meaning you can mount the components either way, *but there was a caveat there*.

The PCB design was fairly straightforward running the horizontal traces on one layer and vertical traces on the other, with an addition of two ground planes and thicker VCC/GND traces. The only annoying thing was that KiCad, for the life of me, doesn't support angle snapping at strange angles; and my thumb cluster is on a 30° angle. Making the thumb cluster super messy. Sigh...

The RGB data in and data out connectors were not a part of the schematic so I had to use a third party plugin to help me modify the web and attach the string of LED's to one of the PCB's pinouts. [WireIt](https://github.com/devbisme/WireIt)

After designing the PCB I shipped the Gerber off to JLCPBC to print off for me.

### PCB Underside - LH

![LH PCB Underside](<images/LH PCB 1.png>)

### PCB Topside - LH

![LH PCB Topside](<images/LH PCB 2.png>)

## Gotcha Moment

Although once receiving the board I realized that the reversible board wouldn't work with the ProMicro the way I had designed it for the 3D design plan as I wanted a minimal keyboard with little height. For that I would have needed to mount MCU directly on the circuit board. So that's a consideration for my next build.

Since my board was already designed to be flippable, the only thing I needed to change was the MCU, so I flipped the MCU footprint and re-traced everything again for the right handed layout.

### PCB Underside - RH

![RH PCB Underside](<images/RH PCB 1.png>)

### PCB Topside - RH

![RH PCB Topside](<images/RH PCB 2.png>)

## Case Design - AutoDesk Fusion

Whilst ErgoGen can and does generate most 3D print designs and DXF files, I found it quite fiddly changing the YAML constantly to design a case.

So instead I decided that the best course was to get a rough outline in ErgoGen, then work the rest of the design in AutoDesk. The ErgoGen created some annoying fillets in the output, so I removed those and re-created the fillets to clean up the design.

### Upper Case

This was fairly straightforward as I just imported the base outlines created from ErgoGen as sketches and worked on them from there.

From the sketches I firstly designed the upper case which was designed to clip into a base.

Using the sketch outputs I was able to create the Choc V1 socket holes, added key cap pullers to them, and a rectangular cutout underneath to allow the switched to clip into the case properly.

The addition of the reset switch, TRRS and USB-C cutouts was straightforward, just an easy sketch and a subtraction extrude.

Additional fun logo was embossed onto the case too.

> [!NOTE]
> Total thickness of the area between the top plate and rectangular cutout must be exactly 14mm for the switches to properly click in, this was giving me some grief with our 3D printer, we set infill to 100% to prevent any wavey patterns around the switches, and waited until the 3D print bed completely cooled. Otherwise the switch holes shrunk due to rapid cooling or warping.
>
> Also, the TRRS cutout needed a 'brim ears' underneath to prevent liftoff from the base plate during printing.

![RH Upper Case](<images/RH Upper Case.png>)

### Lower Case

From the sketches I designed a lower case, or base, which will support an upper case and fit snugly together. This was done by creating inner walls which extruded into the top layer *(subtraction)* to the fit, and a hex fill for supporting the PCB, *which I also added some foam in for sound proofing and support*.

Adding in a patterned hex structure to the inside to help support the PCB. I added some foam on top of this to fill in the spaces, provide more support, and sound proofing.

![RH Lower Case](<images/RH Lower Case.png>)

### Standoffs

TODO: Create standoffs for the board to help with tenting.

### Combined Output

![3D Case](<images/3D Case.png>)

## QMK Firmware

QMK was an interesting beast to try learn and it took me a lot of trial and error figuring out how to program the keyboard. I'm still confused on what the right way to define the parameters are, we have the legacy solution, C header files, C files and rules makefiles, or data driven files with JSON which is the new format. However the documentation isn't really up to date with the new JSON format and the C files also lacked up to date documentation.

There were other keyboards in the repository that I had to copy and paste to see what worked and what didn't.

The pinouts of the ProMicro was a bit confusing at first as they didn't match what was on the MCU physically; once I found this image I was able to map the pins correctly to the PCB design. Now correctly mapping the columns and rows, and RGB matrix.

![ProMicro Pinout](<images/ProMicro Pinout.jpg>)

Also found it quite handy that I was able to download the source QMK firmware for the Voyager and reverse engineer the QMK setup for the Voyager. This allowed me to understand the QMK design process better and how the matrices are used. Also means that I could take a layout I made for my Voyager and with the addition of the extra thumb buttons and removal of some unnecessary functions, was able to get a running board very quickly.

## Components

| Components | ID | Links | Total Cost (NZD) | Quantity | Notes |
| ---------- | -- | ----- | ---------- | -------- | ----- |
| Choc V1 Keycaps | | [Tai-Hao Thins](https://shop.tai-hao.com/products/white-1) | $96.67 | | Same key caps as ZSA Voyager (Needs to be double injected for the RGB) |
| Choc V1 Switches | | [Robins](https://keebd.com/en-nz/products/ambients-silent-linear-twilight-choc-switches?_pos=2&_fid=9a770a5f9&_ss=c) | $60 | 60 | |
| Kailh Hotswap Sockets | | [Choc Hotswap Sockets](https://www.aliexpress.com/item/1005006833673668.html) | $24 | 60 | |
| Pico Micro (USB-C) | | [AliExpress](https://www.aliexpress.com/item/1576902211.html) | $13.7 | 2 | |
| Surface Mount Diodes | SOD 123 - DSF1J | [LCSC](https://www.lcsc.com/product-detail/Fast-Recovery-High-Efficiency-Diodes_FUXINSEMI-DSF1J_C915615.html) | $1.58 | 200 | |
| RGB | led_sk6812mini-e | [LCSC](https://www.lcsc.com/product-detail/RGB-LEDs-Built-in-IC_OPSCO-Optoelectronics-SK6812MINI-E_C5149201.html) | $7.15 | 100 | |
| Surface Mount Reset Button | EVQPUA02K | [LCSC](https://www.lcsc.com/product-detail/Tactile-Switches_PANASONIC-EVQPUA02K_C128539.html) | $1.62 | 5 | |
| TRRS Connector | PJ-320A | [LCSC](https://www.lcsc.com/product-detail/Audio-Connectors_XKB-Connectivity-PJ-320AG-B_C2884984.html) | $0.39 | 5 | |
| TRRS Cable | UGREEN 20782 | [PB Tech](https://www.pbtech.co.nz/product/CABUGR6192/UGREEN-20782-35mm-Male-To-Male-Cable---2M) | $20 | 5 | **You need a 4 pole TRRS cable** (I struggled finding one so just ordered one locally) |
| Circuit Board | | [JLCPCB](https://jlcpcb.com/) | $11.76 | 5 | |
| **Total** | | | **$236.87** | | |

## Notes

- The key caps **must** be double injected for the RGB to shine through, otherwise you will just get an under-glow.

### ErgoGen

- [ErgoGen Guide - Units & Points](https://flatfootfox.com/ergogen-part1-units-points/)
- [YouTube Guide - Designing and Building a Split Keyboard](https://www.youtube.com/watch?v=7UXsD7nSfDY)
- [Notion Guide - Convert KiCad to ErgoGen Footprints](https://nilnil.notion.site/Convert-Kicad-Footprints-to-Ergogen-8340ce87ad554c69af4e3f92bc9a0898)
- [ErgoGen Footprints](https://github.com/ceoloide/ergogen-footprints/tree/main)

### PCB

- [PCB Addon - Wire RatsNest](https://github.com/devbisme/WireIt)
- [PCB Printing - JLCPCB](https://jlcpcb.com/)

### QMK

- [QMK Bootloader](https://docs.qmk.fm/driver_installation_zadig#list-of-known-bootloaders)
- [QMK Matrix to Physical Layout Map](https://docs.qmk.fm/understanding_qmk#matrix-to-physical-layout-map)
- [VSCode Setup](https://docs.qmk.fm/other_vscode)
- Split Keyboard
  - [Serial Wiring](https://docs.qmk.fm/features/split_keyboard#serial-wiring)
  - [Split Keyboard](https://docs.qmk.fm/features/split_keyboard#split-keyboard)
  - [Keeb Handedness](https://docs.qmk.fm/features/split_keyboard#handedness-by-eeprom)
- RGB
  - [RGB: WS2812 LED](https://docs.qmk.fm/drivers/ws2812)
  - [RGB: Matrix](https://docs.qmk.fm/features/rgb_matrix)
- TRRS
  - [TRRS: I2C](https://docs.qmk.fm/drivers/i2c)
  - [TRRS: Serial](https://docs.qmk.fm/drivers/serial)
- Data Driven Configs (.json) - New
  - [QMK JSON (.json) - Preferred Way](https://docs.qmk.fm/reference_info_json)
  - [QMK Data Driven Config](https://docs.qmk.fm/data_driven_config)
- Header Configs (.h/.mk) - Legacy
  - [QMK Config.h](https://docs.qmk.fm/config_options#the-configh-file)
  - [QMK Rules.mk](https://docs.qmk.fm/config_options#the-rules-mk-file)

<!-- TODO: qmk flash -kb southerly -km default -bl avsdude-split-left -->

## Improvements & Considerations

- Next time instead of using a Pro Micro, I will use a MEGA32U4 directly on the board and design the components directly into the board.
  > This will cleanup the USB-C port location and make the reversible board work correctly without having to re-design the PCB case for the mirrored side.

- Diagnose why a TRRS port isn't compatible with a TRS cable *(common audio cable)*, it must use a TRRS cable instead *(4 Pole audio cable)*.
  > I had troubles when first trying this out with a TRS cable and it shorted VCC to GND, the MCU never booted whilst plugged into TRRS.

- Use I2C for TRRS communications next time, this requires some rewiring on the PCB with some pull up resistors. But will allow for multiple devices to be connected through TRRS.

- Figure out how to do matrix lighting from master to slave. (It's doesn't seem to want to update the slave correctly)

- Figure out how the master slave connection works properly, allow USB connection from either side?
