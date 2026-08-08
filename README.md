<div align="center">

# 🏟️ Daffodil Sports Management System

**A C-based console application for sports venue booking & management**

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Storage](https://img.shields.io/badge/Storage-File--Based-0EA678?style=for-the-badge)
![Structure](https://img.shields.io/badge/Core-Binary%20Search%20Tree-F2A93B?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

</div>

---

## ✨ Overview

**Daffodil Sports Management System** is a menu-driven console application built entirely in C that simulates a real-world sports venue booking platform — the kind used to reserve futsal courts, badminton halls, or cricket arenas on campus.

Instead of a database, the system relies on **plain text files** for persistence and a **Binary Search Tree** to keep every registered venue organized and instantly searchable by name. Every password that touches the system — Admin, Provider, or Customer — passes through a custom MD5-style hashing routine before it's ever written to disk, so credentials are never stored in plain text.

The whole system revolves around three connected portals sharing one live venue registry:

| 👤 Role | 🎯 What They Do |
|---|---|
| 🔐 **Admin** | Logs in with hashed credentials and manages game pricing (add / delete / view) |
| 🏢 **Venue Provider** | Signs up, logs in, and registers new venues into the shared BST |
| 🙋 **Customer / Student** | Browses venues alphabetically, searches the BST, books a slot, and can reschedule it later |

From sign-up to payment confirmation, every action is validated, logged to file, and immediately reflected across the system — so a venue added by a Provider is searchable by a Customer in the very same session.

---

## 🚀 Key Features

- 🔒 **MD5-hashed passwords** — never stored in plain text
- 🌳 **Binary Search Tree** venue registry — O(log n) search
- 📅 **Smart slot booking** — blocks double-booking automatically
- 🔁 **Safe file rewrites** — temp-file swap pattern for edits
- 📁 **Zero-setup storage** — pure `.txt` files, no DB needed

---

## 🗂️ Files at a Glance

| File | Purpose |
|---|---|
| `providers.txt` | Provider accounts (username + hash) |
| `customers.txt` | Customer accounts (username + hash) |
| `games.txt` | Game pricing catalogue |
| `bookings.txt` | Slot booking records |
| `temp_games.txt` | Buffer for game deletion |
| `temp_bookings.txt` | Buffer for date changes |

---

## 🧬 Core Structures

```c
struct Game       { name, price, duration }
struct VenueNode  { id, name, area, sport, price, *left, *right }   // BST
struct Booking    { bookingId, customerName, venueName, date, slot, paymentAmount }
```

---

## 🗺️ Menu Flow

```
Main Menu
 ├── 1. Admin            → Add / Delete / View Games
 ├── 2. Venue Provider   → Sign Up → Login → Add / View Venues
 ├── 3. Customer         → Sign Up → Login → Book / Reschedule
 └── 4. Exit
```

---

## ⚙️ Run It

```bash
gcc sports_management.c -o sports_management
./sports_management
```

---

## 👥 Contributors

| Contributor | ID | Role | Key Modules |
|---|---|---|---|
| **Md Abid Hasan Sifat** | `252-35-135` | 🔐 Security & Auth Specialist | `compute_md5`, login/signup flows, `games.txt` management |
| **Md Rakib Hossain** | `252-35-251` | 🌳 BST & Data Structures Specialist | `insertVenue`, `searchVenueBST`, `displayVenuesBST` |
| **Md Thowhidul Mehraj** | `252-35-256` | 📅 Scheduling & Booking Specialist | `showBookedSlots`, `bookSlot`, `changeBookingDate` |

---

## 🔮 Future Scope

- 🗄️ Move to a real database (SQLite/MySQL)
- 🔐 Upgrade hashing to salted SHA-256
- ⚖️ Self-balancing BST (AVL) for guaranteed O(log n)

<div align="center">

Made with 💚 for **Daffodil International University**

</div>
