# Block 1: System Instructions

**Role:**
You are an expert Technical Writer and Senior Software Engineer specializing in C++ and Qt. You are writing a formal graduation/term project report for a university (BSUIR).

**Context:**
You have access to the following files:
1. `стп-2024.pdf`: General university requirements for document structure, formatting, and defense of term papers.
2. `шаблон.pdf`: A visual template demonstrating the required layout.
3. `formatting_lookup.md`: A lookup table containing specific formatting rules extracted from the STP document. Use this as your primary formatting rulebook.
4. `ПОСОБИЕ-2024.pdf`: A comprehensive guide on Russian language rules.
5. Project source code: C++ and Qt files (`main.cpp`, `boat_calc_base.h`, `boat_calc.h`, `boat_calc_widget.h`, `boat_calc_widget.ui`, `winmake.bat`, `linuxmake.sh`, `CMakeLists.txt`).

**Limitations:**
1. **Output Format:** You must generate ONLY raw text. DO NOT use standard Markdown formatting (no asterisks for bold, no hashtags for headers, no markdown lists).
2. **Custom Markup:** You must explicitly tag every structural element using the following exact bracket tags:
   - `[Заголовок H1]` (For main section titles)
   - `[Заголовок H2]` (For sub-section titles)
   - `[Абзац]` (Before every single paragraph of regular text)
   - `[Элемент списка]` (Before every bullet point or numbered list item)
   - `[Место для скриншота: <Description>]` (When suggesting where an image should be placed)
3. **Chunking Requirement:** For every Task must be written at least 4,000 characters. You must split your text generation into logical parts to avoid context cutoff (except for the Action Plan). At the very end of your response, you MUST write exactly: "Системное сообщение: часть <number> из <number>. Напишите *Продолжить*". If it is the final part of a task, write exactly: "Это последняя часть данного задания."
4. **Formatting Priority:** The rules specified in `стп-2024.pdf` (and accessed via `formatting_lookup.md`) take absolute precedence over general Russian language rules from `ПОСОБИЕ-2024.pdf`. Pay special attention to how lists, numbers, and references are introduced according to the STP.
5. **Code Independence:** Do NOT analyze or reference the provided source code files for any sections EXCEPT Section 3.
6. **Language:** The entire output must be written in formal, academic Russian.

**Evaluation:**
Before generating, ensure your response contains no markdown, strictly uses the bracket tags, adheres to the STP phrasing rules (e.g., no dangling prepositions before lists), and includes the chunking footer.

# Block 2: Action Plan

**Task:**
Analyze all provided context files and generate a detailed, step-by-step outline for the graduation project report.

Outline the exact structure of the document, defining the structure of Level 1 headings (Chapters). The required Level 1 headings are:
- Содержание (Table of Contents)
- Введение (Introduction)
- 1 Среда разработки программного средства (Chapter 1)
- 2 Разработка графического интерфейса программного средства (Chapter 2)
- 3 Разработка программного средства (Chapter 3)
- Заключение (Conclusion)
- Список использованных источников (References)

Give more freedom in choosing the names of Level 2 headings (sub-sections) within those chapters, but ensure they logically cover the required topics.
Note the specific requirements for each section (e.g., Section 3 requires deep code analysis and a minimum of 20,000 characters).

Do not write the actual report content yet. Just provide the detailed plan. You do not need to chunk this specific response.

# Block 3: Table of Contents and Introduction

**Task:**
Generate the Table of Contents (Содержание) and the Introduction (Введение) using the custom bracket markup. Do NOT reference the source code.

**Structure Requirements:**
1. **Содержание:**
- List all sections and subsections as defined in the plan.
- Do not use real page numbers. Instead, write "[страница]" where the number should be.
2. **Введение:**
- Must cover the following topics sequentially:
- Topic 1: The goal of the project is to study modern object-oriented programming (OOP) approaches, acquire C++ skills, and learn the Qt framework.
- Topic 2: Evolution of the mental model (From Array of Structures (AoS) to entities, ease of code management, passing pointers).
- Topic 3: The Iron Paradox (The 90s CPU boom masking OOP inefficiencies, computation speed outpacing memory bandwidth, the "Memory Wall").
- Topic 4: Hardware problem (Cache Miss effect, AoS loading unused fields into cache, CPU stalls).
- Topic 5: The modern comeback of Data-Oriented Design (DOD in GameDev/Big Data, how Structure of Arrays (SoA) utilizes cache and SIMD).

[Reminder]
Use chunking if necessary. End your response with the `[Системное сообщение: ...]` regarding the parts remaining. Use ONLY `[Tags]` for formatting.

# Block 4: Section 1

**Task:**
Generate Section 1: "Среда разработки программного средства" using the custom bracket markup. Do NOT reference the source code.

**Structure Requirements:**
1. **Среда разработки программного средства**
2. **Что такое Qt (экосистема)**
   - Discuss it as a cross-platform framework for desktop, mobile, and embedded systems.
   - Mention it goes beyond GUI (DB, network, multimedia).
   - Mention Qt Creator and localization tools.
3. **Расширение языка через препроцессинг**
   - Explain the Meta-Object Compiler (MOC).
   - How it extends standard C++ for signals and slots.
   - Note that the resulting code compiles with standard compilers (GCC, Clang, MSVC).
4. **Лицензирование фреймворка**
   - Explain the hybrid licensing model (commercial and free).
   - Mention open-source versions under GPL and LGPL.
   - Discuss flexibility for open and closed-source software.
5. **Framework Installation and Initial SetupRegistration and Download**
   - For Windows
       - Creating a Qt Account and downloading the official Qt Online Installer from the company's website.
       - Installation Process: a step-by-step walkthrough of the installation wizard.
       - Component Selection: choosing the required compiler versions (MinGW, MSVC, GCC) and development tools (Qt Creator, CMake).
   - For Linux
       - Provide generalized guide for package managers

[Reminder]
Apply `formatting_lookup.md` rules for lists and paragraphs. End with the chunking message.

# Block 5: Section 2

**Task:**
Generate Section 2: "Разработка графического интерфейса программного средства" using the custom bracket markup. Do NOT reference the source code.

**Structure Requirements:**
1. **Разработка графического интерфейса программного средства**
2. **Решение проблемы хардкода (Layouts)**
   - Separation of layout logic from physical coordinates.
   - Layout managers automatically adapt UI.
   - Developers describe behavior, not pixel offsets. Dynamic scaling for DPI.
3. **Абстракция от графических серверов (QPA)**
   - Qt Platform Abstraction isolates app code from the OS.
   - Write once, run on Windows, macOS, Android, Linux.
   - Seamless switching between X11, Wayland, or Linux Framebuffer.
4. **XML-описание интерфейса (.ui)**
   - Qt Designer saves UI in XML format.
   - `.ui` describes object trees and properties, isolating design from C++ logic.
   - Include `[Место для скриншота: Окно Qt Designer с открытым файлом интерфейса]`.
5. **Магия компиляции и утилита UIC**
   - User Interface Compiler (UIC) turns XML into a C++ header.
   - The generated header contains native widget creation code.
   - `setupUi` method automatically builds the UI and layouts. Guarantees strict typing and max performance.

[Reminder]
End with the chunking message.

# Block 6: Section 3

**Task:**
Generate Section 3: "Разработка программного средства".
**CRITICAL REQUIREMENT:** This section MUST be highly detailed and contain a minimum of 9,000 characters (including spaces). You MUST deeply analyze the provided source code (`main.cpp`, `boat_calc.h`, `boat_calc_base.h`, `boat_calc_widget.h`, build scripts). Split your output into multiple chunks using the chunking rule.

**Structure Requirements:**
1. **Разработка программного средства**
   - Introduction: State that the code is a cross-platform desktop app (C++ / Qt6) calculating the separation speed and distance of two boats. Emphasize OOP principles and logic/UI separation.
2. **Архитектура и запуск приложения**
   - Deeply analyze `main.cpp`. How `QApplication` is initialized, how the main widget `Boat_Calc_Widget` is instantiated and shown, and the execution loop `app.exec()`.
   - Give code snippets along the way.
3. **Иерархия классов и бизнес-логика**
   - Analyze `Boat_Calc_Base`: Explain the `Boat_Num` enum, safe setters/getters with `std::isnan`/`std::isinf` checks, and the `get_moveaway_speed()` math logic.
   - Analyze `Boat_Calc` (Inheritance): Explain how it extends the base class with time processing (`time_hours`) and calculates distance.
   - Detail the OOP principles used (Inheritance, Encapsulation, Polymorphism/Virtual destructors).
   - Mention the UML diagram located in Appendix A (`Приложение А`).
   - Give code snippets along the way.
4. **Связь бизнес-логики с графическим интерфейсом**
   - Analyze `Boat_Calc_Widget`. Explain the composition (holding a `Boat_Calc` instance).
   - Detail the UI setup: `ui->setupUi(this)`, dynamic property assignments (`boat_label_property`).
   - Deep dive into Input Validation: How `QDoubleValidator` and `QLocale::c()` are used to prevent invalid inputs (rejecting group separators, enforcing standard notation).
   - Explain Signal/Slot connections using C++11 lambdas (`&QLineEdit::editingFinished`).
   - Give code snippets along the way.
5. **Процесс сборки: препроцессинг, компиляция, линковка**
   - Explain the 3 stages of C++ compilation (applicable up to C++20).
   - Analyze the build automation using CMake as seen in `winmake.bat` and `linuxmake.sh`.
   - Detail the configuration steps (`cmake -B`, generators like MinGW Makefiles, build types).
6. **Развертывание (Deployment) и линковка**
   - Compare static vs dynamic linking.
   - Analyze the deployment phase in the scripts: using `windeployqt.exe` for Windows vs standard binary copying for Linux.

[Reminder]
Ensure deep explanations of the code to reach the 9,000 character limit. End every response part with the chunking message.

# Block 7: Conclusion

**Task:**
Generate the Conclusion (Заключение) using the custom bracket markup.

**Structure Requirements:**
1. **ЗАКЛЮЧЕНИЕ**
2. Write a comprehensive summary of the entire project.
3. State that the goals set in the introduction were successfully met.
4. Summarize the path taken: from setting up the Qt ecosystem and understanding DOD/OOP paradigms, through designing the UI via XML/UIC, to deeply implementing the boat calculation business logic in C++.
5. Conclude with the successful configuration of cross-platform build scripts (CMake) and deployment (windeployqt/Linux).

[Reminder]
End with the chunking message.

# Block 8: Bibliography

**Task:**
Generate the Bibliography (Список использованных источников) using the custom bracket markup.

**Structure Requirements:**
1. **СПИСОК ИСПОЛЬЗОВАННЫХ ИСТОЧНИКОВ**
2. Create a numbered list (using `[Элемент списка]`) of at least 8 highly realistic references.
3. **CRITICAL:** The formatting of the references must strictly follow the rules provided in `стп-2024.pdf` (Section 2.8), accessible via `formatting_lookup.md`. (e.g., Use correct spacing around slashes and dashes).
4. Include references to:
   - Official Qt 6 Documentation (specifically classes used: QApplication, QWidget, QLineEdit, QDoubleValidator).
   - Official CMake Documentation.
   - Standard C++ reference (for std::isnan, std::isinf, std::max, std::abs).
   - A textbook on Object-Oriented Programming in C++.

[Reminder]
End with chunking message.
