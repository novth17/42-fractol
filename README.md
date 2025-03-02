# 🌌 Fract-ol – Fractals, Colors, and Chaos! 🎨✨  

Welcome to **Fract-ol**, where math meets art, and chaos turns into mesmerizing patterns! This project is all about rendering fractals—those infinitely complex, beautiful shapes that emerge from simple mathematical equations. Get ready to dive into the world of Mandelbrot, Julia, and vibrant color palettes!  

---

## 🚀 What is Fract-ol?  

Fract-ol is a **42 school project** that challenges you to generate and manipulate fractals using the **MLX42 graphics library**.  

### 🌀 Available Fractal Sets:  

- **Mandelbrot Set 🌍**  
  The classic fractal that pulls you into an infinite zoom of complexity.  

- **Julia Set 🔮**  
  A customizable fractal where a tiny parameter shift changes everything!  

- And maybe even more... who knows what cool patterns we’ll discover? 😏  

---

## 🎨 Features  

✅ **Beautiful, smooth color gradients** – Because fractals deserve to shine!  
✅ **Zoom in & out** – Get lost in the infinite depths of fractal madness!  
✅ **Move around** – Explore the fractal landscape like an adventurer.  
✅ **Switch color themes** – Customize your fractal with epic palettes.  

---

## ⚡ How to Run  

Clone this repo and compile it with: 

```bash
make opt

🌀 Running the Program

# Mandelbrot Usage:
./fractol mandelbrot

# Julia Usage (Must have custom parameters):
./fractol julia [real_part] [imaginary_part]


⚠️ Julia Set Parameter Rules:
[real_part] & [imaginary_part] must be doubles with a dot.
Values must be between -2.0 and 2.0.
Decimal precision should be less than 9 digits to avoid out-of-bounds errors.



📌 Hien's FAV Julia Set Parameters 😘💋

────────────────────────────────────
 🔹 -0.4    0.6     (Look to your soul)
 🔹  0.285  0.01    (Baby dino)
 🔹  0      0.8     (A sky full of stars - press B!!!)
 🔹 -1.476  0       (Radio hardcore)
 🔹 -0.12  -0.77    (Puzzled bunnies)
────────────────────────────────────
Example, try running: ./fractol julia 0 0.8


🎮 Controls
────────────────────────────────────
 🏁 ESC          ➜ Exit the program  
 🎯 Arrow Keys   ➜ Move the view (← ↑ ↓ →)  
 🔍 Mouse Scroll ➜ Zoom in/out at mouse position  
 ➕ Keypad + / -  ➜ Increase or decrease iterations  
 🎨 Arrow Keys ->>> R, G, B, W   ➜ Switch color modes (Red, Green, Blue, White)  
────────────────────────────────────
```
---

## 🧠 How It Works

Each pixel in the window represents a complex number. The number of iterations determines the color, creating stunning gradients! 🎨

Bitwise operations are used to manipulate colors efficiently, making smooth gradients appear like magic! ✨

---

## 💡 Lessons Learned
Complex numbers are actually fun when they make pretty pictures! 🤓

Optimization is key—fractal rendering can be heavy, it takes some hard work to make it smoother.

Colors + bit shifting = absolute magic.


