# Competitive-Programming-Notebook
This is a repository for MIST_Untitled team codebook. Consist of me, [Istiaque Ahmed Arik](https://github.com/istiaqueahmedarik) and Shihab Ahmed.

The folder `code` contains algorithms used in coding competitions: graph algorithms, data structures, number theory, dynamic programming and other competitive programming utilities.

**NOTE:** Look `code/c++/1. template.cpp` to understand macros used in the code.

## 📚 Quick Start

### Build the Complete Notebook

```bash
python auto_contents.py
python generate_pdf.py
```

This will:
1. Auto-generate `contents.txt` by scanning your `code/` directory
2. Compile the LaTeX document to create `notebook.pdf`

### Requirements
- [Python 3.x](https://www.python.org/)
- [latexmk](https://www.ctan.org/pkg/latexmk/) (part of TeX Live, MiKTeX, etc.)

## 🔧 Workflow

### 1. Generate contents.txt

```bash
python auto_contents.py
```
- Automatically scans `code/` directory
- Generates the table of contents for the notebook

### 2. Generate PDF

```bash
python generate_pdf.py
```

This reads `contents.txt` and generates `notebook.pdf`.

## 🎯 Adding New Algorithms

1. **Add your algorithm file** to the appropriate folder in `code/`:
   ```
   code/graph/my_algorithm.cpp
   ```

2. **Rebuild the notebook**:
   ```bash
   python auto_contents.py
   python generate_pdf.py
   ```

That's it! Your algorithm is now in the PDF.

## 📂 Repository Structure

```
├── code/                          # Algorithm implementations
│   ├── c++/                       # C++ utilities and templates
│   ├── dsa/                       # Data structures and algorithms
│   ├── graph/                     # Graph algorithms
│   ├── number_theory/             # Number theory algorithms
│   ├── dynamic-programming/       # DP techniques
│   └── miscellaneous/             # Other utilities
├── contents.txt                   # Algorithm index (auto-generated)
├── contents.tex                   # LaTeX formatted contents
├── auto_contents.py               # Contents auto-generator
├── generate_pdf.py                # PDF builder
├── notebook.tex                   # LaTeX main document
├── Theory.tex                     # Mathematical formulas reference
└── notebook.pdf                   # Final output
```

## 🔍 Credits

The PDF generation system was adapted from [Stanford ICPC Notebook](https://github.com/jaehyunp/stanfordacm).
