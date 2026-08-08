<div align="center">

🏟️ Daffodil Sports Management System

🚀 A C-Based Sports Venue, Booking & Management System

<p>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Data%20Structure-BST-6A1B9A?style=for-the-badge" alt="BST">
  <img src="https://img.shields.io/badge/Security-Hashing-E65100?style=for-the-badge&logo=letsencrypt&logoColor=white" alt="Security">
  <img src="https://img.shields.io/badge/Storage-File%20Based-2E7D32?style=for-the-badge" alt="File Storage">
</p>

<p>
  <b>🔐 Authentication</b> &nbsp;•&nbsp;
  <b>🌳 BST Venue Search</b> &nbsp;•&nbsp;
  <b>📅 Slot Booking</b> &nbsp;•&nbsp;
  <b>💾 File Management</b>
</p>

</div>

🌟 Project Overview

Daffodil Sports Management System is a C-based application developed to manage sports venues, users, game pricing, schedules, and bookings through a simple role-based interface.

The system contains three major user portals:

👤 Role

🎯 Main Purpose

🔴 Admin

Authentication, game pricing and game management

🔵 Venue Provider

Venue registration and venue listing

🟢 Customer / Student

Venue search, slot booking and booking-date modification

The project combines C structures, pointers, dynamic memory allocation, Binary Search Tree (BST), recursion, hashing concepts, string processing, and persistent text-file storage.

✨ Key Features

🔐 Secure Authentication

Admin login with a maximum of 3 attempts

Venue Provider Sign Up / Login

Customer / Student Sign Up / Login

Passwords are converted to a hash representation before being stored

Persistent account data:

providers.txt

customers.txt

🧑‍💼 Admin Management

Admin can:

➕ Add game pricing

🗑️ Delete games

👀 View available games

🚪 Logout

Game information is stored in games.txt.

🌳 Binary Search Tree Venue Engine

Venues are organized using a Binary Search Tree based on venue name.

The BST provides:

🧱 Dynamic node creation

➕ Alphabetical insertion

🔎 Venue searching

🔄 Recursive in-order traversal

📋 A-Z venue display

📅 Schedule & Booking

Customers can:

View available venues

Search a venue using BST

Select a date

View occupied slots

Enter customer and slot information

Generate a four-digit Booking ID

Save booking/payment information

Booking records are stored in:

bookings.txt

🔄 Change Booking Date

Customers can modify an existing booking using its Booking ID.

The system uses:

bookings.txt
      ↓
temp_bookings.txt
      ↓
Updated bookings.txt

This provides a simple temporary-file replacement mechanism for updating persistent records.

🏗️ System Architecture

                         🏟️ SPORTS MANAGEMENT SYSTEM
                                    │
              ┌─────────────────────┼─────────────────────┐
              │                     │                     │
          🔴 ADMIN              🔵 PROVIDER          🟢 CUSTOMER
              │                     │                     │
        Admin Login           Sign Up / Login       Sign Up / Login
              │                     │                     │
      ┌───────┼───────┐        ┌────┴────┐        ┌──────┼────────┐
      │       │       │        │         │        │      │        │
     ➕      🗑️      👀       Add      View      View   Search   Change
    Game    Game    Games    Venue     BST      Venues  & Book    Date
                                                     │
                                                     ▼
                                                🌳 BST Search
                                                     │
                                                     ▼
                                                📅 Slot Booking
                                                     │
                                                     ▼
                                               💾 bookings.txt

🌳 BST Venue Management

The core venue structure is:

struct VenueNode {
    int id;
    char name[50];
    char area[50];
    char sport[30];
    double price;
    struct VenueNode *left;
    struct VenueNode *right;
};

Core BST Functions

Function

Description

createVenueNode()

Dynamically creates a new venue node

insertVenue()

Inserts a venue alphabetically

searchVenueBST()

Searches for a venue by name

displayVenuesBST()

Recursively displays venues in-order

⚡ Search Complexity

For a balanced BST:

Average Search → O(log n)

Worst case for a highly unbalanced BST:

Worst Case → O(n)

🏟️ Default Venues

The system starts with three default venues:

🏟️ Venue

📍 Area

⚽ Sport

💰 Rate

Daffodil Futsal

Ashulia

Football

1200.00/hr

DIU Indoor

Ashulia

Badminton

500.00/hr

Mirpur Arena

Mirpur

Cricket

2000.00/hr

Venue Providers can dynamically register additional venues.

🔑 Authentication & Security

The project contains a custom function named:

compute_md5()

It generates a 32-character hexadecimal hash representation used during authentication.

Authentication Flow

User enters password
        │
        ▼
  compute_md5()
        │
        ▼
 Hashed password
        │
        ▼
Compare with stored hash
        │
   ┌────┴────┐
   ▼         ▼
 Match     No Match
   │         │
   ▼         ▼
 Login    Reject

Credentials are persisted in:

providers.txt
customers.txt

⚠️ Implementation Note: The uploaded source calls the function compute_md5(), but its internal routine is a custom bitwise hashing routine rather than a standard RFC MD5 implementation. This README describes the actual implementation.

💰 Game Pricing Management

The Admin module uses:

struct Game {
    char name[30];
    double price;
    int duration;
};

Available Operations

Admin Dashboard
      │
      ├── ➕ Add Game Pricing
      ├── 🗑️ Delete Game
      ├── 👀 View All Games
      └── 🚪 Logout

Game information is stored in:

games.txt

Game deletion uses:

games.txt
     ↓
temp_games.txt
     ↓
Updated games.txt

📅 Booking System

The booking engine uses:

struct Booking {
    int bookingId;
    char customerName[50];
    char venueName[50];
    char date[15];
    char slot[20];
    double paymentAmount;
};

Booking Workflow

🔎 Search Venue
      ↓
🌳 BST Search
      ↓
🏟️ Venue Found
      ↓
📅 Enter Date
      ↓
👀 Show Occupied Slots
      ↓
⏰ Enter Desired Slot
      ↓
🎫 Generate Booking ID
      ↓
💳 Record Payment
      ↓
💾 Save to bookings.txt

Booking records follow:

BookingID,CustomerName,VenueName,Date,Slot,PaymentAmount

📂 Data Files

📄 File

📝 Purpose

providers.txt

Venue Provider usernames and hashed passwords

customers.txt

Customer/Student usernames and hashed passwords

games.txt

Game names, prices and durations

bookings.txt

Booking and payment records

temp_games.txt

Temporary file used during game deletion

temp_bookings.txt

Temporary file used during booking-date updates

🧩 Core Modules

🔐 Security & Authentication

compute_md5()
adminLogin()
providerSignUp()
providerLogin()
customerSignUp()
customerLogin()
addGame()
deleteGame()
viewGames()

🌳 BST Venue Engine

createVenueNode()
insertVenue()
searchVenueBST()
displayVenuesBST()

📅 Schedule & Booking Engine

showBookedSlots()
bookSlot()
changeBookingDate()

🛠️ Technologies & Concepts

<div align="center">

Technology / Concept

Usage

💻 C Programming

Main development language

🌳 Binary Search Tree

Venue organization and searching

🔄 Recursion

BST operations and traversal

🧠 Pointers

Dynamic data structures

💾 File Handling

Persistent data storage

🔐 Hashing

Password representation

🧱 Structures

Game, Venue and Booking records

🔤 String Processing

Venue comparison and file parsing

🗃️ Temporary Files

Safe record replacement workflow

</div>

📁 Project Structure

Daffodil-Sports-Management-System/
│
├── 📄 main.c
│
├── 📄 providers.txt
├── 📄 customers.txt
├── 📄 games.txt
├── 📄 bookings.txt
│
├── 📄 temp_games.txt
├── 📄 temp_bookings.txt
│
└── 📘 README.md

The uploaded source does not specify the exact .c filename, so main.c above is a representative project structure rather than an asserted source filename.

👨‍💻 Team Contribution

🏆 Contributors

👨‍💻 Contributor

🆔 ID

🎯 Role

🔧 Main Responsibilities

Md Abid Hasan Sifat

252-35-135

🔐 Security & Authentication Specialist

Authentication workflows, password hashing, Admin/Provider/Customer Sign Up & Login, credential file storage, and Admin game pricing management

Md Rakib Hossain

252-35-251

🌳 Data Structures & BST Engine Specialist

struct VenueNode, dynamic memory allocation, alphabetical BST insertion, venue search, and recursive in-order traversal

Md Thowhidul Mehraj

252-35-256

📅 Schedule, Booking & File Systems Specialist

Schedule visualization, slot booking, Booking ID generation, payment recording, and booking-date modification using temporary-file replacement

🔐 Contributor 1 — Md Abid Hasan Sifat

ID: 252-35-135

Role

Security & Authentication Specialist

Responsibilities

🔑 Admin authentication

👤 Venue Provider authentication

👨‍🎓 Customer/Student authentication

🔐 Password hashing through compute_md5()

💾 Provider credentials → providers.txt

💾 Customer credentials → customers.txt

➕ Add game pricing

🗑️ Delete games

👀 Display games

Main Functions

compute_md5()
adminLogin()
providerSignUp()
providerLogin()
customerSignUp()
customerLogin()
addGame()
deleteGame()
viewGames()

🌳 Contributor 2 — Md Rakib Hossain

ID: 252-35-251

Role

Data Structures & BST Engine Specialist

Responsibilities

🌳 Binary Search Tree architecture

🧱 Dynamic memory allocation

🏟️ Venue node creation

🔤 Alphabetical venue insertion

🔎 BST venue search

🔄 Recursive in-order traversal

📋 A-Z venue display

Main Functions

createVenueNode()
insertVenue()
searchVenueBST()
displayVenuesBST()

📅 Contributor 3 — Md Thowhidul Mehraj

ID: 252-35-256

Role

Schedule, Booking & File Systems Specialist

Responsibilities

📅 Schedule visualization

👀 Display occupied slots

🎫 Booking ID generation

🏟️ Venue booking

💳 Payment amount recording

💾 Booking file management

🔄 Booking-date modification

📄 Temporary-file replacement

Main Functions

showBookedSlots()
bookSlot()
changeBookingDate()

⚠️ Implementation Notes

1. Double-Booking Prevention

The current implementation of showBookedSlots() reads and displays occupied slots for a selected venue and date.

However, the current bookSlot() implementation does not directly reject a newly entered slot if it matches an existing occupied slot.

Therefore:

Current Code:
Show occupied slots ✅
Prevent duplicate slot automatically ❌

This can be improved by adding a slot-existence validation before writing the new booking.

2. Hashing Implementation

Although the function is named:

compute_md5()

the uploaded implementation does not implement the standard MD5 algorithm. It performs a custom bitwise transformation and has a special handling for the Admin password.

The README intentionally documents the implementation as it exists in the source code.

🚀 Future Improvements

Possible future enhancements include:

🛡️ Replace custom hashing with a standard cryptographic password-hashing algorithm

🚫 Add strict double-booking validation

🎫 Ensure generated Booking IDs are always unique

🧹 Add memory cleanup for dynamically allocated BST nodes

📊 Add booking history and cancellation

👤 Add profile management

💳 Improve payment validation

📆 Add date and time validation

🖥️ Develop a graphical/web interface

🗄️ Replace text files with a database for larger-scale deployment

🎯 Learning Outcomes

This project demonstrates practical application of:

C Programming
     ↓
Structures + Pointers
     ↓
Dynamic Memory Allocation
     ↓
Binary Search Tree
     ↓
Recursion
     ↓
File Handling
     ↓
Hashing Concepts
     ↓
Authentication
     ↓
Booking Management

It provides hands-on experience in combining data structures, algorithms, security concepts, and file systems into a single functional application.

👥 Team

<div align="center">

💙 Developed by

Md Abid Hasan Sifat252-35-135

Md Rakib Hossain252-35-251

Md Thowhidul Mehraj252-35-256

🏟️ Daffodil Sports Management System

Built with C • BST • File Handling • Hashing • Teamwork

⭐ If you find this project useful, consider giving it a star!

</div>
