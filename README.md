# Competitive-Programming-Notebook
This is a repository for Fast and Fourier - EAFIT ICPC Team Notebook.

The folder `code` contains most of the algorithms used by our team in the coding competitions: graph, strings, geometry, data structures, network flows, math, dynamic programming and other competitive programming stuff.

**NOTE:** Look `code/c++/template.cpp` to understand macros used in the code.

## 📚 Quick Start

### Build the Complete Notebook

**Automated (Recommended):**
```bash
# Windows PowerShell
.\build.ps1

# Or manually
python generate_contents_smart.py
python generate_pdf.py
```

This will:
1. Auto-generate `contents.txt` by scanning your `code/` directory
2. Compile the LaTeX document to create `notebook.pdf`

### Requirements
- [Python 3.x](https://www.python.org/)
- [latexmk](https://www.ctan.org/pkg/latexmk/) (part of TeX Live, MiKTeX, etc.)

## 🔧 Manual Workflow

### 1. Generate contents.txt (Optional - can be done manually)

**Option A: Smart Auto-generation (Recommended)**
```bash
python generate_contents_smart.py
```
- Automatically scans `code/` directory
- Extracts algorithm names from file comments
- Shows diff with existing contents.txt

**Option B: Basic Auto-generation**
```bash
python generate_contents.py
```
- Uses predefined algorithm names
- Simpler and faster

**Option C: Manual editing**
Edit `contents.txt` directly with this format:
```
[Section name]
subfolder/file.cpp	Description of the file
```
(Note: Use TAB character between filename and description)

### 2. Generate PDF

```bash
python generate_pdf.py
```

This reads `contents.txt` and generates `notebook.pdf`.

## 📖 Contents Automation

See [AUTOMATION_README.md](AUTOMATION_README.md) for detailed documentation on:
- How the auto-generation works
- Customizing algorithm names
- Configuring section order
- Advanced usage examples

## 🎯 Adding New Algorithms

1. **Add your algorithm file** to the appropriate folder in `code/`:
   ```
   code/graph/my_algorithm.cpp
   ```

2. **Optionally add a title comment** at the top of the file:
   ```cpp
   // My Amazing Algorithm
   // Complexity: O(n log n)
   
   void myAlgorithm() {
       // implementation
   }
   ```

3. **Rebuild the notebook**:
   ```bash
   .\build.ps1
   ```

That's it! Your algorithm is now in the PDF.

## 📂 Repository Structure

```
├── code/                          # Algorithm implementations
│   ├── c++/                       # C++ utilities and templates
│   ├── strings/                   # String algorithms
│   ├── graph/                     # Graph algorithms
│   ├── flows/                     # Network flow algorithms
│   ├── data-structures/           # Advanced data structures
│   ├── math/                      # Mathematical algorithms
│   ├── dynamic-programming/       # DP techniques
│   ├── geometry/                  # Computational geometry
│   └── miscellaneous/             # Other utilities
├── contents.txt                   # Algorithm index (auto-generated)
├── generate_contents_smart.py     # Smart auto-generator
├── generate_contents.py           # Basic auto-generator
├── generate_pdf.py                # PDF builder
├── notebook.tex                   # LaTeX template
├── Theory.tex                     # Mathematical formulas reference
└── notebook.pdf                   # Final output

```

## 🔍 Credits

The PDF generation system was adapted from [Stanford ICPC Notebook](https://github.com/jaehyunp/stanfordacm).
