🌌 Fract-ol – Fractals, Colors, and Chaos! 🎨✨
Welcome to Fract-ol, where math meets art, and chaos turns into patterns! This project is all about rendering fractals—those infinitely complex, beautiful shapes that emerge from simple mathematical equations. Get ready to dive into the world of Mandelbrot, Julia, and color palettes!

🚀 What is Fract-ol?
Fract-ol is a 42 school project that challenges you to generate and manipulate fractals using the MLX42 graphics library. You'll get to know:
The Mandelbrot Set 🌍 
The classic fractal that pulls you into an infinite zoom of complexity.

The Julia Set 🔮 
 A customizable fractal where a tiny parameter shift changes everything!
And maybe even more... who knows what cool patterns we’ll discover? 😏
🎨 Features
✅ Beautiful, smooth color gradients – Because fractals deserve to shine!
✅ Zoom in & out – Get lost in the infinite depths of fractal madness!
✅ Move around – Explore the fractal landscape like an adventurer.
✅ Switch color themes – Customize your fractal with epic palettes.

⚡ How to Run
Clone this repo and compile it with:

make opt


**************************************************
*               FRACT-OL USAGE GUIDE             *
**************************************************

🌀 Available Fractal Sets:
   ────────────────────────────────────
   🔹 Mandelbrot
   🔹 Julia
   ────────────────────────────────────

🚀 How to Run:
   ────────────────────────────────────
   🟢 Mandelbrot Usage:
      ➜ ./fractol mandelbrot

   🟣 Julia Usage (Must have custom parameters):
      ➜ ./fractol julia [real_part] [imaginary_part]
      🔹 [real_part] & [imaginary_part] must be doubles with a dot
      🔹 Julia set parameters must be between -2.0 and 2.0
      🔹 Decimal part must be less than 9 digits to avoid out-of-bounds errors
   ────────────────────────────────────

📌 Hien's FAV Julia Set Parameters: 😘💋
   ────────────────────────────────────
   🔹 -0.4    0.6     (Look to your soul)
   🔹  0.285  0.01    (Baby dino)
   🔹  0      0.8     (A sky full of stars - press B!!!)
   🔹 -1.476  0       (Radio hardcore)
   🔹 -0.12  -0.77    (Puzzled bunnies)
   ────────────────────────────────────

🎮 Controls:
   ────────────────────────────────────
   🏁 ESC          ➜ Exit the program
   🎯 Arrow Keys   ➜ Move the view (← ↑ ↓ →)
   🔍 Mouse Scroll ➜ Zoom in/out at mouse position
   ➕ Keypad + / -  ➜ Increase or decrease iterations
   🎨 Arrow Keys ->>> R, G, B, W   ➜ Switch color modes (Red, Green, Blue, White)
   ────────────────────────────────────

🧠 How It Works

Each pixel in the window represents a complex number. The number of iterations determines the color, creating stunning gradients! 🎨

I use bitwise operations to manipulate colors efficiently and make those smooth gradients appear!

💡 Lessons Learned
Complex numbers are actually fun when they make pretty pictures! 🤓
Optimization is key—fractal rendering can be heavy, but I tried hard for a smooth experience.
Colors and bit shifting = magic.
🎭 Final Thoughts
Fractals are a perfect blend of math, code, and art. If you love visually satisfying projects and getting lost in infinite patterns, this is for you!

Enjoy the fractal madness! 🌌✨
