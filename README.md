# 🏟️ Daffodil University Sports Complex Management System

**A Console-Based Sports Complex Management System Developed in C Programming with File Handling**


---

## 📌 Project Overview

The *Daffodil University Sports Complex Management System* is a menu-driven console application developed in *C Programming* that automates the management of a university sports complex.

The system provides a secure environment for administrators to manage sports facilities while allowing customers to book sports slots efficiently. It utilizes *File Handling* for persistent data storage and implements various validation techniques to ensure data integrity.

This project demonstrates practical implementation of:

* C Programming
* File Handling
* Modular Programming
* Authentication System
* Dynamic Data Management
* Booking Automation
* Schedule Management
* Billing System

---
<p align="center">

![C](https://img.shields.io/badge/C-Programming-blue?style=for-the-badge&logo=c)
![File Handling](https://img.shields.io/badge/File-Handling-success?style=for-the-badge)
![Console Application](https://img.shields.io/badge/Console-Application-orange?style=for-the-badge)
![Data Validation](https://img.shields.io/badge/Data-Validation-red?style=for-the-badge)
![Authentication](https://img.shields.io/badge/Admin-Authentication-purple?style=for-the-badge)
![Booking System](https://img.shields.io/badge/Booking-System-brightgreen?style=for-the-badge)
![Billing](https://img.shields.io/badge/Auto-Billing-blueviolet?style=for-the-badge)
![Schedule Tracking](https://img.shields.io/badge/Schedule-Tracking-yellow?style=for-the-badge)
![File System](https://img.shields.io/badge/Text-File%20Storage-lightgrey?style=for-the-badge)

</p>

# 🎯 Project Objectives

* Simplify sports facility booking.
* Automate booking and billing calculations.
* Maintain game information dynamically.
* Secure administrator operations.
* Store all records permanently using text files.
* Provide a centralized schedule management system.

---

# ✨ Key Features

## 🔐 Secure Admin Authentication

* Username & Password based login
* Maximum *3 login attempts*
* Unauthorized access prevention
* Separate Admin and Customer interfaces

---

## 🎮 Dynamic Game Management

Admin can:

* Add new sports
* Delete existing sports
* View all available games
* Store game information dynamically in *games.txt*

Each game stores:

* Game Name
* Price Per Hour
* Minimum Duration

---

## 🏸 Smart Booking Engine

Customers/Admin can:

* Select available games
* Enter booking time
* Automatic duration calculation
* Automatic billing calculation
* Booking confirmation

---

## ⏰ 24-Hour Time Validation

The system validates:

* Invalid time ranges
* Start time
* End time
* Booking duration

Example:

09:00 - 12:00
Duration = 3 Hours

---

## 💰 Automated Billing System

The system automatically calculates:

Total Bill
=
Game Price × Total Hours

Example:

Badminton
Price = $15/hr

Hours = 3

Total = $45

---

## 🆔 Unique Booking ID Generator

Each booking automatically generates a unique *5-digit Booking ID* using:

time(NULL)

Example:

Booking ID : #54827

---

## ✅ Game Validation

Before booking:

* Checks whether the game exists
* Rejects invalid game names
* Prevents fake bookings

---

## 📅 Schedule Tracking

Displays:

* Booking ID
* Customer Name
* Game Name
* Time Slot
* Total Bill

Allows administrators to monitor every booked slot.

---

## 👥 Member Tracking

Automatically tracks every successful booking.

Displays:

* Member Name
* Booked Game
* Time Slot
* Booking ID

Also shows:

* Total Confirmed Members

---

## 📢 Dynamic Notice Board

Supports:

* Viewing Sports Complex Rules
* Admin Announcement Updates
* Real-time Notice Editing

Stored inside:

notice.txt

---

## ❌ Booking Cancellation

Booking can be cancelled using:

* Booking ID

Implements:

* Temporary File Creation
* Record Replacement
* File Rename Technique

---

# 📂 File Structure

Sports-Complex-Management-System/
│
├── sports.c
├── games.txt
├── bookings.txt
├── notice.txt
├── temp.txt
├── temp_games.txt
└── README.md

---

# 💾 Data Storage

The project uses File Handling for persistent storage.

| File           | Purpose                    |
| -------------- | -------------------------- |
| games.txt      | Stores available sports    |
| bookings.txt   | Stores booking history     |
| notice.txt     | Stores announcements       |
| temp.txt       | Temporary booking deletion |
| temp_games.txt | Temporary game deletion    |

---

# 🖥️ Admin Functionalities

✔ Secure Login

✔ View Schedule

✔ View Notice Board

✔ Update Notice Board

✔ Add New Game

✔ Delete Game

✔ View Games

✔ Book Slot

✔ Cancel Booking

✔ View Members

---

# 👤 Customer Functionalities

✔ View Schedule

✔ View Notice Board

✔ Book Game

---

# 🛠 Technologies Used

* C Programming
* File Handling
* Standard C Library
* Time Library
* String Manipulation
* Console-Based User Interface

---

# 📋 Functional Modules

| Module               | Description                |
| -------------------- | -------------------------- |
| Authentication       | Secure Admin Login         |
| Game Management      | Add, Delete & View Games   |
| Booking System       | Slot Reservation           |
| Billing System       | Automatic Bill Calculation |
| Booking ID Generator | Unique ID Creation         |
| Schedule Manager     | Booking Overview           |
| Notice Board         | Dynamic Announcements      |
| Member Tracker       | Booking History            |
| Cancellation System  | Booking Removal            |

---

# 👨‍💻 Team Contributions

| Member                  | Student ID     | Responsibilities                                                                                                                                                                                                                       | Contribution                                  |
| ----------------------- | -------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------- |
| *Abid Hasan Sifat*    | *252-35-135* | • Admin Authentication System (Secure Login)<br>• Login Validation with Maximum 3 Attempts<br>• Dynamic Game Management (Add Game)<br>• Delete Game Feature<br>• View Available Games from File System                                 | *Authentication & Dynamic Game Management*  |
| *Rakib Hossain*       | *252-35-251* | • Smart Booking Engine<br>• 24-Hour Time Validation<br>• Automatic Duration Calculation<br>• Automatic Billing System<br>• Unique Booking ID Generation using time(NULL)`<br>• Game Validation (doesGameExist()` & getGamePrice()) | *Core Booking Engine & Automated Billing*   |
| *Md Thowhidul Mehraj* | *252-35-256* | • Dynamic Notice Board<br>• Admin Notice Update System<br>• Schedule Tracking Module<br>• Member Tracking System<br>• Booking Cancellation using Temporary File & Rename Technique                                                     | *System Analytics, Schedule & Notice Board* |

---

# 🚀 How to Run

## Clone Repository

git clone https://github.com/your-username/Sports-Complex-Management-System.git

## Compile

gcc sports.c -o sports

## Run

./sports

Windows

gcc sports.c -o sports.exe
sports.exe

---

# 📖 Future Improvements

* Password Encryption
* Multiple Admin Accounts
* GUI Version
* Database Integration (MySQL)
* Online Booking
* Payment Gateway
* Email Notifications
* QR Code Booking
* Sports Equipment Inventory
* Monthly Revenue Reports

---

# 📸 Sample Workflow

Admin Login
      │
      ▼
Manage Games
      │
      ▼
Customer Books Slot
      │
      ▼
Booking ID Generated
      │
      ▼
Automatic Bill Generated
      │
      ▼
Booking Saved
      │
      ▼
Schedule Updated
      │
      ▼
Member List Updated
      │
      ▼
Booking Can Be Cancelled

---

# 🎓 Academic Purpose

This project was developed as an academic group project for the *Software Engineering* program at *Daffodil International University (DIU)*. It demonstrates the practical implementation of core programming concepts, including file handling, modular design, authentication, data validation, and console-based system development.

---

# 📜 License

This project is intended for *educational and academic purposes only*.

---

# ⭐ Acknowledgements

Special thanks to our course instructor and *Daffodil International University* for providing the opportunity to develop this project and enhance our practical software development skills.

---

<div align="center">

### ⭐ If you found this project helpful, please consider giving it a Star!

*Built with ❤️ using C Programming*

</div>
