# du-gui

## Graphical Overlay for UNIX program *du*

---

## **Description**

Console built-in program *du* is a UNIX utility to summarize disk usage of the set of files, recursively for directories.

This project is a graphical overlay for *du* program as a student project to master desktop application development with GLADE UI Designer and GTK framework.

---

## **Installation**

### **Get the repository**

Download the Github repository

``` console
git clone *****
```

### **Build**

Change directory:

``` console
cd ./du-gui/du-gui/
```

Build program:

``` console
make clean; make
```

### **Run**

Run app with the following command:

``` console
./bin/du-gui
```

---

## **UI Structure**

### **Menu bar**

1. **Guide** - application user manual
2. **About** - application info and credits

---

### **Choose dir button**

Dialog window used to determine which directory will be examined.

---

### **Combo box**

Patterns for `--exclude` argument passed.

#### **Patterns:**

1. **None**
2. **C files:** `*.c *.h *.cpp *.hpp`
3. **Python files:** `*.py`
4. **Shell files:** `*.sh`

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

1. `-h` - **Default** : Show in human readable scale
2. `-b` - **B** : Scale size to specified block size : B - bytes
3. `-BK` - **KiB** : Scale size to specified block size : K - kilobyes
4. `-BM` - **MiB** : Scale size to specified block size : M - megabytes
5. `-BG` - **GiB** : Scale size to specified block size : G - gigabytes

---

### **Buttons**

1. **Clear** - clear the output area
2. **Execute** - execute build command

### **Scrollable area**

Output text area able to be scrolled up and down for maintain commands history and to handle much bigger outputs.

---

## xxx
