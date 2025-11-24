# DRDO Entropy-Based Password Advisor (C++)

A lightweight C++ cybersecurity mini-project designed for DRDO internship submission. It evaluates password strength using **entropy**, performs breach checks, and gives **auto-improvement suggestions**.

## 🚀 Features
- Entropy calculation (in bits)
- Breach detection using a small common-password list
- Auto suggestions for strengthening password
- Rating system (Very Weak → Strong)
- Sample stronger password idea

## 🛠 Tech Used
- C++ (STL)
- Console-based

## 📂 How to Compile
```bash
g++ main.cpp -o advisor
./advisor
```

## 📌 Example Output
```
Enter password: Abc12

Estimated Entropy (bits): 28.20
Rating: Weak
Breach Check: Not found in small list
Suggestions:
1. Increase length (>= 12 recommended)
2. Add special symbols

Sample stronger idea: Abc12A1!
```
