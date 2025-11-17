PhonebookProject
---------------
Files generated automatically.

How to build:
 - Requires Qt6 (Widgets, Sql) and CMake.
 - mkdir build && cd build
 - cmake ..
 - cmake --build .

Report: doc/report.docx
SQL script: doc/create_tables.sql

Notes:
 - DBStorage uses QPSQL driver. Make sure PostgreSQL client libs and driver are installed.
 - Copy/move profiling counters are in contact.h/cpp (CopyMoveStats).