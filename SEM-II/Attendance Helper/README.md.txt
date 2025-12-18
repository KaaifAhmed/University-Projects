# Attendance Helper

A simple Java console application for taking and saving class attendance.

## Features
- Supports multiple classes (defined in `config.txt`)
- Attendance entry by seat number (p/a/r for present/absent/redo)
- Review and edit attendance before saving
- Attendance saved with date and time in filename and inside file

## Requirements
- Java 8 or newer (JDK)

## Setup
1. **Download or clone the project folder.**
2. **Check your folder structure:**
   - `AttendanceHelper.java` (main source file)
   - `config.txt` (class details)
   - Attendance directories as specified in `config.txt`

3. **Edit `config.txt` as needed:**
   - Format: `className,numStudents,attendanceDir`
   - Example:
     ```
     BSAI_SEMII,6,classes/BSAI_SEMII/attendance/
     BSCS_SEMI,5,classes/BSCS_SEMI/attendance/
     ```

## How to Run
1. **Compile the program:**
   - Open a terminal in the project folder.
   - Run:
     ```
     javac AttendanceHelper.java
     ```
2. **Run the program:**
   - Run:
     ```
     java AttendanceHelper
     ```

## Usage
- Select a class by number.
- Enter attendance for each seat:
  - `p` for present
  - `a` for absent
  - `r` to redo previous seat
- After entry, review and toggle any seat's attendance as needed.
- Save the attendance record when done.
- Attendance files are saved in the specified directory, named as `attendance_YYYY-MM-DD_hh-mm.txt`.

## Notes
- Make sure attendance directories exist or will be created by the program.
- You can add or edit classes in `config.txt`.
- No student names are used, only seat numbers.

## Troubleshooting
- If you see "No classes found. Exiting.", check your `config.txt` format and location.
- If you get file errors, check directory paths in `config.txt`.