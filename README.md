🚀 Smart Attendance System using RFID, ESP32 & React
An IoT-based attendance system with real-time tracking, a modern web dashboard, and seamless IN/OUT toggling using RFID technology.
📌 Table of Contents
Overview
Tech Stack
Features
Hardware Requirements
Software Requirements
System Architecture
Installation Guide
Project Structure
Future Enhancements
Contributing
License
🚀 Overview
This project is a real-time attendance tracking system that uses RFID technology with an ESP32 microcontroller and an RFID RC522 reader. The system:

✔ Reads RFID tags to mark attendance.
✔ Automatically toggles IN/OUT status for users based on their previous state.
✔ Displays attendance data in real-time on a modern, responsive React-based web dashboard.
✔ Uses WebSockets to push live attendance updates without refreshing the page.
✔ Has a dark/light mode toggle for an enhanced user experience.

This project is designed for schools, universities, offices, and events where attendance tracking needs to be automated and efficient.

🛠 Tech Stack
Hardware:
ESP32 (Can also use Arduino with Serial Communication)
RFID RC522 Module
RFID Cards/Tags
OLED Display (SSD1306)
Jumper Wires & Breadboard
Software:
Frontend: React (Vite), Tailwind CSS, Framer Motion
Backend: Node.js, Express.js, Socket.IO, SerialPort
Database (Optional): Firebase / MySQL
Communication: WebSockets for real-time updates
🌟 Features
✅ RFID-Based Attendance System – Scan an RFID card to mark attendance.
✅ Real-Time Web Dashboard – Live updates using WebSockets.
✅ IN/OUT Status Toggle – Users switch between IN and OUT when they tap their card.
✅ Beautiful UI with Dark Mode – Fully responsive design with a light/dark mode switch.
✅ OLED Display Integration – Shows user feedback when scanning RFID cards.
✅ Node.js Backend with Serial Communication – Reads data from the RFID module and sends it to the frontend.
✅ Fully Responsive Design – Works on desktops, tablets, and mobile devices.

📡 Hardware Requirements
Component	Description
ESP32	Microcontroller for processing RFID data.
RFID RC522	RFID module to scan cards/tags.
RFID Tags	Used for user identification.
OLED Display	Displays scanned user details.
Jumper Wires & Breadboard	For wiring and connections.
💻 Software Requirements
Software	Purpose
Node.js	Backend server for handling RFID data and WebSocket connections.
Express.js	Web framework for creating REST APIs.
React.js (Vite)	Frontend framework for the web dashboard.
Tailwind CSS	For styling the frontend.
Framer Motion	For smooth animations and UI effects.
SerialPort (Node.js)	To read RFID data from the ESP32.
Socket.IO	Enables real-time communication between the frontend and backend.
⚙ System Architecture
User taps RFID card on the reader connected to ESP32.
ESP32 reads the card's UID and matches it with known users.
If the UID exists, it toggles the IN/OUT status and sends data to the backend via Serial Communication.
Node.js backend processes the data and sends it to the React dashboard using WebSockets.
React frontend updates instantly to show the latest attendance records.
OLED display provides real-time feedback to the user about their attendance status.
📥 Installation Guide
1️⃣ Set Up Hardware (ESP32 + RFID Reader)
Connect RFID RC522 module to ESP32 using SPI.
Connect OLED Display to ESP32 using I2C.
Upload the Arduino sketch to the ESP32.
2️⃣ Backend Setup (Node.js + Express.js)
Install dependencies:
bash
Copy
Edit
cd backend
npm install
Start the backend server:
bash
Copy
Edit
node server.js
3️⃣ Frontend Setup (React + Vite + Tailwind CSS)
Install dependencies:
bash
Copy
Edit
cd frontend
npm install
Start the frontend development server:
bash
Copy
Edit
npm run dev
Now, open the browser at http://localhost:5173 to access the dashboard.

📂 Project Structure
bash
Copy
Edit
Smart-Attendance/
│── backend/                  # Node.js Backend
│   ├── server.js             # Express Server with WebSockets & SerialPort
│   ├── package.json          # Backend Dependencies
│── frontend/                 # React Frontend (Vite)
│   ├── src/
│   │   ├── components/
│   │   │   ├── Navbar.jsx
│   │   │   ├── AttendanceTable.jsx
│   │   ├── pages/
│   │   │   ├── Dashboard.jsx
│   │   ├── App.jsx
│   │   ├── main.jsx
│   ├── tailwind.config.js
│   ├── package.json          # Frontend Dependencies
│── README.md                 # Documentation
🚀 Future Enhancements
🔹 Cloud Storage Integration – Store attendance logs in Firebase or MySQL.
🔹 Admin Dashboard – Role-based access to view/manage attendance records.
🔹 Face Recognition – Integrate facial recognition for added security.
🔹 Email Notifications – Notify administrators when a student is absent or enters late.

🤝 Contributing
Want to contribute? Feel free to:

Fork the repository
Create a new branch
Make your changes
Submit a Pull Request
📜 License
This project is open-source and available under the MIT License.

💬 Let’s Connect!
📢 If you found this project useful, don’t forget to ⭐ the repo!
📩 Have suggestions or improvements? Feel free to open an issue or contribute.

🚀 Happy Coding! 😃
