<div align="center">

<h1>🌀 FRACT'OL</h1>

**A fractal explorer written in C using MiniLibX**

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-v3-brightgreen?style=flat-square)](https://github.com/42School/norminette)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)](LICENSE)

</div>

---

## 📖 About

**fract-ol** is a 42 School project that explores the mathematical beauty of complex fractals through real-time interactive rendering. Built entirely in C with the MiniLibX graphical library, it generates five distinct fractal sets with smooth colorization, infinite zoom, and live navigation.

The project focuses on:
- Complex number mathematics applied to iterative algorithms
- Efficient pixel-level rendering with MiniLibX
- Clean, modular C architecture respecting the 42 Norm
- Smooth logarithmic color mapping for visually rich output

---

## 🔮 Fractals

| Fractal | Command | Description |
|---|---|---|
| **Mandelbrot** | `./fractol mandelbrot` | The classic fractal set — every complex `c` for which `z² + c` stays bounded |
| **Julia** | `./fractol julia <x> <y>` | A family of fractals sharing Mandelbrot's formula but with a fixed complex parameter |
| **Burning Ship** | `./fractol burning_ship` | A Mandelbrot variant using absolute values, revealing a ship-like structure |
| **Celtic** | `./fractol celtic` | Modified Mandelbrot using `|Re(z²)| + c`, producing intricate Celtic knot-like patterns |
| **Collatz** | `./fractol collatz` | Visual exploration of the famous unsolved Collatz conjecture in the complex plane |

---

## 🎮 Controls

| Input | Action |
|---|---|
| `↑ ↓ ← →` / `W A S D` | Move the view |
| `Scroll Up` | Zoom in (centered on cursor) |
| `Scroll Down` | Zoom out (centered on cursor) |
| `Right Click` | Display fractal coordinates at cursor |
| `+` / `=` | Increase iterations (+10) — more detail |
| `-` | Decrease iterations (-10) — faster render |
| `C` | Cycle through 8 color palettes |
| `F` | Toggle fractal interior color (black/white) |
| `Z` | Display current zoom level |
| `H` | Show help menu |
| `ESC` | Exit |

---

## 🎨 Color Palettes

8 hand-crafted palettes with logarithmic color mapping for smooth gradients at any zoom depth:

| # | Name | Preview |
|---|---|---|
| 1 | 💚 Fluorescent Electric | Neon magentas, cyans and greens |
| 2 | 🔷 Metallic Steel | Deep navy blues to silver |
| 3 | 🔥 Fire Gradient | Black embers to white-hot flame |
| 4 | 💜 Purple Dream | Indigo to rose through orchid |
| 5 | 🌀 Psychedelic Trip | Maximum contrast cycling hues |
| 6 | 🎨 Acid Rainbow | Full spectrum, high saturation |
| 7 | 🌸 Sunset Dream | Violet dusk to warm peach |
| 8 | 🎭 Neon City | Dark urban blues and neon pinks |

---

## ⚙️ Installation

**Prerequisites:** `gcc`, `make`, `git`, and X11 development libraries.

```bash
# Ubuntu / Debian
sudo apt-get install libx11-dev libxext-dev

# Clone the repository
git clone https://github.com/<your-username>/fractol.git
cd fractol

# Build (automatically clones and compiles MiniLibX)
make
```

> The Makefile automatically clones [minilibx-linux](https://github.com/42Paris/minilibx-linux) on first build — no manual setup required.

---

## 🚀 Usage

```bash
# Mandelbrot set
./fractol mandelbrot

# Julia set — try different parameters for different shapes
./fractol julia -0.7 0.27
./fractol julia 0.355 0.355
./fractol julia -0.4 0.6

# Burning Ship
./fractol burning_ship

# Celtic variant
./fractol celtic

# Collatz conjecture
./fractol collatz
```

---

## 🏗️ Architecture

```
fractol/
├── sources/
│   ├── main.c            # Entry point & argument parsing
│   ├── init.c            # MLX and fractal state initialization
│   ├── render.c          # Core rendering loop (Mandelbrot, Julia, Collatz)
│   ├── render_2.c        # Extended rendering (Celtic, Burning Ship)
│   ├── math_utils.c      # Complex number operations & coordinate mapping
│   ├── event.c           # Keyboard event handlers
│   ├── event_2.c         # Mouse handlers & color interpolation
│   ├── event_inits.c     # MLX hook registration
│   ├── init_color.c      # Color palette definitions (palettes 1–4)
│   ├── init_color_2.c    # Color palette definitions (palettes 5–8)
│   ├── print.c           # UI output functions
│   ├── print_2.c         # Extended UI & ship coordinate display
│   ├── free_utils.c      # Memory cleanup utilities
│   └── printf/           # Custom ft_printf implementation
│       ├── ft_printf.c
│       ├── ft_utils.c
│       └── ft_utils_2.c
├── include/
│   └── fractol.h         # Structs, constants, and prototypes
├── libft/                # 42 standard library
├── minilibx-linux/       # Auto-cloned graphical library
└── Makefile
```

**Key data structures:**

```c
typedef struct s_fractal {
    char        *name;           // Fractal identifier
    double      shift_x;        // View offset X
    double      shift_y;        // View offset Y
    double      zoom;           // Current zoom factor
    double      zoom_count;     // Zoom level counter
    int         iterations_def; // Max iteration depth
    double      escape_value;   // Divergence threshold
    double      julia_x;        // Julia parameter (real)
    double      julia_y;        // Julia parameter (imaginary)
    int         f_color;        // Interior pixel color
    int         c;              // Active palette index
    t_color_psy *color_psy;     // Color palette data
    t_img       img;            // MLX image buffer
    void        *mlx_connection;
    void        *mlx_window;
} t_fractal;
```

---

## 🧮 Technical Highlights

**Smooth colorization** — Logarithmic mapping `t = log(1+i) / log(1+max)` ensures color bands don't bunch up at low iteration counts, producing smooth gradients even at shallow zoom levels.

**Cursor-centered zoom** — The mouse position is converted to fractal coordinates before scaling, then the shift is adjusted to keep that point fixed under the cursor — giving precise, natural zoom behavior.

**Collatz in the complex plane** — The formula `f(z) = ¼ × [1 + 4z − (1 + 2z)cos(πz)]` extends the integer Collatz sequence to the complex plane using trigonometric and hyperbolic functions, broken into real and imaginary components separately.

---

## 🛠️ Makefile Rules

```bash
make        # Build fractol (auto-clones minilibx if needed)
make clean  # Remove object files
make fclean # Remove objects, binary, and minilibx clone
make re     # Full rebuild
```

---

## 📚 Resources

- [Fractal Geometry — Wikipedia](https://en.wikipedia.org/wiki/Fractal)
- [Mandelbrot Set deep dive](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Smooth coloring algorithm](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set#Continuous_(smooth)_coloring)
- [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)

---

<div align="center">

Made with ☕ and complex numbers at [42 Paris](https://42.fr)

**jcrochet**

</div>
