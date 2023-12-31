# du-gui

## Graphical Overlay for UNIX program *du*

---

## **Description**

<p align="center">
  <img src="https://raw.githubusercontent.com/Baro-coder/du-gui/master/screenshots/screenshot_about_dialog.png"></img>
</p>

Console built-in program *du* is a UNIX utility to summarize disk usage of the set of files, recursively for directories.

This project is a graphical overlay for *du* program as a student project to master desktop application development with GLADE UI Designer and GTK framework.

---

## **Installation**

### **Requirements**

Application is developed and aims to Debian-based OS, but it can also be run on other UNIX-type operating system.

| Software | Version |
|---|---|
|GCC|11.3.0|
|GTK|3.0|

---

### **Install dependecies**

Install required GLADE, GTK, GCC packages:

``` console
sudo apt install -y glade gcc
```

### **Get the repository**

Download the Github repository:

``` console
git clone https://github.com/Baro-coder/du-gui.git
```

### **Build**

Change directory:

``` console
cd ./du-gui/app/
```

Build program:

``` console
make
```

Then rerun make command to complete building process.

### **Run**

Run app with the following command:

``` console
./bin/du-gui
```

---

## **User guide**

1. `Choose directory` to examine (**on default**: *program current dir*).

2. ***Optional***: `Choose pattern` of files to be excluded from output results.

3. ***Optional***: `Check options` that are fitted to you.

4. ***Optional***: `Select block size` (**on default**: *human readable* format).

5. `Click button` **Execute**.

---

## **UI Controls Structure**

<p align="center">
  <img src="https://raw.githubusercontent.com/Baro-coder/du-gui/master/screenshots/screenshot_main_window.png"></img>
</p>

### **Menu bar**

**Items:**

1. **Guide** - application user manual
2. **About** - application info and credits

---

### **Choose dir button**

Button calls dialog window used to determine which directory will be examined by the program. On default application current directory.

---

### **Combo box**

Patterns for `--exclude` argument passed.

#### **Patterns:**

|Label|Pattern|Description|
|---|---|---|
|**None** | *-* | No file will be excluded
|**C Source Files:**  | `*.c` | Files with extension *.c*
|**C++ Source Files:**  | `*.cpp` | Files with extension *.cpp*
|**Python files:** | `*.py` | Files with extension *.py*
|**Shell scripts:** | `*.sh` | Files with extension *.sh*

---

### **Checkboxes**

1. `-a` - **Include files** : include files, not only directories
2. `-c` - **Show total size** : produce grand total at the last line
3. `-L` - **Follow links** : follow links - dereference all symbolic links
4. `-l` - **Count hard links** :  count size m count size many times if hard linkedany times if hard linked
5. `-S` - **Separate directories** : for directories - do not include size of subdirectories
6. `-x` - **Skip other file systems** : skip directories on different file systems

---

### **Radioboxes**

Block size arguments:

1. `-h` - **Default** : Show in **human readable** scale
2. `-b` - **B** : Scale size to specified block size : **B - bytes**
3. `-BK` - **KiB** : Scale size to specified block size : **K - kilobyes**
4. `-BM` - **MiB** : Scale size to specified block size : **M - megabytes**
5. `-BG` - **GiB** : Scale size to specified block size : **G - gigabytes**

---

### **Buttons**

1. **Clear** - clear the output area
2. **Execute** - execute build command and print results into output area

### **Scrollable window**

Output text area able to be scrolled vertically and horizontally for maintain commands history and to handle much bigger outputs.

---

## **Potential future development**

1. More program arguments implemented like: `-s` (*summarize*) or `-d` (*max recursive depth*).
2. Entry to provide custom exclude patterns.
3. Storing results to output file.
