# 'The Southerly' Split Keeb

## Intro

In 2024 I was getting some serious wrist pain issues from typing all day at my job as a programmer, so I ventured into the world of split keyboards.
Initially I was just curious, but as time went on I wondered *why do we use a silly straight keyboard format*. This quickly turned into a purchase of my first split keyboard, the [ZSA Voyager](https://www.zsa.io/voyager). I quickly fell in love with the keyboard and how it felt with my hands.
Alongside also purchasing a Logitech MX Ergo trackball mouse.

I had quite a tough learning experience to switching to the Voyager strictly due to the fact that whilst I changed keyboard layouts, I switched from traditional mice to trackball mice, **and** started learning the ColemakDH keyboard layout.
Because you know what, *why do we also use a really inefficient form for typing*. Boy howdy was I in for a learning experience.

Switching to the new layer system, getting rid of the numpad, F-keys, moving spaces, tabs and enters; whilst incredibly fun, was quite intensive switch over.
But now sitting here a few months after my mission to improve desk ergonomics; I'm feeling a hell of a lot better with all my pain, voila, gone!

## ErgoGen Layout Printouts/Design

I came across ErgoGen when researching about split keyboards, this piece of software is marvelous... complex but marvelous.
It took me quite a while to figure out how to use ErgoGen and their official docs are still a WIP meaning I was initially going blind with this software.

I came across this youtube video [ErgoGen Tutorial](https://www.youtube.com/watch?v=7UXsD7nSfDY) which dramatically helped me start with the design of my keyboard
Another great guide I came across was this one, which in my honest opinion, **is the best ErgoGen doc set I have found to date**; [ErgoGen Full Run Through](https://flatfootfox.com/ergogen-part1-units-points/)

As an initial design process I decided to create a few models, drill holes and try them out on my fingers.
I enjoyed my Voyager's layout and so I wanted to mimic this layout as close as possible.
Some neat additions I added was the use of two additional thumb keys.

![alt text](<images/ErgoGen Layout.png>)

There was going to be three layers to the case design which I'll get into later. But the brief is a bottom plate which becomes the surrounding case, a top plate which sits just under the switches (they click into the top layer) and the circuit board which will be centered below the top layer by a few millimeters.

![alt text](images/Design_1.jpg)
![alt text](images/Design_2.jpg)
![alt text](images/Design_3.jpg)

## ErgoGen Design Complete

![alt text](images/PCB_1.png)

## AutoDesk Fusion - Case Design

Whilst ErgoGen can and does generate most 3D print designs and DXF files, I found it quite fiddly changing the YAML constantly to design a case.
So instead I decided that the best course was to get a rough outline in ErgoGen, then work the rest of the design in AutoDesk.
This was fairly straightforward as I just imported the base board, and two top layers into AutoDesk and did the following:

> NOTE: I created a key cap puller hole and ladled that as outline_inner_upper to aid in hot-swapping of choc switches

1. Extrude the base 13mm up
2. Create shell around outside of base ~ 3mm
3. Create top layer by combining my bottom & top layer sketches appropriately making a total height of 1.6mm
4. Create a copy of this top layer and expand horizontally by 0.3mm
5. Cut this expanded layer from the main body creating a lip for the top plate to sit in

The circuit board will sit on some foam in the bottom and will be attached to the top plate via the switches.

![alt text](images/AutoDesk_1.png)
![alt text](images/AutoDesk_2.png)


## Components

| Components | Links | Cost (NZD) | Notes |
| ---------- | ----- | ---------- | ----- |
| Choc V1 Keycaps | [Tai-Hao Thins](https://shop.tai-hao.com/products/white-1) | $96.67 | Same key caps as ZSA Voyager |
| Choc V1 Switches | [Ambient Silent Twilight/Nocturnal](https://keebd.com/en-nz/products/ambients-silent-linear-twilight-choc-switches?_pos=2&_fid=9a770a5f9&_ss=c) | $108 |
| Kailh HotSwap Sockets | [Choc HotSwap Sockets](https://keebd.com/en-nz/products/kailh-choc-hotswap-sockets?_pos=1&_psq=hotswap&_ss=e&_v=1.0) | $24 |
| Pico Micro (USB-C) |
| Surface Mount Diodes - SOD 123 |
| RGB - led_sk6812mini-e |
| Surface Mount Reset Button |
| TRRS Connector |
| Screw Mounts? |
